class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;
        vector<int> closestElementsLeft;
        vector<int> closestElementsRight;
        for(int i = 0; i < k; ++i){
            if(l >= 0 && (r == N || abs(arr[l] - x) <= abs(arr[r] - x))){
                closestElementsLeft.push_back(arr[l--]);
            }else{
                closestElementsRight.push_back(arr[r++]);
            }
        }
        vector<int> closestElements(k);
        copy(closestElementsLeft.rbegin(), closestElementsLeft.rend(), closestElements.begin());
        copy(closestElementsRight.rbegin(), closestElementsRight.rend(), closestElements.rbegin());
        return closestElements;
    }
};