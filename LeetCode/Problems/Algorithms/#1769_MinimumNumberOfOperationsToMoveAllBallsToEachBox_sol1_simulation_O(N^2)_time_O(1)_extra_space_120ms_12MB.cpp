class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int N = boxes.size();

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(boxes[j] == '1'){
                    res[i] += abs(i - j);
                }
            }
        }

        return res;
    }
};