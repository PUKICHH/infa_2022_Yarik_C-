#include <iostream>

using namespace std;

void quickSortR(int *a, long N) {
    long i = 0, j = N;
    int temp, p;
    p = a[N >> 1];
    do {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) quickSortR(a, j);
    if (N > i) quickSortR(a + i, N - i);
}
int main() {
    int a[6];
    for (int k = 0; k < 6; k++) cin >> a[k];
    quickSortR(a, 6);
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}