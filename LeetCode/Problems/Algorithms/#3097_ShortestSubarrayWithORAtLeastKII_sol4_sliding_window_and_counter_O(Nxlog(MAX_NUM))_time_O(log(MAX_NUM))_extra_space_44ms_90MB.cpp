class Solution {
private:
    void add(int num, int contrib, vector<int>& freq){
        for(int bit = 0; bit < (int)freq.size(); ++bit){
            if((num >> bit) & 1){
                freq[bit] += contrib;
            }
        }
    }

    int computeOR(vector<int>& freq){
        int rangeOR = 0;
        for(int bit = 0; bit < (int)freq.size(); ++bit){
            if(freq[bit] >= 1){
                rangeOR |= (1 << bit);
            }
        }
        return rangeOR;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_BIT = floor(log2(MAX_NUM + 1));
        const int INF = 1e9;

        int minLen = INF;
        vector<int> freq(MAX_BIT + 1);

        int l = 0;
        for(int r = 0; r < N; ++r){
            add(nums[r], 1, freq);
            while(l <= r && computeOR(freq) >= k){
                minLen = min(minLen, r - l + 1);
                add(nums[l], -1, freq);
                l += 1;
            }
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};