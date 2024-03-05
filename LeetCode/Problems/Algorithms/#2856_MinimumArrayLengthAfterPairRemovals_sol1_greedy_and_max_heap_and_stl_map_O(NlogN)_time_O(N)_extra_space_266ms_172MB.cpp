class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int N = nums.size();

        map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        priority_queue<int> maxHeap;
        for(const pair<const int, int>& P: freq){
            int numFreq = P.second;
            maxHeap.push(numFreq);
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