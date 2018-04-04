#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void swp(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


// did you try submiting this solution on leetcode?, if not can you try and see if this gets accepted
void func(int *arr, int n) {
  for (int i = n - 1; i != 0; i--) {
    if (i - 1 == 0) {
      for (int i = n - 1; i > -1; i--) {
          cout << arr[i];
      }
      cout << endl;
      break;
    }

    if (arr[i - 1] < arr[i]) {
      int j = n - 1;
      while (1) {
        if (arr[j] > arr[i - 1]) {
            break;
        }
        j--;
      }

      swp(&arr[i - 1], &arr[j]);

      sort(&arr[i], arr + n);
      for (int i = 0; i < n; i++) {
          cout << arr[i];
      }
      cout << endl;
      break;
    }
  }
}

int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    func(arr, n);
  }
  return 0;
}
