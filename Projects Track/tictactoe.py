# Importing packages from tkinter
from tkinter import *
from tkinter import messagebox 

# Variables for player and game state
Player1 = 'X'
stop_game = False

# Function to handle the button clicks
def clicked(r, c):
    global Player1
    global stop_game

    if states[r][c] == 0 and not stop_game:
        b[r][c].configure(text=Player1)
        states[r][c] = Player1

        check_if_win()

        if Player1 == 'X':
            Player1 = 'O'
        else:
            Player1 = 'X'

# Function to check if a player has won
def check_if_win():
    global stop_game

    # Check rows and columns
    for i in range(3):
        if states[i][0] == states[i][1] == states[i][2] != 0:  # Row check
            stop_game = True
            messagebox.showinfo("Winner", states[i][0] + " Won!")
            disable_all_buttons()
            return
        if states[0][i] == states[1][i] == states[2][i] != 0:  # Column check
            stop_game = True
            messagebox.showinfo("Winner", states[0][i] + " Won!")
            disable_all_buttons()
            return

    # Check diagonals
    if states[0][0] == states[1][1] == states[2][2] != 0:  # Main diagonal
        stop_game = True
        messagebox.showinfo("Winner", states[0][0] + " Won!")
        disable_all_buttons()
        return
    if states[0][2] == states[1][1] == states[2][0] != 0:  # Anti-diagonal
        stop_game = True
        messagebox.showinfo("Winner", states[0][2] + " Won!")
        disable_all_buttons()
        return

    # Check for tie
    if all(states[i][j] != 0 for i in range(3) for j in range(3)):
        stop_game = True
        messagebox.showinfo("Tie", "It's a tie!")
        disable_all_buttons()

# Function to disable all buttons after the game ends
def disable_all_buttons():
    for i in range(3):
        for j in range(3):
            b[i][j].configure(state=DISABLED)

# Design window
root = Tk()
root.title("Tic Tac Toe") 
root.resizable(0, 0)

# Create buttons and states for the game
b = [[None, None, None], [None, None, None], [None, None, None]]
states = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

# Place buttons in the grid
for i in range(3):
    for j in range(3): 
        b[i][j] = Button(root, height=4, width=8, font=("Helvetica", "20"), command=lambda r=i, c=j: clicked(r, c))
        b[i][j].grid(row=i, column=j)

# Start the main event loop
root.mainloop()
