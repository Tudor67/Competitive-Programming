#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        vector<int> counts(N);
        ordered_set<pair<int, int>> orderedSet;
        map<int, int> count;
        for(int i = N - 1; i >= 0; --i){
            counts[i] = orderedSet.order_of_key({nums[i], 0});
            count[nums[i]] += 1;
            orderedSet.insert({nums[i], count[nums[i]]});
        }
        return counts;
    }
};