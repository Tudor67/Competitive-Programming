class Solution {
private:
    void splitVector(vector<int>& nums, vector<int>& neg, vector<int>& pos){
        neg.clear();
        pos.clear();
        for(int num: nums){
            if(num < 0){
                neg.push_back(num);
            }else{
                pos.push_back(num);
            }
        }
    }

    long long countPairsWithProductLessOrEqual(const vector<int>& nums1, const vector<int>& nums2, long long threshold){
        long long validPairs = 0;
        int j = (int)nums2.size() - 1;
        for(int i = 0; i < (int)nums1.size(); ++i){
            while(j >= 0 && (long long)nums1[i] * (long long)nums2[j] > threshold){
                j -= 1;
            }
            validPairs += (j + 1);
        }
        return validPairs;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> neg1, pos1;
        splitVector(nums1, neg1, pos1);

        vector<int> neg2, pos2;
        splitVector(nums2, neg2, pos2);
        
        long long l = -1e10;
        long long r =  1e10;
        while(l != r){
            long long mid = (l + r) / 2;
            if(2 * mid > l + r){
                mid -= 1;
            }
            if(countPairsWithProductLessOrEqual(vector<int>(neg1.rbegin(), neg1.rend()),
                                                vector<int>(neg2.rbegin(), neg2.rend()), mid) +
               countPairsWithProductLessOrEqual(neg1, vector<int>(pos2.rbegin(), pos2.rend()), mid) +
               countPairsWithProductLessOrEqual(vector<int>(pos1.rbegin(), pos1.rend()), neg2, mid) +
               countPairsWithProductLessOrEqual(pos1, pos2, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};