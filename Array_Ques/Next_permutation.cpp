#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void next_permutation(vector<int>&v){
    int n=v.size();
    int idx=-1;

    for(int i=n-2; i>=0 ; i--){
        if(v[i]<v[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        reverse(v.begin(),v.end());
    }
    int temp=v[idx];
    v[idx]=v[idx+1];
    v[idx+1]=temp;
    
    reverse(v.begin()+idx+1,v.end());
    
}
int main(){
   vector<int>v1;
   int n;
   cout<<"Enetr the number of digits of your no.: "<<endl;
   cin>>n;
   cout<<"Enter the number: "<<endl;
   for(int i=0;i<n ;i++){
    int x;
    cin>>x;
    v1.push_back(x);
   }
   next_permutation(v1);
    cout<<"The next permutation is: ";
    for(int j=0; j<n;j++){
        cout<<v1[j]<<" ";
    }
}
 