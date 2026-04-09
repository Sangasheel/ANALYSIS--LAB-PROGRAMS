#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstras(vector<pair<int,int>>adj[],int Source,vector<int>&dist,int V){

    vector<int>parent(V+1);

    for(int i=1;i<=V;i++){
        parent[i]=i;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,Source});

    dist[Source]=0;

    while(!pq.empty()){


        int node=pq.top().second;

        int wt=pq.top().first;

        pq.pop();

        for(auto it:adj[node]){

            int adjnode=it.first;

            int edgewt=it.second;

            if(wt+edgewt<dist[adjnode]){

                dist[adjnode]=wt+edgewt;

                pq.push({dist[adjnode],adjnode});

                parent[adjnode]=node;

            }

        }

    }

    return parent;



}

vector<int> printpath(vector<int>&parent,int Source,int Dest){

    vector<int>ans;

    while(Dest!=Source){
    
        ans.push_back(Dest);

        Dest=parent[Dest];


    }

    ans.push_back(Source);

    reverse(ans.begin(),ans.end());

    return ans;


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



    vector<int>dist(vertices+1,1e9);
    int Source=1;
 
    vector<int>parent=Dijkstras(adj,Source,dist,vertices);

    // for(auto it:parent){
    //     cout<<it<<" ";
    // }

    vector<int>path=printpath(parent,1,5);

    cout<<"Path "<<endl;


    for(auto it:path){

        cout<<it<<"->"<<" ";


    }





    
    return 0;
}