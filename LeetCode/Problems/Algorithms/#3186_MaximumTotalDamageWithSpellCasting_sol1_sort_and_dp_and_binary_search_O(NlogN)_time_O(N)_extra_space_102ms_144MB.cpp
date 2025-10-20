class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        const int N = power.size();

        vector<int> sortedPowers = power;
        sort(sortedPowers.begin(), sortedPowers.end());

        // maxDamage[i]: max total damage we can cast with sortedPowers[i .. N - 1]
        vector<long long> maxDamage(N + 1);

        long long currPower = 0;
        for(int i = N - 1; i >= 0; --i){
            if(i + 1 < N && sortedPowers[i] == sortedPowers[i + 1]){
                currPower += sortedPowers[i];
            }else{
                currPower = sortedPowers[i];
            }
            int j = upper_bound(sortedPowers.begin() + i, sortedPowers.end(), sortedPowers[i] + 2)
                    - sortedPowers.begin();
            maxDamage[i] = max(maxDamage[i + 1], currPower + maxDamage[j]);
        }

        return maxDamage[0];
    }
};