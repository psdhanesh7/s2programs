#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int h,u,d,f,rheight,fatigue,climbing;
    while(1)
    {
    cin>>h>>u>>d>>f;
    if(h==0 && u==0 && d==0 && f==0)
        break;
    rheight=h;
    climbing=u;
    fatigue=u*(f/100);
    while(climbing>0)
    {
        rheight-=climbing;
        if(rheight<0)
        {
            cout<<"Yes"<<endl;
            goto label;
        }   
        else
        {
            rheight+=d;
            climbing=climbing-fatigue;
        }
    }
    cout<<"No"<<endl;
    label: ;
    }
    
    
    return 0;
}
