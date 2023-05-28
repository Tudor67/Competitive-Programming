class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int N = nums1.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
            [&](int lhs, int rhs){
                return (nums2[lhs] > nums2[rhs]);
            });
        
        long long res = 0;
        long long maxSum1 = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < N; ++i){
            int index = p[i];

            minHeap.push(nums1[index]);
            maxSum1 += nums1[index];

            if((int)minHeap.size() > k){
                maxSum1 -= minHeap.top();
                minHeap.pop();
            }

            if((int)minHeap.size() == k){
                long long minNums2 = nums2[index];
                long long prod = maxSum1 * minNums2;
                res = max(res, prod);
            }
        }

        return res;
    }
};