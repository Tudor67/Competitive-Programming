class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        const int N = t.size();
        
        vector<int> nextGreater(N, N);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && t[st.top()] < t[i]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            nextGreater[i] = i;
            st.push(i);
        }
        
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            if(nextGreater[i] < N){
                answer[i] = nextGreater[i] - i;
            }
        }
        
        return answer;
    }
};