#include <string>
#include "leetcode.h"

using namespace std;


#define is_lowercase_letter(_c) ('a'<=(_c) && (_c)<='z')
#define is_uppercase_letter(_c) ('A'<=(_c) && (_c)<='Z')
#define is_number(_c) ('0'<=(_c) && (_c)<='9')
#define is_alphanumeric(_c) \
    (is_lowercase_letter(_c) || is_uppercase_letter(_c) || is_number(_c))


class Solution{
 public:
  bool isPalindrome(string s){
    string s0="";
    for (unsigned i=0; i<s.size(); ++i){
      if (is_lowercase_letter(s[i]) || is_number(s[i])){
        s0.push_back(s[i]);
      } else if (is_uppercase_letter(s[i])){
        s0.push_back(s[i]-'A'+'a');
      }
    }

    unsigned len=s0.size();
    for (unsigned i=0; i<len/2; ++i){
      if (s0[i]!=s0[len-i-1]){
        return false;
      }
    }
    return true;
  }
};


int main(int argc, char **argv){
  Solution s;
  debug_log("%s\n", s.isPalindrome(string(argv[1]))?"true":"false");

  return 0;
}
