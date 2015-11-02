#include <stdio.h>

#define ROW 3
#define COLLUM 3
#define THE_END 9
#define FALSE 0
#define TRUE 1
#define STARTX 0
#define STARTY 0
#define OPEN 10
#define CLOSED 11

int explore(int x, int y, int pattern[ROW][COLLUM],int count);


int main(void)
{
  int i, j, Count, maze[ROW][COLLUM];

  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
      maze[i][j] = OPEN;
    }
  }
  Count = 0;
  explore(STARTX, STARTY, maze, Count);
  for (i=0; i<3; i++){
    printf("\n");
    for (j=0; j<3; j++){
      printf("%d ",maze[i][j] );
    }
  }
  return 0;
}

int explore(int x, int y,int pattern[ROW][COLLUM],int count)
{
  count++;
  printf("\nThe count is:%d\n", count );
  if ((x<0) || (x >(ROW-1)) || (y<0) || (y>(COLLUM-1))){
    return FALSE;
  }
  if(count == 10){
    printf("To vrikame\n");
    return TRUE;
  }
  /* to see if the block is closed*/
  if (pattern[x][y] < count ){
    return FALSE;
  }
  pattern[x][y] = count;
  if (explore(x+1, y, pattern, count) == TRUE){
    return TRUE;
  }
  if (explore(x-1, y, pattern, count) == TRUE){
    return TRUE;
  }
  if (explore(x, y-1, pattern, count) == TRUE){
    return TRUE;
  }
  if (explore(x, y+1, pattern, count) == TRUE){
    return TRUE;
  }
  pattern[x][y] = OPEN;
  printf("De vrikame tipota\n");
  return  FALSE;
}
