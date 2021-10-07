class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> answer(T.size(), 0);
        
        stack<int> st;
        for(int i = (int)T.size() - 1; i >= 0; --i){
            while(!st.empty() && T[i] >= T[st.top()]){
                st.pop();
            }
            if(!st.empty() && T[i] < T[st.top()]){
                answer[i] = st.top() - i;
            }
            st.push(i);
        }
        
        return answer;
    }
};