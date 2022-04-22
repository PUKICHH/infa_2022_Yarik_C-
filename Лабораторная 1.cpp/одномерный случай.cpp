#include <iostream>
#include <random>

void write(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void move(int *x, int *arr) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, 1);
    int opt = dist(rng);
    switch (opt) {
        case 0:
            arr[*x + 1] = 1;
            arr[*x] = 0;
            *x = *x + 1;
        case 1:
            arr[*x - 1] = 1;
            arr[*x] = 0;
            *x = *x - 1;
    }
}

int test(int n) {
    int *arr;
    arr = new int[n];     //выделяем память
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, n - 1);
    int x, time = 0;
    x = dist(rng);
    arr[x] = 1;
    //write(n, arr);
    while (x > 0 && x < n - 1) {
        move(&x, arr);
        time++;
    }
    //write(n, arr);
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
