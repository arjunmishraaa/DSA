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
      
      int cnt=1; 

        for(int i=0;i<m;){
            for(int j=0; j<n;){
                if(i%2==0){
                    a[i][j]=cnt;
                    cnt++;
                    j++;
                    
                }
                if(j>n-1 && i%2==0){
                    i++;
                    j--;
                    a[i][j]=cnt;
                    cnt++;
                }
                
                if(i%2!=0){
                    a[i][j]=cnt;
                    cnt++;
                    j--;
                }
                 if(j<0 && i%2!=0){
                    j--;
                    i++;
                    a[i][j]=cnt;
                    cnt++;
                }

            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }


    }
    