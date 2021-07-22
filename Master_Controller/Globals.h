/* File Name: Globals
 * Author: Marko Jurisic
 * Date Edited: 21st June 2021
 * 
 * Description: Contains the globals for all functions
 */

#ifndef GLOBALS_H   
#define GLOBALS_H

//Min and max values that the potentiometer can report
const int POT_MIN_BOUND = 0;
const int POT_MAX_BOUND = 1023;

//Min and max values that the LED can safely be PWMED at
const int LED_MIN_INTENSITY = 0;
const int LED_MAX_INTENSITY = 255;

//On and off values for the toggles
const int SW_OFF = 0;
const int SW_ON = 1; /*TODO*/ // Update the parameters

//EMA values:
const float EMA_ALPHA = 0.6;


#endif
