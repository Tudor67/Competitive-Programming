class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        int res = 0;
        for(const pair<const int, int>& P: freq){
            int numFreq = P.second;

            if(numFreq == 1){
                return -1;
            }

            if(numFreq % 3 == 0){
                res += numFreq / 3;
            }else if(numFreq % 3 == 2){
                res += 1 + (numFreq - 2) / 3;
            }else if(numFreq % 3 == 1){
                res += 2 + (numFreq - 4) / 3;
            }
        }

        return res;
    }
};