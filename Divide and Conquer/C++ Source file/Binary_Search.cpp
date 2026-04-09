#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool BinarySearch(vector<int>& a, int st, int end, int key)
{
    if (st > end) return false;

    int mid = (st + end) / 2;

    if (a[mid] == key) return true;
    else if (key < a[mid])
        return BinarySearch(a, st, mid - 1, key);
    else
        return BinarySearch(a, mid + 1, end, key);
}

int main()
{
    ofstream file1("binary_best_case.csv");
    ofstream file2("binary_worst_case.csv");

    file1 << "n,time\n";
    file2 << "n,time\n";

    int repeat = 1000000;

    for (int n = 1000; n <= 50000; n += 5000)
    {
        vector<int> a(n);

        
        for (int i = 0; i < n; i++)
            a[i] = rand();

      
        sort(a.begin(), a.end());

        volatile bool result;

      
        int bestKey = a[n / 2];

        auto start1 = high_resolution_clock::now();

        for (int i = 0; i < repeat; i++)
            result = BinarySearch(a, 0, n - 1, bestKey);

        auto end1 = high_resolution_clock::now();

        long long bestTime =
            duration_cast<nanoseconds>(end1 - start1).count() / repeat;

        file1 << n << "," << bestTime << "\n";

        
        int worstKey = -1; 

        auto start2 = high_resolution_clock::now();

        for (int i = 0; i < repeat; i++)
            result = BinarySearch(a, 0, n - 1, worstKey);

        auto end2 = high_resolution_clock::now();

        long long worstTime =
            duration_cast<microseconds>(end2 - start2).count();

        file2 << n << "," << worstTime << "\n";

    }

    file1.close();
    file2.close();

    

    return 0;
}
