class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        const int N = p.size();

        sort(p.begin(), p.end(),
             [](const vector<int>& LHS, const vector<int>& RHS){
                return pair<int, int>{LHS[0], -LHS[1]} <
                       pair<int, int>{RHS[0], -RHS[1]};
             });

        int validPairs = 0;
        for(int i = 0; i < N; ++i){
            int yThreshold = INT_MIN;
            for(int j = i + 1; j < N; ++j){
                if(p[i][1] >= p[j][1] && p[j][1] >= yThreshold){
                    validPairs += 1;
                    yThreshold = p[j][1] + 1;
                }
            }
        }

        return validPairs;
    }
};