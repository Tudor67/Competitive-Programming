class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int N = seq.length();
        
        vector<int> res(N);
        int currDepth = 0;
        for(int i = 0; i < N; ++i){
            if(seq[i] == '('){
                currDepth += 1;
                res[i] = (currDepth % 2);
            }else{
                res[i] = (currDepth % 2);
                currDepth -= 1;
            }
        }

        return res;
    }
};