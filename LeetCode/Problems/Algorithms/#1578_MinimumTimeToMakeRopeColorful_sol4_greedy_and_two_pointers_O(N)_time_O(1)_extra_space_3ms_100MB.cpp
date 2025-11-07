class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int N = colors.length();

        int res = 0;

        int l = 0;
        while(l < N){
            int r = l;
            int maxTime = 0;
            int totalTime = 0;
            while(r < N && colors[l] == colors[r]){
                maxTime = max(maxTime, neededTime[r]);
                totalTime += neededTime[r];
                r += 1;
            }

            res += (totalTime - maxTime);

            l = r;
        }

        return res;
    }
};