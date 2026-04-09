#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Pair{

    int profit;
    int weight;
    float ratio=0;
};

float Maxprofit_profit(vector<pair<int,int>>a,int Weight){
   

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

float Maxprofit_ratio(vector<Pair>&a,int Maxweight){
   

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

 

  ofstream profit_weight("PW.csv");

  ofstream profit_profit("PP.csv");

  ofstream profit_ratio("PR.csv");

  
  profit_profit<<"profit,weight\n";
  profit_weight<<"profit,weight\n";
  profit_ratio<<"profit,weight\n";





   for(int n=5;n<=25;n+=5){


    vector<pair<int,int>>pp(n);
    vector<pair<int,int>>pw(n);
    vector<Pair>pr(n);

    for(int i=0;i<n;i++){


        int profit=rand()%101;

        int weight=rand()%20+1;

        pp.push_back({profit,weight});
        pw.push_back({weight,profit});



        pr[i].profit=profit;
        pr[i].weight=weight;



    }

    int Maxweight=rand()%101;

    sort(pp.begin(),pp.end());
    reverse(pp.begin(),pp.end());

    sort(pw.begin(),pw.end());


    
    
      float Profit_profit= Maxprofit_profit(pp,Maxweight);

      float Profit_Weight=Maxprofit_weight(pw,Maxweight);

      float Profit_ratio=Maxprofit_ratio(pr,Maxweight);


      profit_profit<<Profit_profit<<","<<Maxweight<<endl;

      profit_weight<<Profit_Weight<<","<<Maxweight<<endl;

      profit_ratio<<Profit_ratio<<","<<Maxweight<<endl;
 
      cout<<"Complted for n ="<<n<<endl;



   }

   profit_profit.close();
   profit_weight.close();
   profit_ratio.close();



    
    return 0;
}