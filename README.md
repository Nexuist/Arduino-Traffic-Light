### Introduction

One of the projects for our Exploring Computer Science class was to develop some kind of device that used LEDs, potentiometers, serial output, etc. This is my project.

I developed a traffic light with a red, yellow, and green LED as well as a potentiometer and two push buttons. The documentation is available here. The code and board were finished completely on March 29, 2016.

### Operation

* The system will begin with the red light turned on and in `STAY_ON` mode.

* The brightness of the LED can be adjusted using the potentiometer in any mode except `FADE` (since fading adjusts brightness automatically).

* The `Change Light` button will iterate between illuminating the red, yellow, and green LEDs.

* The `Change Mode` button will iterate between `BLINK` (turning on and off every half second), `FADE` (moving from lowest to highest brightness and back again), and `STAY_ON` (self explanatory).

### Code Quality

Please note that comments have been added after-the-fact (I was short on time). Also, at the time of this writing, the board had already been taken apart, so I can not test any changes. Therefore, I have not modified the code in any way other than adding comments. This means that there are probably (most likely) sections that are inefficient and unoptimized. I will try to note this in the comments.

### Breadboard

![Arduino and breadboard wired up](/board.png)

The bill of materials is available [here](meme) (bill-of-materials.html)

Red wires carry a 5V charge, black wires connect to ground, and orange wires connect to an Arduino pin. All resistors are 220Ω.
