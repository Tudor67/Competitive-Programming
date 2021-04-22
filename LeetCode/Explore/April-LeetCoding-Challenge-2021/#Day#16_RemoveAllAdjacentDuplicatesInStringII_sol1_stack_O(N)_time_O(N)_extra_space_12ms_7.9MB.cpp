class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char c: s){
            if(st.empty()){
                st.push({c, 1});
            }else{
                if(st.top().first == c){
                    st.top().second += 1;
                    if(st.top().second == k){
                        st.pop();
                    }
                }else{
                    st.push({c, 1});
                }
            }
        }
        
        string answer;
        while(!st.empty()){
            answer += string(st.top().second, st.top().first);
            st.pop();
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};