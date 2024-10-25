#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> arr0 = {nums[0]};
        vector<int> arr1 = {nums[1]};

        ordered_set<pair<int, int>> set0; set0.insert({nums[0], 0});
        ordered_set<pair<int, int>> set1; set1.insert({nums[1], 1});
        
        for(int i = 2; i < N; ++i){
            int g0 = (int)set0.size() - set0.order_of_key({nums[i], i});
            int g1 = (int)set1.size() - set1.order_of_key({nums[i], i});
            if((g0 > g1) || (g0 == g1 && arr0.size() <= arr1.size())){
                arr0.push_back(nums[i]);
                set0.insert({nums[i], i});
            }else{
                arr1.push_back(nums[i]);
                set1.insert({nums[i], i});
            }
        }
        
        vector<int> res;
        copy(arr0.begin(), arr0.end(), back_inserter(res));
        copy(arr1.begin(), arr1.end(), back_inserter(res));
        
        return res;
    }
};