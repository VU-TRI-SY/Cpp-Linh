#ifndef NODE_H_
#define NODE_H_
#include <bits/stdc++.h>
using namespace std;
class Node{
    private:
        string filename_;
        string body_;
        string title_;
        vector <string> links_;
    public:
        Node(string filename){
            filename_ = filename;
        }

        bool addLink(string link){
            for (int i = 0; i < links_.size(); i++){
                if (links_[i] == link){
                    return false;
                }
            }
            links_.push_back(link);
            return true;
        }

        void removeLink(string link){
            for (int i = 0; i < links_.size(); i++){
                if (links_[i] == link){
                    links_.erase(links_.begin() + i);
                }
            }
        }

        void printLinks(){
            for (int i = 0; i < links_.size(); i++){
                cout << i+1 << ") " << links_[i] << endl;
            }
        }

        void setBody(string body){
            body_ = body;
        }

        void setTitle(string title){
            title_ = title;
        }

        void setLinks(vector<string> links){
            links_ = links;
        }

        string getFilename() const{
            return filename_;
        }

        string getBody() const{
            return body_;
        }

        string getTitle() const{
            return title_;
        }

        vector<string> getLinks() const{
            return links_;
        }

        bool operator==(const Node& other) const{
            return filename_ == other.filename_;
        }

        bool operator!=(const Node& other) const{
            return filename_ != other.filename_;
        }

        friend ostream& operator << (ostream& out, const Node& node){
            out << node.title_;
            return out;
        }

};
#endif
 




