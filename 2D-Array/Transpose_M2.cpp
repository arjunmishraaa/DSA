#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
int a[n][m];
int b[m][n];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
cout<<endl<<"the transpose is:"<<endl;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(i<=j) { 
        int temp=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=temp;
       }
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
}
}