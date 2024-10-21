#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sort_012(vector<int>&v,int n){
    int zeros=0;
   int ones=0;
   int twos=0;
    for(int i=0; i<n ;i++){
        if(v[i]==0) zeros++;
        if(v[i]==1) ones++;
        if(v[i]==2) twos++;
   cout<<v[i]<<" ";
   }

 cout<<endl;
  for(int i=0; i<n ;i++){
    if(i<zeros) v[i]=0;
    else if( i<(zeros+ones)) v[i]=1;
    else if (i<(ones+zeros+twos)) v[i]=2;
   }
   for(int i=0; i<n ;i++){
   cout<<v[i]<<" ";
   }
}
int swap(int &a,int &b){
    int temp=a;
    a=b;
    b= temp;
}
int sorting_012(vector<int>&v, int n){
    int i=0;
    int j=n;
    int k=0;
   while(k<=j){
       if(v[k]==2){
        swap(k,j);
        j--;
       }
      if(v[k]==0){
        swap(i,k);
        i++;
        k++;
      }
      if(v[k]==0) k++;
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
   sort_012(v,n);  
}
 