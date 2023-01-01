#include<iostream>
using namespace std;
template<class Type_>
class Darray{
    Type_* holder; 
    int size;
    int maxSize;
    public:
        Darray(int max_size){
            holder = new Type_[max_size];
            maxSize = max_size;
            size = 0;
        }

        bool add(Type_ data){
            if(size < maxSize){
                holder[size] = data; 
                size++;
                return true;
            }
            return false;
        }

        void display(){
            for(int i = 0; i < size; i++){
                cout << holder[i];
                //cout << Student << " "
            }
            //operator overriding
            cout << endl;
        }
};

class Student{
    string name;
    string id;

    public: 
        Student(){
            id = "";
            name = "";
        }

        Student(string id, string name){
            this->id = id;
            this->name = name;
        }

        // std::ostream& operator << (std::ostream& os){
        //     os << id << " " << name << endl;
        //     return os;
        // }
        friend ostream& operator<<(ostream& os, const Student& st){
            os << st.id << " " << st.name << endl;
            return os;
        }
	    // friend istream& operator>>(istream& stream, Child& child);
};

int main(){
    Darray<Student> D(100);
    // Student s1("100", "Jack");
    D.add(Student("100", "Jack"));
    D.add(Student("101", "Jack"));
    D.add(Student("102", "Jack"));
    D.add(Student("103", "Jack"));
    D.add(Student("104", "Jack"));
    D.display();
}