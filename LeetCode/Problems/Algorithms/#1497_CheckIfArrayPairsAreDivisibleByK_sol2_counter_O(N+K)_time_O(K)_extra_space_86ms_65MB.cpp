class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        const int N = arr.size();

        vector<int> freq(k + 1);
        for(int elem: arr){
            freq[(elem % k + k) % k] += 1;
        }

        for(int elem = 1; elem < k; ++elem){
            int complElem = (k - elem) % k;
            if(freq[elem] != freq[complElem]){
                return false;
            }
        }

        if(freq[0] % 2 == 1){
            return false;
        }

        return true;
    }
};