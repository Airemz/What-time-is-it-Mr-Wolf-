// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"

// Functions for testing
// ./game.out <inputs/test01.in
// ./game.out <inputs/gigantica.in > gigantica.out
// diff outputs/gigantica.out outputs/gigantica_real.out

using namespace std;

int main(){
    
    // Create a pointer to a linked list class
    linked_list* Big_Bad_Wolf = new linked_list();

    // Create an infinite while loop for the game which can only be exited with "OVER" command
    while (true){
        // Receive User input
        string user_input = "";
        getline (cin,user_input);
        
        // Call appropriate functions
        if (user_input.find("SPAWN") != string::npos) {
            
            // Extract all numbers from input
            string numbers_only = user_input.substr(user_input.find(" ")+1);

            // Use the space between numbers to distinguish the 2 parameters
            double parameter_1 = stod(numbers_only.substr(0,numbers_only.find(" ")));
            double parameter_2 = stod(numbers_only.substr(numbers_only.find(" ")+1));

            Big_Bad_Wolf->spawn_player(parameter_1, parameter_2);
        }

        else if (user_input.find("TIME") != string::npos) {
            // Extract numbers and parameter
            string numbers_only = user_input.substr(user_input.find(' ')+1);
            double parameter = stod(numbers_only);
            Big_Bad_Wolf->time_function(parameter);
        }

        else if (user_input.find("LUNCH") != string::npos) {
            Big_Bad_Wolf->lunch_function();
        }

        else if (user_input.find("NUM") != string::npos) {
            Big_Bad_Wolf->num_function();
        }

        else if (user_input.find("PRT") != string::npos) {
            // Extract numbers and parameter
            string numbers_only = user_input.substr(user_input.find(' ')+1);
            double parameter = stod(numbers_only);
            Big_Bad_Wolf->prt_function(parameter);
        }

        else if (user_input.find("OVER") != string::npos) {
            Big_Bad_Wolf->over_function();
            
            // Call the linked list destructor and exit the program
            delete Big_Bad_Wolf;
            exit(0);
        }
    }
}