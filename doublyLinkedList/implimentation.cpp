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

void Display(node* head){
   while(head){
     cout<<head->val<<" ";
    head=head->prev;
   }
}

int main(){
    // 10 20 30 40 50

    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    node* d = new node(40);
    node* e = new node(50);
    
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    e->prev=d;
    d->prev=c;
    c->prev=b;
    b->prev=a;

    Display(e);

}
