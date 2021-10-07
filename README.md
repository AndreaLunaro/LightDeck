# Light Deck
## _DIY MIDI Lightroom controller_

[![Arduino](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/ArduinoLogo_®.svg/314px-ArduinoLogo_®.svg.png)](https://www.arduino.cc)

[![LightDeck](https://github.com/AndreaLunaro/LightDeck/blob/Images/camphoto_824023566.jpg)]

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


## Installation

Dillinger requires [Node.js](https://nodejs.org/) v10+ to run.

Install the dependencies and devDependencies and start the server.

```sh
cd dillinger
npm i
node app
```

For production environments...

```sh
npm install --production
NODE_ENV=production node app
```

## Plugins

Dillinger is currently extended with the following plugins.
Instructions on how to use them in your own application are linked below.

| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md][PlDb] |
| GitHub | [plugins/github/README.md][PlGh] |
| Google Drive | [plugins/googledrive/README.md][PlGd] |
| OneDrive | [plugins/onedrive/README.md][PlOd] |
| Medium | [plugins/medium/README.md][PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md][PlGa] |

## Development

Want to contribute? Great!

Dillinger uses Gulp + Webpack for fast developing.
Make a change in your file and instantaneously see your updates!

Open your favorite Terminal and run these commands.

First Tab:

```sh
node app
```

Second Tab:

```sh
gulp watch
```

(optional) Third:

```sh
karma test
```

#### Building for source

For production release:

```sh
gulp build --prod
```

Generating pre-built zip archives for distribution:

```sh
gulp build dist --prod
```

## Docker

Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 8080, so change this within the
Dockerfile if necessary. When ready, simply use the Dockerfile to
build the image.

```sh
cd dillinger
docker build -t <youruser>/dillinger:${package.json.version} .
```

This will create the dillinger image and pull in the necessary dependencies.
Be sure to swap out `${package.json.version}` with the actual
version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on
your host. In this example, we simply map port 8000 of the host to
port 8080 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart=always --cap-add=SYS_ADMIN --name=dillinger <youruser>/dillinger:${package.json.version}
```

> Note: `--capt-add=SYS-ADMIN` is required for PDF rendering.

Verify the deployment by navigating to your server address in
your preferred browser.

```sh
127.0.0.1:8000
```

## License

MIT

**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [MIDI2Lr]: <https://rsjaffe.github.io/MIDI2LR/>
   [Control Surface]: <https://github.com/tttapa/Control-Surface>
   [Arduino Pro micro]: <https://deskthority.net/wiki/Arduino_Pro_Micro>
   [CD74HC4067 Multiplexer]: <https://electropeak.com/learn/interfacing-cd74hc4067-16-channel-analog-digital-multiplexer-with-arduino/>
   [G77 Silicone buttons]: <https://www.aliexpress.com/i/32668706990.html>
   [Rv09 10k Potentiometers]: <https://it.aliexpress.com/item/1005001489136961.html?spm=a2g0o.productlist.0.0.735c47a5YHggVA&algo_pvid=072d6963-011d-4a81-8e05-94d830fb1398&algo_exp_id=072d6963-011d-4a81-8e05-94d830fb1398-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000016318752136%22%7D>
   [Easy EDA]: <https://easyeda.com>

