// define your classes here...
#include <iostream>
#include <string>

class Node{
    public:
        double data_x, data_y;

        // Doubly linked list for fun 
        Node *next, *prev;
        
        // Constructor
        Node();
};

class linked_list {
    private:
        Node *head, *tail;
        
        // Tracking when the list is empty and num of players for many member functions
        bool empty_list;
        unsigned int num_of_players;

    public:
        // Constructor
        linked_list();

        // Destructor
        ~linked_list();

        // Member functions for commands
        void spawn_player(double x_pos, double y_pos);
        void time_function(double t);
        void lunch_function();
        void num_function();
        void prt_function(double d);
        void over_function();

        // Other useful member functions
        void remove_from_game(Node* node);
};