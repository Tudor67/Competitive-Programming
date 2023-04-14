class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        const int N = pushed.size();

        stack<int> st;
        int poppedIndex = 0;

        for(int num: pushed){
            st.push(num);
            while(!st.empty() && st.top() == popped[poppedIndex]){
                poppedIndex += 1;
                st.pop();
            }
        }

        return st.empty();
    }
};