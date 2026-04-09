#include <bits/stdc++.h>
using namespace std;
// Adjacency list representation of a Graph 


int main() {

    int vertices;

    cout<<"No of vertices  "<<endl;

    cin>>vertices;
    vector<int>adj[vertices+1];

    cout<<"No of Edges "<<endl;

    int edges;

    cin>>edges;



    for(int i=0;i<edges;i++){

        cout<<"Enter edge"<<endl;

        int v1,v2;

        cin>>v1>>v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);


    }

    for(int i=1;i<vertices;i++){

        cout<<i<<"-> ";

        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;

        
    }

    

    return 0;
}