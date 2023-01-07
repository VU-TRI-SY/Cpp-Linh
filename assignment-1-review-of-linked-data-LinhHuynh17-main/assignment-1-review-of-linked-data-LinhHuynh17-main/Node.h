#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <string>
using namespace std;
class Node{
    public:
 
        Node (string file_name, string title, string body);
        //DESCRIPTION: Node constructor which initializes the private variables of the node
        //PRE-CONDITION: valid file, title, and body name
        //POST-CONDITION: Private file, title, and body name variables are initialized
 
        ~Node();
        //DESCRIPTION: Node destructor would delete the link nodes and free up memory
        //PRE-CONDITION: There is memory to free in the links vector
        //POST-CONDITION: No memory leaks and link nodes are deleted
   
        bool AddLink (Node* link);
        //DESCRIPTION: Adds node link to links vector. Returns true if link was added successfully.
        //PRE-CONDITION: Has a valid node to add
        //POST-CONDITION: Adds node to the links vector
 
        bool RemoveLink (Node* link);
        //DESCRIPTION: Removes link of node requested. Returns true if remove was successful.
        //PRE-CONDITION: Node exists inside links vector
        //POST-CONDITION: the Node which is asked to be deleted is removed from the links vector
 
        string get_title() const;
        //DESCRIPTION: Getter which gets the private variable "title_"
        //POST-CONDITION: Returns a string which is the title of the node
 
        string get_name() const;
        //DESCRIPTION: Getter which gets the private variable "file_name_"
        //POST-CONDITION: Returns a string which is the file name of the node
 
        string get_body() const;
        //DESCRIPTION: Getter which gets the private variable "body_"
        //POST-CONDITION: Returns a string which is the body of the node
 
        vector<Node*> get_links() const;
        //DESCRIPTION: vector which holds a pointer to the nodes which link to the current node
 
    private:
        string file_name_;
        string title_;
        string body_;
 
        vector <Node*> links;
        //add,remove
        //DESCRIPTION: vector of nodes with links to the current node
};
#endif
 




