#include <iostream>
#include <random>

void write(int n, int k, int **arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
}

void move(int n, int *x, int *y, int **arr) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, 3);
    int opt = dist(rng);
    switch (opt) {
        case 0:
            if (arr[0][*y] != 1 && *x == n - 1) {
                arr[0][*y] = 1;
                arr[n - 1][*y] = 0;
                *x = 0;
            } else {
                if (arr[*x + 1][*y] != 1 && *x != n - 1) {
                    arr[*x + 1][*y] = 1;
                    arr[*x][*y] = 0;
                    *x = *x + 1;
                }
            }
            break;
        case 1:
            if (arr[n - 1][*y] != 1 && *x == 0) {
                arr[n - 1][*y] = 1;
                arr[0][*y] = 0;
                *x = n - 1;
            } else {
                if (arr[*x - 1][*y] != 1 && *x != 0) {
                    arr[*x - 1][*y] = 1;
                    arr[*x][*y] = 0;
                    *x = *x - 1;
                }
            }
            break;
        case 2:
            if (arr[*x][*y + 1] != 1) {
                arr[*x][*y + 1] = 1;
                arr[*x][*y] = 0;
                *y = *y + 1;
            }
            break;
        case 3:
            if (arr[*x][*y - 1] != 1) {
                arr[*x][*y - 1] = 1;
                arr[*x][*y] = 0;
                *y = *y - 1;
            }
            break;

    }
}

void check(int **pos, int *pos_elem, int **arr, int n) {
    for (int i = 0; i < *pos_elem; i++) {
        if (pos[i][1] == 0 || pos[i][1] == n - 1) {
            delete[] pos[i];
            for (int j = i; j < *pos_elem; j++) {
                pos[j] = pos[j + 1];
            }
            *pos_elem = *pos_elem - 1;
            i--;
        } else {
            if (((pos[i][0] != 0) && (pos[i][0] != n - 1) &&
                ((arr[pos[i][0]][pos[i][1] - 1] == 1 || arr[pos[i][0]][pos[i][1] + 1] == 1 ||
                  arr[pos[i][0] - 1][pos[i][1]] == 1 || arr[pos[i][0] + 1][pos[i][1]] == 1))) || ((pos[i][0] == 0) &&
                                                                                                 (arr[pos[i][0]][
                                                                                                          pos[i][1] -
                                                                                                          1] == 1 ||
                                                                                                  arr[pos[i][0]][
                                                                                                          pos[i][1] +
                                                                                                          1] == 1 ||
                                                                                                  arr[pos[i][0] +
                                                                                                      1][pos[i][1]] ==
                                                                                                  1 || arr[n -
                                                                                                           1][pos[i][1]] ==
                                                                                                       1)) ||
                ((pos[i][0] == n - 1) &&
                 (arr[pos[i][0]][pos[i][1] - 1] == 1 || arr[pos[i][0]][pos[i][1] + 1] == 1 || arr[0][pos[i][1]] == 1 ||
                  arr[pos[i][0] - 1][pos[i][1]] == 1))) {
                delete[] pos[i];
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
    int **arr;
    arr = new int *[n]; //allocate memory
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
    std::random_device dev1;
    std::mt19937 rng1(dev1());
    std::uniform_int_distribution<int> dist1(1, n * n);
    int x, y, z, time = 0;
    z = dist1(rng);
    int **pos = new int *[z], pos_elem = 0; //allocate memory
    for (int i = 0; i < z; i++) {
        int equal = 0;
        x = dist(rng);
        y = dist(rng);
        for (int j = 0; j < pos_elem; j++) {
            if (x == pos[j][0] && y == pos[j][1]) {
                equal = 1;
                break;
            }
        }
        if (equal == 1) {
            continue;
        } else {
            pos[pos_elem] = new int[2]; //allocate memory
            pos[pos_elem][0] = x;
            pos[pos_elem][1] = y;
            pos_elem++;
            arr[x][y] = 1;
            *s = *s + 1;
        }

    }
    //write(n, n, arr);
    do {
        check(pos, &pos_elem, arr, n);
        for (int i = 0; i < pos_elem; i++) {
            move(n, &pos[i][0], &pos[i][1], arr);
            time++;
        }

    } while (pos_elem > 0);
//write(n, n, arr);
    for (int i = 0; i < n; i++)
        delete[] arr[i]; //delete all
    delete[] arr; // delete massive
    for (int i = 0; i < pos_elem; i++)
        delete[] pos[i]; //delete all
    delete[] pos; // delete massive
    return time;
}

int main() {
    const int n = 100;
    const int popitka = 20;
    int s = 0;
    int sred = 0;
    for (int i = 5; i <= n; i += 5) { //change size of matrix
        for (int j = 0; j < popitka; j++) { //number of tries
            sred += test(i, &s);
        }
        sred /= popitka;
        s /= popitka;
        std::cout << sred << " ";
        sred = 0;
        float rez = (float) s / (i * i);
        std::cout << rez << '\n';
        s = 0;
    }
}
