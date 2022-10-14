class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int closestSum = sortedNums[0] + sortedNums[1] + sortedNums[2];
        for(int i = 0; i + 2 < N && closestSum != target; ++i){
            int j = i + 1;
            int k = N - 1;
            while(j < k){
                int sum = sortedNums[i] + sortedNums[j] + sortedNums[k];
                if(sum < target){
                    j += 1;
                }else if(sum > target){
                    k -= 1;
                }else{
                    j = k;
                }
                if(abs(target - sum) < abs(target - closestSum)){
                    closestSum = sum;
                }
            }
        }
        
        return closestSum;
    }
};