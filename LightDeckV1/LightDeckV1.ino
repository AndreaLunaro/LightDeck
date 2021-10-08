/**
 * This is an example of the AnalogMultiplex class. It prints the values of all
 * 16 inputs of a multiplexers to the serial monitor.
 * 
 * @boards  AVR, AVR USB, Nano Every, Nano 33, Due, Teensy 3.x, ESP8266, ESP32
 * 
 * Connections
 * -----------
 * 
 *  - A0: CD74HC4067 signal pin ("common input/output")
 *  - 3:  CD74HC4067 address pin S0
 *  - 4:  CD74HC4067 address pin S1
 *  - 5:  CD74HC4067 address pin S2
 *  - 6:  CD74HC4067 address pin S3
 *  
 * Optionally you can connect the enable pin as well, this is useful
 * if you want to use multiple multiplexers with the same address 
 * lines and the same analog input. Otherwise, just connect the enable
 * pin to ground.
 * 
 * If you are using a 3-bit multiplexer, like the CD74HC4051, you can
 * uncomment the code specific to this multiplexer, and use only three
 * address pins.
 *  
 * Behavior
 * --------
 * 
 * Connect some potentiometers or other analog sensors to the 16 inputs
 * of the multiplexer, and open the serial monitor (CTRL+SHIFT+M) or the
 * serial plotter (CTRL+SHIFT+L). You should see all 16 signals printed
 * or plotted.
 * 
 * Written by Pieter P, 31-01-2019  
 * https://github.com/tttapa/Arduino-Helpers
 */

#include <Arduino_Helpers.h> // Include the Arduino Helpers library
#include <AH/Hardware/ExtendedInputOutput/AnalogMultiplex.hpp>
#include <Control_Surface.h>

USBMIDI_Interface midi;

// Instantiate a multiplexer
CD74HC4067 mux = {
  9,            
  {15, 14, 16, 10}, 
 
};


CD74HC4067 mux1 = {
  A1,             
  {5, 6, 7, 8}, 

};


CD74HC4067 mux2 = {
  A0,              
  {1, 2, 3, 4}, 
  
};



CCPotentiometer volumePotentiometers[] = {
  { mux2.pin(0), { MIDI_CC::Pan, CHANNEL_1 } },
  { mux2.pin(1), { MIDI_CC::Pan, CHANNEL_2 } },
  { mux2.pin(2), { MIDI_CC::Pan, CHANNEL_3 } },
  { mux2.pin(3), { MIDI_CC::Pan, CHANNEL_4 } },
  { mux2.pin(4), { MIDI_CC::Pan, CHANNEL_5 } },
  { mux2.pin(5), { MIDI_CC::Pan, CHANNEL_6 } },
  { mux2.pin(6), { MIDI_CC::Pan, CHANNEL_7 } },
  { mux2.pin(7), { MIDI_CC::Pan, CHANNEL_8 } },
  { mux2.pin(8), { MIDI_CC::Pan, CHANNEL_9 } },
  { mux2.pin(9), { MIDI_CC::Pan, CHANNEL_10 } },
  { mux2.pin(10), { MIDI_CC::Pan, CHANNEL_11 } },
  { mux2.pin(11), { MIDI_CC::Pan, CHANNEL_12 } },
  { mux2.pin(12), { MIDI_CC::Pan, CHANNEL_13 } },
  { mux2.pin(13), { MIDI_CC::Pan, CHANNEL_14 } },
  { mux2.pin(14), { MIDI_CC::Pan, CHANNEL_15 } },
  { mux2.pin(15), { MIDI_CC::Pan, CHANNEL_16 } }

};

CCPotentiometer volumePotentiometers1[] = {
  
  { mux1.pin(0), { MIDI_CC::Channel_Volume, CHANNEL_1 } },
  { mux1.pin(1), { MIDI_CC::Channel_Volume, CHANNEL_2 } },
  { mux1.pin(2), { MIDI_CC::Channel_Volume, CHANNEL_3 } },
  { mux1.pin(3), { MIDI_CC::Channel_Volume, CHANNEL_4 } },
  { mux1.pin(4), { MIDI_CC::Channel_Volume, CHANNEL_5 } },
  { mux1.pin(5), { MIDI_CC::Channel_Volume, CHANNEL_6 } },
  { mux1.pin(6), { MIDI_CC::Channel_Volume, CHANNEL_7 } },
  { mux1.pin(7), { MIDI_CC::Channel_Volume, CHANNEL_8 } },
  { mux1.pin(8), { MIDI_CC::Channel_Volume, CHANNEL_9 } },
  { mux1.pin(9), { MIDI_CC::Channel_Volume, CHANNEL_10 } },
  { mux1.pin(10), { MIDI_CC::Channel_Volume, CHANNEL_11 } },
  { mux1.pin(11), { MIDI_CC::Channel_Volume, CHANNEL_12 } },
  { mux1.pin(12), { MIDI_CC::Channel_Volume, CHANNEL_13 } },
  { mux1.pin(13), { MIDI_CC::Channel_Volume, CHANNEL_14 } },
  { mux1.pin(14), { MIDI_CC::Channel_Volume, CHANNEL_15 } },
  { mux1.pin(15), { MIDI_CC::Channel_Volume, CHANNEL_16 } }

};




CCButtonLatched buttonmute[] = { 
  {mux.pin(0), {94, CHANNEL_1}},
  {mux.pin(1), {94, CHANNEL_2}},
  {mux.pin(2), {94, CHANNEL_3}},
  {mux.pin(3), {94, CHANNEL_4}},
  {mux.pin(4), {94, CHANNEL_5}},
  {mux.pin(5), {94, CHANNEL_6}},
  {mux.pin(6), {94, CHANNEL_7}},
  {mux.pin(7), {94, CHANNEL_8}},
  {mux.pin(8), {94, CHANNEL_9}},
  {mux.pin(9), {94, CHANNEL_10}},
  {mux.pin(10), {94, CHANNEL_11}},
  {mux.pin(11), {94, CHANNEL_12}},
  {mux.pin(12), {94, CHANNEL_13}},
  {mux.pin(13), {94, CHANNEL_14}},
  {mux.pin(14), {94, CHANNEL_15}},
  {mux.pin(15), {94, CHANNEL_16}},
};


void setup() {
  Control_Surface.begin(); 
}

void loop() {
  delay(30);
  Control_Surface.loop();  // Update the Control Surface
}
