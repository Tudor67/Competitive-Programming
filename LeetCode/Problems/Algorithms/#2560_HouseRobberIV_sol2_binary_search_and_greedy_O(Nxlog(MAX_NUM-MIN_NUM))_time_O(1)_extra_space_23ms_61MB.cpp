class Solution {
private:
    int computeMaxStolenHouses(vector<int>& nums, int capability){
        const int N = nums.size();

        int maxStolenHouses = 0;
        int prevStolenHouse = INT_MIN;
        for(int i = 0; i < N; ++i){
            if(prevStolenHouse + 1 != i && nums[i] <= capability){
                maxStolenHouses += 1;
                prevStolenHouse = i;
            }
        }
        
        return maxStolenHouses;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int l = MIN_NUM;
        int r = MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeMaxStolenHouses(nums, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};