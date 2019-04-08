#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;


class Solution {
 public:
  int evalRPN(vector<string> &tokens){
    vector<int> v;

    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
      if (*it=="+"){
        int a=*(v.end()-1); v.pop_back();
        int b=*(v.end()-1); v.pop_back();
        v.push_back(b+a);
      } else if (*it=="-"){
        int a=*(v.end()-1); v.pop_back();
        int b=*(v.end()-1); v.pop_back();
        v.push_back(b-a);
      } else if (*it=="*"){
        int a=*(v.end()-1); v.pop_back();
        int b=*(v.end()-1); v.pop_back();
        v.push_back(b*a);
      } else if (*it=="/"){
        int a=*(v.end()-1); v.pop_back();
        int b=*(v.end()-1); v.pop_back();
        v.push_back(b/a);
      } else{
        v.push_back(atoi(it->c_str()));
      }
    }

    return *v.begin();
  }
};


int main(){
  Solution s;
  vector<string> v;
  string str[]={"4", "13", "5", "/", "+"};
  for (int i=0; i<5; ++i){
    v.push_back(str[i]);
  }

  printf("%d\n", s.evalRPN(v));
  return 0;
}
