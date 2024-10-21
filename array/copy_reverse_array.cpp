#include<iostream>
#include<vector>
using namespace std;
int main(){
   vector<int>v;
   int n;
   cin>>n;
   for(int i=0; i<n ;i++){
    int x;
    cin>>x;
    v.push_back(x);
   }
 vector<int> v1;
 for(int i=0 ;i<n;i++){
    v1.push_back(v[n-i-1]);
    cout<<v1[i]<<" ";
 }   
}
 