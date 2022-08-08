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
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int digitsSum = 1; digitsSum <= MAX_DIGITS_SUM; ++digitsSum){
            if((int)buckets[digitsSum].size() >= 2){
                for(int num: buckets[digitsSum]){
                    minHeap.push(num);
                    if((int)minHeap.size() == 3){
                        minHeap.pop();
                    }
                }
                
                int max2 = minHeap.top(); minHeap.pop();
                int max1 = minHeap.top(); minHeap.pop();
                
                res = max(res, max1 + max2);
            }
        }
        
        return res;
    }
};