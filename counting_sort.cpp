#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the no. of elements :";
    cin>>n;
    int a[n];
    int l=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>l)
        l=a[i];
    }
    int b[l+1];
    int c[n];
    for(int i=0;i<l+1;i++)
    {
      b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
      b[a[i]]++;
    }
    for(int i=1;i<l+1;i++)
    {
        b[i]+=b[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        c[b[a[i]]-1]=a[i];
        b[a[i]]--;
    }
    cout<<"Result :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<c[i]<<endl;
    }
}