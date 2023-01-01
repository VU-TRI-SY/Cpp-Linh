#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vt.push_back(1);
    // vt.push_back(2);
    // vt.push_back(3);
    // vt.push_back(4);
    // vt.push_back(5);
    
    // vt.insert(vt.begin() + 3, 10);


    vector<int> vt(5, -1); //(size, init_value)
    for(int i = 0; i < vt.size(); i++){
        cout << vt[i] << endl;
    }
    cout << "---------------------------------\n";
    vt.resize(10, -10);
    for(int i = 0; i < vt.size(); i++){
        cout << vt[i] << endl;
    }
}
