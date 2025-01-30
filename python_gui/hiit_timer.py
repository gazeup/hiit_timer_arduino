import serial
from tkinter import *
import tkinter as tk
import time

#commPort = 'COM3'
#serial_connection = serial.Serial(commPort, baudrate = 9600, timeout = 1)

# Define window
root = tk.Tk()
root.title('HIIT Timer')
root.geometry('500x500')
root.resizable(0, 0)
root.config(bg = '#123456')

# Run main loop
root.mainloop()