#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next; //pointer in the heap memory or the dyanmically implement odject

    Node(int data){ //parameterized constructur helps to take the user input and store it to the data from this->data(user input value)
        this -> data =data;
        this -> next = NULL;
    };
};
void IAThead(Node* &head,int data){
    Node* temp = new Node(data); //creating a pointer of node type and pointing it towards the head of linked list (at first Node )
    temp -> next = head;
    head=temp;


}
void IATtail(Node* &tail,int data){

}
void IATanypoint(Node* &head,Node* &tail , int position , int data){
    //case 1 if the postion is 1 so the insertion is at head so we call another function named IAthead so it will insert the element at the forst Node seperately 
    if(position==1){
        IAThead(head,data);
        return;//the will break the loop so that the remaining commands within this function will not execute 
    }
    
    
}
void print(Node* &head){
    Node* temp=head;// creating pointer towards the first element it stores the first element 
    while(temp!=NULL){ //this loops run till the temp=Null, means the last Node is pointing towards the Null;
        cout<<temp->data<<" "; //prints the previous stores elemwnt from first node
        temp=temp->next;       //this line moves away the pointer name "temp" to the next Node and storing the next element to the same "temp"
    }

}
int main(){

    Node* Node1= new Node(15);
    Node* head= Node1; //pointer named head towards our Created Node1
    Node* tail= Node1; //--------------tail -------------------------
    IATanypoint(head,tail,1,20);
    print(head);
    return 0;
    cout<<head->data;//prints the head of our linked list 
    cout<<tail->data;//-----------tail-------------------

}