class Solution {
private:
    int countLessThanOrEqualTo(vector<int>& nums, const int& THRESHOLD){
        int count = 0;
        for(int num: nums){
            if(num <= THRESHOLD){
                count += 1;
            }
        }
        return count;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        // The kth largest num <=> the (N - k + 1)th num in the sorted vector
        // Binary search min x such that: N - k + 1 <= count(nums <= x)
        // Time: O(Nlog(MAX_NUM-MIN_NUM))
        // Space: O(1)
        int l = MIN_NUM;
        int r = MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(2 * mid > l + r){
                // C++ division problem (rounding towards zero is bad) for negative dividends
                mid = mid - 1;
            }
            if(countLessThanOrEqualTo(nums, mid) < N - k + 1){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return r;
    }
};