class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int answer = 0;
        stack<int> stH;
        stack<int> stPos;
        for(int i = 0; i <= heights.size(); ++i){
            int h = (i < heights.size() ? heights[i] : 0);
            int lastPos = i;
            while(!stH.empty() && stH.top() > h){
                int area = stH.top() * (i - stPos.top());
                lastPos = stPos.top();
                answer = max(area, answer);
                stH.pop();
                stPos.pop();
            }
            stH.push(h);
            stPos.push(lastPos);
        }
        return answer;
    }
};