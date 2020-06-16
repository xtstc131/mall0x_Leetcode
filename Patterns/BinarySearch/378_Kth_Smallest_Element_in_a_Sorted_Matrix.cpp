#include "header.hpp"
class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    const int n = matrix.size();
    long l = matrix[0][0];
    long r = matrix[n - 1][n - 1] + 1;
    while (l < r)
    {
      long m = l + (r - l) / 2;
      int total = 0;
      int s = n;
      for (const auto &row : matrix)
        total += (s = distance(begin(row), upper_bound(begin(row), begin(row) + s, m)));
      if (total >= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};