class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        arr = []
        check = [0] * (bound + 1)
        for i in range(30):
            for j in range(30):
                if (x ** i + y ** j > bound):
                    break
                if(check[x ** i + y ** j]):
                    continue
                arr.append(x ** i + y ** j)
                check[x ** i + y **j] = 1
        return arr
