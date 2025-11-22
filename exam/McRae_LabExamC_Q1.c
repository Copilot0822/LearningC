/* ENGG*1410 Lab Exam – Part 1 Scaffold */
/* Students must complete the function find_clusters().
   They must NOT modify main(). */

#include <stdio.h>

#define MAX_N 100

/* Function prototype to be implemented by the student */
int find_clusters(float arr[], int n, int delta, int clusters[][2]);

int main(void) {
  int n, delta;
  int num_clusters;

  /* Read size first array*/
  if (scanf("%d", &n) != 1) {
    return 1; /* input error */
  }
  if (n < 1 || n > MAX_N) {
    return 1; /* out-of-range size */
  }

  float arr[n];
  /* Read array elements*/
  for (int i = 0; i < n; i++) {
    scanf("%f", &arr[i]);
  }

  /*Read the delta -- the differnece between successive cluster elements*/
  scanf("%d", &delta);

  int clusters[n][2];  // worst case: n clusters (each element alone)

  /* Call student function */
  num_clusters = find_clusters(arr, n, delta, clusters);

  // print number of clusters
  printf("%d\n", num_clusters);

  // print each cluster in: c a b
  for (int c = 0; c < num_clusters; c++) {
    printf("%d %d %d\n",
           c + 1,            // cluster number (1-based)
           clusters[c][0],   // start index
           clusters[c][1]);  // end index
  }

  return 0;
}

/* ---- STUDENT WORK BELOW ---- */
int find_clusters(float arr[], int n, int delta, int clusters[][2]) {
  return 1;
}
