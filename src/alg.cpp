// Copyright 2021 NNTU-CS


int countPairs1(int *arr, int len, int value) {
  return 0;
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) pairs++;
    }
  }
  return pairs;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
  int pairs = 0, l = 0, r = len, mid;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (arr[mid] <= value)
      l = mid;
    else
      r = mid;
  }
  len = r;
  for (int i = 0; i < len-1; i++) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] == value)
        pairs++;
    }
  }
  return pairs;
}

int countPairs3(int *arr, int len, int value) {
  int generalPairs = 0;
  int left = 0;
  int right = len - 1;
  int center;
  while (left < right - 1) {
    center = (right + left) / 2;
    if (arr[center] > value) {
      right = center;
    } else if (arr[center] <= value) {
      left = center;
    }
  }
  len = right - 1;
  for (int i = 0; i < len; i++) {
    left = i + 1;
    right = len - 1;
    int innerPairs = 0;
    while (left < right) {
      center = (left + right) / 2;
      if (arr[center] >= value - arr[i]) {
      right = center;
      } else if (arr[center] < value - arr[i]) {
      left = center + 1;
      }
    }
    while (arr[left] == value - arr[i]) {
    innerPairs++;
    left++;
    }
    generalPairs = generalPairs + innerPairs;
  }
  return generalPairs;
}
