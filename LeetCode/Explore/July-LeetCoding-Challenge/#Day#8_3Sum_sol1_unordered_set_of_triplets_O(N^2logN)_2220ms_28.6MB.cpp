class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& input_nums) {
        unordered_map<int, int> cnt;
        for(int num: input_nums){
            cnt[num] += 1;
        }
        
        vector<int> nums;
        for(const pair<int, int>& p: cnt){
            int max_freq = (p.first == 0 ? 3 : 2);
            for(int k = 1; k <= min(max_freq, p.second); ++k){
                nums.push_back(p.first);
            }
            cnt[p.first] = min(max_freq, p.second);
        }
        
        set<tuple<int, int, int>> triplet_set;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                cnt[nums[i]] -= 1;
                cnt[nums[j]] -= 1;
                int complement = -(nums[i] + nums[j]);
                if(cnt.count(complement) && cnt[complement] > 0){
                    vector<int> v = {nums[i], nums[j], complement};
                    sort(v.begin(), v.end());
                    triplet_set.insert({v[0], v[1], v[2]});
                }
                cnt[nums[i]] += 1;
                cnt[nums[j]] += 1;
            }
        }
        
        vector<vector<int>> answer(triplet_set.size(), vector<int>(3));
        int i = 0;
        for(const tuple<int, int, int>& t: triplet_set){
            answer[i][0] = get<0>(t);
            answer[i][1] = get<1>(t);
            answer[i][2] = get<2>(t);
            i += 1;
        }
        
        return answer;
    }
};