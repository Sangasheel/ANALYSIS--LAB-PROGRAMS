#include <bits/stdc++.h>
using namespace std;

int power(int x,int pow){

    if(pow==0){
        return 1;
    }
    return x*power(x,pow-1);

}

int main() {

    cout<<power(2,2);
    
    return 0;
}