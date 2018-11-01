#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
#include "Bigint.h"

using namespace std;



int main(){
    int choice_1=0;
    cout<<"Enter 1 for addition and 2 for subtraction: ";
    cin>>choice_1;

    // cout<<"hello world"<<endl;
    string str1 = "";
    string str2 = "";
    cout<<"Enter the first number: ";
    cin>>str1;
    cout<<"Enter the second number: ";
    cin>>str2;
    bigintadd b(str1);
    bigintadd b1(str2);
    if(choice_1 == 1){
        cout << (b + b1) << endl;
    }
    if(choice_1 == 2){
        cout << (b - b1) << endl;
    }
    return 0;
}
