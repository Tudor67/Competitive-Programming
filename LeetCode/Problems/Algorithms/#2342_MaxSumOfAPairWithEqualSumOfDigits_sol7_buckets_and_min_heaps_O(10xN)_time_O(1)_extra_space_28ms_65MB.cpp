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
        const int N = nums.size();
        const int MAX_DIGITS_SUM = 9 * 9;

        using MinHeap = priority_queue<int, vector<int>, greater<int>>;
        vector<MinHeap> minHeaps(MAX_DIGITS_SUM + 1);

        for(int num: nums){
            MinHeap& minHeap = minHeaps[computeDigitsSum(num)];
            minHeap.push(num);
            if((int)minHeap.size() > 2){
                minHeap.pop();
            }
        }

        int maxSum = -1;
        for(MinHeap& minHeap: minHeaps){
            if((int)minHeap.size() == 2){
                int a = minHeap.top(); minHeap.pop();
                int b = minHeap.top(); minHeap.pop();
                maxSum = max(maxSum, a + b);
            }
        }

        return maxSum;
    }
};