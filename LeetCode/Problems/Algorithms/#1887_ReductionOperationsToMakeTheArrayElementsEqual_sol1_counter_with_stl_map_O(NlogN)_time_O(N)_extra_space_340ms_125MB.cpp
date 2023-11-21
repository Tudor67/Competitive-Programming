class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        const int N = nums.size();

        map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        int res = 0;
        while((int)freq.size() >= 2){
            res += prev(freq.end())->second;
            prev(prev(freq.end()))->second += prev(freq.end())->second;
            freq.erase(prev(freq.end()));
        }

        return res;
    }
};