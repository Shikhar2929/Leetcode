class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> forward_maxes;
        vector<pair<int,int>> backward_maxes;
        int curr_max = 0;
        for(int i=0; i < height.size(); i++ )
        {
            if(height[i] > curr_max){
                curr_max = height[i];
                forward_maxes.push_back(make_pair(curr_max, i));
            }
        }
        curr_max = 0;
        for(int i=height.size() - 1; i >= 0; i-- )
        {
            if(height[i] > curr_max){
                curr_max = height[i];
                backward_maxes.push_back(make_pair(curr_max, i));
            }
        }
        int answer = 0;
        int i = 0;
        int j = 0;
        while(i < forward_maxes.size() && j < backward_maxes.size())
        {
            if(min(forward_maxes[i].first, backward_maxes[j].first) * abs(forward_maxes[i].second - backward_maxes[j].second) > answer){
                answer = min(forward_maxes[i].first, backward_maxes[j].first) * abs(forward_maxes[i].second - backward_maxes[j].second);
            cout<< i << j; 
            }
            if(forward_maxes[i].first > backward_maxes[j].first)
                j++;
            else if (forward_maxes[i].first < backward_maxes[j].first)
                i++;
            else 
            {
                if(i != forward_maxes.size() - 1)
                    i++;
                else
                    j++;
            }
        }
        return answer;
    }
};
