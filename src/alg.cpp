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
    int nach = 0;
    int count = 0;
    int size = len;
    for (int q = 0; q < len; ++q) {
        while (1) {
            if (arr[(size + nach) / 2] == value - arr[q]) {
                a++;
                break;
            } else if (size - nach == 1 || value - arr[q] < 0) {
                break;
            } else if (arr[(size + nach) / 2] > value - arr[q]) {
                size = (size + nach) / 2;
            } else if (arr[(size + nach) / 2] < value - arr[q]) {
                nach = (size + nach) / 2;
            }
        }
        nach++;
        size = len;
    }
    return a;
}
