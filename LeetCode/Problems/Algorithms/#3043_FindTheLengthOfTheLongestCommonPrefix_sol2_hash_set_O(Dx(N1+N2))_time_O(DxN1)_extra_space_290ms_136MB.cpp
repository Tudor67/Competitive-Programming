class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set1;
        for(int num: arr1){
            while(num > 0){
                set1.insert(num);
                num /= 10;
            }
        }

        int maxLen = 0;
        for(int num: arr2){
            while(num > 0 && !set1.count(num)){
                num /= 10;
            }
            if(num > 0){
                maxLen = max(maxLen, (int)to_string(num).length());
            }
        }

        return maxLen;
    }
};