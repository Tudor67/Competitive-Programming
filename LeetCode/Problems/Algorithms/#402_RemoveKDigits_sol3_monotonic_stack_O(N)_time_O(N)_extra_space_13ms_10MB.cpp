class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char c: num){
            while(!st.empty() && st.back() > c && k >= 1){
                st.pop_back();
                k -= 1;
            }
            if(!st.empty() || c != '0'){
                st.push_back(c);
            }
        }

        while(!st.empty() && k >= 1){
            st.pop_back();
            k -= 1;
        }

        if(st.empty()){
            st.push_back('0');
        }
        
        return st;
    }
};