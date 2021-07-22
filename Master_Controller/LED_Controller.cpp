/* File Name:LED Controller
 * Author: Marko Jurisic
 * Date Edited: 22nd June 2021
 * 
 * Description: Contains functions to setup and use LEDS
 */

// Including all header files
#import <Arduino.h> 
#include "Pin_Assignments.h"
#include "Libraries.h"
#include "Globals.h"

//Variables for ease of array unpacking:

int red_toggle = 0;
int green_toggle = 0;
int blue_toggle = 0;

int red_pot = 0;
int green_pot = 0;
int blue_pot = 0;


/* Function Name:LCDSetup
 * Date Edited: 22nd June 2021
 * 
 * Inputs: None
 * Outputs: None
 * Resources: None
 *
 * Description: Sets up the LCD
 */
void LEDSetup(){

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  
}

/* Function Name:LCDDisplay
 * Date Edited: 21st June 2021
 * 
 * Inputs: None
 * Outputs: None
 * Resources: None
 *
 * Description: Sends values for display on the LCD
 */
void LEDControl(int control_array[]){

  //The LED control first checks if the toggle switch for a respective LED is on. If so, then the LED is active. Once active, the intensity of the LED is determined by the corresponding pot for that LED. If the toggle switch is off, then the LED is inactive.

  //Unpacking the array for ease of design:
  red_toggle = control_array[0];
  green_toggle = control_array[1];
  blue_toggle = control_array[2];

  red_pot = control_array[3];
  green_pot = control_array[4];
  blue_pot = control_array[5];

  //Red LED Control
  if (red_toggle = SW_ON){
      analogWrite(RED_LED, red_pot);
  }
  else{
    analogWrite(RED_LED,0);
  }

  //Green LED Control
  if (green_toggle = SW_ON){
      analogWrite(GREEN_LED, green_pot);
  }
  else{
    analogWrite(GREEN_LED,0);
  }

  //Blue LED Control
  if (blue_toggle = SW_ON){
      analogWrite(BLUE_LED, blue_pot);
  }
  else{
    analogWrite(BLUE_LED,0);
  }
}
