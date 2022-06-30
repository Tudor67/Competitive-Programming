class Solution {
private:
    int countLessThanOrEqualTo(vector<int>& nums, const int& X){
        int count = 0;
        for(int num: nums){
            if(num <= X){
                count += 1;
            }
        }
        return count;
    }
    
public:
    int minMoves2(vector<int>& nums) {
        const int N = nums.size();
        
        // binary search the median of nums vector
        // median is the minimum number x with the property countLessThanOrEqualTo(nums, x) > nums.size() / 2
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        while(l != r){
            int mid = (l + r) / 2;
            if(2 * mid > (l + r)){
                // C++ rounding towards zero (issue for negative numbers)
                mid -= 1;
            }
            if(countLessThanOrEqualTo(nums, mid) > N / 2){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        int median = r;
        
        int minMoves = 0;
        for(int num: nums){
            minMoves += abs(num - median);
        }
        
        return minMoves;
    }
};