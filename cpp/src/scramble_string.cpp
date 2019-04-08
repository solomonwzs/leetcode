#include "utils.h"


static bool same_element(char *s1, char *s2, int len, bool *math){
  for (int i=0; i<len; ++i){
    math[i]=false;
  }
  for (int i=0; i<len; ++i){
    bool ok=false;
    for (int j=0; j<len; ++j){
      if (s1[i]==s2[j] && !math[j]){
        math[j]=true;
        ok=true;
        break;
      }
    }
    if (!ok){
      return false;
    }
  }
  return true;
}


static bool is_scramble(char *s1, char *s2, int len, bool *math){
  if (len==1 && s1[0]==s2[0]){
    return true;
  }

  bool ok=false;
  for (int sub_len=1; sub_len<len && !ok; ++sub_len){
    if (same_element(s1, s2, sub_len, math)){
      ok=is_scramble(s1, s2, sub_len, math)
          && is_scramble(s1+sub_len, s2+sub_len, len-sub_len, math);
    }
    if (!ok && same_element(s1, s2+len-sub_len, sub_len, math)){
      ok=is_scramble(s1, s2+len-sub_len, sub_len, math)
          && is_scramble(s1+sub_len, s2, len-sub_len, math);
    }
  }
  return ok;
}


bool isScramble(char *s1, char *s2){
  int len1;
  for (len1=0; s1[len1]; ++len1);

  int len2;
  for (len2=0; s2[len2]; ++len2);

  if (len1!=len2){
    return false;
  } else{
    bool *math=(bool *)malloc(sizeof(bool)*len1);
    bool ret=is_scramble(s1, s2, len1, math);
    free(math);
    return ret;
  }
}


int main(int argc, char **argv){
  debug_log("%d\n", isScramble(argv[1], argv[2]));
  return 0;
}
