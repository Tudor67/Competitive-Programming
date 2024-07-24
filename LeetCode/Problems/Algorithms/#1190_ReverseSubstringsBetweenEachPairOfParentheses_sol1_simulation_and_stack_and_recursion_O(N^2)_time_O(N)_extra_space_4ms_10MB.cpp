class Solution {
private:
    string f(const int L, const int R, const string& S, vector<int>& pairOf){
        string res;

        int i = L;
        while(i <= R){
            if(S[i] == '('){
                string subRes = f(i + 1, pairOf[i] - 1, S, pairOf);
                res.append(subRes.rbegin(), subRes.rend());
                i = pairOf[i] + 1;
            }else{
                res += S[i];
                i += 1;
            }
        }

        return res;
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
                pairOf[st.top()] = i;
                st.pop();
            }
        }

        return f(0, N - 1, s, pairOf);
    }
};