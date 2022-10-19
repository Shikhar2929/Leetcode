class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            arr = [0]*10
            for j in range(9):
                temp = board[i][j]
                if temp == ".":
                    continue
                temp = int(temp)
                if(arr[temp]):
                    return False
                arr[temp] = 1
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                arr = [0] * 10 
                for ii in range(i, i + 3):
                    for jj in range(j, j +3):
                        temp = board[ii][jj]
                        if temp == ".":
                            continue
                        temp = int(temp)
                        if(arr[temp]):
                            return False
                        arr[temp] = 1
        for j in range(9):
            arr = [0]*10
            for i in range(9):
                temp = board[i][j]
                if temp == ".":
                    continue
                temp = int(temp)
                if(arr[temp]):
                    return False
                arr[temp] = 1
        return True
