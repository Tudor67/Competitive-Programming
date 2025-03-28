class Solution {
private:
    const int INF = 2e9;

    vector<int> computePrefDominant(vector<int> nums){
        const int N = nums.size();

        vector<int> prefDominant(N, INF);
        unordered_map<int, int> freqOf;
        prefDominant[0] = nums[0];
        freqOf[nums[0]] = 1;

        for(int i = 1; i < N; ++i){
            freqOf[nums[i]] += 1;
            if(freqOf[nums[i]] * 2 > i + 1){
                prefDominant[i] = nums[i];
            }else if(freqOf[prefDominant[i - 1]] * 2 > i + 1){
                prefDominant[i] = prefDominant[i - 1];
            }
        }
        
        return prefDominant;
    }

public:
    int minimumIndex(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> prefDominant = computePrefDominant(nums);
        vector<int> suffDominant = computePrefDominant(vector<int>(nums.rbegin(), nums.rend()));
        reverse(suffDominant.begin(), suffDominant.end());

        for(int i = 0; i + 1 < N; ++i){
            if(prefDominant[i] == suffDominant[i + 1] && prefDominant[i] != INF){
                return i;
            }
        }

        return -1;
    }
};