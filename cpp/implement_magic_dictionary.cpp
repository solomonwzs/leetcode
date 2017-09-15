#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "utils.h"

using namespace std;


class MagicDictionary {
 private:
  vector<unordered_map<string, int>> mlist;
  unordered_set<string> od;
  unsigned maxLen;

 public:
  MagicDictionary() {
  }

  void buildDict(vector<string> dict) {
    this->maxLen = 0;
    for (vector<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
      this->od.insert(*it);
      if (this->maxLen < it->length()) {
        this->maxLen = it->length();
      }
    }
    this->mlist.resize(maxLen);

    for (vector<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
      for (unsigned i = 0; i < it->length(); ++i) {
        char ch = (*it)[i];
        (*it)[i] = '*';

        auto item = this->mlist[i].find(*it);
        if (item == this->mlist[i].end()) {
          this->mlist[i].insert(pair<string, int>(*it, 1));
        } else {
          item->second += 1;
        }

        (*it)[i] = ch;
      }
    }
  }

  bool search(string word) {
    auto s = this->od.find(word);
    bool find = s != this->od.end();

    bool match = false;
    for (unsigned i = 0; i < word.length() && i < this->maxLen; ++i) {
      char ch = word[i];
      word[i] = '*';

      auto item = this->mlist[i].find(word);
      if (item != this->mlist[i].end()) {
        if (!find || item->second > 1) {
          match = true;
        }
      }

      word[i] = ch;

      if (match) {
        break;
      }
    }
    return match;
  }
};


int
main(int argc, char ** argv) {
  MagicDictionary *obj = new MagicDictionary();
  vector<string> dict = {"hello", "hallo", "leetcode"};
  obj->buildDict(dict);

  debug_log("%d\n", obj->search("hello"));
  debug_log("%d\n", obj->search("hhllo"));
  debug_log("%d\n", obj->search("hell"));
  debug_log("%d\n", obj->search("leetcoded"));

  delete obj;

  return 0;
}
