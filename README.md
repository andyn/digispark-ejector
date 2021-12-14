# digispark-ejector

Ejection seat handle for combat flight simulation games such as DCS World. 

## Overview and usage

Pulling the rope switch, attached to pin number 0, sends Ctrl-E a dozen times a second or so, triggering the ejection
seat in most combat flight simulation games. Two additional inputs attached to pins 1 and 2 send LAlt-, and LAlt-, respectively.


| ![Prototype version one](https://github.com/andyn/digispark-ejector/blob/master/misc/ejection%20handle.jpg?raw=true) |
|---|
| **Figure 1:** Ejection seat handle. The prototype has got an additional seat height adjustment switch after this picture was taken. |


## Required parts

- Basic electronics tools and skills
- Cheap industrial rope pull switch from Aliexpress.
- Digispark attiny85 board or compatible
- USB cord
- Wire
- Shrink tube or electrical tape
- Hot glue, epoxy or something else that gets the job done
- Whatever mechanical parts you want for the handle itself and extra buttons or switches.

You can stuff aforementioned parts inside the switch assembly in pretty much only one way
that makes sense if you're familiar with basic electronics and Arduino development.

If you're using the LED pin (number 1) for input, remember to
solder it off or the pullup voltage will be 1.7 V instead of 5.0 V.

More comprehensive build instructions shall be provided when prototype number 2 is built.
