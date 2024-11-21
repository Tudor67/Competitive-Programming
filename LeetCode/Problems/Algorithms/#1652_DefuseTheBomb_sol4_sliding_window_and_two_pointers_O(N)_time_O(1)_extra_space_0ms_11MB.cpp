class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int N = code.size();

        if(k == 0){
            return vector<int>(N, 0);
        }

        int p1 = 1;
        int p2 = k;
        if(k < 0){
            k = -k;
            p1 = N - k;
            p2 = N - 1;
        }

        vector<int> res(N);
        int wSum = accumulate(code.begin() + p1, code.begin() + p2 + 1, 0);
        for(int i = 0; i < N; ++i){
            res[i] = wSum;
            wSum -= code[p1 % N];
            wSum += code[(p2 + 1) % N];
            p1 += 1;
            p2 += 1;
        }

        return res;
    }
};