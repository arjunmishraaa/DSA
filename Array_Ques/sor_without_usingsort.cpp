#include<iostream>
#include<vector>
#include<algorithm>
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
   int zeros=0;
   int ones=0;
    for(int i=0; i<n ;i++){
        if(v[i]==0) zeros++;
        if(v[i]==1) ones++;
   cout<<v[i]<<" ";
   }

 cout<<endl;
  for(int i=0; i<n ;i++){
    if(i<zeros) v[i]=0;
    else v[i]=1;
   }
   for(int i=0; i<n ;i++){
   cout<<v[i]<<" ";
   }
}
 