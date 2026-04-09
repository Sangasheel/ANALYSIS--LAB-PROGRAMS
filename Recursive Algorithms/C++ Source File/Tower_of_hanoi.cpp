#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void toh(int n,string src,string aux,string dest){

    if(n==1){
        //cout<<"Move disk 1 from "<<src<<" to "<<dest<<endl;

   return;
    }
    else{

        toh(n-1,src,dest,aux);
        //cout<<"MOve disk "<<n<<"from"<<src<<"to "<<dest<<endl;
        toh(n-1,aux,src,dest);
    }


}

int main() {

   ofstream file("toh_time.csv");

   file<<"n,time\n"<<endl;

   for(int n=1;n<=20;n++){

    auto start = high_resolution_clock::now();

        toh(n, "A", "B", "C");

        auto end = high_resolution_clock::now();

        long long timeTaken =
            duration_cast<microseconds>(end - start).count();

        file << n << "," << timeTaken << "\n";

   }
   
    file.close();
    cout << "\nCSV file generated: toh_time.csv\n";
    
    return 0;
}