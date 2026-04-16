#include <bits/stdc++.h>
using namespace std;


int Minsum(vector<pair<int,int>>adj[],int Source,int Sink,int n,vector<int>&dist,vector<int>&parent){


    dist[Sink]=0;
    int Wt=0;

    

    dist[Sink]=0;
    

    for(int i=Sink-1;i >=Source ;i--){
        

        int node=i;

        for(auto it : adj[node]){

            int adjnode=it.first;
            int Edgewt= it.second;

           if (Edgewt + dist[adjnode] < dist[node]) {

            dist[node] = Edgewt + dist[adjnode];
            parent[node] = adjnode;

            }
        }


    }

   
return dist[Source];

}


void printpath(vector<int>&parent,int Source,int Sink){


    while(Source!=Sink){
 
        cout<<Source<<" -> ";
        Source = parent[Source];

    }
    cout<<Sink;

}



int main() {
    

   int n=7;

   vector<pair<int,int>>adj[n];

   vector<int>dist(n,INT_MAX);

   vector<int>parent(n);

    for(int i=1;i<n;i++){

        parent[i]=i;

    }


   adj[1].push_back({2,3});
   adj[1].push_back({3,4});
   adj[2].push_back({4,5});
   adj[3].push_back({4,6});
   adj[4].push_back({5,7});
   adj[5].push_back({6,1});

   Minsum(adj,1,6,n,dist,parent);

   cout<<dist[1]<<endl;

   printpath(parent,1,6);


    return 0;
}