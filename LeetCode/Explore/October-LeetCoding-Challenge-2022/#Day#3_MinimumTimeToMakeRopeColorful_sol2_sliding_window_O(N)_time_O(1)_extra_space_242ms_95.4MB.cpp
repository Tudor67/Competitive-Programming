class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int N = colors.length();
        
        int res = 0;
        int startPos = 0;
        while(startPos < N){
            int totalTime = 0;
            int maxTime = 0;
            int endPos = startPos;
            while(endPos < N && colors[startPos] == colors[endPos]){
                totalTime += neededTime[endPos];
                maxTime = max(maxTime, neededTime[endPos]);
                endPos += 1;
            }
            res += (totalTime - maxTime);
            startPos = endPos;
        }
        
        return res;
    }
};