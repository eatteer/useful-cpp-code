#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

int** create_matrix(int n, int m) {
  /*
  It consists of creating a main pointer which points to an array of pointers
  where each pointer points to an array, forming a structure that represents a
  matrix

  pointer ----> [pointer] ----> [1, 2, 3, 4]
                [pointer] ----> [5, 6, 7, 8]
                [pointer] ----> [1, 2, 3, 4]
                [pointer] ----> [5, 6, 7, 8]

  pointer ----> [pointer,   pointer,    pointer,    pointer]
                |           |           |           |
                v           v           v           v
                [1, 2, 3, 4][5, 6, 7, 8][1, 2, 3, 4][5, 6, 7, 8]
  */

  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = rand() % 10;  // Fill matrix with random numbers
    }
  }

  return matrix;
}

/*
It is important to free memory after use
*/
void free_memory(int** matrix, int n) {
  for (int i = 0; i < n; i++) {
    delete[] matrix[i];  // Free memory for each pointer in array
  }

  delete[] matrix;  // Free memory for main pointer
}

void print_matrix(int** matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    cout << "[ ";
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "]" << endl;
  }
}

int main() {
  srand(time(NULL));  // Initializate seed for the random number generator
  int n, m = 0;
  cout << "Rows: ";
  cin >> n;
  cout << "Columns: ";
  cin >> m;
  int** matrix = create_matrix(n, m);
  print_matrix(matrix, n, m);
  free_memory(matrix, n);
  return 0;
}