---
layout: project
type: project
image: img/Person-tapping-on-change-password-button-on-device.jpg
title: "Change Password Simulator (Java)"
date: 2022
published: true
labels:
  - Java
  - Change current password
  - Simulator
  - Java's Scanner Library
summary: "This was the 6th assignment on my ICS 111 Intro to Computer Science class where Java is the coding language being used, and the assignment is a simulation of when a user wants to change their password."
---
<img width="300">

Change Current Password Simulator (Java) is a User Interface simulation of which the user wants to, as the name implies, change their password. The user should already know their password, can be changed when you're not running the code (should be on line 14), and it will be tested in the program. Once the user successfully entered their current password, they will be met with a prompt on the requirements for their new password and also requires the user to re-type their password correctly. 

This assignment was all done by myself which took some time for the functions and conditionals to work properly as this was the very first coding language that I was learning at the time. This assignment taught me about functions and using functions to return a value or values, the use of the Scanner library, and using data type final.

Here is the function I made for confirming the password inputted by the user without all the culster of comments:

```java
public static boolean passwordChecker(String NP, String RP) {   //NP is new password, RP is retype password
        boolean passwordConfirmation = false;   
        
        while (!passwordConfirmation) {	
        	if (NP.equals(RP)) {
        		if (NP.length() >= 6) {
        			if (!NP.contains(" ")) {
        				if ((NP.contains("!")) || (NP.contains("$")) || (NP.contains("?"))) {
        					passwordConfirmation = true;
        				} else {
        					System.out.println("Your new password must contain ! or $ or ?.");
        					passwordConfirmation = false;
        					break;  //Used break to stop infinite while loops
        				}
        			} else {
        				System.out.println("Your new password can not have spaces.");
        				passwordConfirmation = false;
        				break;
        			}
        		} else {
        			System.out.println("Your new password must contain 6 or more characters.");
        			passwordConfirmation = false;
        			break; 
        		}
        	} else {
        		System.out.println("Your new passwords do not match.");
        		passwordConfirmation = false;
        		break; 
        	}
        }
     return passwordConfirmation;

    }

}
```
[changePassword.java](https://github.com/waltz-axl-c-tuzon/waltz-axl-c-tuzon.github.io/blob/main/Codes/changePassword.java)
