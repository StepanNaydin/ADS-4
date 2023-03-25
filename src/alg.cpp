// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int a = 0;
    for (int q = 0; q < len; ++q) {
        for (int w = q + 1; w < len; ++w) {
            if (arr[q] + arr[w] == value) {
                a++;
            }
        }
    }
    return a;
}
int countPairs2(int* arr, int len, int value) {
    int a = 0;
    for (int q = 0; q < len; ++q) {
        if (arr[q] == value) {
            break;
        }
        for (int w = q + 1; w < len; ++w) {
            if (arr[q] + arr[w] == value) {
                a++;
            }
        }
    }
    return a;
}
int countPairs3(int* arr, int len, int value) {
    int a = 0;
    int nach = 1;
    int nachh = 1;
    int count = 0;
    int size = len;
    int sizee = len;
    for (int q = 0; q < len; ++q) {
        if (nach == size) {
            break;
        }
        while (1) {
            if (arr[(size + nach) / 2] == value - arr[q]) {
                a++;
                for (int w = 1;; ++w) {
                    if (arr[(size + nach) / 2 + w] == value - arr[q]) {
                        a++;
                    } else {
                        break;
                    }
                }
                for (int w = -1;; --w) {
                    if (arr[(size + nach) / 2 + w] == value - arr[q]) {
                        a++;
                    } else {
                        break;
                    }
                }
                break;
            } else if (size - nach == 1 || value - arr[q] < 0) {
                break;
            } else if (arr[(size + nach) / 2] > value - arr[q]) {
                size = (size + nach) / 2;
            } else if (arr[(size + nach) / 2] < value - arr[q]) {
                nach = (size + nach) / 2;
            }
        }
        nachh++;
        nach = nachh;
        size = len;
    }
    return a;
}
