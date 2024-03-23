#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;//creating a pointer of node type (heap memory)

    Node(int data) { //parameterized constructor that stores our first Node and pointing it towards NuLL like 10 -> NULL
        this->data = data;
        this->next = NULL;
    }
};

void InsertionAtHead(Node* &head,int data ){
    //creating the new node 
    Node* temp = new Node(data);
    //inserting the 12 at rthe left side of 10 
    temp -> next = head;//12->10->NULL
    head = temp;        //defining the node 12 is head 
};

void InsertionAtTail(Node* &tail, int data){
    //creating new node for refference 
    Node* temp= new Node(data);
    //inserting the 12 at the right side of node 10
    tail -> next = temp;
    tail= tail ->next;
}

void print(Node* &head){     // pass by refference we used beacause we dont want to create a new list 
    Node* temp =head;              // starting from the left most node 
    while(temp !=NULL){            //checking the condition if the length of linked list is exist if no Nodethen stops
        cout<<temp -> data<< " ";  //printing the first Node one after space
        temp= temp -> next;        //after printing the first Node now our temp pointer move one Node forward and then checks the conditon if it is true then printing the second node and so on .until the conditon becomes false 
    }
};


int main() {
    // creating the starting nodes 

    Node* Node1 = new Node(10);

    /* cout << Node1->data << endl;//this will print the first Node
    cout <<Node1->next << endl;//this will shows our first Node points towards the null */
    
    //INSERTION AT HEAD 
    Node* head = Node1;//the new head pointed towards node1 here head pointer is used to insert at the head of linked list 
    InsertionAtHead(head,12);
    cout<<"The linked list No.1 after the insertion of 12 at head  : Head -> ";
    print(head);
    cout<<endl;
    //inserting more Node at Head 
    InsertionAtHead(head,15);
    InsertionAtHead(head,8);
    InsertionAtHead(head,45);
    InsertionAtHead(head,6);
    cout<<"The linked list No.1 after the insertion of 5 Nodes at head  : Head -> ";
    print(head);
    cout<<endl;
    
    
// run only one insertion at a time 
/*    //INSERTION AT TAIL
    Node* tail =Node1;//in the singly linked list the head and tail position are same so 10-> Null , here 10 is tail or head , tail pointer used to insert at the tail of Node 10
    InsertionAtTail(tail,12);
    cout<<"The linked list No.2 after the insertion of 12 at tail  : ";
    print(head);
    cout<<endl;
    //inserting more Node at tail
    InsertionAtTail(tail,35);
    InsertionAtTail(tail,45);
    InsertionAtTail(tail,55);
    InsertionAtTail(tail,65);
    InsertionAtTail(tail,75);
    cout<<"The linked list No.2 after the insertion of 5 Nodes at tail : ";
    print(head); */

    return 0;
}

