class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int N = energy.size();

        vector<int> maxEnergy(N + 1);
        for(int i = N - 1; i >= 0; --i){
            maxEnergy[i] = energy[i] + maxEnergy[min(i + k, N)];
        }

        return *max_element(maxEnergy.begin(), maxEnergy.begin() + N);
    }
};