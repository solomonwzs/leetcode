#include "utils.h"

using namespace std;


class Solution{
 public:
  vector<int> grayCode(int n){
    vector<int> out;
    out.push_back(0);

    for (int i=1; i<=n; ++i){
      int size=out.size();
      int d=1<<(i-1);
      for (int j=size-1; j>=0; --j){
        out.push_back(d+out[j]);
      }
    }

    return out;
  }

  vector<int> grayCode0(int n){
    vector<int> out;
    int size=1<<n;
    for (int i=0; i<size; ++i) {
      out.push_back((i>>1)^i);
    }
    return out;
  }
};


int main(int argc, char **argv){
  Solution s;
  vector<int> out=s.grayCode(atoi(argv[1]));
  debug_log("%zu\n", out.size());
  for (unsigned i=0; i<out.size(); ++i){
    print_binary(out[i], atoi(argv[1]));
  }
  return 0;
}
