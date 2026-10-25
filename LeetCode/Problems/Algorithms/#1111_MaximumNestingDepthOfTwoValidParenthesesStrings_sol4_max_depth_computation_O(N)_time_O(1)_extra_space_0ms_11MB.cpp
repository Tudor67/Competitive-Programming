class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int N = seq.length();

        int maxDepth = 0;
        int currDepth = 0;
        for(char c: seq){
            if(c == '('){
                currDepth += 1;
                maxDepth = max(maxDepth, currDepth);
            }else{
                currDepth -= 1;
            }
        }

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            char c = seq[i];
            if(c == '('){
                currDepth += 1;
                res[i] = (int)(currDepth > maxDepth / 2);
            }else{
                currDepth -= 1;
                res[i] = (int)(currDepth >= maxDepth / 2);
            }
        }

        return res;
    }
};