def print_board(board):
    for row in board:
        print(" ".join(str(num) if num != 0 else '.' for num in row))


def find_empty(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                return (i, j)  # row, col
    return None


def is_valid(board, guess, row, col):
    # Check row
    if guess in board[row]:
        return False

    # Check column
    for i in range(9):
        if board[i][col] == guess:
            return False

    # Check 3x3 grid
    box_row = row // 3 * 3
    box_col = col // 3 * 3
    for i in range(box_row, box_row + 3):
        for j in range(box_col, box_col + 3):
            if board[i][j] == guess:
                return False

    return True


def solve_sudoku(board):
    empty = find_empty(board)
    if not empty:
        return True  # Solved

    row, col = empty

    for guess in range(1, 10):
        if is_valid(board, guess, row, col):
            board[row][col] = guess

            if solve_sudoku(board):
                return True

            # Backtrack
            board[row][col] = 0

    return False


def main():
    # Example Sudoku puzzle (0 represents empty cells)
    board = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9],
    ]

    print("Original Sudoku Board:")
    print_board(board)

    if solve_sudoku(board):
        print("\nSolved Sudoku Board:")
        print_board(board)
    else:
        print("No solution exists.")


if __name__ == "__main__":
    main()
