class Solution {
private:
    int computeMaxDigit(int num){
        int maxDigit = 0;
        while(num > 0){
            maxDigit = max(maxDigit, num % 10);
            num /= 10;
        }
        return maxDigit;
    }

public:
    int maxSum(vector<int>& nums) {
        const int N = nums.size();
        
        using MinHeap = priority_queue<int, vector<int>, greater<int>>;
        vector<MinHeap> minHeaps(10);
        for(int i = 0; i < N; ++i){
            int maxDigit = computeMaxDigit(nums[i]);
            MinHeap& h = minHeaps[maxDigit];
            h.push(nums[i]);
            if((int)h.size() > 2){
                h.pop();
            }
        }

        int res = -1;
        for(int digit = 1; digit <= 9; ++digit){
            MinHeap& h = minHeaps[digit];
            if((int)h.size() == 2){
                int a = h.top(); h.pop();
                int b = h.top(); h.pop();
                res = max(res, a + b);
            }
        }
        
        return res;
    }
};