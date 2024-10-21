#include<iostream>
using namespace std;

class node{ //user defined "DATA TYPE";
public:
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=NULL;
        
    }
};

class LinkedList{//user defined "DATA STRUCTURE";
public:
    node* head;
    node* tail;
    int size;
public:     
    LinkedList(){
        head =tail=NULL;
        size=0;
    }
    void insertAtEnd(int val){
        node* temp= new node(val);
        if(size==0) head = tail =temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }

    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }

    void insertAtHead(int val){
        node* temp=new node(val);
        if(size==0) head =tail =temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }

    void insertAtidx(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid index\n";
         else if(idx==0) insertAtHead(val);
         else if(idx==size) insertAtEnd(val);
         else {
            node* t=new node(val);
            node* temp=head;
            for(int i=1;i<idx;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
         }
        
    }

     bool is_empty() {
        if(!head) return true;
        else return false;
     }
     void interleave(LinkedList& LinkedList2) {
        node* tempA = head;
        node* tempB = LinkedList2.head;
        node* next1 = NULL;     
        node* next2 = NULL;

        while (tempA != NULL && tempB != NULL) {
            next1 = tempA->next;
            next2 = tempB->next;

            tempA->next = tempB;
            tempB->next = next1;

            tempA = next1;
            tempB = next2;
        }

        LinkedList2.head = NULL;
    }

   void sortTwoArray(LinkedList& LinkedList2) {
        node* tempA = head;
        node* tempB = LinkedList2.head;
        node* next1 = NULL;     
        node* next2 = NULL;

        while (tempA->val < tempB->val) {
            next1 = tempA->next;
            next2 = tempB->next;

            tempA->next = tempB;
            tempB->next = next1;

            tempA = next1;
            tempB = next2;
        }

        LinkedList2.head = NULL;
    }

};

int main(){
    LinkedList ll ;
    LinkedList ll1 ;
    ll.insertAtEnd(10);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    
    ll.insertAtEnd(100);
    ll.insertAtEnd(300);
    ll.insertAtEnd(400);
    
    ll.display();
    cout<<"\n\n";
    ll.interleave(ll1);
    ll.display();

    cout<<ll.head->val<<"\n";
}