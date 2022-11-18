class Solution {
public:
    int trap(vector<int>& height) {
        int m=0;
        for(int i = 0;i < height.size();i++)
            m = height[i] > height[m] ? i : m;
        cout << m;
        int curr_max = 0;
        int answer = 0;
        for(int i=0;i < m;i++){
            curr_max = max(curr_max, height[i]);
            answer += curr_max - height[i];
        }
        curr_max=0;
        for(int i = height.size() - 1;i > m;i--){
            curr_max = max(curr_max, height[i]);
            answer += curr_max - height[i];
        }
        return answer;
    }
};
