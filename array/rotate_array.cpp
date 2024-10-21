#include<iostream>
#include<vector>
using namespace std;
int rev(int i, int j, vector<int>&v){
   while(i<=j){
    int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
   }
}
int main(){
   vector<int>v;
   int n;
   cin>>n;
   for(int i=0; i<n ;i++){
    int x;
    cin>>x;
    v.push_back(x);
   }
   int k;
   cout<<"Enter the vakue of k:";
   cin>>k;
   if(k>v.size()) k=k%v.size();
  rev(0,v.size()-1-k,v);
  rev(v.size()-k,v.size()-1,v);
  rev(0,v.size()-1,v);
  for(int i=0; i<n ;i++){
   cout<<v[i]<<" ";
   }
}
 