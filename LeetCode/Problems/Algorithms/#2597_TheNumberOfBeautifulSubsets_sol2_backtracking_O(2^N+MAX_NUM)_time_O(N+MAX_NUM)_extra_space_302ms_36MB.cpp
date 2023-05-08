class Solution {
private:
    bool contains(vector<int>& count, int num){
        return (0 <= num && num < (int)count.size() && count[num] >= 1);
    }

    void back(int i, vector<int>& count, vector<int>& nums, int k, int& res){
        if(i >= (int)nums.size()){
            res += 1;
        }else{
            back(i + 1, count, nums, k, res);
            
            if(!contains(count, nums[i] - k) && !contains(count, nums[i] + k)){
                count[nums[i]] += 1;
                back(i + 1, count, nums, k, res);
                count[nums[i]] -= 1;
            }
        }
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        int res = -1;
        vector<int> count(MAX_NUM + 1);
        back(0, count, nums, k, res);
        
        return res;
    }
};