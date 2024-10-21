#include<iostream>
using namespace std; 
int main(){
    int m;
    cout<<"enter the row of 1st matrix: ";
    cin>>m;

    int n;
    cout<<"enter the cols of 1st matrix: ";
    cin>>n;


 
        int a[m][n];
        cout<<"Enter the elements of first matrix";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
     
        
        for(int i=m-1;i>=0;i--){
           if(i%2!=0){
            for(int j=n-1;j>=0;j--){
                cout<<a[i][j]<<" ";
            }
           }else{
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
           }
            cout<<endl;
        }


    }
    