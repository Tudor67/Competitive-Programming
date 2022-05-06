class Solution {
public:
    int halveArray(vector<int>& nums) {
        const int N = nums.size();
        const double TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0.0);
        
        priority_queue<double> maxHeap(nums.begin(), nums.end());
        double sum = TOTAL_SUM;
        int minOperations = 0;
        while(sum > TOTAL_SUM / 2){
            double num = maxHeap.top();
            maxHeap.pop();
            
            sum -= num / 2;
            maxHeap.push(num / 2);
            
            minOperations += 1;
        }
        
        return minOperations;
    }
};