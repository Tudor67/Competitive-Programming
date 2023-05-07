class Solution {
private:
    vector<int> computeDifference(vector<int>& a, vector<int>& b){
        const int A_SIZE = a.size();
        const int B_SIZE = b.size();

        vector<int> diff;
        
        int j = 0;
        for(int i = 0; i < A_SIZE; ++i){
            if(i == 0 || a[i] != a[i - 1]){
                while(j < B_SIZE && b[j] < a[i]){
                    j += 1;
                }
                if(j == B_SIZE || b[j] != a[i]){
                    diff.push_back(a[i]);
                }
            }
        }

        return diff;
    }

public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<int> sortedNums1 = nums1;
        vector<int> sortedNums2 = nums2;
        sort(sortedNums1.begin(), sortedNums1.end());
        sort(sortedNums2.begin(), sortedNums2.end());

        vector<vector<int>> answer(2);
        answer[0] = computeDifference(sortedNums1, sortedNums2);
        answer[1] = computeDifference(sortedNums2, sortedNums1);

        return answer;
    }
};