#include <bits/stdc++.h>
#define INF 10000000000
using namespace std;


auto wall = "0";
//=============dijkstra============================
int dfs(vector<vector<char>> maze, pair<int, int> start, pair<int, int> end)
{
  stack<tuple<int, int, int>> q;
  vector<vector<int>> already_went(maze.size(), vector<int>(maze.at(0).size(), 0));
  tuple<int, int, int> temp;
  get<0>(temp) = start.first;get<1>(temp) = start.second;get<2>(temp) = 0;
  q.push(temp);
  while (!q.empty())
  {
    tuple<int, int, int> check = q.top();
    q.pop();
    if (already_went.at(get<0>(check)).at(get<1>(check)) == 1)
    {
      continue;
    }
    already_went.at(get<0>(check)).at(get<1>(check)) = 1;
    if (get<0>(check) == end.first && get<1>(check) == end.second)
    {
      return get<2>(check);
    }
    if (maze.at(get<0>(check) + 1).at(get<1>(check)) != wall)
    {
      get<0>(temp) = get<0>(check) + 1;get<1>(temp) = get<1>(check);get<2>(temp) = get<2>(check) + 1;
      q.push(temp);
    }
    if (maze.at(get<0>(check)).at(get<1>(check) + 1) != wall)
    {
      get<0>(temp) = get<0>(check);get<1>(temp) = get<1>(check) + 1;get<2>(temp) = get<2>(check) + 1;
      q.push(temp);
    }
    if (maze.at(get<0>(check) - 1).at(get<1>(check)) != wall)
    {
      get<0>(temp) = get<0>(check) - 1;get<1>(temp) = get<1>(check);get<2>(temp) = get<2>(check) + 1;
      q.push(temp);
    }
    if (maze.at(get<0>(check)).at(get<1>(check) - 1) != wall)
    {
      get<0>(temp) = get<0>(check);get<1>(temp) = get<1>(check) - 1;get<2>(temp) = get<2>(check) + 1;
      q.push(temp);
    }
  }
}
//=================================================


int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<char>> maze(n + 2, vector<char>(m + 2, 0));
  for (int i = 1; i < n + 1; ++i)
  {
    for (int j = 1; j < m + 1; ++j)
    {
      char ice;
      cin >> ice;
      maze.at(i).at(j) = ice;
    }
  }
}
