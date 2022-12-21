class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();

        vector<int> answer(N);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                answer[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return answer;
    }
};