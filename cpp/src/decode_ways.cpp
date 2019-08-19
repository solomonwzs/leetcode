#include "leetcode.h"

using namespace std;


class Solution{
 public:
  int numDecodings(string s){
    if (s=="" || s[0]=='0'){
      return 0;
    }

    int f[4];
    vector<int> v;

    int n=1;
    for (unsigned i=1; i<s.size(); ++i){
      if (s[i]=='0'){
        if (s[i-1]!='1' && s[i-1]!='2'){
          return 0;
        } else{
          --n;
          if (n>1){
            v.push_back(n);
          }
          n=1;
        }
      } else if ((s[i-1]=='1' || s[i-1]=='2') && (s[i-1]-'0')*10+s[i]-'0'<=26){
        ++n;
      } else{
        if (n>1){
          v.push_back(n);
        }
        n=1;
      }
    }
    if (n>1){
      v.push_back(n);
    }

    int r=1;
    for (unsigned i=0; i<v.size(); ++i){
      fib(v[i], f);
      r*=f[0];
    }
    return r;
  }

 private:
  void fib(int n, int *out){
    if (n==0){
      out[0]=1;
      out[1]=0;
      out[2]=0;
      out[3]=1;
    } else if (n==1){
      out[0]=1;
      out[1]=1;
      out[2]=1;
      out[3]=0;
    } else if (n%2==0){
      int a[4];
      fib(n/2, a);
      mul(a, a, out);
    } else{
      int a[4], b[4];
      int c[4]={1, 1, 1, 0};
      fib(n/2, a);
      mul(a, a, b);
      mul(b, c, out);
    }
  }

 private:
  void mul(int *a, int *b, int *out){
    out[0]=a[0]*b[0]+a[1]*b[2];
    out[1]=a[0]*b[1]+a[1]*b[3];
    out[2]=a[2]*b[0]+a[3]*b[2];
    out[3]=a[2]*b[1]+a[3]*b[3];
  }
};


int main(int argc, char **argv){
  Solution s;
  debug_log("%d\n", s.numDecodings(argv[1]));

  return 0;
}
