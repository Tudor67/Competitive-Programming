class BinaryIndexedTree{
private:
    const int SIZE;
    vector<int> tree;

    int getNonZeroLSB(int x){
        return x - (x & (x - 1));
    }

public:
    BinaryIndexedTree(const int SIZE): SIZE(SIZE){
        tree.resize(SIZE);
    }

    void add(int pos, int val){
        for(int i = pos; i < SIZE; i += getNonZeroLSB(i)){
            tree[i] += val;
        }
    }

    int computePrefixSum(int pos){
        int prefSum = 0;
        for(int i = pos; i >= 1; i -= getNonZeroLSB(i)){
            prefSum += tree[i];
        }
        return prefSum;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        const int F = flowers.size();
        const int P = people.size();

        // Coordinate compression
        vector<int> sortedValues;
        for(int i = 0; i < F; ++i){
            sortedValues.push_back(flowers[i][0]);
            sortedValues.push_back(flowers[i][1]);
        }

        for(int i = 0; i < P; ++i){
            sortedValues.push_back(people[i]);
        }

        sort(sortedValues.begin(), sortedValues.end());
        sortedValues.resize(unique(sortedValues.begin(), sortedValues.end()) - sortedValues.begin());

        // Build the `res` vector using a BinaryIndexedTree on compressed values
        BinaryIndexedTree tree(sortedValues.size() + 2);
        for(int i = 0; i < F; ++i){
            int l = 1 + lower_bound(sortedValues.begin(), sortedValues.end(), flowers[i][0]) - sortedValues.begin();
            int r = 1 + lower_bound(sortedValues.begin(), sortedValues.end(), flowers[i][1]) - sortedValues.begin();
            tree.add(l, 1);
            tree.add(r + 1, -1);
        }

        vector<int> res(P);
        for(int i = 0; i < P; ++i){
            int compressedVal = 1 + lower_bound(sortedValues.begin(), sortedValues.end(), people[i]) - sortedValues.begin();
            res[i] = tree.computePrefixSum(compressedVal);
        }

        return res;
    }
};