/* File Name:Input Read
 * Author: Marko Jurisic
 * Date Edited: 21st June 2021
 * 
 * Description: Contains functions to read toggle switches and Potentiometers
 */

// Including all header files
#import <Arduino.h> 
#include "Pin_Assignments.h"
#include "Libraries.h"
#include "Globals.h"

//Array to store data from the inputs

int input_array[6] = {0,0,0,0,0,0}; // red toggle, green toggle, blue toggle, red pot, green pot, blue pot

//Variables for input processing
//Pot raws
int red_pot_raw = 0;
int green_pot_raw = 0;
int blue_pot_raw = 0;

//sw raw
int red_sw_raw = 0;
int green_sw_raw = 0;
int blue_sw_raw = 0;

//Filter variables:
int EMA_SAMPLE_RED = 0;
int EMA_SAMPLE_GREEN = 0;
int EMA_SAMPLE_BLUE = 0;


/* Function Name:Input setup
 * Date Edited: 21st June 2021
 * 
 * Inputs: None
 * Outputs: None
 * Resources: None
 *
 * Description: Sets up the toggle switches and potentiometers
 */
void inputSetup(){

  pinMode(RED_POT,INPUT);
  pinMode(GREEN_POT, INPUT);
  pinMode(BLUE_POT, INPUT);
  
  pinMode(RED_SWITCH,INPUT);
  pinMode(GREEN_SWITCH, INPUT);
  pinMode(BLUE_SWITCH,INPUT);

  EMA_SAMPLE_RED = analogRead(RED_POT);
  EMA_SAMPLE_GREEN = analogRead(GREEN_POT);
}

/* Function Name:Input read
 * Date Edited: 21st June 2021
 * 
 * Inputs: None
 * Outputs: None
 * Resources: None
 *
 * Description: Reads the toggle switches and potentiometers and stores the values in the control array
 */
void inputRead(int input_array[]){

  //Reading pot inputs
  red_pot_raw = analogRead(RED_POT);
  green_pot_raw = analogRead(GREEN_POT);
  blue_pot_raw = analogRead(BLUE_POT);

  //Filtering Pot Values - a 100uF capacitor must be added in parallel with the pot
  //Filtering red pot samples
  EMA_SAMPLE_RED = float((EMA_ALPHA*red_pot_raw) +((1-EMA_ALPHA)*EMA_SAMPLE_RED));

  //Filtering green pot samples
  EMA_SAMPLE_GREEN = float((EMA_ALPHA*green_pot_raw) +((1-EMA_ALPHA)*EMA_SAMPLE_GREEN));

  //Filtering blue pot samples
  EMA_SAMPLE_BLUE = float((EMA_ALPHA*blue_pot_raw) +((1-EMA_ALPHA)*EMA_SAMPLE_BLUE));
  //Serial.println(EMA_SAMPLE_BLUE);
  delay(1);

  //Reading sw inputs
  red_sw_raw = analogRead(RED_SWITCH);
  green_sw_raw = analogRead(RED_SWITCH);
  blue_sw_raw = analogRead(RED_SWITCH);

  //Storing switch inputs
  input_array[0] = red_sw_raw;
  input_array[1] = green_sw_raw;
  input_array[2] = blue_sw_raw;
  
  //Mapping the values and storing them into the array
  input_array[3] = map(EMA_SAMPLE_RED,POT_MIN_BOUND,POT_MAX_BOUND, LED_MIN_INTENSITY, LED_MAX_INTENSITY);
  input_array[4] = map(EMA_SAMPLE_GREEN,POT_MIN_BOUND,POT_MAX_BOUND, LED_MIN_INTENSITY, LED_MAX_INTENSITY);
  input_array[5] = map(EMA_SAMPLE_BLUE,POT_MIN_BOUND,POT_MAX_BOUND, LED_MIN_INTENSITY, LED_MAX_INTENSITY);

   Serial.print(EMA_SAMPLE_RED);
   Serial.print(",");
   Serial.print(EMA_SAMPLE_GREEN);
   Serial.print(",");
   Serial.println(EMA_SAMPLE_BLUE);  
}
