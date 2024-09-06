/**
 * Assignment 06
 * @author Waltz Axl C. Tuzon
 * Section: 003
*/
//Import Scanner to be able to write on the console
import java.util.Scanner;	

public class Assignment06 {
    //This is the main method
    public static void main(String[] args) {
      
        //Variable that holds the current password
        final String currentPassword = "ICS111";    //Has final because this variable will only be used once in the process of making the new password
        
        //Constructor method for Scanner typing current password
        Scanner typeCurrentPassword = new Scanner(System.in);
        //Constructor method for Scanner typing new password
        Scanner typeNewPassword = new Scanner(System.in);
        //Constructor method for Scanner retyping new password
        Scanner retypeNewPassword = new Scanner(System.in);
        
        //Program starts with asking the user to input the current password
        System.out.print("Type your current password: "); 
        //String variable that holds the value of user input in typeCurrentPassword.nextLine()
        String typedPassword = typeCurrentPassword.nextLine();
        
        //Conditional If statement that returns two strings when typedPassword != currentPassword
        if (!typedPassword.equals(currentPassword)) {
            
            System.out.println("Password not recognized.");
            System.out.println("Your password was not changed.");
            
        //Otherwise if the condition between the two is True, this else block executes
        } else{
            
            //Program asks user to type the new password
            System.out.print("Type a new password: ");
            //String variable that holds the value of user input in typeNewPassword.nextLine() 
            String newPassword = typeNewPassword.nextLine();
            //Program then again asks user to retype the new password
            System.out.print("Retype the new password: ");
            //String variable that holds the value of user input in retypeNewPassword.nextLine()
            String retypePassword = retypeNewPassword.nextLine();
            

            //Variable that calls the paswordChecker method
            boolean confirmation = passwordChecker(newPassword, retypePassword);
            
            //If statement that executes when passwordConfirmation returns true
            if (confirmation == true) {
            	
            	System.out.println("Your password was changed to: " + newPassword);
            	
            //Otherwise this will be the result
            } else {
            	System.out.println("Your password was not changed.");
            }
        }
    }
    //This is the passwordChecker method
    public static boolean passwordChecker(String NP, String RP) {   //NP is new password, RP is retype password
    	//boolean that returns the value to false
        boolean passwordConfirmation = false;   
        
        //While loop that executes until its parameter is true
        while (!passwordConfirmation) {	
        	
        	//An if statement that executes when NP.equal(RP) is true
        	if (NP.equals(RP)) {
        		//If the first if statement executes, this will check if NP has at least 6 or more characters
        		if (NP.length() >= 6) {
        			//If the above if statement executes, the program would check if spaces, which there should be none
        			if (!NP.contains(" ")) {
        				//Lastly, if the above if statement executes, the program will now check if the new password has "!" or "$" or "?"
        				if ((NP.contains("!")) || (NP.contains("$")) || (NP.contains("?"))) {
        					
        					passwordConfirmation = true;
        					
        				//Otherwise this will be the result
        				} else {
        					
        					System.out.println("Your new password must contain ! or $ or ?.");
        					passwordConfirmation = false;
        					break;  //Used break to stop infinite while loops
        					
        				}
        			//Otherwise this will be the result	
        			} else {
        				
        				System.out.println("Your new password can not have spaces.");
        				passwordConfirmation = false;
        				break;  //Used break to stop infinite while loops
        				
        			}
        		
        		//Otherwise this will be the result
        		} else {
        			
        			System.out.println("Your new password must contain 6 or more characters.");
        			passwordConfirmation = false;
        			break;  //Used break to stop infinite while loops
        			
        		}
        	
        	//Otherwise this will be the result
        	} else {
        		
        		System.out.println("Your new passwords do not match.");
        		passwordConfirmation = false;
        		break;  //Used break to stop infinite while loops
        		
        	}
        	
        }
     return passwordConfirmation;   
    }
}
