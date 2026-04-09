#include <bits/stdc++.h>
using namespace std;
int Bounces(int h){

    int sh=h;
     int bounces=0;
    while(sh>0){
   

        int v=sqrt(2*10*sh);
        v=v-(v*40)/100;
        
        int newh=(v*v)/20;
        sh=newh;
        if(newh>0){
            bounces++;
        }

    }
    return bounces;

}
int main() {
    


    int h=2000;
    cout<<Bounces(h);
    return 0;
}