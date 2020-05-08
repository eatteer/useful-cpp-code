#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

int** create_matrix(int n, int m) {
  /*
  pointer ----> [row pointer] ----> [1, 2, 3, 4]
                [row pointer] ----> [5, 6, 7, 8]
                [row pointer] ----> [1, 2, 3, 4]
                [row pointer] ----> [5, 6, 7, 8]
  */
  /*
  pointer ----> [row pointer,   row pointer,    row pointer,    row pointer]
                |               |               |               |
                v               v               v               v
                [1, 2, 3, 4]    [5, 6, 7, 8]    [1, 2, 3, 4]    [5, 6, 7, 8]
  */

  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
  }

  // input: cin>>*(*(matrix+i)+j);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  return matrix;
}

void free_memory(int** matrix, int n) {
  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void print_matrix(int** matrix, int n, int m) {
  // output: cout<<*(*(matrix+i)+j);
  for (int i = 0; i < n; i++) {
    cout << "[ ";
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "]" << endl;
  }
}

int main() {
  srand(time(NULL));
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