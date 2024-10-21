#include<iostream>
using namespace std;
display(int a[]){
    for(int i=0; i<6;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int arr[6]={12,14,25,36,96,58};
    display(arr);
}