#include <Arduino.h>
#include <WiFi.h>
#include "esp_log.h"
#include "mqtt_client.h"


static const char *TAG = "ESP_FHSTP";
const char* ssid = "hotspot";
const char* password = "12345678";
const char* lwt_message = "OFFLINE";
boolean toggler = false;

static void log_error_if_nonzero(const char *message, int error_code)
{
    if (error_code != 0) {
        ESP_LOGE(TAG, "Last error %s: 0x%x", message, error_code);
    }
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
    esp_mqtt_event_handle_t event = (esp_mqtt_event_handle_t)event_data;
    esp_mqtt_client_handle_t client = event->client;
    int msg_id;
    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        msg_id = esp_mqtt_client_publish(client, "fhstp/id/online", "ONLINE", 0, 1, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
        msg_id = esp_mqtt_client_subscribe(client, "fhstp/#", 1);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        break;

    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        msg_id = esp_mqtt_client_publish(client, "fhstp/id", "subscribed", 0, 0, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA:
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        printf("DATA=%.*s\r\n", event->data_len, event->data);
        digitalWrite(LED_BUILTIN, toggler);
        toggler = !toggler;
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT) {
            log_error_if_nonzero("reported from esp-tls", event->error_handle->esp_tls_last_esp_err);
            log_error_if_nonzero("reported from tls stack", event->error_handle->esp_tls_stack_err);
            log_error_if_nonzero("captured as transport's socket errno",  event->error_handle->esp_transport_sock_errno);
            ESP_LOGI(TAG, "Last errno string (%s)", strerror(event->error_handle->esp_transport_sock_errno));
        }
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}



static void mqtt_app_start(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        // .uri = "ws://mqtt.eclipseprojects.io:80/mqtt",
    };
    mqtt_cfg.uri = "ws://mqtt.eclipseprojects.io:80/mqtt";
    //mqtt_cfg.uri = "mqtt://192.168.0.99:1883";


    mqtt_cfg.lwt_topic = "fhstp/id/online";
    mqtt_cfg.lwt_msg = lwt_message;
    mqtt_cfg.lwt_msg_len = strlen(lwt_message);  // Specify the length of the LWT message
    mqtt_cfg.lwt_qos = 1;
    mqtt_cfg.lwt_retain = 1;  // Set to 1 to retain the last will message
    mqtt_cfg.username = "user";
    mqtt_cfg.password = "password";
    mqtt_cfg.client_id = "ESP32";  // Use the device ID as the client ID



    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    /* The last argument may be used to pass data to the event handler, in this example mqtt_event_handler */
    esp_mqtt_client_register_event(client, MQTT_EVENT_ANY, mqtt_event_handler, NULL);
    esp_mqtt_client_start(client);
}



void setup() {
  
  Serial.begin(115200);
  delay(100);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
    Serial.println();
  }
  Serial.println("Connected to :");
  Serial.println(ssid);

  mqtt_app_start();
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  
}

