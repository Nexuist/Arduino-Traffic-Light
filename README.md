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

The bill of materials is available [here](http://htmlpreview.github.io/?https://github.com/Nexuist/Arduino-Traffic-Light/blob/master/bill-of-materials.html) (bill-of-materials.html)

Red wires carry a 5V charge, black wires connect to ground, and orange wires connect to an Arduino pin. All resistors are 220Ω.

### License

```MIT License

Copyright (c) 2016 Andi Andreas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.```
