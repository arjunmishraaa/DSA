#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val, Node* next=NULL){
            this->val=val;
            this->next=NULL;
        }
};

int main(){

    // 10 20 30 40
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    a.next=&b;
    b.next=&c;
    c.next=&d;

    // printing Using Arrow operator "-->" 
    cout<<a.val<<endl;
    cout<<(a.next->val)<<"\n";    
    cout<<(b.next->val)<<"\n";
    cout<<(c.next->val)<<"\n";

   // printing Using dot operator "." 
   cout<<"\n\n\n";

    cout<<a.val<<endl;
    cout<<((*a.next).val)<<"\n";    
    cout<<((*b.next).val)<<"\n";    
    cout<<((*c.next).val)<<"\n";   

   // printing Using head node:
   
   cout<<"\n\n\n";

   cout<<(a.val)<<"\n";
   cout<<((*a.next).val)<<"\n";
   cout<<((*((*a.next).next)).val)<<"\n";
   cout<<(((*(*((*a.next).next)).next)).val)<<"\n";
    
    
}
