class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int N = energy.size();

        int res = energy[N - 1];
        for(int i = N - k; i < N; ++i){
            int sum = 0;
            for(int j = i; j >= 0; j -= k){
                sum += energy[j];
                res = max(res, sum);
            }
        }

        return res;
    }
};