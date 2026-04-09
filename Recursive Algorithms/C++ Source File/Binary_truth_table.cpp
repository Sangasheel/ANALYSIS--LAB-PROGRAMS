
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void generateTruthTable(vector<int> &arr, int i, int n)
{
    
    if (i == n)
    {
        for (int bit : arr)
           // cout << bit;
       // cout << endl;
        return;
    }


    arr[i] = 0;
    generateTruthTable(arr, i + 1, n);

    arr[i] = 1;
    generateTruthTable(arr, i + 1, n);
}

int main() {


    ofstream file("BinaryTruth.csv");
    file<<"n, time";


    for(int n=1;n<=20;n+=2){

        
        vector<int>temp(n);

        int repeat=1000;

        auto start = high_resolution_clock::now();

        for(int i=0;i<repeat;i++){

         generateTruthTable(temp,0,n);


        }

        auto end =high_resolution_clock::now();

        auto time=duration_cast<microseconds>(end-start).count()/repeat;

       file<<n<<","<<time<<endl;
       cout<<"Completed for n="<<n<<endl;

    }
    cout<<"CSV File Gnerated Sucessfully "<<endl;
    file.close();
    
    return 0;
}