class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        const int N1 = arr1.size();
        const int N2 = arr2.size();

        map<int, int> freq1;
        for(int num: arr1){
            freq1[num] += 1;
        }

        vector<int> res;
        res.reserve(N1);
        for(int num: arr2){
            res.resize(res.size() + freq1[num], num);
            freq1.erase(num);
        }

        for(const pair<const int, int>& P: freq1){
            int num = P.first;
            res.resize(res.size() + freq1[num], num);
        }

        return res;
    }
};