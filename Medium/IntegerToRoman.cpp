class Solution {
public:
    string intToRoman(int num) {
        int arr[] = {1000, 500, 100, 50, 10, 5, 1};
        string greek[] = {"M", "D", "C", "L", "X", "V", "I"};
        int i = 0;
        string answer = "";
        while(i < 7 && num > 0){
            if(num >= arr[i]){
                answer += greek[i];
                num -= arr[i];
                
                continue;
            }
            else {
                if((arr[i] == 5 || arr[i] == 10) && num == arr[i]-1)
                {
                    num -= (arr[i] - 1);
                    answer += "I" + greek[i];
                    
                }
                else if((arr[i] == 50 || arr[i] == 100) && num >= arr[i] - 10){
                    num -= (arr[i] - 10);
                    answer += "X" + greek[i];
                   
                }
                else if((arr[i] == 500 || arr[i] == 1000) && num >= arr[i] - 100)
                {
                    num -= (arr[i] - 100);
                    answer += "C" + greek[i];
                    
                }
                else 
                    i++;
            }
        }
        return answer;
    }
};
