#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        
        vector<int> posOf(N);
        for(int i = 0; i < N; ++i){
            posOf[nums1[i]] = i;
        }
        
        vector<int> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = posOf[nums2[i]];
        }
        
        long long res = 0;
        ordered_set<int> orderedSet;
        for(int i = 0; i < N; ++i){
            long long leftLess = orderedSet.order_of_key(v[i]);
            long long rightGreater = (N - 1) - v[i] - (i - leftLess);
            res += (leftLess * rightGreater);
            orderedSet.insert(v[i]);
        }
        
        return res;
    }
};