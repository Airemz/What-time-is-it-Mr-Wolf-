// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"

//./game.out <inputs/test01.in
// ./game.out <inputs/gigantica.in > gigantica.out
// diff inputs/gigantica.in output gigantica_real.out

using namespace std;

int main(){
    
    // Create the linked list
    linked_list* Big_Bad_Wolf = new linked_list();

    while (true){
        // Receive User input
        string user_input = "";
        getline (cin,user_input);

        // Find the first digit in string for later use to extract parameter
        // char const* digits = "0123456789";
        // size_t const first_digit = user_input.find_first_of(digits);
        
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
            string numbers_only = user_input.substr(user_input.find(' ')+1);
            double parameter = stod(numbers_only);
            Big_Bad_Wolf->prt_function(parameter);
        }

        else if (user_input.find("OVER") != string::npos) {
            Big_Bad_Wolf->over_function();
            delete Big_Bad_Wolf;
            exit(0);
        }
    }
}


/* Notes to ask TA


*/ 
