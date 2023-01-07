#ifndef WEBPAGENETWORK_H_
#define WEBPAGENETWORK_H_
#include <bits/stdc++.h>
#include "Node.h"
#include "Utils.h"

class WebpageNetwork
{
public:
    WebpageNetwork()
    {
        // graph_ = vector<Node *>();
        // history_ = stack<Node *>();
        currentpage_ = nullptr;
    }

    ~WebpageNetwork()
    {
        for (int i = 0; i < graph_.size(); i++)
        {
            delete graph_[i];
            graph_[i] = nullptr;
        }

        while(!history_.empty()){
            Node* tp = history_.top();
            delete tp;
            tp = nullptr;
            history_.pop();
        }
    }

    void AddFiles(vector<string> input_file_names)
    {
        for (int i = 0; i < input_file_names.size(); i++)
        {
            ifstream file(input_file_names[i]);
            if (file.is_open())
            {
                string filename, body, title;
                vector<string> links;
                Node *node = new Node(input_file_names[i]);
                while(!file.eof()){
                    char c;
                    file >> std::noskipws >> c;
                    if(c == '<'){
                        file >> std::noskipws >> c;
                        if(c == 't'){ //<title>
                            getTitle(file, title);
                            node->setTitle(title);
                        }else if(c == 'b'){ //<a>
                            getBody(file, body, links);
                            node->setBody(body);
                        }
                    }
                }
                node->setLinks(links);
                graph_.push_back(node);
                file.close();
            }
            else
            {
                cout << "File " << input_file_names[i] << " Not Found" << endl;
            }
        }
    }

    bool RemoveFiles(vector<string> input_file_names)
    {
        for (int i = 0; i < input_file_names.size(); i++)
        {
            for (int j = 0; j < graph_.size(); j++)
            {
                if (graph_[j]->getFilename() == input_file_names[i])
                {
                    delete graph_[j];
                    graph_[j] = nullptr;
                    graph_.erase(graph_.begin() + j);
                    return true;
                }
            }
            cout << "File " << input_file_names[i] << " Not Found" << endl;
        }
        return false;
    }

    void InteractiveMode(string start)
    {
        bool found = false;
        for(int i = 0; i < graph_.size(); i++){
            if(graph_[i]->getFilename() == start){
                currentpage_ = graph_[i];
                history_.push(currentpage_);
                found = true;
                break;
            }
        }
        if(!found){
            cout << "File " << start << " Not Found" << endl;
            return;
        }else{
            int choice;
            while(1){
                cout << "\n--------- " <<  *currentpage_ << " ---------" << endl << endl;
                cout << "1) Display the HTML Body" << endl;
                cout << "2) List the links" << endl;
                cout << "3) Go back to the previous page" << endl;
                cout << "4) Exit Interactive Mode" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                switch(choice){
                    case 1:
                        cout << "Body of the page: " << endl << endl;
                        cout << currentpage_->getBody() << endl << endl;
                        break;
                    case 2:
                        cout << "Links in the page: " << endl << endl;
                        displayLinks();

                        break;
                    case 3:
                        goBack();
                        break;
                    case 4:
                        exitProgram();
                        break;
                    default:
                        cout << "Invalid Choice" << endl;
                }
            }
        }
    }

private:
    istream &getLink(istream &is, string &link)
    {
        string line = "";

        while (!is.eof())
        {
            char c;
            is >> std::noskipws >> c;
            if (c == '\"')
            {
                while (!is.eof())
                {
                    is >> std::noskipws >> c;
                    if (c == '\"')
                    {
                        break;
                    }
                    line += c;
                }
            }
            if (c == '>')
            {
                break;
            }
        }

        link = trim(line);
        return is;
    }

    istream &getBody(istream &is, string &body, vector<string> &links)
    {
        string link;
        while (!is.eof())
        {
            char c;
            is >> std::noskipws >> c;
            if (c == '>')
                break;
        } // read opening tag of body

        string line = "";
        while (!is.eof())
        {
            char c;
            is >> std::noskipws >> c;
            if (c == '<')
            {
                is >> std::noskipws >> c;
                if (c == 'a') //<a href="link">
                {
                    getLink(is, link);
                    links.push_back(link);
                }
                else
                {
                    if (c == '/')
                    {
                        is >> std::noskipws >> c;
                        if (c == 'a')
                        {                             //</a>
                            is >> std::noskipws >> c; // read >
                        }
                        else
                        {
                            if (c == 'b')
                            { //</body>
                                while (!is.eof())
                                {
                                    is >> std::noskipws >> c;
                                    if (c == '>')
                                    {
                                        body = trim(line);
                                        return is;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                line += c;
            }
        }
        return is;
    }

    istream &getTitle(istream &is, string &title)
    {
        while (!is.eof())
        {
            char c;
            is >> std::noskipws >> c;
            if (c == '>')
                break;
        } // read opening tag of title

        string line = "";
        while (!is.eof())
        {
            char c;
            is >> std::noskipws >> c;

            if (c == '<')
                break;
            line += c;
        } // read title
        while (!is.eof())
        {
            char c;
            is >> std::noskipws >> c;
            if (c == '>')
                break;
        } // read closing tag of title

        title = trim(line);
        // title = line;
        return is;
    }

    void goBack()
    {
        if (history_.size() > 1)
        {
            Node*tp1 = history_.top();
            history_.pop();
            Node*tp2 = history_.top();
            history_.pop();
            if(tp1->getFilename() != tp2->getFilename()){
                currentpage_ = tp2;
                InteractiveMode(currentpage_->getFilename());
            }
        }
        else
        {
            cout << "\nNo more pages to go back to.\n" << endl;
        }
    }

    void exitProgram()
    {
        cout << "\nExiting...\n" << endl;
        exit(0);
    }

    void displayLinks(){
        char c;
        currentpage_->printLinks();
        cout << "X) Return to Menu" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        if(c == 'X' || c == 'x'){
            history_.pop();
            InteractiveMode(currentpage_->getFilename());
        }else{
            int choice = c - '0';
            if(choice > 0 && choice <= currentpage_->getLinks().size()){
                for(int i = 0; i < graph_.size(); i++){
                    if(graph_[i]->getFilename() == currentpage_->getLinks()[choice - 1]){
                        currentpage_ = graph_[i];
                        InteractiveMode(currentpage_->getFilename());
                        history_.push(currentpage_);
                        break;
                    }
                }
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }

    }
    vector<Node *> graph_;
    Node *currentpage_;
    stack<Node *> history_;
};
#endif
