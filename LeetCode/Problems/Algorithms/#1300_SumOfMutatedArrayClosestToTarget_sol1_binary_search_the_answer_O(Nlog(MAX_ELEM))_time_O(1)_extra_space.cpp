class Solution {
private:
    int computeSum(vector<int>& arr, int value){
        int sum = 0;
        for(int elem: arr){
            sum += min(elem, value);
        }
        return sum;
    }
    
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0;
        int r = *max_element(arr.begin(), arr.end());
        while(l != r){
            int mid = (l + r) / 2;
            if(computeSum(arr, mid) < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(abs(computeSum(arr, r - 1) - target) <= abs(computeSum(arr, r) - target)){
            r -= 1;
        }
        return r;
    }
};