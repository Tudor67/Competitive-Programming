class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int N = nums.size();
        
        deque<int> decDQ;
        for(int i = 0; i < N; ++i){
            if(decDQ.empty() || nums[decDQ.back()] > nums[i]){
                decDQ.push_back(i);
            }
        }
        
        deque<int> incDQ;
        for(int i = N - 1; i >= 0; --i){
            if(incDQ.empty() || nums[i] > nums[incDQ.front()]){
                incDQ.push_front(i);
            }
        }
        
        int maxRampWidth = 0;
        while(!decDQ.empty() && !incDQ.empty()){
            while(!incDQ.empty() && nums[decDQ.back()] > nums[incDQ.back()]){
                incDQ.pop_back();
            }
            if(!incDQ.empty() && nums[decDQ.back()] <= nums[incDQ.back()]){
                int rampWidth = incDQ.back() - decDQ.back();
                maxRampWidth = max(maxRampWidth, rampWidth);
            }
            decDQ.pop_back();
        }
        
        return maxRampWidth;
    }
};