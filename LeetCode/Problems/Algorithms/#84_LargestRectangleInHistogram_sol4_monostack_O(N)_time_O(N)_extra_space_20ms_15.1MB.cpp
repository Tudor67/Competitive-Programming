class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Main idea:
        //   The largest rectangle which passes through the index i and has a height equal to heights[i]
        //   will have a left bound at the first height lower than heights[i] to the left and
        //   a right bound at the first height lower than heights[i] to the right.
        // Details:
        //   leftIdx[i]  = index of the first shorter building (< heights[i]) to the left of i;
        //   rightIdx[i] = index of the first shorter building (< heights[i]) to the right of i;
        //   Values of leftIdx and rightIdx can be simply computed with a monostack.
        // In other words:
        //   1.) heights[leftIdx[i]] < heights[i] > heights[rightIdx[i]];
        //   2.) heights[j] >= heights[i], where j in [leftIdx[i] + 1, rightIdx[i] - 1]
        //   3.) leftIdx[i] < i < rightIdx[i];
        //   4.) area[i] = heights[i] * (rightIdx[i] - leftIdx[i] - 1);
        //   5.) answer = max(area[0], area[1], ... area[i], ... area[N - 1]);
        // Complexity:
        //   Time: O(N)
        //   Extra-Space: O(N)
        const int N = heights.size();
        stack<int> st;
        
        vector<int> leftIdx(N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftIdx[i] = -1;
            }else{
                leftIdx[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> rightIdx(N);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightIdx[i] = N;
            }else{
                rightIdx[i] = st.top();
            }
            st.push(i);
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            int area = heights[i] * (rightIdx[i] - leftIdx[i] - 1);
            answer = max(area, answer);
        }
        
        return answer;
    }
};