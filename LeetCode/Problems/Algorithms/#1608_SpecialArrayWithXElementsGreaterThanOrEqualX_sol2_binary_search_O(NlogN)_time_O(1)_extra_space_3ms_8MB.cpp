class Solution {
private:
    int countEqualOrGreater(vector<int>& nums, int x){
        int count = 0;
        for(int num: nums){
            if(x <= num){
                count += 1;
            }
        }
        return count;
    }
    
public:
    int specialArray(vector<int>& nums) {
        const int N = nums.size();
        
        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(mid < countEqualOrGreater(nums, mid)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        if(r == countEqualOrGreater(nums, r)){
            return r;
        }
        
        return -1;
    }
};