#include<iostream>
#include<vector>
using namespace std; 
int main(){
    // vector<int>v(10);
    vector< vector<int> >v; // Declaraton of 2D vectoe!!!
    int n;
    cout<<"Enetr the value of n: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        vector<int>a(i);
        v.push_back(a);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i) {
                v[i][j]=1;
            }
            else {
                 v[i][j]=v[i-1][j]+v[i-1][j-1];
        }
    }
        
    }
    
     for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        }
}
