#include<iostream>
using namespace std;
class node{
public:
    int val;
    node* prev;
    node* next;
    node( int val){
        this->val=val;
        this->prev=nullptr;
        this->next=nullptr;
    }
};
class DLL{
public:
    node* head;
    node* tail;
    int size;
    DLL(){
        head=tail=nullptr;
        size=0;
    }

    void insertAtTail(int val){
        node* temp=new node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            temp->next=nullptr;
            tail=temp;
        }
        size++;
    }
    void insertAtHead(int val){
        node* temp=new node(val);
        if(size==0) head =tail =temp;
        else{
            temp->next=head;
            head->prev=temp;
            temp->prev=nullptr;
            head=temp;
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


};


int main(){
    // 10 20 30 40 50
    DLL dll;
    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);

    // node* a = new node(10);
    // node* b = new node(20);
    // node* c = new node(30);
    // node* d = new node(40);
    // node* e = new node(50);
    
    // a->next=b;
    // b->next=c;
    // c->next=d;
    // d->next=e;

    // e->prev=d;
    // d->prev=c;
    // c->prev=b;
    // b->prev=a;

    dll.display();

    

}
