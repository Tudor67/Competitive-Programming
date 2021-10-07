class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int N = seq.length();
        vector<int> answer(N);
        int depthParity = 0;
        for(int i = 0; i < N; ++i){
            if(seq[i] == '('){
                depthParity ^= 1;
                answer[i] = depthParity;
            }else{
                answer[i] = depthParity;
                depthParity ^= 1;
            }
        }
        return answer;
    }
};