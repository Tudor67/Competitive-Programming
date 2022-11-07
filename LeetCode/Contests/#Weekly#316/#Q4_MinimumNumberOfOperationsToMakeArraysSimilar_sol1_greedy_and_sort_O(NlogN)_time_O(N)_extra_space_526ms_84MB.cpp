class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        const int N = nums.size();
        
        vector<int> sortedEvenNums;
        vector<int> sortedOddNums;
        for(int num: nums){
            if(num % 2 == 0){
                sortedEvenNums.push_back(num);
            }else{
                sortedOddNums.push_back(num);
            }
        }
        
        sort(sortedEvenNums.begin(), sortedEvenNums.end());
        sort(sortedOddNums.begin(), sortedOddNums.end());
        
        vector<int> sortedTarget = target;
        sort(sortedTarget.begin(), sortedTarget.end());
        
        long long res = 0;
        for(int i = N - 1; i >= 0; --i){
            if(sortedTarget[i] % 2 == 0){
                res += max(0, (sortedEvenNums.back() - sortedTarget[i]) / 2);
                sortedEvenNums.pop_back();
            }else{
                res += max(0, (sortedOddNums.back() - sortedTarget[i]) / 2);
                sortedOddNums.pop_back();
            }
        }
        
        return res;
    }
};