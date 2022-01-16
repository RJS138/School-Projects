from tkinter import *
from PIL import  Image, ImageTk
from tkinter import ttk
import random

#setup of the window and tkinter initialization
root = Tk()
root.geometry("500x500")
root.title("Dice Rolling Simulator")


#For spacing
BlankLine = Label(root, text=" ")
BlankLine.pack()

#Helpful Hints and my shcool requiremtn 
school = Label(root, text="Robert Saunders Jr(RJS6748) | May 4, 2021")
school.pack()

#Main instructional text to tell you whats happening
Instruction = Label(root, text="You Rolled: ")
Instruction.pack()

#Setup for the six sides of the die
die = ['die1.png', 'die2.png', 'die3.png', 'die4.png', 'die5.png']
root.counter = 0

#Setup for the Dice image must use the PIL library tkinter does not support PNG
DieImage = ImageTk.PhotoImage(Image.open(random.choice(die)))
DieLabel = Label(root, image=DieImage)
DieLabel.image = DieImage
DieLabel.pack(expand=True)

#The main logic of the entire application. Dice image and counter are updated each time the button is pressed.
def roll_die():
    DieImage = ImageTk.PhotoImage(Image.open(random.choice(die)))
    DieLabel.configure(image=DieImage)
    DieLabel.image = DieImage
    root.counter += 1
    buttonCount.configure(text= 'Times Rolled: '  + str(root.counter))

#Setup for the button and Initial Label value
button = Button(root, text="Roll", fg='grey', command=roll_die)
button.pack(expand=True)
buttonCount = Label(root, text="Click At Least Once")
buttonCount.pack()

#Is the main loop for keeping the window open
root.mainloop()