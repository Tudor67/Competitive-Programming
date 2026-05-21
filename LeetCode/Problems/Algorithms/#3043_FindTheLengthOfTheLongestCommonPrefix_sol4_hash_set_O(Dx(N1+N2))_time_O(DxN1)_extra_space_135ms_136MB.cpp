class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        const int N1 = arr1.size();
        const int N2 = arr2.size();

        unordered_set<int> vis;
        for(int num: arr1){
            for(int prefix = num; prefix > 0; prefix /= 10){
                vis.insert(prefix);
            }
        }

        int maxCommonPrefix = 0;
        for(int num: arr2){
            for(int prefix = num; prefix > 0; prefix /= 10){
                if(vis.contains(prefix)){
                    maxCommonPrefix = max(maxCommonPrefix, prefix);
                    break;
                }
            }
        }

        if(maxCommonPrefix > 0){
            return to_string(maxCommonPrefix).length();
        }

        return 0;
    }
};