class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> finalIntervals;
        int start = newInterval[0];
        int end = newInterval[1];
        bool flag = true;
        for(auto n : intervals) {
            int currstart = n[0];
            int currend = n[1];
            if(currstart < start && currend < start)
                finalIntervals.push_back(n);
            else if(currstart <= start && currend > end)
            {   
                finalIntervals.push_back(n);
                flag = false;
            }
            else if(currstart < start && currend <= end)
                start = currstart;
            if(currstart <= end && currend > end) 
                end = currend;
            else if(currstart > end && currend > end && flag)
            {
                finalIntervals.push_back({start, end});
                flag = false;
            }
            if(currstart > end && currend > end) {
                finalIntervals.push_back(n);
            }
        }
        if(flag)
            finalIntervals.push_back({start, end});
        return finalIntervals;
    }
};
