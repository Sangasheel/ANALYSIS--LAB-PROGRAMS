#include <bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;


void Permutation(string s ,int idx){

    if(idx==s.length()-1){

       // cout<<s<<" "<<endl;
       return;

    }

    for(int i=idx;i<s.length();i++){

         char temp=s[i];
         s[i]=s[idx];
         s[idx]=temp;

         Permutation(s,idx+1);

         temp=s[i];
         s[i]=s[idx];
         s[idx]=temp;


    }


}
int main() {

    ofstream file("Permutation.csv");

    file<<" n,time\n";


    for(int n=1;n<=10;n+=1){

        string s(n,'a');

        for(int i=0;i<n;i++){

            s[i]='a'+i;
        }

        int repeats=5;
        auto start =high_resolution_clock::now();

        for(int i=0;i<repeats;i++){
            Permutation(s,0);
        }

        auto end = high_resolution_clock::now();

        auto time = duration_cast<nanoseconds>(end-start).count()/repeats;

        file<<n<<","<<time<<"\n";

        cout<<"Run for n ="<<n<<endl;


    }
    file.close();

    cout<<"CSV file generated sucessfully "<<endl;



   
    return 0;
}