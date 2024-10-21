#include<iostream>
using namespace std;
int main(){
    int n,m,a,b,k;
    cin>>n>>m;
    int a[m],b[m];
     for(int j=0; j<n; j++){
        for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
     for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
     
    for(int i=0; i<m;i++){
        if(a[i]!=b[i]) k++;
    }
    }
    
}