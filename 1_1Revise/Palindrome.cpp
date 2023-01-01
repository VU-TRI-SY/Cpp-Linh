#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int n){
    if(n < 0)
        return false;

    int temp = n;
    int reverse = 0; 
    while(temp > 0){
        int c = temp % 10;  //get the last digit of temp
        reverse = reverse * 10 + c; // add c to the end of reverse
        temp = temp / 10; //remove the last dgit of temp
    }
    return reverse == n; //return true if reverse = n, otherwise return false
}
int main(){

}