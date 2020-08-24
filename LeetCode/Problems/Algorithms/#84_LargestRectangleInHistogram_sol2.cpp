class Solution {
public:
    int largestRectangleArea(vector<int>& initial_heights) {
        const int N = initial_heights.size();
        vector<int> heights(N + 2, 0);
        for(int i = 1; i <= N; ++i){
            heights[i] = initial_heights[i - 1];
        }
        
        int answer = 0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i <= N + 1; ++i){
            int idx = st.top();
            while(heights[idx] > heights[i]){
                st.pop();
                answer = max((i - (st.top() + 1)) * heights[idx], answer);
                idx = st.top();
            }
            st.push(i);
        }
        
        return answer;
    }
};