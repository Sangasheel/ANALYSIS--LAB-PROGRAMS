#include <bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

int Sum(int n){

    if(n==1)return 1;
    return n+Sum(n-1);
   

}

int main() {

    ofstream file("sum_time2.csv");
    file<<" n,time\n";
     
     int repeats=1000;

    for(int n=1000;n<=20000;n+=2000){

        
        auto start=high_resolution_clock::now();

        for(int i=0;i<repeats;i++){

            Sum(n);
        }
        

        auto end=high_resolution_clock::now();

        auto time=duration_cast<microseconds>(end-start).count()/repeats;

        file<<n<<","<<time<<"\n";

        cout<<"Run for n ="<<n<<endl;



    }

    cout<<"CSV file generated suessfully "<<endl;

    file.close();
    

    

    return 0;
    
}