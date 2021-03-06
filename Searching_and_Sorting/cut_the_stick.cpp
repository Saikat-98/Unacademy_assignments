//Cut the Stick Problem Code: SSWK01C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<long long>
#define eb(x) emplace_back(x)
#define setbits(x) __builtin_popcountll(x)
#define tz(x) __builtin_ctzll(x)
#define lz(x) __builtin_clzll(x)
#define fsetbit(x) ffsll(x)
#define mod 1000000007
#define inf 1e18
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
#define debug(x, val) cout << "The value of " << x << " is: " << val << "\n";
#define op(x) cout << x << "\n";
void fastIO()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve()
{
  int n;
  cin >> n;
  vi v;
  map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.eb(val);
    if (m.find(val) != m.end())
      m[val] += 1;
    else
      m.insert(make_pair(val, 1));
  }

  int count = 0;
  for (auto i : m)
  {
    cout << v.size() - count << endl;
    count += i.second;
  }
}

int32_t main()
{
  fastIO();
  solve();

  return 0;
}