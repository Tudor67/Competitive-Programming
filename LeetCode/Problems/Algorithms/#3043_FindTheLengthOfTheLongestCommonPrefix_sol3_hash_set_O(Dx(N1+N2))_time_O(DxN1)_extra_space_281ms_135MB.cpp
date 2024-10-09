class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixesSet1;
        for(int num: arr1){
            while(num > 0){
                prefixesSet1.insert(num);
                num /= 10;
            }
        }
        
        int res = 0;
        for(int num: arr2){
            while(num > 0 && !prefixesSet1.count(num)){
                num /= 10;
            }
            
            int len = 0;
            while(num > 0){
                len += 1;
                num /= 10;
            }
            res = max(res, len);
        }
        
        return res;
    }
};