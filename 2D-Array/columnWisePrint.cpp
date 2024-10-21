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
     
     int minc=0;
     int maxc=n;
     int minr=0;
     int maxr=n;
        
       while(maxc>minc && minr<maxr){
        for(int i=minc; i<maxc ; i++){
            cout<<a[minr][i]<<" ";
        }
        minr++;
         for(int i=minr; i<maxr ; i++){
            cout<<a[i][maxc-1]<<" ";
        }
        maxc--;
         for(int i=maxc-1; i>=minc ; i--){
            cout<<a[maxr-1][i]<<" ";
        }
        maxr--;
         for(int i=maxr-1; i>=minr; i--){
            cout<<a[i][minc]<<" ";
        }
        minc++;
       }


    }
    