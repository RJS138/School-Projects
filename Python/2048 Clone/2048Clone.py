from ast import Try
import tkinter as tk
from tkinter import font
import random
from typing import Collection, Text
from warnings import catch_warnings

#Defines all the colors to match the orginal game and defines font for better looking 
#numbers and text.
class Colors():
    GRID_COLOR = "#a39489"
    EMPTY_CELL_COLOR = "#c2b3a9"
    SCORE_LABEL_FONT = ("Verdana", 24)
    SCHOOL_LABEL_FONT = ("Verdana", 8)
    SCORE_FONT = ("Helvetica", 36, "bold")
    GAME_OVER_FONT = ("Helvetica", 48, "bold")
    CELL_FONT = ("Helvetica", 55, "bold")
    GAME_OVER_FONT_COLOR = "#ffffff"
    WINNER_BG = "#ffcc00"
    LOSER_BG = "#a39489"
    CELL_COLORS ={
        2: '#eee4da',
        4: '#ede0c8',
        8: '#edc850',
        16: '#edc53f',
        32: '#f67c5f',
        64: '#f65e3b',
        128: '#edcf72',
        256: '#edcc61',
        512: '#f2b179',
        1024: '#f59563',
        2048: '#edc22e',
    }
    CELL_NUMBER_COLORS={
        2: '#776e65',
        4: '#f9f6f2',
        8: '#f9f6f2',
        16: '#f9f6f2',
        32: '#f9f6f2',
        64: '#f9f6f2',
        128: '#f9f6f2',
        256: '#f9f6f2',
        512: '#776e65',
        1024: '#f9f6f2',
        2048: '#f9f6f2',
    }   
    CELL_NUMBER_FONTS={
        2: ("Helvetica", 55, "bold"),
        4: ("Helvetica", 55, "bold"),
        8: ("Helvetica", 55, "bold"),
        16: ("Helvetica", 55, "bold"),
        32: ("Helvetica", 55, "bold"),
        64: ("Helvetica", 55, "bold"),
        128: ("Helvetica", 55, "bold"),
        256: ("Helvetica", 55, "bold"),
        512: ("Helvetica", 55, "bold"),
        1024: ("Helvetica", 55, "bold"),
        2048: ("Helvetica", 55, "bold"),
    } 
    #This is the main game class for controllling the grid and the methods applied to it
