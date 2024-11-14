class Solution {
private:
    void updateFreq(vector<int>& freq, int contrib, int num){
        for(int bit = 0; bit < (int)freq.size(); ++bit){
            if((num >> bit) & 1){
                freq[bit] += contrib;
            }
        }
    }

    int getWindowOR(vector<int>& freq){
        int windowOR = 0;
        for(int bit = 0; bit < (int)freq.size(); ++bit){
            if(freq[bit] > 0){
                windowOR |= (1 << bit);
            }
        }
        return windowOR;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_BIT = 30;
        const int INF = 1e9;

        int minLen = INF;
        vector<int> freq(MAX_BIT + 1);
        int l = 0;
        for(int r = 0; r < N; ++r){
            updateFreq(freq, 1, nums[r]);
            while(l <= r && getWindowOR(freq) >= k){
                minLen = min(minLen, r - l + 1);
                updateFreq(freq, -1, nums[l]);
                l += 1;
            }
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};