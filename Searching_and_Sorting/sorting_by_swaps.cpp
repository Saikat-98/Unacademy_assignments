#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int merge(const vector<int> &first, const vector<int> &second, vector<int> &final)
{
  final.clear();

  int count = 0, i = 0, j = 0;
  while (i < first.size() and j < second.size())
  {
    if (first[i] <= second[j])
      final.push_back(first[i]), i++;
    else
    {
      count += first.size() - i;
      final.push_back(second[j]), j++;
    }
  }

  while (i < first.size())
    final.push_back(first[i]), i++;
  while (j < second.size())
    final.push_back(second[j]), j++;

  return count;
}

int countNumberOfInversions(vector<int> &v)
{
  if (v.size() <= 1)
    return 0;

  vector<int> left(v.begin(), v.begin() + (v.size() / 2));
  vector<int> right(v.begin() + (v.size() / 2), v.end());

  return countNumberOfInversions(left) + countNumberOfInversions(right) + merge(left, right, v);
}

int32_t main()
{
  fastIO();
  w(t)
  {
    int n, count = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      int val;
      cin >> val;
      v[i] = val;
    }
    cout << countNumberOfInversions(v) << "\n";
  }
  return 0;
}