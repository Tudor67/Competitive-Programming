class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> freqOf;
        for(int p: power){
            freqOf[p] += 1;
        }

        map<int, long long> maxDamage;
        maxDamage[freqOf.rbegin()->first + 3] = 0;
        for(auto it = freqOf.rbegin(); it != freqOf.rend(); it = next(it)){
            int p = it->first;
            long long pFreq = it->second;
            maxDamage[p] = max(maxDamage.upper_bound(p)->second,
                               p * pFreq + maxDamage.upper_bound(p + 2)->second);
        }

        return maxDamage.begin()->second;
    }
};