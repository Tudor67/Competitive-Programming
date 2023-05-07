class Solution {
private:
    vector<int> computeDifference(unordered_set<int>& set1, unordered_set<int>& set2){
        vector<int> diff;

        for(int elem: set1){
            if(!set2.count(elem)){
                diff.push_back(elem);
            }
        }

        return diff;
    }

public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<vector<int>> answer(2);
        answer[0] = computeDifference(set1, set2);
        answer[1] = computeDifference(set2, set1);

        return answer;
    }
};