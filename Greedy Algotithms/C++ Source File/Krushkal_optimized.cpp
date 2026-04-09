#include <bits/stdc++.h>
using namespace std;

// =====================
//    DISJOINT SET
// =====================

vector<int> parent, rank_;

void init(int v){
    parent.resize(v+1);
    rank_.resize(v+1, 0);
    for(int i = 1; i <= v; i++){
        parent[i] = i;  // every node is its own parent initially
    }
}

int find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]);  // path compression
    return parent[x];
}

bool unionNodes(int x, int y){
    int px = find(x);
    int py = find(y);

    if(px == py) return false;  // same component = cycle!

    if(rank_[px] < rank_[py])       parent[px] = py;
    else if(rank_[px] > rank_[py])  parent[py] = px;
    else{
        parent[py] = px;
        rank_[px]++;
    }

    return true;
}

// =====================
//    KRUSKAL
// =====================

void Kruskal(vector<pair<int,int>> adj[], int v){

    // push all edges into min heap

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    for(int i = 1; i <= v; i++){
        for(auto it : adj[i]){
            pq.push({it.second, i, it.first});  // {weight, node1, node2}
        }
    }

    vector<pair<int,int>> MST;
    int sum = 0;

    while(!pq.empty()){

        auto it = pq.top();
        pq.pop();

        int wt    = it[0];
        int node1 = it[1];
        int node2 = it[2];

        // if no cycle → add edge to MST
        if(unionNodes(node1, node2)){
            MST.push_back({node1, node2});
            sum += wt;
        }

    }

    // print MST
    cout << "MST Edges:" << endl;
    for(auto it : MST){
        cout << "(" << it.first << "," << it.second << ")" << endl;
    }
    cout << "Minimum Sum: " << sum << endl;

}

// =====================
//       MAIN
// =====================

int main() {

    int v = 6;

    vector<pair<int,int>> adj[v+1];

    adj[5].push_back({1,4});   adj[1].push_back({5,4});
    adj[5].push_back({4,9});   adj[4].push_back({5,9});
    adj[4].push_back({1,1});   adj[1].push_back({4,1});
    adj[1].push_back({2,2});   adj[2].push_back({1,2});
    adj[4].push_back({2,3});   adj[2].push_back({4,3});
    adj[3].push_back({2,3});   adj[2].push_back({3,3});
    adj[3].push_back({4,5});   adj[4].push_back({3,5});
    adj[3].push_back({6,8});   adj[6].push_back({3,8});
    adj[6].push_back({2,7});   adj[2].push_back({6,7});

    init(v);  // initialize disjoint set

    Kruskal(adj, v);

    return 0;
}

// ## Time Complexity

// **Operation 1: `init()`**
// ```
// loop runs V times → O(V)
// Running Total: O(V)
// ```

// **Operation 2: Building min heap**
// ```
// each edge pushed once (we do 2E pushes for undirected)
// each push costs O(log E) → O(E log E)
// Running Total: O(V) + O(E log E)
// ```

// **Operation 3: `while(!pq.empty())`**
// ```
// runs 2E times → O(E)
// Running Total: O(V) + O(E log E) + O(E)
// ```

// **Operation 4: `pq.top()` and `pq.pop()`**
// ```
// O(log E) per call, called 2E times → O(E log E)
// Running Total: O(V) + O(E log E) + O(E) + O(E log E)
// ```

// **Operation 5: `unionNodes()` → calls `find()` twice**
// ```
// find() with path compression → O(α(V)) ≈ O(1)
// called 2E times → O(E)
// Running Total: O(V) + O(E log E) + O(E) + O(E log E) + O(E)
// ```

// **Operation 6: `MST.push_back()`**
// ```
// happens V-1 times → O(V)
// Running Total: O(V) + O(E log E) + O(E) + O(E log E) + O(E) + O(V)
// ```

// ### Summing Up
// ```
// O(V)          ← init
// + O(E log E)  ← building heap
// + O(E)        ← while condition
// + O(E log E)  ← pq.top() and pq.pop()
// + O(E)        ← unionNodes
// + O(V)        ← MST push
// ──────────────────────────────────────
// = O(2V) + O(2E logE) + O(2E)
// = O(V)  + O(E log E) + O(E)  ← drop constants

// O(V) and O(E) drop as smaller than O(E log E)
// ```

// ### ✅ TC Final: **O(E log E)**

// ---

// ## Space Complexity
// ```
// O(V + E)   ← adjacency list
// + O(V)     ← parent array
// + O(V)     ← rank array
// + O(E)     ← priority queue
// + O(V)     ← MST storage
// ─────────────────────────────
// = O(V + E) + O(3V) + O(E)
// = O(4V + 2E)  ← drop constants
// = O(V + E)