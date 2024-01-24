#include <iostream>
#include <string>

using namespace std;
struct Mystruct{
    int id;
    string name;
    string country;
};
void inputusersstruct(Mystruct &s){
    cout<<"enter the id : ";
    cin>>s.id;
    cin.ignore();
    cout<<"enter the name  : ";
    getline(cin,s.name);
    cout<<"enter the Country : ";
    getline(cin,s.country);
};

void displaymystruct(const Mystruct &s){
    cout<<"\nMy Struct\n"<<endl;
    cout<<"ID : "<<s.id << endl;
    cout<<"Name : "<<s.name<<endl;
    cout<<"Country : "<<s.country<<endl;
};
int main(){
    Mystruct*structptr= new Mystruct;
    inputusersstruct(*structptr);
    displaymystruct(*structptr);
    printf("Hello World\n");

    return 0;
}
