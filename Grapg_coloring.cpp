#include <iostream>
using namespace std;
#define V 4
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
  for (int i = 0; i < V; i++)
  {
    if (graph[v][i] && c == color[i])
      return false;
  }
  return true;
}

// Recursive function to solve Graph Coloring
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
  if (v == V)
    return true;

  for (int c = 1; c <= m; c++)
  {
    if (isSafe(v, graph, color, c))
    {
      color[v] = c;

      /// Recur to assign colors to the rest of the vertices
      if (graphColoringUtil(graph, m, color, v + 1) == true)
        return true;

      /// Backtrack: If assigning 'c' didn't lead to a solution, remove it
      color[v] = 0;
    }
  }
  return false;
}

int main()
{
  bool graph[V][V] = 
  {
      {0, 1, 1, 1},
      {1, 0, 1, 0},
      {1, 1, 0, 1},
      {1, 0, 1, 0},
  };

  int m = 3;
  int color[V];

  for (int i = 0; i < V; i++)
    color[i] = 0;

  if (graphColoringUtil(graph, m, color, 0) == false)
  {
    cout << "Solution does not exist";
  }
  else
  {
    cout << "Solution Exists: Following are the assigned colors \n";
    for (int i = 0; i < V; i++)
      cout << "Vertex " << i << " ---> Color " << color[i] << endl;
  }

  return 0;
}
