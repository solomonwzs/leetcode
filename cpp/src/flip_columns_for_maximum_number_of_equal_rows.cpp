#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    map<string, int> m;
    vector<int>& row = matrix[0];
    string s;
    for (auto i : row) {
      s.push_back(i + '0');
    }
    m[s] = 1;

    for (size_t i = 1; i < matrix.size(); ++i) {
      string s;
      if (matrix[i][0] == row[0]) {
        for (auto i : matrix[i]) {
          s.push_back(i + '0');
        }
      } else {
        for (auto i : matrix[i]) {
          if (i == 0) {
            s.push_back('1');
          } else {
            s.push_back('0');
          }
        }
      }
      m[s] += 1;
    }

    int ans = 0;
    for (auto i : m) {
      if (i.second > ans) {
        ans = i.second;
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto matrix = vector<vector<int>>{
      vector<int>{0, 1}, vector<int>{1, 1}
    };
    cout << s.maxEqualRowsAfterFlips(matrix) << endl;
  }
  {
    auto matrix = vector<vector<int>>{
      vector<int>{0, 0, 0}, vector<int>{0, 0, 1}, vector<int>{1, 1, 0}
    };
    cout << s.maxEqualRowsAfterFlips(matrix) << endl;
  }
  return 0;
}
