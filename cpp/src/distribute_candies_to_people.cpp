#include <vector>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

static inline int root(int a0, int b0, int c0) {
  long a = a0, b = b0, c = c0;
  double r = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
  return (int)r;
}

class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    int n = (1 + num_people) * num_people / 2;

    int turn = root(num_people * num_people, 2 * n - num_people * num_people, -2 * candies);
    vector<int> ans(num_people);
    if (turn > 0) {
      for (int i = 0; i < num_people; ++i) {
        ans[i] = (i + 1 + (turn - 1) * num_people + i + 1) * turn / 2;
        candies -= ans[i];
      }
    }

    int k = num_people * turn;
    for (int i = 0; candies > 0 && i < num_people; ++i) {
      if (candies > k + i + 1) {
        ans[i] += k + i + 1;
        candies -= k + i + 1;
      } else {
        ans[i] += candies;
        candies = 0;
      }
    }

    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto ans = s.distributeCandies(7, 4);
    for (unsigned i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  {
    auto ans = s.distributeCandies(10, 3);
    for (unsigned i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  {
    auto ans = s.distributeCandies(1000000000, 1000);
    for (unsigned i = 0; i < 10; ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
