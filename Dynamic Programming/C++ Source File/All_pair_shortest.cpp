#include <bits/stdc++.h>
using namespace std;
#define inf 999
void print_matrix(vector<vector<int>>&W){


    for(int i=1;i<W[0].size();i++){

        for(int j=1;j<W[i].size();j++){

            if(W[i][j]==inf){
                cout<<"INF ";
            }

            else{

                cout<<W[i][j]<<"  ";

            }

            
        }

        cout<<endl;

    }
    cout<<endl;

}
void Floyd_Warshall(vector<vector<int>>&adj,int v){

    vector<vector<int>>W(v,vector<int>(v));

    for(int i=1;i<v;i++){
        for(int j=1;j<v;j++){
            W[i][j]=adj[i][j];
        }
    }

    for(int k=1;k<v;k++){

        for(int i=1;i<v;i++){

            for(int j=1;j<v;j++){

                
                W[i][j]=min(W[i][j],W[i][k]+W[k][j]);


            }
            
            

        }

           cout<<"Intermidiate via "<<k<<endl;
            print_matrix(W);


    }
    
   
}



int main() {
   
    int v=4;

    vector<vector<int>>adj(v+1,vector<int>(v+1,inf));


    for(int i=1;i<v+1;i++){
        
        adj[i][i]=0;

    }
  

    adj[1][2]=3;
    adj[2][1]=2;
    adj[1][4]=5;
    adj[4][3]=2;
    adj[3][2]=1;
    adj[2][4]=4;

    print_matrix(adj);

    Floyd_Warshall(adj,v+1);

  


    return 0;


}