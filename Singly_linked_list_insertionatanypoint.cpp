#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* next;

Node(int data){
    this ->data=data;
    this->next= NULL;
    }
};
void Iathead(Node* &head,int data){
        //new node
    Node* temp = new Node(data);

    temp->next=head;
    head=temp;
    };
void Iattail(Node* &tail,int data){
        //new node
    Node* temp = new Node(data);

    tail->next=temp;
    tail=tail->next;
    };

void IatAnyPoint(Node* &head, Node* &tail,int position , int data){
    //insert at Start
    if(position == 1) {
        Iathead(head, data);
        return;
    }
    Node* temp  = head;
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    //inserting at Last Position
    if(temp -> next == NULL) {
        Iattail(tail,data);
        return ;
    }
    //creating a node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void print(Node* &head ){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    };
    
}
int main(){
    Node* Node1= new Node(25);
    Node* head=Node1;
    Node* tail=Node1;
    Iathead(head,35);
    Iathead(head,45);
    Iathead(head,55);
    Iathead(head,65);
    cout<<"Before insertion at any point : ";
    print(head);
    cout<<endl;
    cout<<"After insertion at the 3rd poisiton : ";
    IatAnyPoint(head,tail,3,75);
    print(head);
    cout<<endl;
    cout<<"HEAD : "<<head->data<<endl;
    cout<<"TAIL : "<<tail->data<<endl;



    return 0;


}