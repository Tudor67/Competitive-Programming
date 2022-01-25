class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        const int N1 = arr1.size();
        const int N2 = arr2.size();
        
        sort(arr2.begin(), arr2.end());
        
        int answer = 0;
        for(int i = 0; i < N1; ++i){
            bool isValid = true;
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
            if((it != arr2.end() && abs(arr1[i] - *it) <= d) ||
               (it != arr2.begin() && abs(arr1[i] - *prev(it)) <= d)){
                isValid = false;
            }
            if(isValid){
                answer += 1;
            }
        }
        
        return answer;
    }
};