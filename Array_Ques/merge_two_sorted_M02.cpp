#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sort(vector<int>&a,vector<int>&b, int n,int m){
    for(int i=0;i<m;i++){
        a.pop_back();
    }
   for(int i=0,j=0; i<n+m;){
    if(i==m) a.push_back(b[j++]);
    if(a[i]<=b[j]){
        a.push_back(a[i++]);
        }
    else a.push_back(b[j++]);
    }
    return a;
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
    sort(v1,v2,n,m);  
    for(int i=0; i<n;i++){
        cout<<v1[i]<<" ";
    }
}
 