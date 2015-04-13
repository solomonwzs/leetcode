from collections import deque


class Solution:
    def numIslands(self, grid):
        row=len(grid)
        if row==0:
            return 0
        col=len(grid[0])

        flag=[([0]*col) for i in range(row)]

        ret=0
        for i in range(row):
            for j in range(col):
                if grid[i][j]=="1" and flag[i][j]==0:
                    ret+=1
                    queue=deque([(i, j)])
                    flag[i][j]=1
                    while len(queue)!=0:
                        pos=queue.popleft()

                        if pos[0]>0 and flag[pos[0]-1][pos[1]]==0 \
                                and grid[pos[0]-1][pos[1]]=="1":
                            flag[pos[0]-1][pos[1]]=1
                            queue.append((pos[0]-1, pos[1]))

                        if pos[1]<col-1 and flag[pos[0]][pos[1]+1]==0 \
                                and grid[pos[0]][pos[1]+1]=="1":
                            flag[pos[0]][pos[1]+1]=1
                            queue.append((pos[0], pos[1]+1))

                        if pos[0]<row-1 and flag[pos[0]+1][pos[1]]==0 \
                                and grid[pos[0]+1][pos[1]]=="1":
                            flag[pos[0]+1][pos[1]]=1
                            queue.append((pos[0]+1, pos[1]))

                        if pos[1]>0 and flag[pos[0]][pos[1]-1]==0 \
                                and grid[pos[0]][pos[1]-1]=="1":
                            flag[pos[0]][pos[1]-1]=1
                            queue.append((pos[0], pos[1]-1))

        return ret


if __name__=="__main__":
    s=Solution()
    print s.numIslands(["11000",
                        "11000",
                        "00100",
                        "00011"])
