#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stdio.h>

using namespace std;

class TimeMap {
 public:
  unordered_map<string, map<int, string>> dict;

  TimeMap() {
  }

  void set(string key, string value, int timestamp) {
    this->dict[key].insert({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto elem = this->dict[key].upper_bound(timestamp);
    if (elem == this->dict[key].begin()) {
      return "";
    } else {
      elem--;
      return elem->second;
    }
  }
};

int
main(int argc, char **argv) {
  TimeMap *obj = new TimeMap();
  obj->set("foo", "bar", 1);
  cout << obj->get("foo", 1) << endl;
  cout << obj->get("foo", 3) << endl;
  obj->set("foo", "bar2", 4);
  cout << obj->get("foo", 4) << endl;
  cout << obj->get("foo", 5) << endl;
  delete(obj);

  obj = new TimeMap();
  obj->set("love", "high", 10);
  obj->set("love", "low", 20);
  printf("[%s]\n", obj->get("love", 5).c_str());
  delete(obj);

  return 0;
}
