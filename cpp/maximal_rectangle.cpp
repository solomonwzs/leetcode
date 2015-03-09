#include "utils.h"


static int largest_rectangle_area(int len[], int n, int max_len_idx[]){
  if (n==0){
    return 0;
  }

  int size=0;
  int max=0;
  int i=0;
  while (i<n || size>0){
    if (i<n && (size==0 || len[i]>=len[max_len_idx[size-1]])){
      ++size;
      max_len_idx[size-1]=i;
      ++i;
    } else{
      int max_height=len[max_len_idx[size-1]];
      int left_idx=size==1?0:max_len_idx[size-2]+1;
      int width=i-left_idx;
      int area=max_height*width;
      if (max<area){
        max=area;
      }

      --size;
    }
  }

  return max;
}


int maximalRectangle(char **matrix, int numRows, int numColumns){
  int *max_width=(int *)malloc(sizeof(int)*numRows*numColumns);
  int *max_height=(int *)malloc(sizeof(int)*numRows*numColumns);
  int *idx=(int *)malloc(sizeof(int)*(numColumns>numRows?numColumns:numRows));
  int *len=(int *)malloc(sizeof(int)*(numColumns>numRows?numColumns:numRows));

#define __p(_m, _i, _j) (_m[numColumns*(_i)+(_j)])
  for (int i=numRows-1; i>=0; --i){
    for (int j=numColumns-1; j>=0; --j){
      if (matrix[i][j]=='0'){
        __p(max_width, i, j)=0;
        __p(max_height, i, j)=0;
      } else{
        __p(max_width, i, j)=j!=numColumns-1?__p(max_width, i, j+1)+1:1;
        __p(max_height, i, j)=i!=numRows-1?__p(max_height, i+1, j)+1:1;
      }
    }
  }

  int max=0;
  for (int i=0; i<numRows; ++i){
    len[i]=0;
  }
  for (int j=0; j<numColumns; ++j){
    bool exec=false;
    for (int i=0; i<numRows; ++i){
      if (!exec && __p(max_width, i, j)!=len[i]-1){
        exec=true;
      }
      len[i]=__p(max_width, i, j);
    }

    if (exec){
      int area=largest_rectangle_area(len, numRows, idx);
      if (max<area){
        max=area;
      }
    }
  }

  for (int i=0; i<numColumns; ++i){
    len[i]=0;
  }
  for (int i=0; i<numRows; ++i){
    bool exec=false;
    for (int j=0; j<numColumns; ++j){
      if (!exec && __p(max_height, i, j)!=len[j]-1){
        exec=true;
      }
      len[j]=__p(max_height, i, j);
    }

    if (exec){
      int area=largest_rectangle_area(len, numColumns, idx);
      if (max<area){
        max=area;
      }
    }
  }
#undef __p

  free(len);
  free(idx);
  free(max_height);
  free(max_width);
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
