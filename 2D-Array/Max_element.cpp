#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
int arr[n][m];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
}
int max=arr[0][0];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]>max) max=arr[i][j];
    }
}
cout<<"The maximum num is: "<<max<<endl;

int sum=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        sum+=arr[i][j];
    }
}
cout<<"The sum of all element in matrix is :"<<sum;
}