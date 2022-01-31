class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        
        stack<int> st;
        vector<int> nextSmaller(N);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nextSmaller[i] = N;
            }else{
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> prevSmaller(N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                prevSmaller[i] = -1;
            }else{
                prevSmaller[i] = st.top();
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