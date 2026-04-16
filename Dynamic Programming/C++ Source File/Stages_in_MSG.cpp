#include <bits/stdc++.h>
using namespace std;

 int Stages(vector<pair<int,int>>adj[],int Source,int Sink ){

      stack<int>st;
      st.push(Source);
      int stages=0;


      while(!st.empty()){


        int node=st.top();
        st.pop();
        stages++;

        if(node==Sink) break;

        for(auto it: adj[node]){

            int adjnode=it.first;
            st.push(adjnode);

        }
      }

      return stages;



 }

int main() {
    

//    int n=7;
  int v,e;
  cout<<"Enter no of vertices "<<endl;
  cin>>v;
  cout<<"Enter no of edges"<<endl;
  cin>>e;

   vector<pair<int,int>>adj[v+1];

//    adj[1].push_back({2,3});
//    adj[1].push_back({3,4});
//    adj[2].push_back({4,5});
//    adj[3].push_back({4,6});
//    adj[4].push_back({5,7});
//    adj[5].push_back({6,1});

  for(int i=0;i<e;i++){

    int n1;
    int n2;
    int wt;
    cout<<"Enter node 1 node2 edge wt "<<endl;
    cin>>n1>>n2>>wt;

    adj[n1].push_back({n2,wt});

  }

  

   cout<<"No of Stages "<< Stages(adj,1,6);



    return 0;
}