class Solution {
public:
    int findLatestStep(vector<int>& arr, int M) {
        const int N = arr.size();
        if(N == M){
            return N;
        }else{
            set<int> zerosPos({0, N + 1});
            for(int i = N - 1; i >= 0; --i){
                set<int>::iterator rightIt = zerosPos.upper_bound(arr[i]);
                set<int>::iterator leftIt = prev(rightIt);
                zerosPos.insert(arr[i]);
                if(*rightIt - arr[i] - 1 == M || arr[i] - *leftIt - 1 == M){
                    return i;
                }
            }
        }
        return -1;
    }
};