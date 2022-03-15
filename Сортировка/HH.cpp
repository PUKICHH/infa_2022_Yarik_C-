#include <iostream>

using namespace std;

int main() {
    int N = 6;
    int a[N];
    for (int k = 0; k < N; k++) cin >> a[k];
    int min = 0;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        min = i;
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        if (i != min) {
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
}