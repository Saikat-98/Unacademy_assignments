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

int minimumPos(vi &v, int startIdx)
{
  int min = startIdx;
  for (int i = startIdx + 1; i < v.size(); i++)
    if (v[i] < v[min])
      min = i;
  return min;
}

void update(vi &v, int startIdx, int min)
{
  int count = 0;
  for (int i = startIdx; i < v.size(); i++)
    if (v[i] >= min and v[i] != 0)
      v[i] -= min, count++;
  cout << count << endl;
}

int swapped(vi &v, int startIdx)
{
  int count = 0;
  for (int i = startIdx; i < v.size(); i++)
    if (v[i] == 0)
      swap(v[i], v[startIdx + count]), count++;
  return count + startIdx;
}

void solve()
{
  int n;
  cin >> n;
  vi v;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.eb(val);
  }

  for (int i = 0; i < n; i++)
    update(v, i, v[minimumPos(v, i)]), i = swapped(v, i) - 1;
}

int32_t main()
{
  fastIO();
  solve();

  return 0;
}