class Game(tk.Frame):
    def __init__(self):
        tk.Frame.__init__(self)
        self.grid()
        self.master.title("2048")

        self.main_grid = tk.Frame(
            self, bg=Colors.GRID_COLOR, bd=3, width=600, height=600)
        #Padding for score at top
        self.main_grid.grid(pady=(100,0))
        self.makeGUI()
        self.start_game()
        #Binds the keys neede dto play and allows multiple action to be made under each
        self.master.bind("<Left>", self.left)
        self.master.bind("<Right>", self.right)
        self.master.bind("<Up>", self.up)
        self.master.bind("<Down>", self.down)

        #defines the main game loop
        self.mainloop()

    #This function creates the GUI mainly the grid system that the game plays in
    def makeGUI(self):
        self.cells = []
        for i in range(4):
            row = []
            for j in range(4):
                cell_frame = tk.Frame(
                    self.main_grid, bg=Colors.EMPTY_CELL_COLOR, width=150, height=150)
                cell_frame.grid(row=i, column=j, padx = 5, pady = 5)
                cell_number = tk.Label(self.main_grid,bg=Colors.EMPTY_CELL_COLOR)
                cell_number.grid(row=i, column=j)
                cell_data = {"frame": cell_frame , "number": cell_number}
                row.append(cell_data)
            self.cells.append(row)
        #Setup for the required text to show i coded this and the scoring text
        school_frame =  tk.Frame(self)
        school_frame.place(relx = 0.5, y= 0, anchor="n")
        #I manually padded the spacing so that it looked a litle cleaner. THis is required purely to
        #prove authenticty of code base as requested by assignemnt rubric.
        tk.Label(school_frame, text="     Robert Saunders Jr                                      (RJS6748) | May 4, 2021", font= Colors.SCHOOL_LABEL_FONT).grid(row=0)
        score_frame = tk.Frame(self)
        score_frame.place(relx = 0.5, y =45, anchor="center")
        tk.Label(score_frame, text="Score", font= Colors.SCORE_LABEL_FONT).grid(row=0)
        self.score_label = tk.Label(score_frame, text="0", font= Colors.SCORE_FONT)
        self.score_label.grid(row=1)
      
        
    #Function for creating the initial tiles to start playing with
    def start_game(self):
        self.matrix = [[0] * 4 for l in range(4)]
        #defines two random tile and assignes their value at 2
        row = random.randint(0,3)
        column = random.randint(0,3)
        self.matrix[row][column] = 2
        self.cells[row][column]["frame"].configure(bg=Colors.CELL_COLORS[2])
        self.cells[row][column]["number"].configure(bg=Colors.CELL_COLORS[2], fg= Colors.CELL_NUMBER_COLORS[2],font=Colors.CELL_NUMBER_FONTS[2], text="2")
        while(self.matrix[row][column] != 0):
            row = random.randint(0,3)
            column = random.randint(0,3)
        self.matrix[row][column] = 2
        self.cells[row][column]["frame"].configure(bg=Colors.CELL_COLORS[2])
        self.cells[row][column]["number"].configure(bg=Colors.CELL_COLORS[2], fg= Colors.CELL_NUMBER_COLORS[2],font=Colors.CELL_NUMBER_FONTS[2], text="2")

        self.score = 0
    #Thsi function is called to stack two tiles together and prepares the board for the main game mechanic of combining them
    def stack(self):
        try:
            new_matrix = [[0] * 4 for l in range(4)]
            for i in range(4):
                fill_position = 0
                for j in range(4):
                    if self.matrix[i][j] != 0:
                        new_matrix[i][fill_position] = self.matrix[i][j]
                        fill_position += 1
            self.matrix = new_matrix
        except:
            print ("No Moves")
    #THsi funciton is called to combne two tiles in game to make them grow
    def combine(self):
        for i in range(4):
            for j in range(3):
                if self.matrix[i][j] != 0 and self.matrix[i][j] == self.matrix[i][j + 1]:
                    self.matrix[i][j] *= 2
                    self.matrix[i][j + 1] = 0
                    self.score += self.matrix[i][j]
    #Reversed the matrix for calulating if tiles can be combind or stacked            
    def reverse(self):
        new_matrix = []
        for i in range(4):
            new_matrix.append([])
            for j in range(4):
                new_matrix[i].append(self.matrix[i][3 - j])
        self.matrix = new_matrix
    #Transposes the entire matrix to make the tiles easier to manager later on
    def transpose(self):
        new_matrix = [[0] * 4 for l in range(4)]
        for i in range(4):
            for j in range(4):
                new_matrix[i][j] = self.matrix[j][i]
        self.matrix = new_matrix 
    #THis fucntion adds new tiles to the board and is used on every key press proably a bad idea but oh well
    def add_new_tile(self):
        row = random.randint(0,3)
        column = random.randint(0,3)
        while (self.matrix[row][column] != 0):
            row = random.randint(0,3)
            column = random.randint(0,3)
        self.matrix[row][column] = random.choice([2,4])
    #Updates the grid based on the key pressed. This is called evey key press
    def update_GUI(self):
        for i in range(4):
            for j in range(4):
                cell_value = self.matrix[i][j]
                if cell_value == 0:
                    self.cells[i][j]["frame"].configure(bg=Colors.EMPTY_CELL_COLOR)
                    self.cells[i][j]["number"].configure(bg=Colors.EMPTY_CELL_COLOR, text="")
                else:
                    self.cells[i][j]["frame"].configure(bg=Colors.CELL_COLORS[cell_value])
                    self.cells[i][j]["number"].configure(bg=Colors.CELL_COLORS[cell_value], fg=Colors.CELL_NUMBER_COLORS[cell_value],font=Colors.CELL_NUMBER_FONTS[cell_value], text=str(cell_value))
        self.score_label.configure(text=self.score)
        self.update_idletasks()
    #This is the main game logic and uses the above functions to manipualte the grid into the 2048 game
    def left(self, event):
        self.stack()
        print("Stack")
        self.combine()
        print("COMBINE")
        self.stack()
        print("Stack")
        self.add_new_tile()
        print("NEW")
        self.update_GUI()
        print("UI")
        self.game_over()
        print("GO")
    def right(self, event):
        self.game_over()
        self.reverse()
        self.combine()
        self.stack()
        self.reverse()
        self.add_new_tile()
        self.update_GUI()
        self.game_over()
    def up(self, event):
        self.game_over()
        self.transpose()
        self.stack()
        self.combine()
        self.stack()
        self.transpose()
        self.add_new_tile()
        self.update_GUI()
        
    def down(self, event):
        self.game_over()
        self.transpose()
        self.reverse()
        self.stack()
        self.combine()
        self.stack()
        self.reverse()
        self.transpose()
        self.add_new_tile()
        self.update_GUI()
        self.game_over()
        
    #THese fucntions check if there are more possible moves or not needed for end game conditionss
    def horizontal_move_exists(self):
        for i in range(4):
            for j in range(3):
                if self.matrix[i][j] == self.matrix[i][j + 1]:
                    return True
        return False

    def vertical_move_exists(self):
        for i in range(3):
            for j in range(4):
                if self.matrix[i][j] == self.matrix[i + 1][j]:
                    return True
        return False
    #This fucntion displays the end game screen either a winning screen or a game over for losing
    def game_over(self):
        if any(2048 in row for row in self.matrix):
            game_over_frame = tk.Frame(self.main_grid, borderwidth=2)
            game_over_frame.place(relx=0.5, rely=0.5, anchor="center")
            tk.Label(game_over_frame, text="You Win!", bg=Colors.WINNER_BG,fg=Colors.GAME_OVER_FONT_COLOR, font=Colors.GAME_OVER_FONT).pack()
        elif not any(2048 in row for row in self.matrix) and not self.horizontal_move_exists() and not self.vertical_move_exists():
            game_over_frame = tk.Frame(self.main_grid, borderwidth=2)
            game_over_frame.place(relx=0.5, rely=0.5, anchor="center")
            tk.Label(game_over_frame, text="Game Over!", bg=Colors.LOSER_BG,fg=Colors.GAME_OVER_FONT_COLOR, font=Colors.GAME_OVER_FONT).pack()
def main():
    Game()

if __name__ == "__main__":
    main()