#include <set>
#include <string>
#include <vector>

class Solution {
 public:
  std::string destCity(std::vector<std::vector<std::string>>& paths) {
    std::set<std::string> ends;
    for (auto path : paths) {
      ends.insert(path[1]);
    }
    for (auto path : paths) {
      ends.erase(path[0]);
    }
    return *ends.begin();
  }
};

int main(int argc, char **argv) {
  return 0;
}
