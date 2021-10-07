class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;
        set<vector<int>> incSubsequencesSet;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            bool isIncreasing = true;
            int bitCount = 0;
            int prevOneBit = -1;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    if(prevOneBit >= 0){
                        if(nums[prevOneBit] > nums[bit]){
                            isIncreasing = false;
                        }
                    }
                    bitCount += 1;
                    prevOneBit = bit;
                }
            }
            if(isIncreasing && bitCount >= 2){
                vector<int> incSubsequence;
                for(int bit = 0; bit < N; ++bit){
                    if((mask >> bit) & 1){
                        incSubsequence.push_back(nums[bit]);
                    }
                }
                incSubsequencesSet.insert(incSubsequence);
            }
        }
        vector<vector<int>> incSubsequences(incSubsequencesSet.begin(), incSubsequencesSet.end());
        return incSubsequences;
    }
};