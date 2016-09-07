
#include "solution.h"

std::vector<std::vector<int> > RotateMatrix(std::vector<std::vector<int> > m) {
    int N = m.size() - 1;
    for (int n = 0; n < N; ++n) {
        for (int k = n; k < N-n; ++k) {
            int temp = m[k][n];
            m[k][n] = m[n][N-n-k];
            m[n][N-n-k] = m[N-n-k][N-n];
            m[N-n-k][N-n] = m[N-n][k+n];
            m[N-n][k+n] = temp;
        }
    }
    return m;
}
