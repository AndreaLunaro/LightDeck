# Light Deck
## _DIY MIDI Lightroom controller_

[![Arduino](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/ArduinoLogo_®.svg/314px-ArduinoLogo_®.svg.png)](https://www.arduino.cc)

<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/Assembled.jpg">

Light Deck is an open-source MIDI Lightroom controller. Source code, PCB schematics ad 3D case files are all available and fully customizable.

- Speed up your photo editing
- All the basic and advanced Lightroom controls
- Never use the mouse when all you need is just light and quick photo editing
- Super esay to install and use

## Features

- All the controls from the basics tab are available  
- Copy and paste settings between photos
- Controls fro the HSL tab are available (Sat, Lum, Hue profiles)
- Basic Transformation, Correction and Details controls are available
- Buttons to navigate between photos and to export
- Of course undo and redo button are present too (
who does not make mistakes?)

The project would not have been possible if there had not been two major open source projects, in particular the plugin [MIDI2Lr]. The second project is the [Control Surface] Arduino library which made writing the code extremely simple (as you will see, very few lines of code were enough).

> The idea of the project is to create an cheap version of
> Lightroom controllers that are on the market and to allow
> everyone to speed up photo editing by minimizing the use
> of the mouse and keyboard.


## Part List

#### Hardware
To build the Light Deck as I imagined it would take very few components:

- [Arduino Pro micro] - The brain oh the system (the microcontroller has HID enabled)
- [CD74HC4067 Multiplexer] - You will need 3 of them (to have in total 48 input)
- [G77 Silicone buttons] - Those are perfect if you don't like the sound of tactile buttons, you need 16 of them (but to be onest tactile buttons are a better and cheaper option to those but it's necessary to edit the schematics, it's all up to you).
- [Rv09 10k Potentiometers] - You will neer 32 of those

#### PCB
Once you buy the fundamental components, to be able to assemble them you will need the PCB. Gerber files are available in the folders and to be able to order it directly online (PCB way, JLCPCB, etc). The original file is editable with the [Easy EDA] online tool (I used this so that anyone can edit it without having to own the Altium license)

#### Case
To complete the project it is possible to 3D print a case and the labels to have all the writings related to the controls also on the case. Also in this case the STL files of the case and the editable files of fusion 360 are available for download.


## Mount the case

Following these instructions, it is possible to mount the PCB and the supports for the buttons inside the case.
The procedure is quite intuitive, in fact, if you decide to use high tactile buttons instead of silicone ones everything will be simple and immediate.
<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/AllComonent.jpeg">

The first thing to do is to print and cut out the stickers that are necessary to understand which controls you are going to operate. If you don't have any sticker paper, you can use normal paper, and use our double-sided tape to stick it on the case.

I also recommend that you plaster and paint the case to give it a cleaner look.

Now you can place the pcb in the base, and match the three holes of the board with the three pins on the case:
<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/PCBinBase.jpeg">

Then on each button place the 3D printed support and make sure they are all straight:
<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/ButtonMount.jpeg">

After that you can position the upper part of the case so that all the power rods and all the button supports fit, this is the most difficult part, if you have problems try to help you with a small turn to align the supports that could be moved:
<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/AllPotMount.jpeg">

Start putting all the knobs on the potentiometers making sure to align the tab as much as possible with the symbols tapped on the sticker:

<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/PotMount.jpeg">

Having done that you can put caps on the button mounts are an optional thing, but they provide a larger contact surface:
<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/ButtonCapMount.jpeg">

Once finished you should get something similar to the picture:

<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/Assembled.jpg">

## Installation of the profiles on MIDI2Lr
The code to load on the Arduino is very simple but to compile it as mentioned above you need the library [Control Surface].

Before you can use the midi controller you obviously need to have a version of Lightroom installed (either Classic or the CC version). Then install the MIDI2Lr plug in and you're almost ready to go.

First download the three xml profiles you find in the folders and upload them to a profile folder.

<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/SaveProfiles.png">

Then open Lightroom and go to File/Plug-in Extras/General Options, here in the profiles section enter the names of the downloaded profiles and put them in the appropriate folder, save and exit.

<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/OpenOptions.png">
<img width="512" alt="Assembled" src="https://github.com/AndreaLunaro/LightDeck/blob/Images/WriteProfiles.png">

From the Control Panel of MIDI2Lr with Load button load one of the three profiles to start (you will be able to select profiles then pushing Hue, Lum, Sat buttons), and connect the LightDeck. Try to move some enhancement to see if the plugin receives correctly the data.

There you have already finished with the installation, simple isn't it?

## Video Demo

Below is a short video demonstration of how the LightDeck works:

[![Demo](https://i.ytimg.com/vi/1icHaoc9lCU/hq720.jpg?sqp=-oaymwEXCNAFEJQDSFryq4qpAwkIARUAAIhCGAE=&rs=AOn4CLDj1xGIn1QekBRq72owKwd6D9e6YA)](https://www.youtube.com/watch?v=1icHaoc9lCU)


## License

**Free Software, Hell Yeah!**


   [MIDI2Lr]: <https://rsjaffe.github.io/MIDI2LR/>
   [Control Surface]: <https://github.com/tttapa/Control-Surface>
   [Arduino Pro micro]: <https://deskthority.net/wiki/Arduino_Pro_Micro>
   [CD74HC4067 Multiplexer]: <https://electropeak.com/learn/interfacing-cd74hc4067-16-channel-analog-digital-multiplexer-with-arduino/>
   [G77 Silicone buttons]: <https://www.aliexpress.com/i/32668706990.html>
   [Rv09 10k Potentiometers]: <https://it.aliexpress.com/item/1005001489136961.html?spm=a2g0o.productlist.0.0.735c47a5YHggVA&algo_pvid=072d6963-011d-4a81-8e05-94d830fb1398&algo_exp_id=072d6963-011d-4a81-8e05-94d830fb1398-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000016318752136%22%7D>
   [Easy EDA]: <https://easyeda.com>

