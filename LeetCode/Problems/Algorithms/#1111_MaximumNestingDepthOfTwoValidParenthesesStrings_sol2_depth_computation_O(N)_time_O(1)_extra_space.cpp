class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int N = seq.length();
        vector<int> answer(N);
        int depth = 0;
        for(int i = 0; i < N; ++i){
            if(seq[i] == '('){
                depth += 1;
                answer[i] = depth % 2;
            }else{
                answer[i] = depth % 2;
                depth -= 1;
            }
        }
        return answer;
    }
};