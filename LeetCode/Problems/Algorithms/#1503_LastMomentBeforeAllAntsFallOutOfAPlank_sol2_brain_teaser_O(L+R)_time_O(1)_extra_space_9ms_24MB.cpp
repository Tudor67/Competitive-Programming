class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        if(!left.empty()){
            lastMoment = *max_element(left.begin(), left.end());
        }
        if(!right.empty()){
            lastMoment = max(lastMoment, n - *min_element(right.begin(), right.end()));
        }
        return lastMoment;
    }
};