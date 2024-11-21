class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int N = code.size();

        vector<int> res(N);
        int wSum = 0;
        if(k > 0){
            wSum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
        }else if(k < 0){
            wSum = accumulate(code.end() + k, code.end(), 0);
        }

        for(int i = 0; i < N; ++i){
            res[i] = wSum;
            if(k > 0){
                wSum += code[(i + k + 1) % N];
                wSum -= code[(i + 1) % N];
            }else if(k < 0){
                wSum += code[i];
                wSum -= code[(i + k + N) % N];
            }
        }

        return res;
    }
};