class Solution {
public:
    string robotWithString(string s) {
        const int N = s.length();

        vector<char> suffMin(N + 1, 'z' + 1);
        for(int i = N - 1; i >= 0; --i){
            suffMin[i] = min(s[i], suffMin[i + 1]);
        }

        string res;
        stack<char> st;
        for(int i = 0; i < N; ++i){
            st.push(s[i]);
            while(!st.empty() && st.top() <= suffMin[i + 1]){
                res += st.top();
                st.pop();
            }
        }

        return res;
    }
};