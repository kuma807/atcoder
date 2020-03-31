// ============how it works=================
// input:
  //maze: type can be changed
    //maze shoud be sorrounded by wall
      // #####
      // #s..#
      // #...#
      // #..g#
      // #####
  // pair<int, int> start: start.first = H, start.second = W
  //pair<int, int> end: end.first = H, end.second = W
// output:
  //int: clouset path length
// ========================================

auto wall = "#";
//=============bfs============================
int bfs(vector<vector<char>> maze, pair<int, int> start, pair<int, int> end)
{
  queue<tuple<int, int, int>> q;
  vector<vector<int>> already_went(maze.size(), vector<int>(maze.at(0).size(), 0));
  tuple<int, int, int> temp;
  get<0>(temp) = start.first;get<1>(temp) = start.second;get<2>(temp) = 0;
  q.push(temp);
  while (!q.empty())
  {
    tuple<int, int, int> check = q.front();
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
