#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enetr the value of n: ";
    cin>>n;
    int a[n][n];
    for(int i=0; i<n ;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
        int target;
        cin>>target;
        int cnt=0;
   
    for (int i = 0, j = n - 1; i < n && j >= 0;) {
        if (a[i][j] == target){
             cnt++; break;
        }
         if (a[i][j] > target)  j--;
         else  i++;
    }

    if(cnt==0) cout<<"False";
    else cout<<"True";

}