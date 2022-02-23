class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        const int N = arr.size();
        const int MEDIAN = arr[(N - 1) / 2];
        
        int i = 0;
        int j = N - 1;
        vector<int> answer;
        while((int)answer.size() < k){
            if(MEDIAN - arr[i] > arr[j] - MEDIAN){
                answer.push_back(arr[i]);
                i += 1;
            }else{
                answer.push_back(arr[j]);
                j -= 1;
            }
        }
        
        return answer;
    }
};