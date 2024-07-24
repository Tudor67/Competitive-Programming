class Solution {
private:
    void solve(const int L, const int R, const int DIRECTION, const string& S,
               vector<int>& pairOf, string& res){
        int i = (DIRECTION == 1 ? L : R);
        while(L <= i && i <= R){
            if(S[i] == '('){
                solve(i + 1, pairOf[i] - 1, -1, S, pairOf, res);
                i = pairOf[i] + 1;
            }else if(S[i] == ')'){
                solve(pairOf[i] + 1, i - 1, 1, S, pairOf, res);
                i = pairOf[i] - 1;
            }else{
                res += S[i];
                i += DIRECTION;
            }
        }
    }

public:
    string reverseParentheses(string s) {
        const int N = s.length();

        vector<int> pairOf(N);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                pairOf[i] = st.top();
                pairOf[st.top()] = i;
                st.pop();
            }
        }

        string res;
        solve(0, N - 1, 1, s, pairOf, res);

        return res;
    }
};