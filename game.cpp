#include "game.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
// Constructor, no need for destructor as this gets deallocated with LL
Node::Node(){
    next = nullptr;
    prev = nullptr;

}

// Constructor
linked_list::linked_list(){
    // Initialize head and tail to nullptrs so random memory isn't allocated
    // Delcare the list as empty
    head = nullptr;
    tail = nullptr;
    empty_list = true;
    num_of_players = 0;
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

    // Check for any cheaters
    if (x_pos <= 0 || y_pos <= 0){cout << "failure" << endl;} 
    
    else{

        // Create a new node with player data, update private members and output success
        Node* new_player = new Node;
        new_player->data_x = x_pos;
        new_player->data_y = y_pos;

        empty_list = false;
        num_of_players++;

        cout << "success" << endl;

        // If LL is empty set head and tail, else link new node to tail and prev, and set new tail
        if (head == nullptr){

            head = new_player;
            tail = new_player;

        } else{
            
            // Add the new node to beginning of LL
            new_player->next = head;
            head->prev = new_player;
            head = new_player;
        }
    }
}

void linked_list::time_function(double t){

    // Create temp node to itterate through LL 
    Node* temp = head;

    while (temp != nullptr){

        // Update x and y values according to manual. Need to store old data_x as the value is being updated 
        double store_x = temp->data_x;

        temp->data_x -= t * cos(atan2(temp->data_y,temp->data_x));
        temp->data_y -= t * sin(atan2(temp->data_y,store_x));

        // Remove the player if they are cheating
        if (temp->data_x <= 0 || temp->data_y <= 0){remove_from_game(temp);} 
        
        if (head == nullptr){break;}
        else {temp = temp->next;}
    }

    // Output
    cout << "num of players: " << num_of_players << endl;
    temp = nullptr;
}

void linked_list::lunch_function(){

    // Create temp node to itterate through LL
    Node* temp = head;

    while (temp != nullptr){
        
        // Remove the player if they are <1 distance to the wolf
        if ((sqrt( pow((temp->data_x),2) + pow((temp->data_y),2))) < 1){remove_from_game(temp);} 

        if (head == nullptr){break;}
        else {temp = temp->next;}
    }

    // Output
    cout << "num of players: " << num_of_players << endl;
    temp = nullptr;
}

void linked_list::num_function(){

    // Output
    cout << "num of players: " << num_of_players << endl;

}

void linked_list::prt_function(double d){

    // Check if list is empty
    if (empty_list){cout << "no players found" << endl;}

    else{
        // Create temp node to itterate through LL aswell as counter
        Node* temp = head;
        int player_count = num_of_players;

        while (temp != nullptr){

            // Check if euclidian distance is < d, if so output coords
            if ((sqrt( pow((temp->data_x),2) + pow((temp->data_y),2))) < d){
            
                // Output x and y data in proper form
                cout << temp->data_x <<  " "  << temp->data_y << " ";
            } else{player_count--;}

            temp = temp->next;
        }

        if(player_count == 0){cout << "no players found";}
        temp = nullptr;
        // End the line after printing
        cout << endl;
    }
}

void linked_list::over_function(){

    // Check if LL is empty (i.e no players are alive)
    if (empty_list){cout << "wolf wins" << endl;}
    else{cout << "players win" << endl;}
}

void linked_list::remove_from_game(Node* node){

    // Check if node is the only item in LL
    if (node == head && node == tail){
        
        // Reset the head and tail pointers
        head = nullptr;
        tail = nullptr;
        empty_list = true;
        num_of_players--;
        delete node;
        
    } else{
        
        // Check if node is head of LL
        if (node == head){head = node->next; head->prev = nullptr;} 
        
        // Check if node is at the tail
        else if (node == tail){tail = node->prev; tail->next = nullptr;}

        // Node is somewhere inbetween
        else{

            // Link previous node to next
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        
        // Deallocate the node and decrement number of players
        delete node;
        num_of_players--;
    }
}