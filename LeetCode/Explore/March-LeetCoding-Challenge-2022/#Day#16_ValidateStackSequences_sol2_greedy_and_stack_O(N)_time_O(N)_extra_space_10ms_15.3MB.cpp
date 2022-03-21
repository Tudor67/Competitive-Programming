class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        const int N = pushed.size();
        
        stack<int> st;
        for(int i = 0, j = 0; i < N; ++i){
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                ++j;
            }
        }
        
        return st.empty();
    }
};