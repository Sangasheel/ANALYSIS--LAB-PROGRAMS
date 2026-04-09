#include <bits/stdc++.h>
using namespace std;

void search(vector<int>&a,int st,int end,int &max,int &min){

    if(st>end)return;

    int mid=(st+end)/2;

    if(a[mid]<min){
        min=a[mid];
    }
    if(a[mid]>max){
        max=a[mid];
    }

    search(a,st,mid-1,max,min);
    search(a,mid+1,end,max,min);



}

int main() {

    int min=INT_MAX,max=INT_MIN;

    vector<int>a={1};
    search(a,0,a.size()-1,max,min);

    cout<<min<<max<<endl;

    
    return 0;
}