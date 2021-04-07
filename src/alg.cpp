// Copyright 2021 NNTU-CS


int countPairs1(int* arr, int len, int value) {
    unsigned int pairs = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                pairs++;
            }
        }
    }
    return pairs;
}

int countPairs2(int* arr, int len, int value) {
    unsigned int pairs = 0, left = 0, right = len - 1;
    while (arr[right] > value) {
        right--;
    }
    while (right != 0) {
        while (left < right) {
            if (arr[right] + arr[left] == value) {
                pairs++;
            }
            left++;
        }
        right--;
        left = 0;
    }
    return pairs;
}

int countPairs3(int* arr, int len, int value) {
    unsigned int pairs = 0, left = 0, right = len - 1;
    while (arr[right] > value) {
        right--;
    }
    while (left != right) {
        pairs += cbinsearch(arr, len, value - arr[left], left+1);
        left++;
    }
    return pairs;
}
int countPairs3(int* arr, int size, int value, int lft) {
    int pairs = 0, mid = 0, left = lft, right = size;
    while (true) {
        mid = (right + left) / 2;
        if (value < arr[mid]) {
            right = mid - 1;
        } else if (value > arr[mid]) {
            left = mid + 1;
        } else {
            while (arr[mid] == value && mid >= lft) {
                mid--;
            }
            mid++;
            while (arr[mid] == value) {
                pairs++;
                mid++;
            }
            break;
        }
        if (left > right) {
            break;
        }
    }
    return pairs;
}
