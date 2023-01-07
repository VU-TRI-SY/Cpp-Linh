#ifndef WEBPAGENETWORK_H_
#define WEBPAGENETWORK_H_
#include "Node.h"
#include <stack>
#include <vector>
 
class WebpageNetwork{
    public:
 
    WebpageNetwork();
    //DESCRIPTION: Constructor which initializes WebpageNetwork object and allocates resources
    //POST-CONDITION: WebPageNetwork object is created and private variables are initialized
 
    ~WebpageNetwork();
    //DESCRIPTION: Destructor gets rid of any dynamically allocated nodes inside the "graph_" and "history_" variables of the program
    //PRE-CONDITION: There are dynamically allocated nodes inside the "graph_" and "history_" variables
    //POST-CONDITION: The successful clearing of space and no leaking memory
 
    void AddFiles(vector<string> input_file_names);
    /* DESCRIPTION: adds each of these webpages listed in the vector to the graph. If the file cannot be found, output to the screen
    "File [inputFilename] Not Found" where you replace [inputFilename] with the filename that wasn't found. */
 
    //PRE-CONDITIONS: Needs the parameter to include a non-empty vector with valid files names
    //POST-CONDITIONS: Nodes for each of the files are created and are added to the graph vector
 
    bool RemoveFiles(vector<string> input_file_names); //removes a file from graph ie. deleting node
    /*DESCRIPTION: This method removes any files listed and their associated links. If the file cannot be found, output to the screen
    "File [inputFilename] Not Found" where you replace [inputFilename] with the filename that wasn't found.*/
 
    //PRE-CONDITIONS: Needs the parameter to include a non-empty vector with valid files names
    //POST-CONDITIONS: Nodes for file names listed are removed along with their link nodes
 
    void InteractiveMode(string start);
    /*DESCRIPTION: Enters the system into interactive mode where the user can traverse all of the webpages connected to the one that they
    start at.  If  start cannot be found, then output "File [start] Not Found" where you replace [start] with the filename that wasn't found. Provides other options as well
    such as allowing the user to go back to the previous page as well as seeing the body of the node.*/
 
    //PRE-CONDITION: a valid start point of a file which hasn't been deleted yet/exists within the vector
    //POST-CONDITION: Able to exit interactive mode without errors or program crashing and with no memory leaks
 
    friend ostream& operator<<(ostream& out, const Node& node);
    //DESCRIPTION: displays the title of the page
    //PRE-CONDITION: The parameter is a valid node
    //POST-CONDITION: The node's title is printed out

    private:
    string ParseBody (string file_name);
    //DESCRIPTION: Searches for the body of the HTML page
    //PRE-CONDITION: The file exists and contains a body
    //POST-CONDITION: The body of the HTML page is returned as a string

    vector<string> ParseLinks (string file_name);
    //DESCRIPTION: Searches for the links in the HTML page
    //PRE-CONDITION: The file exists and contains links
    //POST-CONDITION: The links in the HTML page are returned as a vector of string(s)

    string ParseTitle(string file_name);
    //DESCRIPTION: Searched for the title of the HTML page
    //PRE-CONDITION: The file exists and contains a title
    //POST-CONDITION: The title of the HTML page is returned as a string
 
    void DisplayBody(const Node* node); //fetch the string of the body of the node
    //DESCRIPTION: Display the body of the HTML page.
    //PRE-CONDITION: anything in the body but not empty.
    //POST-CONDITION: print out the content in the body.
 
    void ListLinks(const Node* node);
    //DESCRIPTION: Display a list of links in the HTML page.
    //PRE-CONDITION: the links exist in the HTML page
    //POST-CONDITION: print out the list of links to other HTML pages

    void GoBack();
    //DESCRIPTION: Go back to a previous action, like the previous HTML page.
    //PRE-CONDITION: the history has to have at least two nodes.
    //POST-CONDITION: Traverse to the last node has been visited.
 
    void Exit();
    //DESCRIPTION: Leave the node and exit the current HTML page.
    //PRE-CONDITION: The history has to have at least one node.
    //POST-CONDITION: Program stops running

    vector<Node*> graph_;
    //DESCRIPTION: This vector contains pointers to a webpage node. Meant to represent a graph.

    stack<Node*> history_;
    //DESCRIPTION: This stack contains the history of the pages the user visited. Meant to make it easier to go back a page(s).
};
#endif
 
 



