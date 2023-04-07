class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>,greater<int>> right;
    int lsize;
    int rsize;
    bool midVal;
    int middle;
    double median;
    MedianFinder() {
        lsize = 0;
        rsize = 0;
        middle = 0;
        midVal = 0;
        median = 0.0;
    }
    
    void addNum(int num) {
        if (lsize == 0 && rsize == 0 && !midVal) {
            middle = num;
            midVal = true;
            median = middle;
        }
        else if (lsize == 0 && rsize == 0) {
            midVal = false;
            left.push(min(num, middle));
            right.push(max(num, middle));
            lsize++;
            rsize++;
            median = (left.top() + right.top()) / 2.0;
        }
        else if (!midVal) {
            int l = left.top();
            int r = right.top();
            if (l < num) {
                right.push(num);
                middle = right.top();
                right.pop();
            } else {
                left.push(num);
                middle = left.top();
                left.pop();
            }
            midVal = true;
            median = middle;
        }
        else {
            int l = left.top();
            int r = right.top();
            int minMiddle = min(num, middle);
            int maxMiddle = max(num, middle);
            if (minMiddle > l) {
                right.push(minMiddle);
                right.push(maxMiddle);
                int temp = right.top();
                right.pop();
                left.push(temp);
            }
            else if (maxMiddle < r) {
                left.push(minMiddle);
                left.push(maxMiddle);
                int temp = left.top();
                left.pop();
                right.push(temp);
            }
            else {
                left.push(minMiddle);
                right.push(maxMiddle);
            }
            lsize++;
            rsize++;
            midVal = false;
            median = (left.top() + right.top()) / 2.0;
        }
    }
    double findMedian() {
        return median;
    }
};
