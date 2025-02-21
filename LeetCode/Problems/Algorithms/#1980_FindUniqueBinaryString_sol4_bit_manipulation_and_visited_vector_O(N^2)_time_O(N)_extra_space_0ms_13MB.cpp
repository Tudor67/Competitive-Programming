class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int N = nums.size();

        vector<bool> vis(N + 1, false);
        for(string& numStr: nums){
            int num = stoi(numStr, nullptr, 2);
            vis[min(N, num)] = true;
        }

        for(int num = 0; num <= N; ++num){
            if(!vis[num]){
                string numStr = bitset<20>(num).to_string();
                return numStr.substr(20 - N);
            }
        }

        return "";
    }
};