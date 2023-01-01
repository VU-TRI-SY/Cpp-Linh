#include<iostream>
#include<stack>
using namespace std;
class Student{
    string name;
    string id;

    public: 
        Student(){
            id = "";
            name = "";
            cout << "Construct is called" << endl;
        }

        Student(string id, string name){
            this->id = id;
            this->name = name;
            cout << "Construct is called" << endl;
        }

        Student(const Student&st){
            this->name = st.name;
            this->id = st.id;
            cout << "Copy Construct is called" << endl;
            
        }

        ~Student(){
            cout << "Destructor is called" << endl;
        }

        friend ostream& operator<<(ostream& os, const Student& st){
            os << st.id << " " << st.name << endl;
            return os;
        }
};

void changeSt(Student st){
    //do st
}
int main(){
    Student std("100", "Jack"); //construct with 2 arguments is called
    cout << "--------" << endl;
    changeSt(std); // std is passed by value ---> the copy constructor of Student is called to creates
    cout << "--------" << endl;
    //the object "st" that is the copy version of "std"
} 