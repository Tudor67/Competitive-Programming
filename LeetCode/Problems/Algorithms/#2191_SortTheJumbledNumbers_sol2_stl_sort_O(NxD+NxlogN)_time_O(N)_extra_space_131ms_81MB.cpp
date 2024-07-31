class Solution {
private:
    int getMappedVal(int x, vector<int>& mapping){
        int mappedVal = 0;
        int p10 = 1;
        do{
            mappedVal += p10 * mapping[x % 10];
            p10 *= 10;
            x /= 10;
        }while(x > 0);
        return mappedVal;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int N = nums.size();

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {getMappedVal(nums[i], mapping), i};
        }

        sort(v.begin(), v.end());

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            res[i] = nums[v[i].second];
        }

        return res;
    }
};