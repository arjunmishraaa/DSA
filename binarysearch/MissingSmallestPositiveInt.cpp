#include<iostream>
using namespace std;
int main(){
    int a[]={0,1,3,4,6,7,8,9,11};
    int n=9;
    // for(int i=0;i<n;i++){
    //     if(a[i]!=i) {
    //     cout<<"The smallest missing number is "<<i<<endl;
    //     break;
    //     }
    // }USING BINARY SEARCH ALGORITHM::::

    int low=0;
    int high=n-1;
    for(int i=0;i<n;i++){
        int mid=low+(high-low)/2;
        if(a[mid]==mid) low=mid+1;
        else if(a[mid]>mid) high=mid-1;
        if((a[mid]!=mid) && (a[mid-1]==(mid-1))) {
            cout<<mid<<endl;
            break;
        }
    }



    
}