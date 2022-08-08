class Solution {
private:
    int computeDigitsSum(int num){
        int digitsSum = 0;
        while(num > 0){
            digitsSum += (num % 10);
            num /= 10;
        }
        return digitsSum;
    }
    
public:
    int maximumSum(vector<int>& nums) {
        const int MAX_DIGITS_SUM = 9 * 9;
        
        vector<vector<int>> buckets(MAX_DIGITS_SUM + 1);
        for(int num: nums){
            buckets[computeDigitsSum(num)].push_back(num);
        }
        
        int res = -1;
        for(int digitsSum = 1; digitsSum <= MAX_DIGITS_SUM; ++digitsSum){
            if((int)buckets[digitsSum].size() >= 2){
                vector<int>& v = buckets[digitsSum];
                
                for(int i = (int)v.size() - 1; i >= (int)v.size() - 2; --i){
                    for(int j = 0; j < i; ++j){
                        if(v[j] > v[i]){
                            swap(v[j], v[i]);
                        }
                    }
                }
                
                int sum = accumulate(v.end() - 2, v.end(), 0);
                res = max(res, sum);
            }
        }
        
        return res;
    }
};