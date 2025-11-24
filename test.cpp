#include<bits/stdc++.h>
using namespace std;

vector<int>v[10000];
bool visited[10000]={false};

void BFS(int starting_vertex)
{
  queue<int>q;
  q.push(starting_vertex);
  visited[starting_vertex]=true;
  while(!q.empty())
  {
    int x=q.front();
    cout<<x<<" ";
    q.pop();
    for(int i=0;i<v[x].size();i++)
    {
      int y=v[x][i];
      if(visited[y]==false)
      {
        q.push(y);
        visited[y]=true;
      }
    }
  }
}

int main()
{
  int node,edge;
    int a,b;
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int start;
    cin>>start;
    BFS(start);
  return 0;
}
