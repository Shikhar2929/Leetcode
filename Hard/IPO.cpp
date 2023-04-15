class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int curr_capital = w;
        vector<pair<int, int>> arr; 
        for (int i = 0; i < profits.size(); i++) {
            arr.push_back(make_pair(capital[i], profits[i]));
        }
        sort(arr.begin(), arr.end());
        int j = 0;
        priority_queue<int> diff;
        for (int i = 0; i < k;i++) {
            while (arr[j].first <= curr_capital && j < arr.size()) {
                diff.push(arr[j].second);
                j++;
            }
            if (diff.size() == 0) {
                break;
            }
            int temp = diff.top();
            diff.pop();
            if (temp < 0) break;
            cout << temp << endl;
            curr_capital += temp;
        }
        return curr_capital;
    }
};
