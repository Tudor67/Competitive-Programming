#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Matrix = vector<vector<ll>>;
const Matrix IDENTITY_MATRIX = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
const Matrix CLOCKWISE_ROTATION_MATRIX = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
const Matrix COUNTERCLOCKWISE_ROTATION_MATRIX = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};

Matrix multiply(const Matrix& A, const Matrix& B){
    const int A_ROWS = A.size();
    const int A_COLS = A[0].size();
    const int B_COLS = B[0].size();
    Matrix C(A_ROWS, vector<ll>(B_COLS, 0));
    for(int i = 0; i < A_ROWS; ++i){
        for(int j = 0; j < B_COLS; ++j){
            for(int k = 0; k < A_COLS; ++k){
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<ll, ll>> points(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> points[i].first >> points[i].second;
    }

    int M;
    cin >> M;

    vector<Matrix> prefT(M + 1, IDENTITY_MATRIX);
    for(int i = 1; i <= M; ++i){
        int op, p;
        cin >> op;
        if(op == 1){
            prefT[i] = CLOCKWISE_ROTATION_MATRIX;
        }else if(op == 2){
            prefT[i] = COUNTERCLOCKWISE_ROTATION_MATRIX;
        }else if(op == 3){
            cin >> p;
            prefT[i] = {{-1, 0, 0}, {0, 1, 0}, {2 * p, 0, 1}};
        }else if(op == 4){
            cin >> p;
            prefT[i] = {{1, 0, 0}, {0, -1, 0}, {0, 2 * p, 1}};
        }
        prefT[i] = multiply(prefT[i - 1], prefT[i]);
    }

    int Q;
    cin >> Q;

    for(int i = 1; i <= Q; ++i){
        int A, B;
        cin >> A >> B;
        Matrix C = multiply({{points[B].first, points[B].second, 1}}, prefT[A]);
        ll x = C[0][0];
        ll y = C[0][1];
        cout << x << " " << y << "\n";
    }

    return 0;
}