#include <bits/stdc++.h>
using namespace std;
struct node
{
public:
  int id;
  int profit;
  int deadline;
  node(int i, int p, int d) : id(i), profit(p), deadline(d) {}
};
int main()
{
  int n;
  cin >> n;
  vector<node> v;
  int i, p, d;
  while (n--)
  {
    cin >> i >> p >> d;
    v.emplace_back(i, p, d);
  }
  sort(v.begin(), v.end(), [](const node &a, const node &b)
       { return a.profit > b.profit; });

  auto it=max_element(v.begin(), v.end(), [](const node &a, const node &b)
              { return a.deadline < b.deadline; });
  int x=it->deadline;
   int result =0;
  vector<bool> slot(x + 1, false);

 for (int k = 0; k < v.size(); k++)
    {
        for (int d = v[k].deadline; d >= 1; d--)
        {
            if (!slot[d])
            {
                slot[d] = true; 
                result += v[k].profit;
                break;
            }
        }
    }
  cout<<result<<endl;
  return 0;
}