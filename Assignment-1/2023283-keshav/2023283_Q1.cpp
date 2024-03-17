#include <iostream>
using namespace std;
void Toh(int n, char sourceT, char destiny,
char auxT1, char auxT2){
    if (n == 0){
        return;
    }
    if (n == 1){
    
    cout <<"T"<< sourceT <<" --> T"<<destiny<<endl;
    return;
    }
    Toh(n - 2, sourceT, auxT1, auxT2,destiny);
    cout <<"T"<< sourceT <<" --> T"<<auxT2<<endl;
    cout <<"T"<< sourceT <<" --> T"<<destiny<<endl;
    cout <<"T"<< auxT2 <<" --> T"<<destiny<<endl;
    Toh(n - 2, auxT1, destiny, sourceT,auxT2);
}
int main(){
    int n;
    cout<<"Enter the number of disks : ";
    cin>>n;
    cout<<"The sequence of steps are :-"<<endl;
    Toh(n, '1', '4', '2', '3');
    return 0;
}
