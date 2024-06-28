class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        const int N = nums.size();

        int maxLen = 0;
        deque<int> minDQ;
        deque<int> maxDQ;
        int l = 0;
        for(int r = 0; r < N; ++r){
            while(!minDQ.empty() && nums[minDQ.back()] >= nums[r]){
                minDQ.pop_back();
            }
            minDQ.push_back(r);

            while(!maxDQ.empty() && nums[maxDQ.back()] <= nums[r]){
                maxDQ.pop_back();
            }
            maxDQ.push_back(r);

            while(!minDQ.empty() && !maxDQ.empty() && nums[maxDQ.front()] - nums[minDQ.front()] > limit){
                if(minDQ.front() == l){
                    minDQ.pop_front();
                }
                if(maxDQ.front() == l){
                    maxDQ.pop_front();
                }
                l += 1;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};