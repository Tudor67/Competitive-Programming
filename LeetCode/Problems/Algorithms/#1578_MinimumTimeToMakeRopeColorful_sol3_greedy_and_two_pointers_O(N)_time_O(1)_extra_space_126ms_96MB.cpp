class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int N = colors.length();

        int res = 0;

        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && colors[l] == colors[r]){
                r += 1;
            }

            int timeSum = accumulate(neededTime.begin() + l, neededTime.begin() + r, 0);
            int timeMax = *max_element(neededTime.begin() + l, neededTime.begin() + r);
            res += (timeSum - timeMax);
            
            l = r;
        }

        return res;
    }
};