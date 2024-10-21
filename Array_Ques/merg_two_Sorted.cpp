#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sort(vector<int>&a,vector<int>&b, int n,int m){
   vector<int>v;
   for(int i=0,j=0; i<n+m;){
    if(i==n) v.push_back(b[j++]);
    if(j==m) v.push_back(a[i++]);
    else if(a[i]<=b[j]){
        v.push_back(a[i++]);
        }
    else v.push_back(b[j++]);
    }
    return v;
}
int main(){
   vector<int>v1;
   vector<int>v2;
   int n;
   cin>>n;
   for(int i=0; i<n ;i++){
    int x;
    cin>>x;
    v1.push_back(x);
   }
   int m;
   cin>>m;
    for(int i=0; i<m ;i++){
    int x;
    cin>>x;
    v2.push_back(x);
   }
    vector<int>v= sort(v1,v2,n,m);  
    for(int i=0; i<n+m;i++){
        cout<<v[i]<<" ";
    }
}
 