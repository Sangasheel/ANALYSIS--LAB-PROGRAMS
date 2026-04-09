#include <bits/stdc++.h>
using namespace std;



int  Prims(vector<pair<int,int>>adj[],vector<pair<int,int>>&Mst,int Source,int Vertex){


    int Sum=0;

    vector<bool>Visited(Vertex+1,false);


    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({0,Source,-1});

    while(!pq.empty()){

        auto it=pq.top();

        int wt=it[0];
        int node=it[1];
        int parent=it[2];

        pq.pop();
 
        if(Visited[node]) continue;

        Visited[node]=true;

        if(parent!=-1){

            Sum=Sum+wt;

            Mst.push_back({node,parent});

        }

        for(auto it:adj[node]){

            

          int adjnode=it.first;
          int edgewt=it.second;

          if(!Visited[adjnode]){

             pq.push({edgewt,adjnode,node});


          }

         

        }

        

    }

    return Sum;




}
int main() {

    int vertices=6;

    vector<pair<int,int>>adj[vertices+1];

    adj[5].push_back({4,9});                
    adj[4].push_back({5,9});      

    adj[1].push_back({5,4});
    adj[5].push_back({1,4});


    adj[1].push_back({2,2});
    adj[2].push_back({1,2});

    adj[2].push_back({6,7});
    adj[6].push_back({2,7});

    adj[6].push_back({3,8});
    adj[3].push_back({6,8});

    adj[3].push_back({4,5});
    adj[4].push_back({3,5});

    adj[1].push_back({4,1});
    adj[4].push_back({1,1});

    adj[2].push_back({4,3});
    adj[4].push_back({2,3});

    adj[2].push_back({3,3});
    adj[3].push_back({2,3});

    


    vector<pair<int,int>>MST;

    int Source=5;

    int sum =Prims(adj,MST,5,vertices);

    


       cout<<"MST "<<endl;

        for(auto it:MST){

            cout<<"("<<it.first<<","<<it.second<<")";


        }



        cout<<"\nMinimum Sum "<<sum<<endl;

    

    



    return 0;
}