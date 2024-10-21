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
        b[j][i]=a[i][j];
    }
}
cout<<endl<<"the transpose is:"<<endl;
for(int i=0;i<m;i++){
    for(int j=0;j<n1;j++){
      cout<<b[i][j]<<" ";
    }
    cout<<endl;
}
}