---
layout: project
type: project
image: img/heartRateOUterPic.jpg
title: "Target Heart-Rate For Exercising Simulator (C)"
date: 2023
published: true
labels:
  - C
  - Target Heart-Rate For Exercising
  - Simulator
  - Heart-Rate Simulator
summary: "This was the 5th assignment on my ICS 212 Program Structure class where C and C++ are the coding languages being used, this one uses C, and the assignment is a simulation of a user's age and their calculated target heart-rate for exercising."
---

<img src="/img/5966305_s.jpg">

Target Heart-Rate For Exercising Simulator (C) is a code that will output a calculated target heart-rate for people when they are exercising. The code will ask for input, calculates it, and outputs the result to the user before ending the program. Users will need to enter a year, an age, and then the code will compute for the target heart-rate

This assignment was all done by myself. This project taught me about user input, symbolic constants, instance variabes, and formatted strings. 

Note: This code needs its custom-made .h file in order to work

Here is a snippet from the whole code that calculates the target heart-rate after being given input values:

```c
 birthYear = (int) getdouble();
  printf("Please enter the current year: ");
  currentYear = (int) getdouble();
  age = currentYear - birthYear;
  maxHeartRate = MAX_HEART_RATE - age;
  lowHeartRateTarget = (int)(maxHeartRate * LOW_HR_TARGET);
  upperHeartRateTarget = (int)(maxHeartRate * UPPER_HR_TARGET);
```
Needed files: [targetHeartRate.c](https://github.com/waltz-axl-c-tuzon/waltz-axl-c-tuzon.github.io/blob/main/Codes/targetHeartRate.c),
[getdouble.c](https://github.com/waltz-axl-c-tuzon/waltz-axl-c-tuzon.github.io/blob/main/Codes/getdouble.c),
[getdouble.h](https://github.com/waltz-axl-c-tuzon/waltz-axl-c-tuzon.github.io/blob/main/Codes/getdouble.h)
