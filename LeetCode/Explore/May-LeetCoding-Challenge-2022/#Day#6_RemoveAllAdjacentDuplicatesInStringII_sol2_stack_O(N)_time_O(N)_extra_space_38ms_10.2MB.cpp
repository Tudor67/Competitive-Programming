class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char c: s){
            if(st.empty() || st.top().first != c){
                st.emplace(c, 1);
            }else{
                st.top().second += 1;
                if(st.top().second == k){
                    st.pop();
                }
            }
        }
        
        string res;
        while(!st.empty()){
            char c = st.top().first;
            int cFreq = st.top().second;
            st.pop();
            res.append(cFreq, c);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};