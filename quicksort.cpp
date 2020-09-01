#include<iostream>

using namespace std;

int part(int a[],int l,int h)
{
    if(l<h)
    {
        int i=l-1;
        int x=a[h];
        for(int j=l;j<h;j++)
        {
            if(a[j]<=x)
            {
                i++;
                swap(a[i],a[j]);
            }
        }
        swap(a[i+1],a[h]);
        return i+1;
    }
}

void qsr(int a[],int l,int h)
{
    if(l<h)
    {
        int m=part(a,l,h);
        qsr(a,l,m-1);
        qsr(a,m+1,h);
    }
}

int main()
{
    int n;
    cout<<"Enter the no. of elements :"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    qsr(a,0,n-1);
    cout<<"Results is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }

}