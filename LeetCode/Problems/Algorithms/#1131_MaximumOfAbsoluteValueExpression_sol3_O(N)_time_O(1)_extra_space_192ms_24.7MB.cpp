class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        const vector<pair<int, int>> SIGN_PAIRS = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        int answer = 0;
        for(const pair<int, int>& SIGN_PAIR: SIGN_PAIRS){
            int sign1 = SIGN_PAIR.first;
            int sign2 = SIGN_PAIR.second;
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
            for(int i = 0; i < arr1.size(); ++i){
                int val = arr1[i] + sign1 * arr2[i] + sign2 * i;
                minVal = min(val, minVal);
                maxVal = max(val, maxVal);
            }
            answer = max(maxVal - minVal, answer);
        }
        return answer;
    }
};