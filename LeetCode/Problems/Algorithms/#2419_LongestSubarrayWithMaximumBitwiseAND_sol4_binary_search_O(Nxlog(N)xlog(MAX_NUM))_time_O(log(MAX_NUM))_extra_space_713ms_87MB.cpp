class Solution {
private:
    void updateFreq(vector<int>& freq, int num, int contrib){
        for(int bit = 0; bit < (int)freq.size(); ++bit){
            if((num >> bit) & 1){
                freq[bit] += contrib;
            }
        }
    }

    int computeAND(vector<int>& freq, const int TARGET_LEN){
        int andVal = 0;
        for(int bit = 0; bit < (int)freq.size(); ++bit){
            if(freq[bit] >= TARGET_LEN){
                andVal |= (1 << bit);
            }
        }
        return andVal;
    }

    int computeMaxAND(vector<int>& nums, const int TARGET_LEN, const int MAX_BIT){
        const int N = nums.size();

        int maxAND = 0;
        vector<int> freq(MAX_BIT + 1);
        for(int i = 0; i < N; ++i){
            updateFreq(freq, nums[i], 1);
            if(i >= TARGET_LEN){
                updateFreq(freq, nums[i - TARGET_LEN], -1);
            }
            maxAND = max(maxAND, computeAND(freq, TARGET_LEN));
        }

        return maxAND;
    }

public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_BIT = log2(MAX_NUM + 1);

        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(computeMaxAND(nums, mid, MAX_BIT) == MAX_NUM){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};