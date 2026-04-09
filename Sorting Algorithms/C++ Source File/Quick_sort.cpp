#include <bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

int Partition(vector<int>&a,int low ,int high){


    int pivot=a[low];

    int cnt=0;

    for(int i=low+1;i<=high;i++){
        if(a[i]<pivot){
            cnt++;
        }
    }
   int pindex=cnt+low;
    swap(a[low],a[pindex]);
  
     int i=low; int j=high;

    while(i<pindex&&j>pindex){

        while(a[i]<pivot){
            i++;
        }

        while(a[j]>pivot){
            j--;
        }

        if(i<pindex&&j>pindex){

            swap(a[i],a[j]);
            i++;
            j--;

        }
        




    }
    
  return pindex;

}

void Quick_Sort(vector<int>&a,int low,int high){

    if(low<high){

       
      int pindex=Partition(a,low,high);
       Quick_Sort(a,low,pindex-1);
       Quick_Sort(a,pindex+1,high);


    }



}


int main() {

    
     ofstream file("Quicksort.csv");

     file<<"n,time\n";

     for(int n=100;n<=5000;n+=500){

          
           vector<int>a(n);

        for(int i=0;i<n;i++){

            a[i]=rand();
        }
        int repeat =1000;
    
          auto start=high_resolution_clock::now();

        for(int i=0;i<repeat;i++){

            Quick_Sort(a,0,n-1);

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