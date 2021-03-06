#include<iostream>
#include<string>

using namespace std;

int rod_cut(int a[],int p)
{
    if(p==0)
    return 0;
    int q = INT16_MIN;
    for(int i=1;i<p+1;i++)
    {
        q = max(q,(a[i]+rod_cut(a,p-i)));
    }
    return q;
}

int main(){
    int a[11]={0,1,5,8,9,10,17,17,20,24,30};
    int q;
    cin>>q;
    int ans = rod_cut(a,q);
    cout<<"ANSWER : "<<ans;
}