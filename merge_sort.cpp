#include <iostream>

using namespace std;

void mrg(int *arr,int l,int m,int r)
{

    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j] = arr[m+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return;
}


void mergesrt(int arr[],int s,int e)
{

    if(s==e)
    {
        return;
    }

    int m = s+(e-s)/2;

    mergesrt(arr,s,m);
    mergesrt(arr,m+1,e);
    mrg(arr,s,m,e);

    return;
}



int main()
{
    int n;
    cout<<"Enter the no.:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter items:"<<endl;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    mergesrt(arr,0,n-1);

    cout<<"Solution:"<<endl;
    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<endl;
    }
}
