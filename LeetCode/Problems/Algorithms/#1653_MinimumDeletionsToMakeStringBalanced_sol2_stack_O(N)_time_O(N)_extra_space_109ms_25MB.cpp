class Solution {
public:
    int minimumDeletions(string s) {
        int minDeletions = 0;

        stack<char> st;
        for(char c: s){
            if(!st.empty() && st.top() == 'b' && c == 'a'){
                st.pop();
                minDeletions += 1;
            }else{
                st.push(c);
            }
        }

        return minDeletions;
    }
};