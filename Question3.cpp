#include<bits/stdc++.h>
using namespace std;
class Coord{
    int x;
    int y;
    public:
    Coord(int x, int y){
        this->x = x;
        this->y = y;
        cout << "Constructor of class Coord is called (2 arguments)" << endl;
    }

    Coord(const Coord &c){
        this->x = c.x;
        this->y = c.y;
        cout << "Copy constructor of class Coord is called" << endl;
    }

    Coord& operator=(const Coord &c){
        this->x = c.x;
        this->y = c.y;
        cout << "Assignment operator of class Coord is called" << endl;
        return *this;
    }

    int get_x(){
        return x;
    }
    
    int get_y(){
        return y;
    }

    ~Coord(){
        cout << "Destructor of class Coord is called" << endl;
    }
};

class Rectangle{
    int width;
    int height;
    public:
    Rectangle(int width, int height){
        this->width = width;
        this->height = height;
        cout << "Constructor of class Rectangle is called (2 arguments)" << endl;
    }

    Rectangle(const Rectangle &r){
        this->width = r.width;
        this->height = r.height;
        cout << "Copy constructor of class Rectangle is called" << endl;
    }

    Rectangle& operator=(const Rectangle &r){
        this->width = r.width;
        this->height = r.height;
        cout << "Assignment operator of class Rectangle is called" << endl;
        return *this;

    }

    ~Rectangle(){
        cout << "Destructor of clas Rectangle is called" << endl;
    }

};

Rectangle& AlloRect(Coord c, int w, int l, Rectangle*& rect)
{
    int temp = c.get_x();
    Rectangle* p_rect_a = new Rectangle(temp, l); 
    Rectangle* r = new Rectangle(w, c.get_y()); 
    Rectangle r2(*p_rect_a); 
    rect = r; 
    return* p_rect_a;
}

int main(){
    Rectangle* rect = new Rectangle(5, 6);
    Coord c(1, 2);
    cout << "-----------------------------------------------------" << endl;
    cout << "Constructors when AlloReact() is called" << endl << endl;
    AlloRect(c, 3, 4, rect);

    cout << "Destructor when AlloReact() is run" << endl << endl;
    cout << "-----------------------------------------------------" << endl;

}