class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int answer = 0;
        if(!left.empty()){
            answer = max(answer, *max_element(left.begin(), left.end()));
        }
        if(!right.empty()){
            answer = max(answer, n - *min_element(right.begin(), right.end()));
        }
        return answer;
    }
};