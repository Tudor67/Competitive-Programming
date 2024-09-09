#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int N = nums.size();

        ordered_set<pair<int, int>> s;
        for(int i = 1; i <= dist + 1; ++i){
            s.insert({nums[i], i});
        }

        long long sum = 0;
        for(int i = 0; i < k - 1; ++i){
            sum += s.find_by_order(i)->first;
        }

        long long minCost = nums[0] + sum;
        for(int i = dist + 2; i < N; ++i){
            if(s.order_of_key({nums[i], i}) <= k - 2){
                sum -= s.find_by_order(k - 2)->first;
                sum += nums[i];
            }
            s.insert({nums[i], i});

            if(s.order_of_key({nums[i - dist - 1], i - dist - 1}) <= k - 2){
                sum -= nums[i - dist - 1];
                sum += s.find_by_order(k - 1)->first;
            }
            s.erase({nums[i - dist - 1], i - dist - 1});

            long long cost = nums[0] + sum;
            minCost = min(minCost, cost);
        }

        return minCost;
    }
};