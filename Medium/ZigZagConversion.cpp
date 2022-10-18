class Solution {
public:
    string convert(string s, int numRows) {
        string arr[numRows];
        int i = 0;
        bool up = true;
        for(auto n : s)
        {
            arr[i] += n;
            if(numRows == 1)
                continue;
            if(up && i < numRows - 1)
                i++;
            else if(up )
            {
                i--;
                up = false;
            }
            else if(i > 0)
                i--;
            else
            {
                i++;
                up = true;
            }   
        }
        string answer = "";
        for(int i = 0; i < numRows; i++)
            answer += arr[i];
        return answer;
    }
    
};
