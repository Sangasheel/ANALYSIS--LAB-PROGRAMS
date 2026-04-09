#include <bits/stdc++.h>
using namespace std;

int Count;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* newnode = new Node(val);
        return newnode;
    } else if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void traverse(Node* root,int x ,int y ) {


    if (root==NULL) return ;

    if(root->data>=x&&root->data<=y){

        Count++;   

    }
    traverse(root->left,x,y);
    traverse(root->right,x,y);

}



int main() {
    Node* root = NULL;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int val : a)
        root = insert(root, val);


     int x,y;
     cout<<"Enter Range [x,y]"<<endl;
     cin>>x>>y;


     Count=0;
    traverse(root,x,y);

    cout<<"Total "<<Count<<" Elements in Range "<<endl;


   
    return 0;
}