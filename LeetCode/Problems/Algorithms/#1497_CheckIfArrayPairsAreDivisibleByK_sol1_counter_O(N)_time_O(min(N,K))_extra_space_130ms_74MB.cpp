class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        const int N = arr.size();

        unordered_map<int, int> freq;
        for(int elem: arr){
            freq[(elem % k + k) % k] += 1;
        }

        for(const pair<const int, int>& P: freq){
            int elem = P.first;
            int complElem = (k - elem) % k;
            if(!freq.count(complElem) || freq[elem] != freq[complElem]){
                return false;
            }
        }

        if(freq.count(0) && freq[0] % 2 == 1){
            return false;
        }

        return true;
    }
};