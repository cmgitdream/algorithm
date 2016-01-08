
#include <stdio.h>
#include <malloc.h>

// merge two sorted sub arrays
void merge_two(int arr1[], int len1, int arr2[], int len2, int merged[])
{
  int i = 0;
  int j = 0;
  int n = 0;
  int len = len1 + len2;

  // core algorithm :
  // choose the smaller one to merged array,
  // until one of sub arrays ends
  // and copy the reminder elements to merged array
  while(n < len) {
    // arr1 ends, copy reminder of arr2 to merged array
    if (i == len1) {
      merged[n++] = arr2[j++]; 
      continue;
    }
    // arr2 ends, copy reminder of arr1 to merged array
    if (j == len2) {
      merged[n++] = arr1[i++];
      continue;
    }
    if(arr1[i] < arr2[j]) {
      merged[n++] = arr1[i];
      i++;
    } else {
      merged[n++] = arr2[j];
      j++;
    }
  }
}

void do_merge_sort(int arr[], int len, int res[], int res_len)
{
  if(len < 2) {
    return;
  } 

  int i = 0;
  int half = len/2;
  int remind = len - half;

  // 1. split arr into two sub arrays
  do_merge_sort(arr, half, res, half);
  do_merge_sort(arr+half, remind,  res+half, remind);

  // 2. merge two sub arrays
  merge_two(arr, half, arr+half, remind, res);

  // 3. copy sorted res to arr
  for (i = 0; i < len; i++) {
    arr[i] = res[i];
  }
}

int *merge_sort(int arr[], int len)
{
  int *res = (int *)malloc(sizeof(int) * len);
  if (res == NULL) {
    printf("%s: malloc failed\n", __func__);
    return NULL;
  }
  do_merge_sort(arr, len, res, len);
  return res;
}

void print_array(int arr[], int len)
{
  int i = 0;
  if (arr == NULL) 
    return;
  for (i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  //int arr[] = {10, 2, 12, 3, 4, 9, 6, 5, 8, 1};
  if (argc < 2) {
    return 1;
  }

  int i = 0;
  int n = argc - 1;
  int *arr;
  int *out = NULL;

  arr = (int *)malloc(sizeof(int) * n);
  if (arr == NULL) {
    printf("malloc failed\n");
    return 1;
  }

  for (i = 0; i < n; i++) {
    arr[i] = atoi(argv[i+1]);
  }
  print_array(arr, n);

  out = merge_sort(arr, n);
  print_array(out, n);

  if (out != NULL)
    free(out);
  return 0;
}
