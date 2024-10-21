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

    //10 20 30 40
    Node* a= new Node (10);
    Node* b= new Node (20);
    Node* c= new Node (30);
    Node* d= new Node (40);
    
     //LINKING NODE USING NODE-POINT METHOD;
    a->next=b;
    b->next=c;
    c->next=d;

    
    // Node* temp=a;
//    while(temp.next!=NULL){  //Last NOde will not get printed;
//     cout<<temp.val<<" ";
//       temp=*(temp.next);
//    }

//     cout<<"\n";
//    while(1){  
//     cout<<temp->val<<" ";
//     if(temp->next==NULL) break;
//       temp=temp->next;
//    }


cout<<a->val<<" ";
cout<<a->next->val<<" ";
cout<<a->next->next->val<<" ";
cout<<a->next->next->next->val<<" ";

    
    
}
