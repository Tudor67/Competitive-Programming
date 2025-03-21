class Solution {
public:
    bool divideArray(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        for(auto& [num, numFreq]: freq){
            if(numFreq % 2 == 1){
                return false;
            }
        }

        return true;
    }
};