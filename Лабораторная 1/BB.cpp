#include <iostream>
#include <random>

void write(int n, int k, int **arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
}

void move(int *x, int *y, int **arr) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, 3);
    int opt = dist(rng);
    switch (opt) {
        case 0:
            arr[*x + 1][*y] = 1;
            arr[*x][*y] = 0;
            *x = *x + 1;
        case 1:
            arr[*x - 1][*y] = 1;
            arr[*x][*y] = 0;
            *x = *x - 1;
        case 2:
            arr[*x][*y + 1] = 1;
            arr[*x][*y] = 0;
            *y = *y + 1;
        case 3:
            arr[*x][*y - 1] = 1;
            arr[*x][*y] = 0;
            *y = *y - 1;
    }
}

int test(int n) {
    int **arr;
    arr = new int *[n];     //выделяем память
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, n - 1);
    int x, y, time = 0;
    x = dist(rng);
    y = dist(rng);
    arr[x][y] = 1;
    //write(n, n, arr);
    while (x > 0 && x < n - 1 && y > 0 && y < n - 1) {
        move(&x, &y, arr);
        time++;
    }
    //write(n, n, arr);
    for (int i = 0; i < n; i++)
        delete[] arr[i]; //delete all
    delete[] arr; // delete massive
    return time;
}

int main() {
    const int n = 100;
    const int popitka = 20;
    int sred = 0;
    for (int i = 5; i <= n; i += 5) {     //change size of matrix
        for (int j = 0; j < popitka; j++) {     //number of tries
            sred += test(i);
        }
        sred /= popitka;
        std::cout << sred << " ";
        sred = 0;
        std::cout << i << '\n';
    }
}