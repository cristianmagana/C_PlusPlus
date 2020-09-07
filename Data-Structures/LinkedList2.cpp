#include <iostream>
using namespace std;

// Provided node class
class node {
    void *info;
    node *next;
public:
    node (void *v) {info = v; next = 0; }
    void put_next (node *n) {next = n;}
    node *get_next ( ) {return next;}
    void *get_info ( ) {return info;}
};

// List class template
template <class T>
class list {
    node *start;
public:
    list (T v) {
        start = new node (&v);
    }

    // Insert method
    void insert (T *value, int place=-1) {
        node *temp = new node (value);

        // if going to the beginning, change the reference to start
        if (place == 0) {
            temp->put_next(start);
            start = temp;
        }

        // if not the beginning, determine where to put it
        else {
            node *before = start;

            // Loop to find the preceeding node
            for (int i = 1; before->get_next() != 0; i++) {
                if (i == place) { 
                    break;
                }
                before = before->get_next();
            }

            // Insert after preceeding node and point to the next node
            temp->put_next(before->get_next());
            before->put_next(temp);
        }
    }

    // Remove function
    void remove(int place) {

        // when removing from the beginning, change start pointer
        if (place == 0) {
            start = start->get_next();
        }

        // Find node to remove
        else {
            node *curr = start;
            for (int i = 1; curr != 0; i ++) {
                if (i == place) {
                    // remove the target node 
                    curr->put_next(curr->get_next()->get_next());
                    break;
                }
                curr = curr->get_next();
            }
        }
    }

    // Print nodes
    void display() {
        for (node *current = start; current != 0; current = current->get_next()) {
            cout << *(static_cast<T*>(current->get_info())) << endl;
        }
        cout << endl;
    }
};

int main() {
    int nine = 9;
    int eight = 8;
    int seven = 7;
    int six = 6;
    int five = 5;
    
    cout << "Create list holding '10'" << endl;
    list<int> *hold_list = new list<int>(10);
    
    cout << endl << "Placing " << nine << " at start of list." << endl;
    hold_list->insert(&nine,0);

    cout << endl << "Inserting " << eight << " at 2nd place." << endl;
    hold_list->insert(&eight,1);

    cout << endl << "Appending " << seven << " to the list." << endl;
    hold_list->insert(&seven);

    cout << endl << "Placing " << six << " at start of list." << endl;
    hold_list->insert(&six,0);

    cout << endl << "Inserting " << five << " at 3rd place." << endl;
    hold_list->insert(&five,2);

    cout << endl << "Show completed list:" << endl;
    hold_list->display();

    cout << "Removing the first element:" << endl;
    hold_list->remove(0);
    hold_list->display();

    cout << "Removing the last element:" << endl;   
    hold_list->remove(4); 
    hold_list->display();

    cout << "Removing the second element:" << endl;
    hold_list->remove(1);
    hold_list->display();
}
