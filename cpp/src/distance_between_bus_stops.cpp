#include <vector>
#include <cstdio>

using namespace std;

class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int all = 0;
    int part = 0;
    int a = min(start, destination);
    int b = max(start, destination);

    for (unsigned i = 0; i < distance.size(); ++i) {
      if (a <= (int)i && (int)i < b) {
        part += distance[i];
      }
      all += distance[i];
    }
    return min(part, all - part);
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto distance = vector<int>{1,2,3,4};
    printf("%d\n", s.distanceBetweenBusStops(distance, 0, 1));
  }
  {
    auto distance = vector<int>{1,2,3,4};
    printf("%d\n", s.distanceBetweenBusStops(distance, 0, 2));
  }
  {
    auto distance = vector<int>{1,2,3,4};
    printf("%d\n", s.distanceBetweenBusStops(distance, 0, 3));
  }
  return 0;
}
