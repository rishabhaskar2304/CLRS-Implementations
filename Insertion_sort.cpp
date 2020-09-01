#include <iostream>

using namespace std;

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

    int key,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    cout<<"Solution:"<<endl;
    for(i=0;i<n;i++)
    {

        cout<<arr[i]<<endl;
    }
}