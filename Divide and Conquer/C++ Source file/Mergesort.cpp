#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&a,int st,int mid,int end){

    int left=st;
    int right=mid+1;

    vector<int>temp;



     while(left<=mid&&right<=end){

        if(a[left]<=a[right]){

            temp.push_back(a[left]);
            left++;

        }
        else{
            temp.push_back(a[right]);
            right++;
        }

     }

     while(left<=mid){

        temp.push_back(a[left]); left++;

     }

     while(right<=end){
        temp.push_back(a[right]); right++;

     }
     int k=0;

     for(int i=st;i<=end;i++){

        a[i]=temp[k];
        k++;

     }



}

void ms(vector<int>&a,int st,int end){

     if(st>=end) return;

    int mid=(st+end)/2;


    ms(a,st,mid);
    ms(a,mid+1,end);
    merge(a,st,mid,end);

    
}

int main() {

    vector<int>a={5,4,3,2,1};

    ms(a,0,a.size()-1);

    for(auto it:a){
        cout<<it<<" ";
    }
    
    return 0;
}