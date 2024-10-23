#include <iostream>
#include <vector>
using namespace std;

void generateMagicSquare(int n) {
    // Create a 2D vector initialized with 0
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    // Start position (first row, middle column)
    int num = 1;
    int i = 0, j = n / 2;

    // Place numbers from 1 to n*n
    while (num <= n * n) {
        magicSquare[i][j] = num;
        num++;

        // New position
        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;

        // If the new cell is already filled, move down instead
        if (magicSquare[new_i][new_j] != 0) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }

    // Print the magic square
    cout << "The Magic Square for n = " << n << " is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    // Input: Size of the magic square (must be odd)
    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;

    // Ensure the input is odd
    if (n % 2 == 1) {
        generateMagicSquare(n);
    } else {
        cout << "Please enter an odd number." << endl;
    }

    return 0;
}
