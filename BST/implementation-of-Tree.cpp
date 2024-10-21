#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val){
       this->val=val;
       this->left=nullptr;
       this->right=nullptr;
    }
};

void displayTree(Node* root){
        if(root==nullptr) return;
        cout<< root->val <<" ";
        displayTree(root->left);
        displayTree(root->right);

    }

int SumNode(Node* root){
    if(root==nullptr) return 0;
    return root->val + SumNode(root->left) + SumNode(root->right);
}

int Size(Node* root){
    if(root==nullptr) return 0;
   return 1+Size(root->left) + Size(root->right);

}
int main(){
    Node* a =new Node(1);
    Node* b =new Node(2);
    Node* c =new Node(3);
    Node* d =new Node(4);
    Node* e =new Node(5);
    Node* f =new Node(6);
    Node* g =new Node(7);

    a->left=b; //1
    a->right=c;//2

    b->left=d;//3
    b->right=e;//4

    c->left=f;
    c->right=g;

    displayTree(a);
    cout<<endl;
    cout<<SumNode(a);
    cout<<endl;
    cout<<Size(a);

}
