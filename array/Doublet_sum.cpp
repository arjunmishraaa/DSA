#include<iostream>
#include<vector>
using namespace std;
int main(){
   vector<int>v;
   v.push_back(1);
   v.push_back(3);
   v.push_back(2);
   v.push_back(4);
   v.push_back(3);
   v.push_back(4);
   v.push_back(1);
   v.push_back(6);
   int cnt=0;
   for(int i=0; i<v.size()-1; i++){
    for(int j=i+1;j<v.size(); j++){
        if((v[i]+v[j])==7) cnt++;
    }
}
 cout<<cnt;
}