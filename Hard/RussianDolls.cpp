class Solution {
public:
    vector<int> arr;
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int answer = 0;
        for(vector<int> e : envelopes) {
            if (arr.size() == 0) {
                arr.push_back(e[1]);
                continue;
            }
            //cout << "Bitchass stop this shit";
            auto up = lower_bound(arr.begin(), arr.end(), e[1]);
            if(up == arr.end())
                arr.push_back(e[1]);
            else 
                arr[up - arr.begin()] = e[1];
        }
        //for (auto i : arr) cout << i << endl;
        return arr.size();
    }
};
