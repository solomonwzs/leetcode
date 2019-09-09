#include <cstdio>
#include <string>

using namespace std;

class Solution {
 public:
  string dayOfTheWeek(int day, int month, int year) {
    int d = 0;
    for (int i = 1971; i < year; ++i) {
      d += is_leap_year(i) ? 366 : 365;
    }
    for (int i = 1; i < month; ++i) {
      d += dom[i - 1];
      if (is_leap_year(year) && i == 2) {
        d += 1;
      }
    }
    d += day;
    return string(dow[d % 7]);
  }
 private:
  static const char *dow[];
  static const int dom[];

  static bool is_leap_year(int year) {
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
  };
};
  
const char *Solution::dow[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
const int Solution::dom[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char **argv) {
  Solution s;
  printf("%s\n", s.dayOfTheWeek(31, 8, 2019).c_str());
  printf("%s\n", s.dayOfTheWeek(18, 7, 1999).c_str());
  printf("%s\n", s.dayOfTheWeek(29, 2, 2016).c_str());
  printf("%s\n", s.dayOfTheWeek(1, 3, 2016).c_str());
  return 0;
}
