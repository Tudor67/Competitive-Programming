class Solution {
public:
    int scoreOfParentheses(string S) {
        const int N = S.length();
        vector<int> score(N, 0);
        stack<int> activePositions;
        stack<int> st;
        for(int r = 0; r < N; ++r){
            if(S[r] == '('){
                st.push(r);
            }else{
                int l = st.top();
                st.pop();
                if(l + 1 == r){
                    score[l] = 1;
                    activePositions.push(l);
                }else{
                    while(!activePositions.empty() && l < activePositions.top()){
                        score[l] += 2 * score[activePositions.top()];
                        score[activePositions.top()] = 0;
                        activePositions.pop();
                    }
                    activePositions.push(l);
                }
            }
        }
        int answer = 0;
        while(!activePositions.empty()){
            answer += score[activePositions.top()];
            activePositions.pop();
        }
        return answer;
    }
};