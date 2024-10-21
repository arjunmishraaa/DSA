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
   int a,b;
   cin>>a>>b;
  for(int i=a,j=(b); i<b; ){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
  for(int i=0; i<n ;i++){
   cout<<v[i]<<" ";
   }
}
 