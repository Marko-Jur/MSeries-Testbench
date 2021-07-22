/* File Name: Master Controller
 * Author: Marko Jurisic
 * Date Edited: 21st June 2021
 * 
 * Description: Master state machine which serves as top level controller for the MSeries Testbench
 */

// Including all header files
#include "Pin_Assignments.h"
#include "Libraries.h"
#include "LED_Controller.h"
#include "Input_Read.h"
#include "LCD_Display.h"

int control_array[6] = {0,0,0,0,0,0}; //red toggle, green toggle, blue toggle, red pot, green pot, blue pot

void setup() {

  Serial.begin(9600); // Setup the serial

  LCDSetup(); //Setup the LCD

  LEDSetup(); //Setup the LEDs

  inputSetup(); //Setting up the inputs
  
}

void loop() {

  inputRead(control_array); // Read all the inputs and store them in an array


  LEDControl(control_array); //Pass in inputs for LED intensity and on/off control

  LCDDisplay(/*TODO*/); //Pass in inputs for data display on LCD

 
  
}
