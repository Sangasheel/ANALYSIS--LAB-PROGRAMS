#include <bits/stdc++.h>
using namespace std;

void search(int a[],int low,int high,int&Min,int&Max){

    if(low>high){
        return ;
    }

    int mid=(low+high)/2;
    Min=min(a[mid],Min);
    Max=max(a[mid],Max);

    search(a,low,mid-1,Min,Max);
    search(a,mid+1,high,Min,Max);



}



int main() {

    int n;
    cout<<"Enter size "<<endl;
    cin>>n;
    int a[n];
    
    cout<<"Enter elements "<<endl;

    for(int i=0;i<n;i++){
        cin>>a[i];


    }
    
     int  Max=INT16_MIN;
      int  Min=INT16_MAX;

    search(a,0,n-1,Min,Max);

    cout<<"Min "<<Min<<endl;
    cout<<"Max "<<Max<<endl;

    return 0;

}

