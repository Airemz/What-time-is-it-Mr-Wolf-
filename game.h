// define your classes here...
#include <iostream>
#include <string>
class Node{
    public:
        double data;
        Node *next = nullptr;
};

class linked_list {
    private:
        Node *head, *tail;
        bool empty_list;

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
        void time_function(double d);
        void over_function();
};