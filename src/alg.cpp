// Copyright 2021 NNTU-CS
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        pairs++;
    }
  }
  return pairs;
}

int countPairs2(int *arr, int len, int value) {
  int pairs = 0;
  int j = len - 1;
  for (int i = 0; i < len / 2 + 1; i++) {
    while (arr[i] + arr[j] != value && i < j) {
      if (arr[i] + arr[j] > value) {
        int temp = arr[j];
        while (arr[j] == temp) {
          j--;
        }
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
    if (arr[i] + arr[j] == value) {
      int temp = arr[j];
      int temp2 = j;
      while (temp == arr[temp2] && temp2 > i) {
        pairs++;
        temp2--;
      }
      if (arr[i] != arr[i + 1])
        j = temp2;
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
      if (middle == first || middle == last)
        break;
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
        while (number == arr[middle - j] && i < middle - j) {
          pairs++;
          j++;
        }
        break;
      }
    }
  }
  return pairs;
}
