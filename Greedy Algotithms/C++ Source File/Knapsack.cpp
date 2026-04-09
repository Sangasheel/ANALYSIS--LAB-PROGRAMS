#include <bits/stdc++.h>
using namespace std;

struct Pair{

    int profit;
    int weight;
    float ratio=0;
};

float Maxprofit(vector<pair<int,int>>a,int Weight){
   

     float Maxprofit=0;
     int wcount=0;
     
    for(int i=0;i<a.size();i++){

        if(wcount>=Weight){
            break;

        }
    
         if(wcount+a[i].second<=Weight){

              Maxprofit=Maxprofit+a[i].first;
              wcount+=a[i].second;

         }
         else{
              
            int rem=Weight-wcount;

            float ratio=(float)a[i].first/a[i].second;

            float frac_profit=rem*ratio;


             Maxprofit=Maxprofit+frac_profit;

             wcount+=rem;


         }

       
    }

    return Maxprofit;

     

}


float Maxprofit_weight(vector<pair<int,int>>a,int Maxweight){


    
     float Maxprofit=0;
     int wcount=0;
     
    for(int i=0;i<a.size();i++){

        if(wcount>=Maxweight){
            break;

        }

    
         if(wcount+a[i].first<=Maxweight){

              Maxprofit=Maxprofit+a[i].second;
              wcount+=a[i].first;

         }
         else{
              
            int rem=Maxweight-wcount;

            float ratio=(float)a[i].second/a[i].first;

            float frac_profit=rem*ratio;



             Maxprofit=Maxprofit+frac_profit;

             wcount+=rem;


         }

       
    }

    return Maxprofit;





}

void Sort(vector<Pair>&a){

    for(int i=0;i<a.size()-1;i++){
        for(int j=0;j<a.size()-i-1;j++){

            if(a[j].ratio<a[j+1].ratio){

                swap(a[j],a[j+1]);

            }
        }
    }
}

float Maxprofit_weight_ratio(vector<Pair>&a,int Maxweight){
   

    for(int i=0;i<a.size();i++){

        
        a[i].ratio=(float) a[i].profit/a[i].weight;

    }

    Sort(a);


    
    int wcount=0;
    float Maxprofit=0;

    for(int i=0;i<a.size();i++){

          if(wcount>=Maxweight){
            break;

        }

    
         if(wcount+a[i].weight<=Maxweight){

              Maxprofit=Maxprofit+a[i].profit;
              wcount+=a[i].weight;

         }
         else{
              
            int rem=Maxweight-wcount;

            float ratio=(float)a[i].profit/a[i].weight;

            float frac_profit=rem*ratio;



             Maxprofit=Maxprofit+frac_profit;

             wcount+=rem;

         }





    }

    return Maxprofit;



}





int main() {

  vector<pair<int,int>>a={{20,20},{5,10},{6,15},{15,5},{10,2}};

  vector<pair<int,int>>b={{20,20},{10,5},{15,6},{5,15},{2,10}};




//   for(int i=0;i<5;i++){

//        cout<<"Enter Profit Weight"<<endl;
    
//        cin>>a[i].first;

//        cin>>a[i].second;
        
//   }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());

//   for(int i=0;i<5;i++){

//     cout<<a[i].first<<" "<<a[i].second<<endl;
//   }
  int W=20;


  cout<<"Max profit by profit  "<<endl;

  cout<<Maxprofit(a,W)<<endl;

  cout<<"Max profit by weight  "<<endl;

  cout<<Maxprofit_weight(b,W)<<endl;

   vector<Pair> p={{20,20},{5,10},{6,15},{15,5},{10,2}};

   cout<<"Max profit/weight ratio"<<endl;
 
   cout<<Maxprofit_weight_ratio(p,20);
  


    
    return 0;
}