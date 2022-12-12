#include<bits/stdc++.h>
using namespace std;
int sumOfN(int i, int n){
    if(n == 0){
        return 0;
    }

    if(i % 2 == 0){
        return i + sumOfN(i+1, n-1);
    }else{
        return sumOfN(i+1, n);
    }
}

int main(){
    cout << sumOfN(0, 6) << endl;
}