#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std;
using namespace std::chrono;
bool LinearSearch(vector<int>&a,int i,int key,int n){
    
    if(i>=n) return false;
    if(a[i]==key){
        return true;
    }
    return LinearSearch(a,i+1,key,n);

}
int main() {

    ofstream file1("linear_best_case.csv");
    ofstream file2("linear_worst_case.csv");
    
    file1<<"n,time"<<endl;
    file2<<"n,time"<<endl;

     int repeat=1000;


    for(int n=1000;n<=50000;n+=5000){

        vector<int>a(n);

        for(int i=0;i<n;i++){
            a[i]=rand();
        }

        int bestindex=a[0];

        auto start1 = high_resolution_clock::now();

        for(int i=0;i<repeat;i++){

            LinearSearch(a, 0, bestindex, n);
        }
        
        auto end1 = high_resolution_clock::now();
        auto bestTime = duration_cast<nanoseconds>(end1 - start1).count()/repeat;

         file1 << n << "," << bestTime << "\n";


        int worstindex = -1;

        auto start2 = high_resolution_clock::now();
        
        for(int i=0;i<repeat;i++){

               LinearSearch(a, 0, worstindex, n);

        }
       
        auto end2 = high_resolution_clock::now();
        auto worstTime = duration_cast<nanoseconds>(end2 - start2).count()/repeat;

          file2 << n << "," << worstTime << "\n";



    }

    file1.close();
    file2.close();


    
    return 0;
}