class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int N = nums.size();

        priority_queue<int> maxHeap;
        int numFreq = 0;
        for(int i = 0; i < N; ++i){
            numFreq += 1;
            if(i == N - 1 || nums[i] != nums[i + 1]){
                maxHeap.push(numFreq);
                numFreq = 0;
            }
        }

        int res = N;
        while((int)maxHeap.size() >= 2){
            int a = maxHeap.top(); maxHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();

            if(a - 1 >= 1){
                maxHeap.push(a - 1);
            }
            if(b - 1 >= 1){
                maxHeap.push(b - 1);
            }

            res -= 2;
        }

        return res;
    }
};