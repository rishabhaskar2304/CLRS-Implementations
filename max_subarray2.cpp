#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    int a[n];
    int sum=0;
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int in=sum;
    int left_sum=INT16_MIN;
    sum = 0;
    int max_left;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(left_sum<sum)
        {
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum=INT16_MIN;
    sum = 0;
    int max_right;
    for(int i=n-1;i>-1;i--)
    {
        sum+=a[i];
        if(right_sum<sum)
        {
            right_sum=sum;
            max_right=i;
        }
    }
    cout<<"Max subarray between "<<max_right<<" and "<<max_left<<" = "<<right_sum+left_sum-in;
}