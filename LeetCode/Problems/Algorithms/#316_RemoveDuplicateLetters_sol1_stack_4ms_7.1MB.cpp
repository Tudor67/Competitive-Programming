class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(128, 0);
        for(char c: s){
            cnt[c] += 1;
        }
        
        stack<char> st;
        vector<bool> inStack(128, false);
        for(char c: s){
            cnt[c] -= 1;
            if(inStack[c]){
                continue;
            }
            while(!st.empty() && st.top() > c && cnt[st.top()] >= 1){
                inStack[st.top()] = false;
                st.pop();
            }
            st.push(c);
            inStack[c] = true;
        }
        
        string answer;
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};