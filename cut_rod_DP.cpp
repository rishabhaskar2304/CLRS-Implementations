#include<iostream>
#include<string>

using namespace std;

int rod_cutdp(int a[],int p,int b[])
{
    if(b[p]>=0)
    return b[p];
    if(p==0)
    return 0;
    int q = INT16_MIN;
    for(int i=1;i<p+1;i++)
    {
        q = max(q,(a[i]+rod_cutdp(a,p-i,b)));
    }
    b[p]=q;
    return q;
}

int rod_cut(int a[],int p)
{
    /* Stores value of each recursion encountered */
    int b[p+1];
    for(int i=0;i<p+1;i++)
    b[i]=INT16_MIN;
    int q = rod_cutdp(a,p,b);
    return q;
}



int main(){
    int a[11]={0,1,5,8,9,10,17,17,20,24,30};
    int q;
    cin>>q;
    int ans = rod_cut(a,q);
    cout<<"ANSWER : "<<ans;
}