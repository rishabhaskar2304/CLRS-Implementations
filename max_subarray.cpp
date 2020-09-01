#include<iostream>

using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}

int max_subarr_cross(int a[],int l,int m,int h)
{
    int left_sum = INT16_MIN;
    int sum=0;
    for(int i=m;i>=l;i--)
    {
        sum+=a[i];
        if(sum>left_sum)
        {
            left_sum = sum;
        }
    }
    int right_sum = INT16_MIN;
    sum = 0;
    for(int i=m+1;i<=h;i++)
    {
         sum+=a[i];
        if(sum>right_sum)
        {
            right_sum = sum;
        }
    }
    return right_sum + left_sum;
}

int max_sub(int a[],int l,int h)
{
    if(l==h)
    {
        return a[l];
    }
    else
    {
        int m= (l+h)/2;

        return max(max(max_sub(a,l,m),max_sub(a,m+1,h)),max_subarr_cross(a,l,m,h));
    }
    
}

int main()
{
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max = max_sub(arr,0,n-1);
    cout<<"Result:"<<max<<endl;
}

