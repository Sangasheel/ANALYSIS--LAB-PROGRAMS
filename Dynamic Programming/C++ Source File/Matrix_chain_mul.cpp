#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>Matrix_chain(vector<vector<int>>&M,vector<int>&Order,int n){
 
   
    int j=0;
    for(int i=1;i<=n;i++){
        M[i][i]=0;
    }

    vector<vector<int>>S(n+1,vector<int>(n+1,0));

    for(int l=2;l<=n;l++){

        for(int i=1;i<=n-l+1;i++){

            j=i+l-1;

            for(int k=i;k<=j-1;k++){

                int q = M[i][k] + M[k+1][j] + Order[i-1]*Order[k]*Order[j];

                if(M[i][j] >q){
                    
                    M[i][j]=q;
                    S[i][j]=k;
                }
            }

        }


    }

    return S;

}

void print_Parenthesis(int i, int j, vector<vector<int>>& S) {
    
    if(i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";

    print_Parenthesis(i, S[i][j], S);      
    print_Parenthesis(S[i][j] + 1, j, S);   

    cout << ")";
}


int main() {
    
    int n=5;
    vector<int>Order={2,4,2,5,6,2};
    vector<vector<int>>M(n+1,vector<int>(n+1,INT_MAX));


     vector<vector<int>> S = Matrix_chain(M, Order, n);

    cout << "Minimum multiplications: " << M[1][5] << endl;

    cout << "Optimal Parenthesization: ";
    print_Parenthesis(1, 5, S);


    return 0;
}