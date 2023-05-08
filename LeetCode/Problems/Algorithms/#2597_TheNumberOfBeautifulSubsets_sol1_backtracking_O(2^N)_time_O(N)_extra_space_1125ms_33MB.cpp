class Solution {
private:
    bool contains(unordered_map<int, int>& count, int num){
        unordered_map<int, int>::iterator it = count.find(num);
        return (it != count.end() && it->second >= 1);
    }

    void back(int i, unordered_map<int, int>& count, vector<int>& nums, int k, int& res){
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
        
        int res = -1;
        unordered_map<int, int> count;
        back(0, count, nums, k, res);
        
        return res;
    }
};