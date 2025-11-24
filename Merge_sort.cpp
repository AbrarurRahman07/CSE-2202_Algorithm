#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int h)
{
  vector<int>temp;
  int i = l, j = m + 1, k = 0;
  while (i <= m && j <= h)
  {
    if (arr[i] < arr[j])
    {
      temp.push_back(arr[i++]);
    }
    else
    {
      temp.push_back( arr[j++]);
    }
  }
  while (i <= m)
  {
    temp.push_back(arr[i++]);
  }
  while (j <= h)
  {
    temp.push_back(arr[j++]);
  }
  for (int p = 0; p < k; p++)
    arr[l + p] = temp[p];
}
void merge_sort(int arr[], int l, int h)
{
  if (l < h)
  {
    int m = (l + h) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, h);
    merge(arr, l, m, h);
  }
}
int main()
{
  int arr[] = {9, 4, 3, 11, 15, 20, 2, 24, 30, 1, 35};
  int n = sizeof(arr) / sizeof(arr[0]);

  merge_sort(arr, 0, n - 1);

  cout << "Sorted Array: ";
  for (auto a : arr)
    cout << a << " ";
  cout << endl;
}
