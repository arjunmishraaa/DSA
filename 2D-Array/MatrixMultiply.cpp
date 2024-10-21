#include<iostream>
using namespace std; 
int main(){
    int m;
    cout<<"enter the row of 1st matrix: ";
    cin>>m;

    int n;
    cout<<"enter the cols of 1st matrix: ";
    cin>>n;

    int p;
    cout<<"enter the row of 2nd matrix: ";
     cin>>p;

    int q;
    cout<<"enter the cols of 2nd matrix: ";
    cin>>q;

    if(n==p){
        int a[m][n];
        int b[p][q];
        cout<<"Enter the elements of first matrix";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                cin>>b[i][j];
            }
        }

        int res[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){

                for(int k=0; k<n ;k++){
                    res[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }



    }else{
        cout<<"Can't multiplied";
    }
}