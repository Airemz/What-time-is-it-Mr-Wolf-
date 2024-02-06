// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main(){
    
    while (true){
        // Receive User input
        string user_input = "";
        getline (cin,user_input);

        // Find the first digit in string for later use to extract parameter
        char const* digits = "0123456789";
        size_t const first_digit = user_input.find_first_of(digits);
        
        // Call appropriate functions
        if (user_input.find("SPAWN") != string::npos) {
            
            // Extract all numbers from input
            string numbers_only = user_input.substr(first_digit,string::npos);

            // Use the space between numbers to distinguish the 2 parameters
            double parameter_1 = stod(numbers_only.substr(0,user_input.find(' ')));
            double parameter_2 = stod(numbers_only.substr(numbers_only.find(' ')+1));
        }

        else if (user_input.find("TIME") != string::npos) {
            string numbers_only = user_input.substr(first_digit);
            double parameter = stod(numbers_only);

        }

        else if (user_input.find("LUNCH") != string::npos) {
            
        }

        else if (user_input.find("NUM") != string::npos) {
            
        }

        else if (user_input.find("PRT") != string::npos) {
            string numbers_only = user_input.substr(first_digit);
            double parameter = stod(numbers_only);
            
        }

        else if (user_input.find("OVER") != string::npos) {
            exit(0);
        }

        else{
            std::cout << "unexpected input" << endl;
        }


    }
    

}


/* Planning
test
Step 1: take user input in main function
    - input will be a string and some strings will have parameters like last time
    - could try using similar method to last time, although MUST avoid mem leaks
    - call appropriate function using case switch, could also hardcode using multiple if statements?
    - parameters will be double!

Step 2: Spawn function
    - Called on "SPAWN" with two parameters which must both be > 0
    - Create a new node with data being x and y positions
    - link the  linked list appropriately by keeping a current node, head and tail in public?
    - output "success" or "failure"

Step 3: Time Function
    - called on "TIME" with parameter t
    - Update data of each node by iterating through list
    - Delete any nodes which are out of bounds (x or y is not >0)
    - Relink linked list
    - output "num of players: N"

Step 4: Lunch Function
    - called on "LUNCH" 
    - Delete the nodes of any players <1 and update linked list
    - output "num of players: N" after deleting

Step 5: PRT Function
    - called on "PRT" with parameter d
    - itterate through the linked list and print the data
    - print the coordinates of players or no players found

Step 6: OVER Function
    - called on "OVER" 
    - wolf wins if linked list is empty(?) or players win if linked list is not
    - end the program either exiting while loop or exit function








*/ 
