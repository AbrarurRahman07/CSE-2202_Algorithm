#include <bits/stdc++.h>
using namespace std;
struct node
{
public:
  int profit;
  int weight;
  double average;
  node(int a, int b) : profit(a), weight(b)
  {
    average = (double)a / b;
  }
};

int main()
{
  int n, c;
  cin >> n >> c;
  vector<node> item;
  for (int i = 0; i < n; i++)
  {
    int v, w;
    cin >> v >> w;
    item.emplace_back(v, w);
  }

  sort(item.begin(), item.end(), [](const node &a, const node &b)
       { return a.average > b.average; });

  double result=0.00;
  int i=0;
  while(c!=0 && i<n)
  {
    if(c>=item[i].weight)
      {
        result+=(double)item[i].profit;
        c-=item[i].weight;
      }
    else 
    {
      
      result+=item[i].average*c;
      c=0;
    }
    i++;
  }
  cout<<fixed<<setprecision(4)<<result<<endl;
  return 0;
}