#include <bits/stdc++.h>
#include "MyCo.h"
using namespace std;

MyCo::MyCo() //Constructor with no arguments - default constructor
{
    cout << "Default constructor arguments is called" << endl;
    count = 1;
}
MyCo::MyCo(const MyCo &m) //Copy constructor
{
    cout << "Copy constructor is called" << endl;
    this->count = m.count + 3;
}
MyCo::MyCo(int i) //Constructor with one argument
{
    cout << "Constructor with one argument is called" << endl;
    count = i;
}
MyCo &MyCo::Foo(MyCo m1, MyCo &m2, int c) //Method with three arguments - Function
{
    MyCo m = m1;
    m.count += c;
    m2.count += c;
    return m2;
}
MyCo::~MyCo() //Destructor
{
    cout << "Destructor is called" << endl;
    // std::cout << count << std::endl;
}

int main()
{
    MyCo m1(11), m2;
    //m1 and m2 is created ---> 2 consrtuctors are called
    MyCo me = m1; //Copy constructor is called
    cout << &me << " " << &m1 << endl;
    m1 = m1.Foo(m2, me, 13); //Function is called
    return 0;
    //pass by value
    //m1.Foo(m2, me, 13) return a reference to me
    //Foo is called ---> destructor is called for m
    //m1 is assigned to result of m1.Foo(m2, me, 13)
}

//main is called ---> 2 destructor is called

// MyCo& MyCo::Foo(MyCo m1, MyCo &m2, int c) //Method with three arguments - Function
// {
//     MyCo m = m1; //copy constructor is called
//     m.count += c;
//     m2.count += c;
//     return m2;
// }
