#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int h)
{
  int pivot=arr[l];
  int i=l+1;
  int j=h;
  while(1)
  {
    while(arr[i]<=pivot && i<=h)
    {
      i++;
    }
    
    while(arr[j]>pivot && j>=l)
    {
      j--;
    }
    if(i<j)
    {
      swap(arr[i],arr[j]);
    }
    else
    {
      break;
    }
  }
  swap(arr[l],arr[j]);
  return j;
}
void quick_sort(int arr[],int l, int h)
{ 
   if(l<h)
   {
    int pa=partition(arr,l,h);
     quick_sort(arr,l,pa-1);
     quick_sort(arr,pa+1,h);
   }
}
int main()
{
  int arr[] = {9,4,3,11,15,20,2,24,30,1,35};
  int n = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr,0, n-1);

  cout << "Sorted Array: ";
  for (auto a : arr)
    cout << a << " ";
  cout << endl;
}
