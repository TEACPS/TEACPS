# Simple LED

Build the following circuit:
GND 🡪 $220 Ω$ resistor (red-red-black-black) 🡪 LED 🡪 3V

Take care about the LED direction (Long lead 🡪 +). Try reversing the LED; it will no longer glow.

![Circuit design of the \"Simple LED\" example to supply a LED with
power through an
ESP23.](./media/circuit-simple-led.svg)

## How to calculate the resistor

The power drop on a red LED is usually around $1.8V$ 
(the exact amount depends on the LED type and its color).

$$
3.3V (power source) - 1.8V (LED) = 1.5V (Resistor)
$$

The LED typically has its maximum brightness around $20 mA$, but $15 mA$ are OK and on the safe side.

$$
R = U / I = 1.5 / 0.015 = 100 Ω
$$

Resistors are usually only available in standard values, so use the next
bigger resistor if the exact value isn't available. Better to be above
calculated resistor value, not below: this saves battery life and heat. Also,
our resistors have $+/- 5%$ tolerance. As we do not have such a small
resistor, we use a bigger one; the light will simply be darker. You can
also test with the $220 Ω$ resistor.

A bit more background info:
<http://www.evilmadscientist.com/2012/resistors-for-leds/>
