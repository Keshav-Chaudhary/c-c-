// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
// Main() function: where the execution of
// program begins
int main()
{
    int a , b ,c ;
    cin>>a>>b>>c;
    if(a>b) {
         if(a>c){
            cout<<"a is the largest\n"<<a<<endl;
        }
    }
    else if (b>c){
        cout<<"b is the greatest\n"<<b<<endl;
    } 
    else {
        cout<<"c is the largest  "<<c<<"\n"<<endl;
    }
    return 0;
}