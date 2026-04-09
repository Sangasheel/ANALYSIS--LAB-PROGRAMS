#include <bits/stdc++.h>
using namespace std;


int partition(vector<int>&a,int st, int end){
    

    int val=a[st];

    int min_cnt=0;


    for(int i=st;i<=end;i++){

        if(a[i]<val){
            min_cnt++;
        }

    }
    swap(a[st],a[st+min_cnt]);

    int pindex=st+min_cnt;
    int left=st;
    int right=end;

    while(left<=pindex&&right>=pindex){


        while(a[left]<=a[pindex]){
              
            left++;
        }

        while(a[right]>a[pindex]){
            right--;
        }

        if(left<pindex&&right>pindex){
            swap(a[left],a[right]);left++;
            right--;
        }

    }

    return pindex;




}

void qs(vector<int>&a,int st,int end){


    if(st<end){

        int pindex=partition(a,st,end);
        qs(a,st,pindex-1);
        qs(a,pindex+1,end);


    }



}

int main() {


     vector<int> a = {5, 4, 3, 2, 1};

    qs(a, 0, a.size() - 1);

    for (auto it : a) {
        cout << it << " ";
    }

    return 0;
    


    return 0;
}