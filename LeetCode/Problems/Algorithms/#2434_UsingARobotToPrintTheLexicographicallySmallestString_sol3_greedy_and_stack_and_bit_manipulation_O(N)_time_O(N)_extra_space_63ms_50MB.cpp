class Solution {
private:
    bool containsSmallerElem(int mask, int threshold){
        int smallerMask = (1 << threshold) - 1;
        return ((mask & smallerMask) > 0);
    }

public:
    string robotWithString(string s) {
        const int N = s.length();
        
        vector<int> suffMask(N + 1);
        for(int i = N - 1; i >= 0; --i){
            suffMask[i] = (1 << (s[i] - 'a')) | suffMask[i + 1];
        }

        string res;
        stack<int> st;
        for(int i = 0; i < N; ++i){
            st.push(i);
            while(!st.empty() && !containsSmallerElem(suffMask[i + 1], s[st.top()] - 'a')){
                res += s[st.top()];
                st.pop();
            }
        }

        return res;
    }
};