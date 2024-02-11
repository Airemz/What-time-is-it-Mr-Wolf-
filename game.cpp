#include "game.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Constructor, no need for destructor as this gets deallocated in remove from game member function
Node::Node(){
    next = nullptr;
    prev = nullptr;
}

//////////////////////////////////////////////////////
//////////// Linked List Member Functions ////////////
//////////////////////////////////////////////////////

// Constructor
linked_list::linked_list(){
    // Initialize head and tail to nullptrs so random memory isn't allocated
    // Delcare the list as empty and set num of players
    head = nullptr;
    tail = nullptr;
    empty_list = true;
    num_of_players = 0;
}

// Destructor
linked_list::~linked_list(){
    // Delete the linked list starting from head, move head to the next node each time stopping when head reaches nullptr
    while( head != nullptr ) {
        Node* current = head;
        head = head->next;
        delete current;
        current = nullptr;
    }
}

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

        // If LL is empty set node as head and tail
        if (head == nullptr){

            head = new_player;
            tail = new_player;

        } else{
            
            // Add the new node to beginning of LL, moving the head and setting next and previous
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

        // Update x and y values according to manual. Need to store old data_x as the value is being overwrited 
        double store_x = temp->data_x;

        temp->data_x -= t * cos(atan2(temp->data_y,temp->data_x));
        temp->data_y -= t * sin(atan2(temp->data_y,store_x));

        // Remove the player if they are cheating
        if (temp->data_x <= 0 || temp->data_y <= 0){remove_from_game(temp);} 
        
        // Check if list is empty i.e the head is empty after removing the last node or if the next node is a nullptr. If not move on to next node.
        if (head == nullptr || head->next == nullptr){break;}
        else {temp = temp->next;}
    }

    // Output and deallocate the temp node
    cout << "num of players: " << num_of_players << endl;
    temp = nullptr;
}

void linked_list::lunch_function(){

    // Create temp node to itterate through LL
    Node* temp = head;

    while (temp != nullptr){
        
        // Remove the player if they are <1 distance to the wolf using the euclidian formula
        if ((sqrt( pow((temp->data_x),2) + pow((temp->data_y),2))) < 1){remove_from_game(temp);} 

        // Check if list is empty i.e the head is empty after removing the last node or if the next node is a nullptr. If not move on to next node.
        if (head == nullptr || head->next == nullptr){break;}
        else {temp = temp->next;}
    }

    // Output and deallocate the temp node
    cout << "num of players: " << num_of_players << endl;
    temp = nullptr;
}

void linked_list::num_function(){

    // Output the private member num of players
    cout << "num of players: " << num_of_players << endl;

}

void linked_list::prt_function(double d){

    // Check if list is empty using private variable
    if (empty_list){cout << "no players found" << endl;}

    else{
        // Create temp node to itterate through LL aswell as player counter. The player counter is used to check if there are no players found within the distance specified. The players still exist so we shouldn't decrease the private variable, num_of_players however we must decrement a temp var of the same value to check if all players have been accounted for.
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

        // If all players have been accounted for but none are within the distance specified provide the following output. 
        if(player_count == 0){cout << "no players found";}

        // Deallocate the temp node
        temp = nullptr;

        // End the line after printing all coords or no players found
        cout << endl;
    }
}

void linked_list::over_function(){

    // Check if LL is empty (i.e no players are alive) then wolf wins, else players win
    if (empty_list){cout << "wolf wins" << endl;}
    else{cout << "players win" << endl;}
}

void linked_list::remove_from_game(Node* node){

    // Check if node is the only item in LL
    if (node == head && node == tail){
        
        // Reset the head and tail pointers and private members
        head = nullptr;
        tail = nullptr;
        empty_list = true;
        num_of_players--;
        delete node;
        
    } else{
        
        // Check if node is head of LL, if so, move head and set head prev
        if (node == head){head = node->next; head->prev = nullptr;} 
        
        // Check if node is at the tail, if so move tail and set tail next
        else if (node == tail){tail = node->prev; tail->next = nullptr;}

        // Node is somewhere inbetween
        else{

            // Link previous node to next node 
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        
        // Deallocate the node and decrement number of players
        delete node;
        num_of_players--;
    }
}
