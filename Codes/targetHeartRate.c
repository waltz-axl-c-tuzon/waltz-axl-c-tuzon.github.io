/**
 * In Assignment 5, the program will ask the user to 
 * enter user's birth year and the current year. The
 * program will calculate the user's target heart-rate
 * for exercising.
 *
 * @author     Tuzon, Waltz Axl
 * @assignment ICS 212 Assignment 05
 * @date       September 6, 2023
 */

// Including stdio.h allows to perform input and output operations.
#include <stdio.h>
// Including custom-made program getdouble.h to use when inputting floating points.
#include "getdouble.h"

// Defining a symbolic constant that holds a value that
// never changes, 220, maximum heart-rate.
#define MAX_HEART_RATE 220
// Defining a symbolic constant for minimum heart-rate target, 0.50
#define LOW_HR_TARGET 0.50
// Defining a symbolic constant for maximum heart-rate target, 0.85
#define UPPER_HR_TARGET 0.85

/*
 * Type int main function, where program executes all written
 * codes within the body.
 * 
 * @return 0, returns expected output if there are no errors.
 */
int main(void) {
  
  // Instance variables that holds the initial value of current year,
  // birth year, age, and minimum and maximum heart-rate.
  int currentYear = 0;
  int birthYear = 0;
  int age = 0;
  int maxHeartRate = 0;
  int lowHeartRateTarget = 0;
  int upperHeartRateTarget = 0;
  
  // Used the function puts() to make it look visually appealing.
  puts("");

  // Program will greet the user. Function puts() displays a string and newline.
  // Can't put any variable in it.
  puts("Hello! I am here to calculate your target heart-rate.");

  // Program will ask user to enter their birthyear and current year.
  printf("Please enter your birth year: ");
  // Instance variable will be re-initialized based on the user's input
  // and calculations.
  // getdouble() will be casted into (int) and the values for lowHeartRateTarget
  // and maxHeartRateTarget will be casted to (int).
  birthYear = (int) getdouble();
  printf("Please enter the current year: ");
  currentYear = (int) getdouble();
  age = currentYear - birthYear;
  maxHeartRate = MAX_HEART_RATE - age;
  lowHeartRateTarget = (int)(maxHeartRate * LOW_HR_TARGET);
  upperHeartRateTarget = (int)(maxHeartRate * UPPER_HR_TARGET);
  
  // Using function puts() to separate user the previous outputs and user inputs.
  puts("");
  puts("~~~~~~~~~~~~~~~ Here are the results from your inputs ~~~~~~~~~~~~~~~");
  // Program will now print out the results from user's input.
  // Used %i to specifically format the age, maxHeartRate, lowHeartRateTarget, and upperHeartRateTarget to int.
  printf("Your calculated age from the current year and birth year inputs is: %i.\n", age);
  printf("Your calculated maximum heart-rate is: %i.\n", maxHeartRate);
  printf("From your calculated age and maximum heart-rate, your target heart-rate is between %i and %i beats per minute (bpm).\n", lowHeartRateTarget, upperHeartRateTarget);
  // Using another puts() function to indicate that the result's ended.
  puts("~~~~~~~~~~~~~~~ End of result ~~~~~~~~~~~~~~~");
  puts("");

  // Return 0, indicates that the program ran succesfully
  // as long as it returns 0.
  return 0;
} 
