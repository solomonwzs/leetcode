#include "utils.h"

using namespace std;


class Solution{
 public:
  vector<string> restoreIpAddresses(string s){
    vector<string> ip_group;
    gen_ip(s, 0, 1, "", ip_group);

    return ip_group;
  }

 private:
  void gen_ip(string s, int offset, int n, string ip,
                  vector<string> &ip_group){
    if (offset==(int)s.size() && n>4){
      ip_group.push_back(ip);
    } else{
      int min_len, max_len;
      valid_len(s, offset, n, &min_len, &max_len);
      for (int i=min_len; i<=max_len; ++i){
        string sub=s.substr(offset, i);
        if ((i>1 && sub[0]=='0')
            || (i==3 && atoi(sub.c_str())>255)){
          return;
        } else{
          gen_ip(s, offset+i, n+1, n==1?ip+sub:ip+"."+sub, ip_group);
        }
      }
    }
  }

  void valid_len(string s, int offset, int n, int *min, int *max){
    int remain_len=s.size()-offset;
    *min=remain_len-(4-n)*3;
    *max=remain_len-(4-n);

    if (*min<1){
      *min=1;
    }

    if (*max>3){
      *max=3;
    }
  }
};


int main(int argc, char **argv){
  Solution s;
  vector<string> ip_group=s.restoreIpAddresses(argv[1]);
  for (unsigned i=0; i<ip_group.size(); ++i){
    debug_log("%s\n", ip_group[i].c_str());
  }
  return 0;
}
