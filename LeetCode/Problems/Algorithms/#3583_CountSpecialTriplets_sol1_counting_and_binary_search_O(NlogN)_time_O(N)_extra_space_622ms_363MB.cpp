class Solution {
private:
    int countNum(int num, int l, int r, unordered_map<int, vector<int>>& indicesOf){
        if(l > r || !indicesOf.count(num)){
            return 0;
        }
        vector<int>& ids = indicesOf[num];
        return upper_bound(ids.begin(), ids.end(), r) -
               lower_bound(ids.begin(), ids.end(), l);
    }

public:
    int specialTriplets(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        unordered_map<int, vector<int>> indicesOf;
        for(int i = 0; i < N; ++i){
            indicesOf[nums[i]].push_back(i);
        }

        int validTriplets = 0;
        for(int i = 0; i < N; ++i){
            int num = nums[i];
            long long leftCount = countNum(2 * num, 0, i - 1, indicesOf);
            long long rightCount = countNum(2 * num, i + 1, N - 1, indicesOf);
            validTriplets += (leftCount * rightCount) % MODULO;
            validTriplets %= MODULO;
        }

        return validTriplets;
    }
};