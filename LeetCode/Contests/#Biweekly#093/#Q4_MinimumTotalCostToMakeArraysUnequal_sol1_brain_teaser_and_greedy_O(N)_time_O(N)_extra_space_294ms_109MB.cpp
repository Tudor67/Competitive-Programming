class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();

        long long res = 0;
        int totalSize = 0;
        vector<int> count(N + 1);
        for(int i = 0; i < N; ++i){
            if(nums1[i] == nums2[i]){
                count[nums1[i]] += 1;
                totalSize += 1;
                res += i;
            }
        }

        int mostFreqNum = max_element(count.begin(), count.end()) - count.begin();
        for(int i = 0; i < N && 2 * count[mostFreqNum] > totalSize; ++i){
            if(nums1[i] != nums2[i]){
                if(nums1[i] != mostFreqNum && nums2[i] != mostFreqNum){
                    totalSize += 1;
                    res += i;
                }
            }
        }

        if(2 * count[mostFreqNum] > totalSize){
            res = -1;
        }

        return res;
    }
};