#include <string>
#include <vector>
#include "utils.h"

using namespace std;

struct point{
  int row, col;
  point(int a, int b):row(a), col(b){}
};

#define bp(_b, _p) \
    _b[_p.row][_p.col]

#define point_up(_p) \
    point(_p.row-1, _p.col)

#define point_down(_p) \
    point(_p.row+1, _p.col)

#define point_left(_p) \
    point(_p.row, _p.col-1)

#define point_right(_p) \
    point(_p.row, _p.col+1)



class Solution{
 public:
  void solve(vector< vector<char> > &board){
    int row=board.size();
    if (row==0){
      return;
    }
    int col=board[0].size();

    for (int i=0; i<col; ++i){
      if (board[0][i]=='O'){
        this->mark(board, row, col, point(0, i));
      }
      if (board[row-1][i]=='O'){
        this->mark(board, row, col, point(row-1, i));
      }
    }

    for (int i=0; i<row; ++i){
      if (board[i][0]=='O'){
        this->mark(board, row, col, point(i, 0));
      }
      if (board[i][col-1]=='O'){
        this->mark(board, row, col, point(i, col-1));
      }
    }
    for (int i=0; i<row; ++i){
      for (int j=0; j<col; ++j){
        if (board[i][j]!='o'){
          board[i][j]='X';
        } else{
          board[i][j]='O';
        }
      }
    }
  }

 private:
  void mark(vector< vector<char> > &board, int row, int col, point p){
    vector<point> list;
    list.push_back(p);
    bp(board, p)='o';

    unsigned i=0;
    while (i<list.size()){
      point q=list[i];

      if (q.row-1>=0 && bp(board, point_up(q))=='O'){
        bp(board, point_up(q))='o';
        list.push_back(point_up(q));
      }

      if (q.row+1<row && bp(board, point_down(q))=='O'){
        bp(board, point_down(q))='o';
        list.push_back(point_down(q));
      }

      if (q.col-1>=0 && bp(board, point_left(q))=='O'){
        bp(board, point_left(q))='o';
        list.push_back(point_left(q));
      }

      if (q.col+1<col && bp(board, point_right(q))=='O'){
        bp(board, point_right(q))='o';
        list.push_back(point_right(q));
      }
      ++i;
    }
  }
};


int main(int argc, char **argv){
  string str= "XXXX"
              "XOOX"
              "XXOX"
              "XOXX";
  vector< vector<char> > board;
  for (int i=0; i<4; ++i){
    vector<char> row;
    for (int j=0; j<4; ++j){
      row.push_back(str[i*4+j]);
    }
    board.push_back(row);
  }

  Solution s;
  s.solve(board);

  for (int i=0; i<4; ++i){
    for (int j=0; j<4; ++j){
      printf("%c", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}
