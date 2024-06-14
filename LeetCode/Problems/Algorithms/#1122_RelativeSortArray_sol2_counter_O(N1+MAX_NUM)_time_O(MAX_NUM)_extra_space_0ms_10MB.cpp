class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        const int N1 = arr1.size();
        const int N2 = arr2.size();
        const int MAX_NUM = *max_element(arr1.begin(), arr1.end());

        vector<int> freq1(MAX_NUM + 1);
        for(int num: arr1){
            freq1[num] += 1;
        }

        vector<int> res;
        res.reserve(N1);
        for(int num: arr2){
            res.resize(res.size() + freq1[num], num);
            freq1[num] = 0;
        }

        for(int num = 0; num <= MAX_NUM; ++num){
            res.resize(res.size() + freq1[num], num);
        }

        return res;
    }
};