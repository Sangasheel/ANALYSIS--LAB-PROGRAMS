#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void merge(vector<int>&a,int low,int mid,int high){

    int t1=low;
    int t2=mid+1;


    vector<int>temp(high-low+1);
    int j=0;


    while(t1<=mid&&t2<=high){

        if(a[t1]<=a[t2]){

            temp[j]=a[t1];
            j++;
            t1++;

        }
        else{

            temp[j]=a[t2];
            j++;
            t2++;

        }

    }

    while(t1<=mid){

        temp[j]=a[t1];
        j++;
        t1++;

    }

    while(t2<=high){

        temp[j]=a[t2];
        j++;
        t2++;

    }

     j=0;

    for(int i=low;i<=high;i++){

        a[i]=temp[j];
        j++;

    }


}

void mergesort(vector<int>&a,int low,int high){

    if(low>=high){
        return;

    }
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);

}



int main() {

    

     ofstream file("Mergesort.csv");

     file<<"n,time\n";

     for(int n=100;n<=5000;n+=500){

          
           vector<int>a(n);

        for(int i=0;i<n;i++){

            a[i]=rand();
        }
        int repeat =1000;
    
          auto start=high_resolution_clock::now();

        for(int i=0;i<repeat;i++){

            mergesort(a,0,n-1);

        }
        auto end =high_resolution_clock::now();

        auto time = duration_cast<nanoseconds>(end-start).count();

        file<<n<<","<<time<<endl;

        cout<<"Completed for n"<<n<<endl;


     }

     cout<<"CSV file gennerated "<<endl;

     file.close();

    


    return 0;
}

