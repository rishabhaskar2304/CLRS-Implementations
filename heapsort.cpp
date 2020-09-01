#include<iostream>

using namespace std;

static int heapsize;

void prt(int a[],int n)
{
     for(int i=1;i<n+1;i++)
    {
        cout<<a[i]<<endl;
    }
    return;
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return 2*i+1;
}

void max_heapify(int a[],int i){
    int l = left(i);
    int r = right(i);
    int x=i;
    if(l<=heapsize&&a[l]>a[i])
    x=l;
    else 
    x=i;
    if(r<=heapsize&&a[r]>a[x])
    x=r;
    if(x!=i)
    { swap(a[i],a[x]);
      max_heapify(a,x);
    }
    // cout<<"a[i] "<<a[i]<<" a[l] "<<a[l]<<" a[r] "<<a[r]<<" a[x] "<<a[x]<<endl;
    return; 
}

void build_max(int a[],int n)
{
    heapsize=n;
    for(int i=n/2;i>0;i--)
    {
        max_heapify(a,i);
    }
   // prt(a,n);
    return;
}

void heapsort(int a[],int n)
{
    build_max(a,n);
    for(int i=n;i>1;i--)
    {
        swap(a[1],a[i]);
        heapsize--;
        max_heapify(a,1);
      //  cout<<"heapsize "<<heapsize<<endl;
    }
}


int main()
{
    int n;
    cout<<"Enter the no. of elements :";
    cin>>n;
    int a[n+1];
    for(int i=1;i<n+1;i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
    cout<<"Result :"<<endl;
    prt(a,n);
}