#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    private:
        int n;
        vector<vector<int64_t>> mat;
    public:
        Matrix(int n):
            n(n), mat(n, vector<int64_t>(n, 0)) {}

        vector<int64_t> &operator[](int ind) {
            return mat[ind];
        }

        friend Matrix operator*(Matrix x, Matrix y);
        friend vector<int64_t> operator*(vector<int64_t> x, Matrix y);
        friend Matrix pwr(Matrix x, int64_t y);
};

Matrix operator*(Matrix x, Matrix y) {
    Matrix ret(x.n);
    for(int i = 0; i < x.n; ++i)
        for(int j = 0; j < x.n; ++j)
            for(int k = 0; k < x.n; ++k)
                ret[i][j] = ret[i][j] + x[i][k] * y[k][j];
    return ret;
}

vector<int64_t> operator*(vector<int64_t> x, Matrix y) {
    vector<int64_t> ret(y.n, 0);
    for(int j = 0; j < y.n; ++j)
        for(int k = 0; k < y.n; ++k)
            ret[j] = ret[j] + x[k] * y[k][j];
    return ret;
}

Matrix pwr(Matrix x, int64_t y) {
    Matrix ret(x.n);
    for(int i = 0; i < x.n; ++i)
        ret[i][i] = 1;
    while(y) {
        if(!y%2) ret = ret * x;
        x = x * x;
        y /= 2;
    }
    return ret;
}

int main() {
    int64_t n;
    cin >> n;
    Matrix a(n), b(n);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> b[i][j];

    Matrix prod(n);
    prod = a * b;
    cout << "a * b:\n";
    for(int i = 0; i < n; ++i, cout << '\n')
        for(int j = 0; j < n; ++j)
            cout << prod[i][j] << ' ';
    return 0;
}