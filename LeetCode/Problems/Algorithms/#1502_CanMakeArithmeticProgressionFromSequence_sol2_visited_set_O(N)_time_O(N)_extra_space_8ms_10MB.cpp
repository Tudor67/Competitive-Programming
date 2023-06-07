class Solution {
private:
    int findMinElem(vector<int>& arr, int forbiddenElem){
        const int N = arr.size();
        int minElem = forbiddenElem;
        for(int i = 0; i < N; ++i){
            if(arr[i] != forbiddenElem){
                if(minElem == forbiddenElem || arr[i] < minElem){
                    minElem = arr[i];
                }
            }
        }
        return minElem;
    }

public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const int N = arr.size();

        // Step 1: compute firstMinElem and secondMinElem of arr
        //         compute the targetDiff = firstMinElem - secondMinElem
        int firstMinElem = findMinElem(arr, INT_MAX);
        int secondMinElem = findMinElem(arr, firstMinElem);
        int targetDiff = secondMinElem - firstMinElem;

        // Step 2: put all elements of arr in a visited set
        unordered_set<int> vis(arr.begin(), arr.end());

        // Step 3: check special cases
        if(targetDiff == 0){
            return ((int)vis.size() == 1);
        }

        if(targetDiff >= 1 && (int)vis.size() != N){
            return false;
        }

        // Step 4: check if vis set contains all N elements of an arithmetic progression
        //         with difference == targetDiff and first element == firstMinElem
        for(int i = 1; i <= N - 1; ++i){
            if(!vis.count(firstMinElem + i * targetDiff)){
                return false;
            }
        }

        return true;
    }
};