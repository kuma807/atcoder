#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int main()
{
  string S;
  int N, ans = 0;
  cin >> N >> S;
  for (int i = 0; i < N - 2; ++i)
  {
    if (S.at(i) == 'A' && S.at(i + 1) == 'B' && S.at(i + 2) == 'C')
    {
      ans += 1;
    }
  }
  cout << ans << endl;
}
