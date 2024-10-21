#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    int x;
    bool flag=false;
    cin>>x;
    for(int i=0; i<n ;i++)
    {
       if(x==arr[i]) flag=true;
    }
    if(flag==true) cout<<"Yes Element is present";
}