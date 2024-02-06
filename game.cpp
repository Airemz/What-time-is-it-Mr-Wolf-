#include "game.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
linked_list::linked_list(){
    // Initialize head and tail to nullptrs so random memory isn't allocated
    head = nullptr;
    tail = nullptr;
}

// Destructor
linked_list::~linked_list(){
    // Delete the linked list starting from head, move head to the next node each time 
    while( head != nullptr ) {
        Node* current = head;
        head = head->next;
        delete current;
        current = nullptr;
    }
}

// Member functions for commands
void linked_list::spawn_player(double x_pos, double y_pos){

}
void linked_list::time_function(double t){

}
void linked_list::lunch_function(){

}
void linked_list::num_function(){

}
void linked_list::time_function(double d){

}
void linked_list::over_function(){

}