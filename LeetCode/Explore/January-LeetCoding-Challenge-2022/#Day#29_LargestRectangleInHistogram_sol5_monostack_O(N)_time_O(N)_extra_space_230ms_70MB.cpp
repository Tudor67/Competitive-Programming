class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        
        stack<int> st;
        vector<int> nextSmaller(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && heights[st.top()] > heights[i]){
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> prevSmaller(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i = 0; i < N; ++i){
            int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};