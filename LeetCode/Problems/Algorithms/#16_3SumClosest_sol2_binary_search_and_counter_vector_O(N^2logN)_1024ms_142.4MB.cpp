class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int SHIFT = 1e3;
        vector<int> cnt(2 * SHIFT + 5, 0);
        for(int num: nums){
            cnt[num + SHIFT] += 1;
        }
        
        sort(nums.begin(), nums.end());
        
        int answer = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 1; ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                int firstNum = nums[i];
                int secondNum = nums[j];
                int expectedThirdNum = target - (firstNum + secondNum);
                
                vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), expectedThirdNum);
                set<int> thirdNumCandidates;
                if(it != nums.end()){
                    thirdNumCandidates.insert(*it);
                }
                if(it != nums.begin()){
                    thirdNumCandidates.insert(*prev(it));
                }
                
                cnt[firstNum + SHIFT] -= 1;
                cnt[secondNum + SHIFT] -= 1;
                for(int thirdNum: thirdNumCandidates){
                    int sum = firstNum + secondNum + thirdNum;
                    if(cnt[thirdNum + SHIFT] > 0 && abs(target - sum) < abs(target - answer)){
                        answer = sum;
                    }
                }
                cnt[firstNum + SHIFT] += 1;
                cnt[secondNum + SHIFT] += 1;
            }
        }
        
        return answer;
    }
};