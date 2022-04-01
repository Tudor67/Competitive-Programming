class Solution {
private:
    bool isValid(vector<int>& nums, int m, const int& MAX_SUM){
        int subarrays = 1;
        int sum = 0;
        for(int num: nums){
            sum += num;
            if(sum > MAX_SUM){
                subarrays += 1;
                sum = num;
            }
        }
        return (subarrays <= m);
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        
        int l = MAX_NUM;
        int r = TOTAL_SUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(nums, m, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};