#include<bits/stdc++.h>
using namespace std;

int MaxCrossingSum(int* arr,int l,int m,int r)
{
  int left_sum=INT_MIN;
  int right_sum=INT_MIN;

  int sum=0;
  for(int i=m;i>=l;i--)
  {
    sum+=arr[i];
    if(sum>left_sum)
    left_sum=sum;
  }
  
  sum=0;
  for(int i=m+1;i<=r;i++)
  {
    sum+=arr[i];
    if(sum>right_sum)
    right_sum=sum;
  }
  return left_sum+right_sum;
}

int MaxSumSubArray(int* arr,int l,int r)
{
  if(l==r)
  return arr[l];

  int m=(l+r)/2;
  int lss=MaxSumSubArray(arr,l,m);
  int rss=MaxSumSubArray(arr,m+1,r);
  int css=MaxCrossingSum(arr,l,m,r);
  return max({lss,rss,css});
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int Sum=MaxSumSubArray(arr,0,n-1);
  cout<<"Maximum Sum of the Subarray is:"<<Sum<<endl;
  return 0;
}