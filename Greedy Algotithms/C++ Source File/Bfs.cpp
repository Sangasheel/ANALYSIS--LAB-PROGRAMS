#include <bits/stdc++.h>
using namespace std;

  vector<int> bfs(vector<int>adj[],int Source,int v){

    queue<int>q;
    q.push(Source);
  
    vector<int>ans; vector<bool>visited(v+1,false);
    visited[Source]=true;

    while(!q.empty()){

        int node=q.front();
        q.pop();

        //  if(visited[node]) continue;

        //    visited[node]=true;
           ans.push_back(node);

        for(auto it:adj[node]){

            int adjnode=it;
            if(!visited[adjnode]){

                visited[adjnode]=true;

                q.push(adjnode);
            }

        }

    }

    return ans;




  }
int main() {
    
    int v=7;
    int e=9;


    vector<int>adj[v+1];

     adj[5].push_back(1);
     adj[1].push_back(5);

     adj[5].push_back(4);
     adj[4].push_back(5);

     adj[4].push_back(1);
     adj[1].push_back(4);

     adj[1].push_back(2);
     adj[2].push_back(1);

     adj[4].push_back(2);
     adj[2].push_back(4);

      adj[3].push_back(2);
      adj[2].push_back(3);

      adj[3].push_back(4);
      adj[4].push_back(3);

      adj[3].push_back(6);
      adj[6].push_back(3);

       adj[6].push_back(2);
       adj[2].push_back(6);
       

      vector<int>ans= bfs(adj,5,v);

      for(auto it :ans){
        cout<<it<<" ";
      }



    return 0;
}