class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int SHIFT = -MIN_NUM;
        
        vector<int> count(MAX_NUM - MIN_NUM + 1);
        for(int num: nums){
            count[num + SHIFT] += 1;
        }
        
        vector<int> sortedNums;
        sortedNums.reserve(N);
        for(int num = MIN_NUM; num <= MAX_NUM; ++num){
            while(count[num + SHIFT] > 0){
                count[num + SHIFT] -= 1;
                sortedNums.push_back(num);
            }
        }
        
        return sortedNums;
    }
};