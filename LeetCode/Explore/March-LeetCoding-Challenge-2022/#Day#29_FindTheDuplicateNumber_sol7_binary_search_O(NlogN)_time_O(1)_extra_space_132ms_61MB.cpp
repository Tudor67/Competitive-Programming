class Solution {
private:
    int countLessOrEqual(vector<int>& nums, const int& K){
        int count = 0;
        for(int num: nums){
            if(num <= K){
                count += 1;
            }
        }
        return count;
    }
    
public:
    int findDuplicate(vector<int>& nums) {
        const int N = (int)nums.size() - 1;
        
        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(mid < countLessOrEqual(nums, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};