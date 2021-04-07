// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        pairs++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
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
  for (int i = len; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
      if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int generalCount = 0;
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
    int innerCount = 0;
    while (left < right) {
      center = (left + right) / 2;
      if (arr[center] >= value - arr[i]) {
      right = center;
      } else if (arr[center] < value - arr[i]) {
      left = center + 1;
      }
    }
    while (arr[left] == value - arr[i]) {
    innerCount++;
    left++;
    }
    generalCount = generalCount + innerCount;
  }
  return generalCount;
}
