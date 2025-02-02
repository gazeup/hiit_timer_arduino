import serial
from tkinter import *
import tkinter as tk
import time

commPort = 'COM3'
serial_connection = serial.Serial(commPort, baudrate = 9600, timeout = 1)

# Send data
def sendData():
    active_time = int(entryHiitTime.get())
    pause_time = int(entryPauseTime.get())
    rounds = int(entryRounds.get())
    
    data = f"{active_time},{pause_time},{rounds}\n"
    serial_connection.write(data.encode())
    print(f"Sent: {data}")    

# Define fonts and colors
font_entry = ("Helvetica", 14)
font_button = ("Helvetica", 14, "bold")

background_color = '#f9f4ef'
text_color_entry = '#716040'
text_color_button = '#f9f4ef'
secondary_color = '#eaddcf'
highlight_color = '#f25042'

# Define window
root = tk.Tk()
root.title('HIIT Timer')
root.geometry('400x500')
root.resizable(0, 0)
root.config(bg = background_color)

# Center-align grid
root.grid_columnconfigure(0, weight=1)
root.grid_columnconfigure(1, weight=1)

# Define layout with centered alignment
def create_labeled_entry(label_text, default_value, row):
    label = tk.Label(root, text=label_text, font=font_entry, bg=background_color, fg=text_color_entry)
    label.grid(pady=(34,0), row=row, column=0, columnspan=2)

    entry = tk.Entry(root, width=10, font=font_entry, bg=secondary_color, fg=highlight_color, relief="flat", justify="center")
    entry.insert(0, default_value)
    entry.grid(ipady=13, row=row+1, column=0, columnspan=2, sticky="ew")

    return entry

#Create title
hiitTitle = tk.Label(root, text='Hiit Timer', font=('Helvetica', 23), bg=background_color, fg=text_color_entry)
hiitTitle.grid(pady=(13,0), row=0, column=0, columnspan=2)

# Create labeled entries
entryHiitTime = create_labeled_entry("Exercise Time", "10", 1)
entryPauseTime = create_labeled_entry("Pause Time", "5", 3)
entryRounds = create_labeled_entry("Rounds", "4", 5)

# Start Session Button
start_session_button = tk.Button(root, width=15, text='Start Session', borderwidth=0, relief="flat",
                                 font=font_button, bg=highlight_color, fg=text_color_button, command=sendData)
start_session_button.grid(ipady=13, pady=34, row=7, column=0, columnspan=2, sticky="ew")

# Run main loop
root.mainloop()