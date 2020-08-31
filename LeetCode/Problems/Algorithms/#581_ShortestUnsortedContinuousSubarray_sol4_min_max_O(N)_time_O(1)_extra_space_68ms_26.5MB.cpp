class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        bool unsorted_started = false;
        int min_elem = INT_MAX;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] > nums[i]){
                unsorted_started = true;
            }
            if(unsorted_started){
                min_elem = min(nums[i], min_elem);
            }
        }
        
        unsorted_started = false;
        int max_elem = INT_MIN;
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] > nums[i + 1]){
                unsorted_started = true;
            }
            if(unsorted_started){
                max_elem = max(nums[i], max_elem);
            }
        }
        
        int l = 0;
        int r = 0;
        if(unsorted_started){
            for(int i = 0; i < N; ++i){
                if(nums[i] > min_elem){
                    l = i;
                    break;
                }
            }
            
            for(int i = N - 1; i >= 0; --i){
                if(nums[i] < max_elem){
                    r = i;
                    break;
                }
            }
        }
        
        int answer = r - l + 1;
        if(answer <= 1){
            answer = 0;
        }
        
        return answer;
    }
};