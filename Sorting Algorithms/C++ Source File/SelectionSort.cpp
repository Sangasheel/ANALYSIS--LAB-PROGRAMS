#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
void Selectionsort(vector<int>&a,int n){

    int idx;
    int j;
    
    for(int i=0;i<n;i++){

        idx=i;
        for( j=i+1;j<n;j++){

            if(a[j]<a[i]){
               
                idx=j;
            }
        }

        swap(a[idx],a[i]);

    }


}
int main() {

     
    ofstream file1("selection_best_case.csv");
    ofstream file2("selection_worst_case.csv");

    file1 << "n,time\n";
    file2 << "n,time\n";

    for (int n = 1000; n <= 20000; n += 2000)
    {
       
        vector<int> a(n);

       
        for (int i = 0; i < n; i++)
            a[i] = i;

    int repeat = 50;

auto start1 = high_resolution_clock::now();

for(int r=0; r<repeat; r++)
{
    vector<int> temp =a; // copy again
    Selectionsort(temp, n);
}

auto end1 = high_resolution_clock::now();

long long bestTime =
duration_cast<nanoseconds>(end1 - start1).count() / repeat;

        file1 << n << "," << bestTime << "\n";

        
        vector<int> a2(n);

       
        for (int i = 0; i < n; i++)
            a2[i] = n - i;

        auto start2 = high_resolution_clock::now();
        Selectionsort(a2, n);
        auto end2 = high_resolution_clock::now();

        long long worstTime =
            duration_cast<microseconds>(end2 - start2).count();

        file2 << n << "," << worstTime << "\n";

        cout << "Done for n = " << n << endl;
    }

    file1.close();
    file2.close();

    cout << "\nCSV files generated successfully!\n";

    
    return 0;
}