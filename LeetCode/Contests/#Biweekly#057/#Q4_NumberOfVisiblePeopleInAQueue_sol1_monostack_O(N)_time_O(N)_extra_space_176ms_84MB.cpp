class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int N = heights.size();
        vector<int> answer(N, 0);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && heights[st.top()] < heights[i]){
                answer[st.top()] += 1;
                st.pop();
            }
            if(!st.empty()){
                answer[st.top()] += 1;
            }
            st.push(i);
        }
        return answer;
    }
};