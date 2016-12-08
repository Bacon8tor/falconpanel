
#include <HID-Project.h>
#include <HID-Settings.h>

/*
  Copyright (c) 2015 Craig Andera

  Falconpanel - a set of functions for turning an Arduino into a
  DirectX game controller.

  Modify the components array below to match your setup.

    EDITTED BY:  BACON8TOR

*/


const int pinLed = LED_BUILTIN;

#include "components.h"

int dxButton = 1;

Component* components[] = {

  //Laser Arm
  new OnOffSwitch(new DigitalInputPullupPin(0),
                    new MomentaryButton(new DxButton(dxButton++)),
                    new MomentaryButton(new DxButton(dxButton++))),
  //Master Arm
  new OnOffOnSwitch(new DigitalInputPullupPin(2),
                    new DigitalInputPullupPin(3),
                      new MomentaryButton(new DxButton(dxButton++)),
                      new MomentaryButton(new DxButton(dxButton++)),
                      new MomentaryButton(new DxButton(dxButton++))),
  //Cat I/III
  new OnOffSwitch(new DigitalInputPullupPin(4),
                    new MomentaryButton(new DxButton(dxButton++)),
                    new MomentaryButton(new DxButton(dxButton++))),
  //Pitch ALT Hold
  new OnOffOnSwitch(new DigitalInputPullupPin(7),
                    new DigitalInputPullupPin(8),
                      new MomentaryButton(new DxButton(dxButton++)),
                      new MomentaryButton(new DxButton(dxButton++)),
                      new MomentaryButton(new DxButton(dxButton++))),
  //Roll HDG Hold
  new OnOffOnSwitch(new DigitalInputPullupPin(9),
                    new DigitalInputPullupPin(10),
                      new MomentaryButton(new DxButton(dxButton++)),
                      new MomentaryButton(new DxButton(dxButton++)),
                      new MomentaryButton(new DxButton(dxButton++))),
  //Landing Gear 
  new OnOffSwitch(new DigitalInputPullupPin(11),
                    new MomentaryButton(new DxButton(dxButton++)),
                    new MomentaryButton(new DxButton(dxButton++)))
  
                    
};



const int componentCount = sizeof(components)/sizeof(Component*);

void setup() {
  pinMode(pinLed, OUTPUT);

  for (int i = 0; i < componentCount; ++i) {
    components[i]->setup();
  }

  // Sends a clean report to the host. This is important on any Arduino type.
  // Make sure all desired USB functions are activated in USBAPI.h!
  Gamepad.begin();

}

void loop() {

  for (int i = 0; i < componentCount; ++i) {
    components[i]->update();
  }

  // functions before only set the values
  // this writes the report to the host
  Gamepad.write();

  // simple debounce
  delay(75);
}
/*
  Prototypes:

  void begin(void);
  void end(void);
  void write(void);
  void press(uint8_t b);
  void release(uint8_t b);
  void releaseAll(void);
  void buttons(uint32_t b);
  void xAxis(int16_t a);
  void yAxis(int16_t a);
  void rxAxis(int16_t a);
  void ryAxis(int16_t a);
  void zAxis(int8_t a);
  void rzAxis(int8_t a);
  void dPad1(int8_t d);
  void dPad2(int8_t d);

  Definitions:
  GAMEPAD_DPAD_CENTERED 0
  GAMEPAD_DPAD_UP 1
  GAMEPAD_DPAD_UP_RIGHT 2
  GAMEPAD_DPAD_RIGHT 3
  GAMEPAD_DPAD_DOWN_RIGHT 4
  GAMEPAD_DPAD_DOWN 5
  GAMEPAD_DPAD_DOWN_LEFT 6
  GAMEPAD_DPAD_LEFT 7
  GAMEPAD_DPAD_UP_LEFT 8
*/
/*  */
