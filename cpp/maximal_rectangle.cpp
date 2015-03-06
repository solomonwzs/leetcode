#include "utils.h"


struct max_len{
  int width, heigth;
};

int maximalRectangle(char **matrix, int numRows, int numColumns){
  struct max_len *m=(struct max_len *)malloc(sizeof(struct max_len)
                                             *numRows*numColumns);
  for (int i=numRows-1; i>=0; --i){
    for (int j=numColumns-1; j>=0; --j){
      struct max_len *cur=m+(numColumns*i+j);
      if (matrix[i][j]=='0'){
        cur->width=0;
        cur->heigth=0;
      } else{
        cur->width=j!=numColumns-1?m[numColumns*i+j+1].width+1:1;
        cur->heigth=i!=numRows-1?m[numColumns*(i+1)+j].heigth+1:1;
      }
    }
  }

  int max=0;
  for (int i=0; i<numRows; ++i){
    for (int j=0; j<numColumns; ++j){
      struct max_len *cur=m+(numColumns*i+j);
      if (cur->width!=0){
        int pre_width=i==0?0:m[numColumns*(i-1)+j].width;
        int width=numColumns;
        int area=0;
        for (int k=i; width>pre_width && k<numRows && matrix[k][j]=='1'; ++k){
          if (width>m[numColumns*k+j].width){
            width=m[numColumns*k+j].width;
            area=width*(k-i+1);
          } else{
            area+=width;
          }
          max=area>max?area:max;
        }
        
        int pre_height=j==0?0:m[numColumns*i+j-1].heigth;
        int heigth=numRows;
        area=0;
        for (int k=j; heigth>pre_height && k<numRows && matrix[i][k]=='1'; ++k){
          if (heigth>m[numColumns*i+k].heigth){
            heigth=m[numColumns*i+k].heigth;
            area=(k-j+1)*heigth;
          } else{
            area+=heigth;
          }
          max=area>max?area:max;
        }
      }
    }
  }

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
