class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int N = seq.length();
        vector<int> answer(N);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(seq[i] == '('){
                st.push(i);
                answer[i] = st.size() % 2;
            }else{
                answer[i] = answer[st.top()];
                st.pop();
            }
        }
        return answer;
    }
};