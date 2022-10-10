class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int N = colors.length();
        
        int res = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            if(j == N - 1 || colors[j] != colors[j + 1]){
                int totalTime = accumulate(neededTime.begin() + i, neededTime.begin() + j + 1, 0);
                int maxTime = *max_element(neededTime.begin() + i, neededTime.begin() + j + 1);
                res += (totalTime - maxTime);
                i = j + 1;
            }
        }
        
        return res;
    }
};