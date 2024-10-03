#include <bits/stdc++.h>
using namespace std;

class Block{
private:
    const int L;
    const int R;
    const int CAPACITY;
    list<int> values;
    int shift;

public:
    Block(const int L, const int R): L(L), R(R), CAPACITY(R - L + 1){
        shift = 0;
    }

    void collectValues(vector<int>& outValues){
        for(int val: values){
            outValues.push_back(val + shift);
        }
    }

    void specialInsert(int k){
        auto it = values.begin();
        for(int val = L; val <= R; ++val){
            if(it != values.end() && val == *it + shift){
                (*it) -= 1;
                it++;
            }else{
                k -= 1;
            }

            if(k == 0){
                values.insert(it, val - shift);
                break;
            }
        }
    }

    void applyShiftOp(){
        shift -= 1;
    }

    bool exceedsLeftBound(){
        return (!values.empty() && values.front() + shift < L);
    }

    void popLeftBound(){
        values.pop_front();
    }

    void pushRightBound(){
        values.push_back(R - shift);
    }

    int getRemPlaces(){
        return CAPACITY - (int)values.size();
    }
};

class Range{
private:
    vector<Block> blocks;

public:
    Range(const int N){
        const int BLOCK_SIZE = sqrt(N) + 1;
        const int TOTAL_BLOCKS = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;
        for(int i = 0; i < TOTAL_BLOCKS; ++i){
            blocks.push_back(Block(1 + i * BLOCK_SIZE, (i + 1) * BLOCK_SIZE));
        }
    }

    void specialInsert(int k){
        int lastBlockIndex = 0;
        for(int i = 0; i < (int)blocks.size(); ++i){
            if(blocks[i].getRemPlaces() < k){
                k -= blocks[i].getRemPlaces();
                blocks[i].applyShiftOp();
            }else{
                blocks[i].specialInsert(k);
                lastBlockIndex = i;
                break;
            }
        }

        for(int i = lastBlockIndex; i >= 1; --i){
            if(blocks[i].exceedsLeftBound()){
                blocks[i].popLeftBound();
                blocks[i - 1].pushRightBound();
            }
        }
    }

    vector<int> getValues(){
        vector<int> values;
        for(Block& block: blocks){
            block.collectValues(values);
        }
        return values;
    }
};

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        int N, G;
        cin >> N >> G;

        vector<int> E(N);
        for(int i = 0; i < N; ++i){
            cin >> E[i];
        }

        const int MAX_E = *max_element(E.begin(), E.end());

        Range range(2 * MAX_E + 2);
        for(int i = 0; i < N; ++i){
            range.specialInsert(E[i]);
        }

        E = range.getValues();

        reverse(E.begin(), E.end());

        pair<int, int> res = {abs(G - E[0]), 0};
        for(int i = 1; i < N; ++i){
            res = min(res, {abs(G - E[i]), i});
        }

        cout << "Case #" << TEST_CASE_ID << ": " << res.second + 1 << " " << res.first << "\n";
    }
};

int main(){
    ifstream cin("line_of_delivery_part_2_input.txt");
    ofstream cout("line_of_delivery_part_2_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}