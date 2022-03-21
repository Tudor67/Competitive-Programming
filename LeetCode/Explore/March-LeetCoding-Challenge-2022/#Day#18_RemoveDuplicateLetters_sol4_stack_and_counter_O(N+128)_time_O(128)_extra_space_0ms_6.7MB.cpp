class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(128);
        for(char c: s){
            count[c] += 1;
        }
        
        string st;
        vector<bool> inStack(128, false);
        for(char c: s){
            if(!inStack[c]){
                while(!st.empty() && st.back() > c && count[st.back()] >= 1){
                    inStack[st.back()] = false;
                    st.pop_back();
                }
                st.push_back(c);
                inStack[c] = true;
            }
            count[c] -= 1;
        }
        
        return st;
    }
};