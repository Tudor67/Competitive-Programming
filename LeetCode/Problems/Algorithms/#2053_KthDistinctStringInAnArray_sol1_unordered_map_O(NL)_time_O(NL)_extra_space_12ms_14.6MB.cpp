class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for(const string& S: arr){
            count[S] += 1;
        }
        
        for(const string& S: arr){
            if(count[S] == 1){
                k -= 1;
            }
            if(k == 0){
                return S;
            }
        }
        
        return "";
    }
};