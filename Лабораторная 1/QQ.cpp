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
            if (arr[*x + 1] != 1) {
                arr[*x + 1] = 1;
                arr[*x] = 0;
                *x = *x + 1;
            }
        case 1:
            if (arr[*x - 1] != 1) {
                arr[*x - 1] = 1;
                arr[*x] = 0;
                *x = *x - 1;
            }
    }
}

void check(int *pos, int *pos_elem, int *arr, int n) {
    for (int i = 0; i < *pos_elem; i++) {
        if (pos[i] == 0 || pos[i] == n - 1) {
            for (int j = i; j < *pos_elem; j++) {
                pos[j] = pos[j + 1];
            }
            *pos_elem = *pos_elem - 1;
            i--;
        } else {
            if (arr[pos[i] - 1] == 1 || arr[pos[i] + 1] == 1) {
                for (int j = i; j < *pos_elem; j++) {
                    pos[j] = pos[j + 1];
                }
                *pos_elem = *pos_elem - 1;
                i--;
            }
        }
    }
}

int test(int n, int *s) {
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, n - 1);
    std::random_device dev1;
    std::mt19937 rng1(dev1());
    std::uniform_int_distribution<int> dist1(1, n / 2);
    int x, y, z, time = 0;
    z = dist1(rng);
    int *pos = new int[z], pos_elem = 0;    //allocate memory
    for (int i = 0; i < z; i++) {
        int equal = 0;
        x = dist(rng);
        //y = dist(rng);
        for (int j = 0; j < pos_elem; j++) {
            if (x == pos[j]) {
                equal = 1;
                break;
            }
        }
        if (equal == 1) {
            continue;
        } else {
            pos[pos_elem] = x;
            pos_elem++;
            arr[x] = 1;
            *s = *s + 1;
        }

    }
    //write(n, arr);
    while (pos_elem > 0) {
        check(pos, &pos_elem, arr, n);
        for (int i = 0; i < pos_elem; i++) {
            move(&pos[i], arr);
        }
        time++;
    }
    //write(n, arr);
    delete[] arr;   // delete massive
    //for (int i = 0; i < pos_elem; i++)
    //delete[] pos[i];   //delete all
    delete[] pos;   // delete massive
    return time;
}

int main() {
    const int n = 100;
    const int popitka = 20;
    int s = 0;
    int sred = 0;
    for (int i = 5; i <= n; i += 5) {     //change size of matrix
        for (int j = 0; j < popitka; j++) {     //number of tries
        sred += test(i, &s);
        }
        sred /= popitka;
        s /= popitka;
        std::cout << sred << " ";
        sred = 0;
        float rez = (float) s / i;
        std::cout << rez << '\n';
        s = 0;
    }
}
