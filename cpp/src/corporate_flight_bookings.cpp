#include <vector>
#include <iostream>
#include <cstdio>
#include <sys/time.h>

using namespace std;

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n + 1, 0);
    for (auto &b : bookings) {
      ans[b[0] - 1] += b[2];
      ans[b[1]] -= b[2];
    }
    for (int i = 1; i < n; ++i) {
      ans[i] += ans[i - 1];
    }
    return {ans.begin(), ans.end() - 1};
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto bookings = vector<vector<int>> {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;
    vector<int> ans = s.corpFlightBookings(bookings, n);
    for (int i = 0; i < n; ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  {
    vector<vector<int>> bookings;
    int n = 20000;
    for (int i = 0; i < 20000; ++i) {
      bookings.push_back({1, 20000, 10000});
    }

    struct timeval start, end;
    int time_usec;
    gettimeofday(&start, NULL);
    s.corpFlightBookings(bookings, n);
    gettimeofday(&end, NULL);
    time_usec = (int)((end.tv_sec - start.tv_sec) * 1000 +
                      (end.tv_usec - start.tv_usec) / 1000);
    printf("%d ms\n", time_usec);
  }
  return 0;
}
