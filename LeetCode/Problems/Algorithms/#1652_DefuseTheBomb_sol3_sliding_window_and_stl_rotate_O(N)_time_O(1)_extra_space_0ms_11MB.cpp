class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int N = code.size();

        vector<int> res;
        res.reserve(N);

        int wSum = 0;
        for(int i = 0; i < abs(k); ++i){
            wSum += code[i];
        }
        res.push_back(wSum);

        for(int i = abs(k); i < abs(k) + N - 1; ++i){
            wSum += code[i % N];
            wSum -= code[i - abs(k)];
            res.push_back(wSum);
        }

        if(k > 0){
            rotate(res.begin(), res.begin() + 1, res.end());
        }else if(k < 0){
            rotate(res.begin(), res.begin() + (N + k), res.end());
        }

        return res;
    }
};