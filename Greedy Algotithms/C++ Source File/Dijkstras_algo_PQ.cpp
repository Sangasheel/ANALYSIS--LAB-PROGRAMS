#include <bits/stdc++.h>
using namespace std;

void Dijkstras(vector<pair<int,int>>adj[],vector<int>&dis,int Source){

    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;

    pq.push({0,Source});
     dis[Source]=0;


    while(!pq.empty()){

        int dist=pq.top().first;

        int node = pq.top().second;

        pq.pop();

        for(auto it:adj[node]){


            int adjnode=it.first;

            int edgeweight=it.second;

            if(dist+edgeweight<dis[adjnode]){

                dis[adjnode]=dist+edgeweight;

                pq.push({dis[node],adjnode});

            }

        }

    }



}

int main() {

    int vertices=5;
    int edges;


    vector<pair<int,int>>adj[vertices+1]; 


    adj[1].push_back({2,2});
    adj[2].push_back({1,2});

    adj[1].push_back({3,4});
    adj[3].push_back({1,4});

    adj[2].push_back({3,1});
    adj[3].push_back({2,1});

    adj[2].push_back({4,7});
    adj[4].push_back({2,7});

    adj[3].push_back({5,3});
    adj[5].push_back({3,3});

    adj[4].push_back({5,1});
    adj[5].push_back({4,1});
    
    
    // 1 based indexing 

    //priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;

     
    // for(int i=0;i<edges;i++){

    //     int weight;

    //     cout<<"Enter edge with edge weight "<<endl;

    //     int v1,v2;

    //     cin>>v1>>v2>>weight;

    //     adj[v1].push_back({v2,weight});
    //     adj[v2].push_back({v1,weight});


    // }

    vector<int>dist(vertices+1,INT_MAX);
    int Source=1;

   

    Dijkstras(adj,dist,Source);
    




    
    return 0;
}