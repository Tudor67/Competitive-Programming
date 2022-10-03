class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        
        int i = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        int j = i + 1;
        while(j - i - 1 < k){
            if(j == N || (i >= 0 && j < N && x - arr[i] <= arr[j] - x)){
                i -= 1;
            }else{
                j += 1;
            }
        }
        
        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};