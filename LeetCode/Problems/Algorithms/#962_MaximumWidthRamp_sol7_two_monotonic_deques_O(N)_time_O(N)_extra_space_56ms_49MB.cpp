class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int N = nums.size();

        deque<int> prefDQ;
        for(int i = 0; i < N; ++i){
            if(prefDQ.empty() || nums[prefDQ.back()] > nums[i]){
                prefDQ.push_back(i);
            }
        }

        deque<int> suffDQ;
        for(int i = N - 1; i >= 0; --i){
            if(suffDQ.empty() || nums[i] > nums[suffDQ.front()]){
                suffDQ.push_front(i);
            }
        }

        int maxWidth = 0;
        while(!prefDQ.empty() && !suffDQ.empty()){
            int i = prefDQ.front();
            prefDQ.pop_front();

            while(!suffDQ.empty() && nums[i] <= nums[suffDQ.front()]){
                maxWidth = max(maxWidth, suffDQ.front() - i);
                suffDQ.pop_front();
            }
        }

        return maxWidth;
    }
};