#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int temp = arr[i];
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] > temp)
        swap(arr[j+1], arr[j]);
    }
  }
}
int main()
{
  int arr[] = {43, 31, 26, 29, 12};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertion_sort(arr, n);
  for (auto a : arr)
    cout << a << " ";
  cout << endl;
}
