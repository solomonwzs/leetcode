#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class MountainArray {
 public:
  MountainArray(vector<int> arr): _n(0), _arr(arr) {
  }

  int get(int index) {
    if (_n++ > 100) {
      printf(">>> error");
    }
    return this->_arr[index];
  }
  
  int length() {
    return (int)this->_arr.size();
  }

 private:
  unsigned _n;
  vector<int> _arr;
};

class Solution {
 public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int top = this->findTop(mountainArr);
    if (mountainArr.get(top) == target) {
      return top;
    }

    int a = 0;
    int b = top - 1;
    while (a <= b) {
      int m = (a + b) / 2;
      int v = mountainArr.get(m);
      if (v == target) {
        return m;
      } else if (v < target) {
        a = m + 1;
      } else {
        b = m - 1;
      }
    }

    a = top + 1;
    b = mountainArr.length() - 1;
    while (a <= b) {
      int m = (a + b) / 2;
      int v = mountainArr.get(m);
      if (v == target) {
        return m;
      } else if (v > target) {
        a = m + 1;
      } else {
        b = m - 1;
      }
    }

    return -1;
  }

 private:
  int findTop(MountainArray &mountainArr) {
    int a = 0;
    int b = mountainArr.length() - 1;
    while (true) {
      int m = (a + b) / 2;
      int t = mountainArr.get(m);
      if (m > 0 && m < mountainArr.length()) {
        int prev = mountainArr.get(m - 1);
        int next = mountainArr.get(m + 1);
        if (prev < t && t > next) {
          return m;
        } else if (prev < t && t < next) {
          a = m;
        } else {
          b = m;
        }
      }
    }
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    MountainArray arr(vector<int>{1,2,3,4,5,3,1});
    cout << s.findInMountainArray(3, arr) << endl;
  }
  {
    MountainArray arr(vector<int>{0,1,2,4,2,1});
    cout << s.findInMountainArray(3, arr) << endl;
  }
  {
    MountainArray arr(vector<int>{1,5,2});
    cout << s.findInMountainArray(1, arr) << endl;
  }
  {
    MountainArray arr(vector<int>{1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11,9,7,5,3});
    cout << s.findInMountainArray(21, arr) << endl;
  }
  return 0;
}
