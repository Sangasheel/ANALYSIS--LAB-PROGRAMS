#include <bits/stdc++.h>
using namespace std;


void mul2x2(vector<vector<int>>&a,vector<vector<int>>&b,vector<vector<int>>&c,int i,int j){




    c[i][j] = (a[i][j]*b[i][j]) + (a[i][j+1]*b[i+1][j]);

    c[i][j+1] = (a[i][j]*b[i][j+1]) + (a[i][j+1]*b[i+1][j+1]);

    c[i+1][j] = (a[i+1][j]*b[i][j]) +(a[i+1][j+1]*b[i+1][j]);

    c[i+1][j+1] =(a[i+1][j]*b[i][j+1]) + (a[i+1][j+1]*b[i+1][j+1]);



}


void Matrix_mul(vector<vector<int>>&a,vector<vector<int>>&b,vector<vector<int>>&c,int i,int j,int n){


  if(n==2){

    mul2x2(a,b,c,i,j);

    return;

  }

  int half=n/2;

  for(int di=0;di<n;di+=half){

    for(int dj=0;dj<n;dj+=half){

      Matrix_mul(a,b,c,i+di,j+dj,half);

    }


  }



}
void Matrix_multiplication_iteration(vector<vector<int>>&a,vector<vector<int>>&b,vector<vector<int>>&c,int n){


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            c[i][j]=0;
            for(int k=0;k<n;k++){

                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }




}



int main() {


    vector<vector<int>>a=
    {               
      
        {1,2,3,4},
        {0,2,5,3},
        {3,2,1,1},
        {1,3,4,5}

    };

      vector<vector<int>>b=
    {               
      
        {1,2,3,4},
        {4,5,2,3},
        {7,3,2,1},
        {3,3,4,1}

    };

    int n=4;

    vector<vector<int>>c(n,vector<int>(n,0));
    vector<vector<int>>C(n,vector<int>(n,0));

    Matrix_multiplication_iteration(a,b,C,n);

    cout<<"Iteration"<<endl;

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    Matrix_mul(a,b,c,0,0,n);

    cout<<"Recursive"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }





    


    return 0;
}