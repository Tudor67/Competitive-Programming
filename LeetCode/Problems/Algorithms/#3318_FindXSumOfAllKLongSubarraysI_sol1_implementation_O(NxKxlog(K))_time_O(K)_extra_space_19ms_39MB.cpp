class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int N = nums.size();

        vector<int> res(N - k + 1);
        unordered_map<int, int> freqOf;

        for(int i = 0; i + k - 1 < N; ++i){
            freqOf.clear();
            for(int j = i; j <= i + k - 1; ++j){
                freqOf[nums[j]] += 1;
            }

            vector<pair<int, int>> v;
            for(auto [num, numFreq]: freqOf){
                v.push_back({numFreq, num});
            }

            sort(v.rbegin(), v.rend());

            int sum = 0;
            for(int j = 0; j < min(x, (int)v.size()); ++j){
                sum += (v[j].first * v[j].second);
            }

            res[i] = sum;
        }

        return res;
    }
};