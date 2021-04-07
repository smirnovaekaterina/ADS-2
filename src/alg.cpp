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
  int pairs = 0;
  int j = len - 1;
  for (int i = 0; i < len / 2 + 1; i++) {
    if (arr[i] + arr[j] > value) {
      int temp = arr[j];
      while (arr[j] == temp) {
        j--;
      }
    }
    else if (arr[i] + arr[j] < value) {
      return pairs;
    }
    if (arr[i] + arr[j] == value) {
      pairs++;
    }
  }
  return pairs;
}

int countPairs3(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len / 2 + 1; i++) {
    int number = value - arr[i];
    int first = i;
    int last = len;
    while (first < last) {
      int middle = (first + last) / 2;
      if (number < arr[middle]) {
        last = middle;
      } else if (number > arr[middle]) {
        first = middle;
      } else if (number == arr[middle]) {
        int j = 0;
        while (number == arr[middle + j]) {
          pairs++;
          j++;
        }
        j = 1;
        while (number == arr[middle - j]) {
          pairs++;
          j++;
        }
        break;
      }
    }
  }
  return pairs;
}
