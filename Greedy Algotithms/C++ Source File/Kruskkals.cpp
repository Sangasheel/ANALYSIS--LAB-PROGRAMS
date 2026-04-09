#include <bits/stdc++.h>
using namespace std;


// if  bfs(node1) == bfs(node2) then node1 and node2 are present 
// not present


  bool bfs(vector<pair<int,int>>adj[],int Source,int v,int target){



    queue<int>q;
    q.push(Source);

    vector<bool>visited(v+1,false);
    visited[Source]=true;

    while(!q.empty()){

        int n=q.front();
        q.pop();


        if(n==target)  return true;

        for(auto it:adj[n]){

            int adjnode=it.first;
            if(!visited[adjnode]){

                visited[adjnode]=true;

                q.push(adjnode);
            }

        }

    }


    return false;



  }

  bool exists(vector<pair<int,int>>adj[],int v ,int v1,int v2){
     
    return bfs(adj,v1,v,v2);

  }


  void Krushkal(vector<pair<int,int>>adj[],int v,int Source){


    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;


    for(int i=1;i<v;i++){

        for(auto it:adj[i]){

           pq.push({it.second,i,it.first});
           
        }


    }

    vector<pair<int,int>>MST[v+1];

    

    while(!pq.empty()){


        auto it=pq.top();

        int wt=it[0];
        int node1=it[1];
        int node2=it[2];

        pq.pop();

       

        if(!exists(MST,v,node1,node2)){

            MST[node1].push_back({node2,wt});
            MST[node2].push_back({node1,wt});

        }

        
    }


    for(int i=1;i<v;i++){
        cout<<i<<"->";
        for(auto it:MST[i]){
            cout<<it.first<<" ";
        }
        cout<<endl;
    }


  }





int main() {

      int v=7;
    int e=9;


    vector<pair<int,int>>adj[v+1];

     adj[5].push_back({1,4});
     adj[1].push_back({5,4});

     adj[5].push_back({4,9});
     adj[4].push_back({5,9});

     adj[4].push_back({1,1});
     adj[1].push_back({4,1});

     adj[1].push_back({2,2});
     adj[2].push_back({1,2});

     adj[4].push_back({2,3});
     adj[2].push_back({4,3});

      adj[3].push_back({2,3});
      adj[2].push_back({3,3});

      adj[3].push_back({4,5});
      adj[4].push_back({3,5});

      adj[3].push_back({6,8});
      adj[6].push_back({3,8});

       adj[6].push_back({2,7});
       adj[2].push_back({6,7});
       

    //    if(bfs(adj,5,v,7)==true){
    //     cout<<"present ";
    //    }
    //    else{
    //     cout<<"not present "<<endl;
    //    }

    // if(exists(adj,5,v,1,7)){cout<<"true";} 
    // else {cout<<"false";}

    Krushkal(adj,v,5);




    
    return 0;
}