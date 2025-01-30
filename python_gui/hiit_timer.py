import serial
from tkinter import *
import tkinter as tk
import time

commPort = 'COM3'
serial_connection = serial.Serial(commPort, baudrate = 9600, timeout = 1)

def startSession():
    serial_connection.write(b'o')

# Define window
root = tk.Tk()
root.title('HIIT Timer')
root.geometry('500x500')
root.resizable(0, 0)
root.config(bg = '#123456')

# Define layout
start_session_button = tk.Button(root, text = 'Start Session', bg = 'grey', command = startSession)
start_session_button.grid(row=0, column=0)

# Run main loop
root.mainloop()