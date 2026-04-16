#include <bits/stdc++.h>
using namespace std;


int Minsum(vector<pair<int,int>>adj[],int Source,int Sink,int n,vector<int>&dist,vector<int>&parent){



    dist[Source]=0;
    

    for(int i=Source;i <=Sink ;i++){
        

        int node=i;

        for(auto it : adj[node]){

            int adjnode=it.first;
            int Edgewt= it.second;

           if (Edgewt + dist[node] < dist[adjnode]) {

            dist[adjnode] = Edgewt + dist[node];
            parent[adjnode] = node;

            }
        }


    }

   
return dist[Sink];

}


void printpath(vector<int>&parent,int Source,int Sink){

   
    vector<int>ans;
    while(Sink!=Source){
 
       
         ans.push_back(Sink);
        Sink = parent[Sink];

    }

    ans.push_back(Source);

    reverse(ans.begin(),ans.end());


    for(auto it:ans){
        cout<<it<<"-> ";
    }
   

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

   cout<<dist[6]<<endl;

   printpath(parent,1,6);


    return 0;
}