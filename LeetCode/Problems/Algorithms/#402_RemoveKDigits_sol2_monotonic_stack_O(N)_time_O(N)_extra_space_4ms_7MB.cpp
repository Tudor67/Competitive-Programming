class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char c: num){
            while(!st.empty() && st.back() > c && k > 0){
                st.pop_back();
                k -= 1;
            }
            if(c == '0' && st.empty()){
                continue;
            }else{
                st.push_back(c);
            }
        }
        
        while(!st.empty() && k > 0){
            st.pop_back();
            k -= 1;
        }
        
        if(st.empty()){
            st = "0";
        }
        
        return st;
    }
};