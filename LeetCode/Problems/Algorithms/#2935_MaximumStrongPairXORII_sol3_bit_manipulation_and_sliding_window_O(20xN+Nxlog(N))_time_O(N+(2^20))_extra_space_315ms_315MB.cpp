class Solution {
private:
    void updateOperation(int num, const int MAX_BITS, vector<int>& freq, const int VAL){
        int prefMask = 1;
        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            prefMask = (prefMask << 1) | ((num >> bit) & 1);
            freq[prefMask] += VAL;
        }
    }

    int getMaxXOR(int num, const int MAX_BITS, vector<int>& freq){
        int maxXOR = 0;
        int prefMask = 1;
        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            prefMask = (prefMask << 1) | ((num >> bit) & 1);
            if(freq[prefMask ^ 1] >= 1){
                prefMask ^= 1;
                maxXOR = (maxXOR << 1) | 1;
            }else{
                maxXOR = (maxXOR << 1);
            }
        }
        return maxXOR;
    }

public:
    int maximumStrongPairXor(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_BITS = 20;
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> freq((1 << (MAX_BITS + 1)));
        
        int maxXOR = 0;
        int j = 0;
        for(int i = 0; i < N; ++i){
            while(j < N && 2 * sortedNums[i] >= sortedNums[j]){
                updateOperation(sortedNums[j], MAX_BITS, freq, 1);
                j += 1;
            }
            maxXOR = max(maxXOR, getMaxXOR(sortedNums[i], MAX_BITS, freq));
            updateOperation(sortedNums[i], MAX_BITS, freq, -1);
        }
        
        return maxXOR;
    }
};