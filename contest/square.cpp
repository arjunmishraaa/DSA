#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[4];
    int b[4];
    int k;
    for(int j=0; j<n; j++){
        for(int i=0; i<4; i++)
    {
        cin>>a[i]>>b[i];
    }
     for(int j=0; j<4; j++){
        for(int i=j+1; i<4; i++)
    {
        if(a[j]==a[i]|| b[j]==b[i])
        {
           k=sqrt((a[i]-a[j])*(a[i]-a[j]) + (b[i]-b[j])*(b[i]-b[j]));
        }
    }
    }
    cout<<k*k<<endl;
    }
    
   
}