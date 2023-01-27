class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        const int N = nums.size();

        long long res = 0;
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        for(int i = 1; i <= k; ++i){
            int num = maxHeap.top();
            maxHeap.pop();
            
            res += num;
            
            maxHeap.push((num + 2) / 3);
        }
        
        return res;
    }
};