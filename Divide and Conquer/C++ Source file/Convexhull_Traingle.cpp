#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;

};

int area(point a,point b,point c){

     return abs(
        a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)
    );

}

bool lies(point a,point b,point c,point p){

    return (area(a,b,c)==(area(a,b,p))+area(b,c,p)+area(a,c,p));


}



// basic idea of this convex hull approach is that a point lies inside a traingle only if there exists a traingle containing it 


void Convex_hull_Triangle_method(vector<point>&points,vector<bool>&lies_inside){

    int n=points.size();

    //vector<bool>lies_inside;// used to check point lies inside or not 

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){

                 if(area(points[i],points[j],points[k]) == 0)
                continue;

                // this 3 loops are used to generate all possible triangles 

                // this is same as we generate all possible permutations of an array but fixed 3 points 

              for(int p=0;p<n;p++){

                // this loop used to check whether the point lies inside any traingle or not

                if(p==i||p==j||p==k) continue; // skip the points an traingle 


                if(lies(points[i],points[j],points[k],points[p])){

                    lies_inside[p]=true;
                }
                

              }


            }
        }
    }



}


int main() {

     vector<point> points = {
        {0,3},{2,2},{1,1},{2,1},{3,0},{0,0},{3,3}
    };
    int n=points.size();

    vector<bool>lies_inside(n,false);


    Convex_hull_Triangle_method(points,lies_inside);

    cout<<"Convex hull "<<endl;

    for(int i=0;i<n;i++){

        if(!lies_inside[i]){
            cout<<"("<<points[i].x<<","<<points[i].y<<") ";
        }

    

    }



    
    return 0;
}