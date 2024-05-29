class Solution {
private:
    void back(int i, unordered_map<int, int>& freq, vector<int>& nums, int k, int& res){
        if(i == (int)nums.size()){
            if(!freq.empty()){
                res += 1;
            }
        }else{
            back(i + 1, freq, nums, k, res);

            if(freq[nums[i] - k] == 0 && freq[nums[i] + k] == 0){
                freq[nums[i]] += 1;
                back(i + 1, freq, nums, k, res);
                freq[nums[i]] -= 1;
            }
        }
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, int> freq;
        int res = 0;
        back(0, freq, nums, k, res);

        return res;
    }
};