#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, l, q;

    // Initialize m[i][i] to 0
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length.
    for (l = 2; l < n; l++) {
        for (i = 1; i <= n - l; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int arr[] = {20, 35, 15, 5, 10, 20, 15,7, 66};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, size));
    return 0;
}

