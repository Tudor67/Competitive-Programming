class Solution {
private:
    void lrReverse(const string& S, const int L, const int R, const vector<int>& PAIR_OF, string& res){
        int i = L;
        while(i <= R){
            if(S[i] == '('){
                rlReverse(S, i + 1, PAIR_OF[i] - 1, PAIR_OF, res);
                i = PAIR_OF[i] + 1;
            }else{
                res += S[i];
                i += 1;
            }
        }
    }

    void rlReverse(const string& S, const int L, const int R, const vector<int>& PAIR_OF, string& res){
        int i = R;
        while(i >= L){
            if(S[i] == ')'){
                lrReverse(S, PAIR_OF[i] + 1, i - 1, PAIR_OF, res);
                i = PAIR_OF[i] - 1;
            }else{
                res += S[i];
                i -= 1;
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
                int startIndex = st.top();
                st.pop();
                pairOf[startIndex] = i;
                pairOf[i] = startIndex;
            }
        }

        string res;
        lrReverse(s, 0, N - 1, pairOf, res);

        return res;
    }
};