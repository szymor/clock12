# 12-dioded clock

### What is it?
As the name suggests, it is a 12-dioded clock, each diode represents one digit on the clock face. Hours are minutes are represented respectively by constant and blinking light.

### Hardware
Quite straight-forward construction. Just look at the schematics.

LEDs are controlled using a PWM signal. In my variant of the device there is no possibility to set the clock time because there is no physical access to the button and the jumper - take a glance at one of the images in the img folder to know what I am talking about.

### Software
I am not too proud of the quality of the code - without the -O3 optimization it is pretty useless in the current form, this is the price of writing things in a too abstract way.

I2C library has been created by Peter Fleury.

### Other information
Date of project completion - August 2014
