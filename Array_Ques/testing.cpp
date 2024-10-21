#include<iostream>
using namespace std;
int swap(int &a,int &b){
    int temp=a;
    a=b;
    b= temp;
}
int main(){
    int a=5,b=9;
    swap(a,b);
    cout<<a<<" "<<b;
}