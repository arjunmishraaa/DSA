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
     int cnt=1;
        
       while(maxc>minc && minr<maxr){
        for(int i=minc; i<maxc ; i++){
            a[minr][i]=cnt;
            cnt++;
        }
        minr++;
         for(int i=minr; i<maxr ; i++){
            a[i][maxc-1]=cnt;
            cnt++;
        }
        maxc--;
         for(int i=maxc-1; i>=minc ; i--){
            a[maxr-1][i]=cnt;
            cnt++;
        }
        maxr--;
         for(int i=maxr-1; i>=minr; i--){
            a[i][minc]=cnt;
            cnt++;
        }
        minc++;
       }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }


    }
    