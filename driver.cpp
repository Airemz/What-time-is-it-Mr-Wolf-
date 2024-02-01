// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"


int main(){
    
    // your code goes here...  

}


/* Planning

Step 1: take user input in main function
    - input will be a string and some strings will have parameters like last time
    - could try using similar method to last time, although MUST avoid mem leaks
    - call appropriate function using case switch, could also hardcode using multiple if statements?

Step 2: Spawn function
    - Called on "SPAWN" with two parameters which must both be > 0
    - Create a new node with data being x and y positions
    - link the  linked list appropriately by keeping a current node, head and tail in public?
    - output "success" or "failure"

Step 3: Time Function
    - called on "TIME" with parameter t
    - Update data of each node by iterating through list
    - Delete any nodes which are out of bounds (x or y is not >0)
    - output "num of players: N"





*/ 
