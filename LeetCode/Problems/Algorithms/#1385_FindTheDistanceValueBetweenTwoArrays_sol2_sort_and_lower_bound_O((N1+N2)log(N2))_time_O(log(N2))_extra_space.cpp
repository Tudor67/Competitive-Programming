class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        const int N1 = arr1.size();
        const int N2 = arr2.size();
        
        sort(arr2.begin(), arr2.end());
        
        int answer = 0;
        for(int i = 0; i < N1; ++i){
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i] - d);
            if(it == arr2.end() || *it > arr1[i] + d){
                answer += 1;
            }
        }
        
        return answer;
    }
};