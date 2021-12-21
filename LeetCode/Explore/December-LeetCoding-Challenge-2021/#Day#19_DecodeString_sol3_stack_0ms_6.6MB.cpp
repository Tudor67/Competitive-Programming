class Solution {
public:
    string decodeString(string s) {
        s = "1[" + s + "]";
        
        const int N = s.length();
        stack<pair<int, string>> st;
        
        int multFactor = 0;
        for(int i = 0; i < N - 1; ++i){
            if(isdigit(s[i])){
                multFactor = 10 * multFactor + (s[i] - '0');
            }else if(s[i] == '['){
                st.push({multFactor, ""});
                multFactor = 0;
            }else if(s[i] == ']'){
                multFactor = st.top().first;
                string substr = st.top().second;
                st.pop();
                while(multFactor > 0){
                    st.top().second += substr;
                    multFactor -= 1;
                }
            }else{
                st.top().second += s[i];
            }
        }
        
        return st.top().second;
    }
};