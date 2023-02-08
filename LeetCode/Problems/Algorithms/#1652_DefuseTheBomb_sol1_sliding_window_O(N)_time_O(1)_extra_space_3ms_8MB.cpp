class Solution {
private:
    void solve(vector<int>& code, int p1, int p2, vector<int>& res){
        const int N = code.size();
        int sum = accumulate(code.begin() + p1, code.begin() + p2 + 1, 0);
        for(int i = 0; i < N; ++i){
            res[i] = sum;
            sum -= code[p1 % N];
            sum += code[(p2 + 1) % N];
            p1 += 1;
            p2 += 1;
        }
    }

public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int N = code.size();

        vector<int> res(N);
        if(k == 0){
            // stop
        }else if(k < 0){
            solve(code, N - abs(k), N - 1, res);
        }else if(k > 0){
            solve(code, 1, k,  res);
        }

        return res;
    }
};