class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int K) {
        const int N = points.size();
        int answer = INT_MIN;
        
        multiset<int> yxDiffs;
        yxDiffs.insert(points[0][1] - points[0][0]);
        for(int i = 0, j = 1; j < N; ++j){
            while(i < j && points[j][0] - points[i][0] > K){
                yxDiffs.erase(yxDiffs.find(points[i][1] - points[i][0]));
                i += 1;
            }
            if(i < j){
                int lDiff = *yxDiffs.rbegin();
                int rSum = points[j][0] + points[j][1];
                answer = max(lDiff + rSum, answer);
            }
            yxDiffs.insert(points[j][1] - points[j][0]);
        }
        
        return answer;
    }
};