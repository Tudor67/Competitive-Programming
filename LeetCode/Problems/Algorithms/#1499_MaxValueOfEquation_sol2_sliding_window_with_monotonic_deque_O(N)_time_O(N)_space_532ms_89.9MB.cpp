class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int K) {
        int answer = INT_MIN;
        deque<int> maxDQ;
        maxDQ.push_back(0);
        for(int j = 1; j < points.size(); ++j){
            while(!maxDQ.empty() && points[j][0] - points[maxDQ.front()][0] > K){
                maxDQ.pop_front();
            }
            if(!maxDQ.empty()){
                int lDiff = points[maxDQ.front()][1] - points[maxDQ.front()][0];
                int rSum = points[j][0] + points[j][1];
                answer = max(lDiff + rSum, answer);
            }
            int rDiff = points[j][1] - points[j][0];
            while(!maxDQ.empty() && points[maxDQ.back()][1] - points[maxDQ.back()][0] <= rDiff){
                maxDQ.pop_back();
            }
            maxDQ.push_back(j);
        }
        return answer;
    }
};