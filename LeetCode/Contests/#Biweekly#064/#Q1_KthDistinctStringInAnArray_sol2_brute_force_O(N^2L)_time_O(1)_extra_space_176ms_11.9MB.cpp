class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        for(const string& S: arr){
            if(count(arr.begin(), arr.end(), S) == 1){
                k -= 1;
            }
            if(k == 0){
                return S;
            }
        }
        return "";
    }
};