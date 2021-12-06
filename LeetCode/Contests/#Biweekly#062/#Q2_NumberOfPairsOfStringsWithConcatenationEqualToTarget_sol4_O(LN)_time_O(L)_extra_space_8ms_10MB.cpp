class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        const int N = nums.size();
        const int TARGET_LEN = target.length();
        
        vector<int> suffFreq(TARGET_LEN + 1);
        for(const string& S: nums){
            const int S_LEN = S.length();
            if(S_LEN >= TARGET_LEN){
                continue;
            }
            if(target.compare(TARGET_LEN - S_LEN, S_LEN, S) == 0){
                suffFreq[S_LEN] += 1;
            }
        }
        
        int pairsCount = 0;
        for(const string& S: nums){
            const int S_LEN = S.length();
            if(S_LEN >= TARGET_LEN){
                continue;
            }
            if(target.compare(0, S_LEN, S) == 0){
                pairsCount += suffFreq[TARGET_LEN - S_LEN];
                pairsCount -= (int)(2 * S_LEN == TARGET_LEN && target.compare(TARGET_LEN - S_LEN, S_LEN, S) == 0);
            }
        }
        
        return pairsCount;
    }
};