#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;
const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s)
{
    return rtrim(ltrim(s));
}

istream& getLink(istream &is, string &link)
{
    string line = "";
    
    while (!is.eof())
    {
        char c;
        is >> std::noskipws >> c;
        if(c == '\"'){
            while(!is.eof()){
                is >> std::noskipws >> c;
                if(c == '\"'){
                    break;
                }
                line += c;
            }
        }
        if(c == '>'){
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
            else{
                if (c == '/'){
                    is >> std::noskipws >> c;
                    if(c == 'a'){ //</a>
                        is >> std::noskipws >> c; //read >
                    }else{
                        if(c == 'b'){ //</body>
                            while(!is.eof()){
                                is >> std::noskipws >> c;
                                if(c == '>'){
                                    body = trim(line);
                                    return is;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }else{
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
    cout << line << endl;
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


int main()
{
    ifstream is("data.html");
    string title, body;
    vector<string> links;
    getTitle(is, title);
    getBody(is, body, links);
    cout << "title: " << title << endl;
    cout << "body: " << body << endl;
    cout << "Links: " << endl;
    for (int i = 0; i < links.size(); i++)
    {
        cout << i + 1 << ") " << links[i] << endl;
    }
    is.close();
}