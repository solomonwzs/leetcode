#include "utils.h"


struct max_len{
  int width, heigth;
};


int maximalRectangle(char **matrix, int numRows, int numColumns){
  struct max_len *m=(struct max_len *)malloc(sizeof(struct max_len)
                                             *numRows*numColumns);
#define __m(_i, _j) (m[numColumns*(_i)+(_j)])
  for (int i=numRows-1; i>=0; --i){
    for (int j=numColumns-1; j>=0; --j){
      if (matrix[i][j]=='0'){
        __m(i, j).width=0;
        __m(i, j).heigth=0;
      } else{
        __m(i, j).width=j!=numColumns-1?__m(i, j+1).width+1:1;
        __m(i, j).heigth=i!=numRows-1?__m(i+1, j).heigth+1:1;
      }
    }
  }

  int max=0;
  for (int i=0; i<numRows; ++i){
    for (int j=0; j<numColumns; ++j){
      if (__m(i, j).width!=0){
        int pre_width=i==0?0:__m(i-1, j).width;
        int width=numColumns;
        int area=0;
        for (int k=i; width>pre_width && k<numRows && matrix[k][j]=='1'; ++k){
          if (width>__m(k, j).width){
            width=__m(k, j).width;
            area=width*(k-i+1);
          } else{
            area+=width;
          }
          max=area>max?area:max;
        }
        
        int pre_height=j==0?0:__m(i, j-1).heigth;
        int heigth=numRows;
        area=0;
        for (int k=j; heigth>pre_height && k<numColumns && matrix[i][k]=='1'; ++k){
          if (heigth>__m(i, k).heigth){
            heigth=__m(i, k).heigth;
            area=(k-j+1)*heigth;
          } else{
            area+=heigth;
          }
          max=area>max?area:max;
        }
      }
    }
  }
#undef __m
  free(m);
  return max;
}


int main(int argc, char **argv){
  char *matrix[]={
    (char *)"0110",
    (char *)"0000",
    (char *)"0010",
    (char *)"0101",
    (char *)"0001",
    (char *)"0010"
  };
  debug_log("%d\n", maximalRectangle(matrix, 6, 4));
  return 0;
}
