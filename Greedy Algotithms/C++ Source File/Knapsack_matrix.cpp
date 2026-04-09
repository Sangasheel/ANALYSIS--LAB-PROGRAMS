#include <bits/stdc++.h>
using namespace std;


typedef vector<vector<int>> Matrix;


void SortMatrix(Matrix&M){

    int n=M.size();
    int col=1;


    for(int i=0;i<n-1;i++){

        //    float r1=M[i][0];
        //     float r2= M[i][1];


        for(int j=0;j<n-i-1;j++){

            //if(r1>r2) then swap

            if(M[j][col]>M[j+1][col]){

            
                for(int k=0;k<M[0].size();k++){

                    swap(M[j][k],M[j+1][k]);

                }

            }

        }
    }


}



float Knapsack(Matrix &M,int Maxweight){

    int wtcnt=0;
    float MaxProfit=0;
    
    for(int i=0;i<M.size();i++){


        for(int j=0;j<M[0].size();j++){

            if(wtcnt>=Maxweight)return MaxProfit;

             if(j==0){         // j loop avoid 

             int profit=M[i][0];
             int weight=M[i][1];
             if(wtcnt+weight>Maxweight){

                int rem=Maxweight-wtcnt;
                float ratio=(float)profit/weight;
                MaxProfit+=ratio*rem;
                wtcnt+=rem;
             }

            else{

             MaxProfit+=profit;
             wtcnt+=weight;

            }
        

             }
             
        }


    }

    return MaxProfit;

}





float Knapsack_optimized(Matrix& M, int Maxweight){
    int wtcnt = 0;
    float MaxProfit = 0;

    for(int i = 0; i < M.size(); i++){

        if(wtcnt >= Maxweight) return MaxProfit;

        int profit = M[i][0];
        int weight = M[i][1];

        if(wtcnt + weight > Maxweight){
            // take fraction
            int rem = Maxweight - wtcnt;
            float ratio = (float)profit / weight;
            MaxProfit += ratio * rem;
            wtcnt += rem;
        }
        else{
            // take whole item
            MaxProfit += profit;
            wtcnt += weight;
        }
    }

    return MaxProfit;
}


int main() {


    Matrix M={

        {10 ,20},
        {5, 10},
        {6,15},
        {15,5},
        {10,2}

    };

    // cout<<M.size()<<endl;


    SortMatrix(M);
    for(int i=0;i<M.size();i++){

        for(auto it:M[i]){

            cout<<it<<" ";

        }
        cout<<endl;
    }

    cout<<Knapsack(M,20);
    
    return 0;
}