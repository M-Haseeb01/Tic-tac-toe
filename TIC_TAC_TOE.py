import math

def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_winner(board):
    for row in board:
        if row[0] == row[1] == row[2] and row[0] != " ":
            return row[0]
    for col in range(3):
        if board[0][col] == board[1][col] == board[2][col] and board[0][col] != " ":
            return board[0][col]
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != " ":
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != " ":
        return board[0][2]
    return None

def is_board_full(board):
    for row in board:
        if " " in row:
            return False
    return True

def minimax(board, depth, is_maximizing):
    # Check terminal conditions:
    winner = check_winner(board)
    if winner == "O":
        return 1  # Maximizing player wins
    elif winner == "X":
        return -1  # Minimizing player wins
    elif is_board_full(board):
        return 0  # Draw

    if is_maximizing:
        best_score = -math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == " ":
                    board[i][j] = "O"
                    score = minimax(board, depth + 1, False)
                    board[i][j] = " "
                    best_score = max(score, best_score)
        return best_score
    else:
        best_score = math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == " ":
                    board[i][j] = "X"
                    score = minimax(board, depth + 1, True)
                    board[i][j] = " "
                    best_score = min(score, best_score)
        return best_score

def best_move(board):
    best_score = -math.inf
    move = None
    for i in range(3):
        for j in range(3):
            if board[i][j] == " ":
                board[i][j] = "O"
                score = minimax(board, 0, False)
                board[i][j] = " "
                if score > best_score:
                    best_score = score
                    move = (i, j)
    return move

def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X" 

    while True:
        print_board(board)
        if check_winner(board) or is_board_full(board):
            break

        if current_player == "X":
            move = input("Enter your move as row and column (e.g., '0 2'): ")
            try:
                i, j = map(int, move.split())
                if board[i][j] == " ":
                    board[i][j] = "X"
                    current_player = "O"
                else:
                    print("That space is already taken. Try again.")
            except (ValueError, IndexError):
                print("Invalid input. Please enter row and column numbers between 0 and 2.")
        else:
            print("Computer is making a move...")
            move = best_move(board)
            if move:
                board[move[0]][move[1]] = "O"
                current_player = "X"
            else:
                print("No possible moves!")
                break

    print_board(board)
    winner = check_winner(board)
    if winner:
        print("Winner is:", winner)
    else:
        print("It's a tie!")

if __name__ == "__main__":
    main()
