#include<iostream>
using namespace std;
int main(){
    int arr[9]={1,2,4,5,9,15,18,21,23};
    int n=9;
    int x=20;
    int lo=0;
    int hi=8;
    for(int i=0;i<n;++i){
        int mid=(lo+hi)/2;
        if(arr[mid]==x) {
            cout<<arr[mid]<<"  ";
            break;
        }
        else if(arr[mid]<x) lo=mid+1;
        else if(arr[mid]>x && arr[mid-1]<x) {
            cout<<arr[mid-1 ]<<"  ";
            break;
        }
        else hi=mid-1;
    }
}
