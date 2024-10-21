#include<iostream>
#include<vector>
using namespace std;
int sort(vector<int>&v){
    int i=0,j=v.size()-1;
   while(i<j)
   {
        if(v[i]==0) i++;
        if(v[j]==1) j--;
        if(v[i]==1 && v[j]==0){
            v[i]=0;
            v[j]=1;
            i++;
            j--;
        }
   }
     for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
      sort(v);
}
