#include <bits/stdc++.h>
using namespace std;
void selecion_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i)
    {
      swap(arr[i], arr[min]);
    }
  }
}
int main()
{
  int arr[] = {9, 13, 43, 31, 26, 29, 12};
  int n = sizeof(arr) / sizeof(arr[0]);

  selecion_sort(arr, n);

  cout << "Sorted Array: ";
  for (auto a : arr)
    cout << a << " ";
  cout << endl;
}
