class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int N = nums.size();

        unordered_set<string> numsSet(nums.begin(), nums.end());
        for(int mask = 0; mask <= N; ++mask){
            string s(N, '0');
            for(int bit = 0; bit < N; ++bit){
                s[bit] = char('0' + ((mask >> bit) & 1));
            }
            if(!numsSet.count(s)){
                return s;
            }
        }

        return "";
    }
};