class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<vector<int>> res;
        res.reserve(k);

        using T3 = tuple<int, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;

        for(int i1 = 0; i1 < min(k, N1); ++i1){
            minHeap.push({nums1[i1] + nums2[0], i1, 0});
        }

        while(!minHeap.empty() && k >= 1){
            k -= 1;

            int i1 = get<1>(minHeap.top());
            int i2 = get<2>(minHeap.top());
            minHeap.pop();

            res.push_back({nums1[i1], nums2[i2]});

            if(i2 + 1 < N2){
                minHeap.push({nums1[i1] + nums2[i2 + 1], i1, i2 + 1});
            }
        }

        return res;
    }
};