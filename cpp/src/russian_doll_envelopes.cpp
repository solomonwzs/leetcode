#include <algorithm>
#include <vector>
#include "utils.h"

using namespace std;


#define ggt(_a_, _b_) \
    ((_a_).first > (_b_).first && (_a_).second > (_b_).second)

#define lt(_a_, _b_) \
    ((_a_).second < (_b_).second)

#define last(_v_) \
    ((_v_)[(_v_).size() - 1])

#define slast(_v_) \
    ((_v_)[(_v_).size() - 2])


bool lessPair(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}


int findFirstGreater(vector<pair<int, int>> &lst, pair<int, int> &p){
  int start = 0;
  int end = lst.size() - 1;
  if (ggt(p, lst[end])){
    return end + 1;
  }
  while (start < end) {
    int mid = (start + end) / 2;
    if (ggt(p, lst[mid])) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return ggt(lst[start], p) ? start : start + 1;
}


class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>>& envepores) {
    if  (envepores.size() == 0) {
      return 0;
    }

    vector<int> height(envepores.size());
    vector<int> maxLen(envepores.size());
    sort(envepores.begin(), envepores.end(), lessPair);

    maxLen[0] = 1;
    int max = 1;
    for (size_t i = 1; i < envepores.size(); i++) {
      maxLen[i] = 1;
      for (size_t j = 0; j < i; j++){
        if (ggt(envepores[i], envepores[j]) && maxLen[j] + 1 > maxLen[i]){
          maxLen[i] = maxLen[j] + 1;
        }
      }
      if (maxLen[i] > max) {
        max = maxLen[i];
      }
    }
    return max;
  }

  int maxEnvelopes1(vector<pair<int, int>>& envepores) {
    if  (envepores.size() == 0) {
      return 0;
    }
    sort(envepores.begin(), envepores.end(), lessPair);

    vector<pair<int, int>> lst;
    lst.push_back(envepores[0]);
    for (size_t i = 1; i < envepores.size(); i++) {
      int j = findFirstGreater(lst, envepores[i]);
      if (j > (int)lst.size() - 1){
        if (ggt(envepores[i], last(lst))) {
          lst.push_back(envepores[i]);
        } else if (lst.size() == 1 && lt(envepores[i], last(lst))) { 
          last(lst) = envepores[i];
        } else if (lst.size() >= 2  && ggt(envepores[i], slast(lst)) &&
                  lt(envepores[i], last(lst))) {
          last(lst) = envepores[i];
        }
      } else {
        if (j == 0 && lt(envepores[i], lst[j])) {
          lst[j] = envepores[i];
        } else if (j >= 1 && lt(envepores[i], lst[j]) &&
                   ggt(envepores[i], lst[j - 1])) {
          lst[j] = envepores[i];
        }
      }
    }
    return lst.size();
  }
};


int main(int argc, char **argv){
  vector<pair<int, int>> envepores;
  // envepores.push_back(pair<int, int>(2, 100));
  // envepores.push_back(pair<int, int>(3, 200));
  // envepores.push_back(pair<int, int>(4, 300));
  // envepores.push_back(pair<int, int>(5, 500));
  // envepores.push_back(pair<int, int>(5, 400));
  // envepores.push_back(pair<int, int>(5, 250));
  // envepores.push_back(pair<int, int>(6, 370));
  // envepores.push_back(pair<int, int>(6, 360));
  // envepores.push_back(pair<int, int>(7, 380));
  //
  // envepores.push_back(pair<int, int>(46, 89));
  // envepores.push_back(pair<int, int>(50, 53));
  // envepores.push_back(pair<int, int>(52, 68));
  // envepores.push_back(pair<int, int>(72, 45));
  // envepores.push_back(pair<int, int>(77, 81));
  //
  envepores.push_back(pair<int, int>(30, 50));
  envepores.push_back(pair<int, int>(12, 2));
  envepores.push_back(pair<int, int>(3, 4));
  envepores.push_back(pair<int, int>(12, 15));

  Solution s;
  debug_log("%d\n", s.maxEnvelopes(envepores));

  return 0;
}
