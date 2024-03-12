#include<iostream>
using namespace std;
class Arcade{
    // private class created :- not accessible outside this class o/w it will shows error 
    private:
    int peoples; 
    
    public:
    int levels;
    char points;
    int badges;

    //getter and setter
    int getpeoples(){
        return peoples;
    }
    /*void setpeoples(int peoples){
        this -> peoples = peoples;
    }*/

    //simple constructor 
    Arcade (){
        cout<<"simple constructor called "<<endl;
    }
    //parameterized constructor 
    Arcade (int levels , int points , int badges){
        this -> levels = levels;
        this -> points = points;
        this -> badges = badges;/* this is a pointer to the current instance of the class. 
        It's often used in C++ to distinguish between local variables and member variables with the same name.
        peoples:- on the left side of the assignment refers to a member variable of the class.
        peoples:- on the right side of the assignment refers to the parameter passed to the function.
        So, this->peoples = peoples; assigns the value of the parameter peoples to the member variable peoples of the class */
    }
    //copy constructor
    Arcade (Arcade& Me){//& is used here for pass of reference is we dont use it here it will shows error as it struck in continous infinte loop 
        this -> levels = Me.levels;
        this -> points = Me.points;
        this -> badges = Me.badges;
    }
    //print 
    void print(){
        cout<<"The Level is : "<<levels<<endl;
        cout<<"The points is : "<<points<<endl;
        cout<<"The bagde is : "<<badges<<endl;
    }


};

int main (){
    //object of class means the instance of class 
    //Arcade Me;
    //Me.peoples=45; this will give the error as we use here the private class so, getting rid from this we use the concept of getter/setters 
    //Me.levels=12;
    //Me.points='A';

    Arcade Me(15,'a',45);
    Me.print();
    Arcade You(Me);// shallow copy of object me using the customized copy constructor 
    You.print();
    
    
    //below will shows error of literal operator only if we dont have getter and setter and peoples in private class  
    //cout<<"the number of peoples :"<<Me.peoples<<endl; 
    
    //Me.setpeoples(152); //takees the people from outside and storing it inside class "peoples"
    
    //cout<<"the number of peoples :"<<Me.getpeoples()<<endl;
    //cout<<"the levels is :"<<Me.levels<<endl;
    //cout<<"the points are :"<<Me.points<<endl;
    return 0;
}