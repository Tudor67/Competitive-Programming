class Solution {
private:
    int computeReverseNumber(int num){
        int revNum = 0;
        while(num > 0){
            revNum = revNum * 10 + (num % 10);
            num /= 10;
        }
        return revNum;
    }
    
public:
    int countDistinctIntegers(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> v(2 * N);
        for(int i = 0; i < N; ++i){
            v[i] = nums[i];
            v[i + N] = computeReverseNumber(nums[i]);
        }
        
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        return v.size();
    }
};