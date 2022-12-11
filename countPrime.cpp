#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;

    if(n == 2)
        return true;

    //if n > 2 ---> check [2, n-1], if exists i (n % i = 0) ---> n is not a prime number   
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void countPrime(int m, int n){
    if(m > n){
        return; //stop -- base case: stop recursive
    }else{
        if(isPrime(m)){
            cout << m << ", ";
        }

        countPrime(m+1, n);
    }
}

void F(int*& p, int* y){
    cout << "Value of pointer p in F() " << p << endl;
    cout << "Address of pointer p in F() " << &p <<endl;
    p = y; //gan dia chi cua ben b cho pointer p
}


int nthCat(int n){
    if(n == 0){
        return 1;
    }else{
        return (2 * (2*n - 1) * nthCat(n-1)) / (n+1) ;
    }
}

int main(){
    cout << nthCat(8);
}
