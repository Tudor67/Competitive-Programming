class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int answer = 0;
        deque<int> minDQ;
        deque<int> maxDQ;
        for(int i = 0, j = 0; j < nums.size(); ++j){
            // update minDQ
            while(!minDQ.empty() && nums[j] < nums[minDQ.back()]){
                minDQ.pop_back();
            }
            minDQ.push_back(j);
            
            // update maxDQ
            while(!maxDQ.empty() && nums[j] > nums[maxDQ.back()]){
                maxDQ.pop_back();
            }
            maxDQ.push_back(j);
            
            // update answer
            while(!minDQ.empty() && !maxDQ.empty() && nums[maxDQ.front()] - nums[minDQ.front()] > limit){
                if(minDQ.front() < maxDQ.front()){
                    i = minDQ.front() + 1;
                    minDQ.pop_front();
                }else{
                    i = maxDQ.front() + 1;
                    maxDQ.pop_front();
                }
            }
            answer = max(j - i + 1, answer);
        }
        return answer;
    }
};