class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int N = nums.size();

        vector<int> freq(N + 1);
        for(int num: nums){
            freq[num] += 1;
        }

        const int MAX_FREQ = *max_element(freq.begin(), freq.end());
        vector<vector<int>> res(MAX_FREQ);
        for(int num = 0; num <= N; ++num){
            while(freq[num] > 0){
                freq[num] -= 1;
                res[freq[num]].push_back(num);
            }
        }

        return res;
    }
};