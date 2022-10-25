#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        const int N = nums1.size();
        
        long long res = 0;
        ordered_set<pair<int, int>> diffSet;
        for(int i = N - 1; i >= 0; --i){
            res += (int)diffSet.size() - diffSet.order_of_key({nums1[i] - nums2[i], i});
            diffSet.insert({nums1[i] - nums2[i] + diff, i});
        }
        
        return res;
    }
};