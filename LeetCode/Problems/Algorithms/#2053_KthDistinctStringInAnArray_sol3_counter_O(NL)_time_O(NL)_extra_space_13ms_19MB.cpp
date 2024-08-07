class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        const int N = arr.size();

        unordered_map<string, int> freq;
        for(const string& S: arr){
            freq[S] += 1;
        }

        for(const string& S: arr){
            if(freq[S] == 1){
                freq[S] -= 1;
                k -= 1;
            }
            if(k == 0){
                return S;
            }
        }

        return "";
    }
};