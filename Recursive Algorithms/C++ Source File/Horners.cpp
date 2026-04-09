#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int Horners(vector<int>& a, int i, int x) {

  
    if (i == a.size() - 1)
        return a[i];

  
    return a[i] + x*Horners(a, i + 1, x);
}


int main() {


    ofstream file("Horners.csv");
     
    file<<"n,time"<<endl;

    int x=5;

    for(int n=10;n<=200;n+=20){

        vector<int>a(n);

        for(int i=0;i<n;i++){
            a[i]=rand();
        }

        int repeat=1000;

       

        auto start = high_resolution_clock::now();

         for(int i=0;i<repeat;i++){

            Horners(a,0,x);
        }

        auto end=high_resolution_clock::now();


        auto time = duration_cast<microseconds>(end-start).count();

        file<<n<<","<<time<<endl;

        cout<<"Completeted for n="<<n<<endl;



        




    }

    cout<<"CSV file Generated Sucessfully "<<endl;

    file.close();

    
    return 0;
}