class Solution {
private:
    bool isPossible(vector<int>& nums, int operations){
        const int N = nums.size();

        if(2 * operations > N){
            return false;
        }

        for(int i = 0; i < operations; ++i){
            if(nums[i] == nums[N - operations + i]){
                return false;
            }
        }

        return true;
    }

public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int N = nums.size();

        int l = 0;
        int r = N / 2;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(nums, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return N - 2 * r;
    }
};