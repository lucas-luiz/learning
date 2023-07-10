import tkinter as tk
from tkinter import messagebox
from tkinter import Toplevel
from tkinter import ttk
from typing import *
import math

def closeLimite(limite: Toplevel):
    if limite:
        limite.destroy()
        limite = None

def createButton(limite: Toplevel, callback) -> tk.Frame:
    frame_button = tk.Frame(limite)
    frame_button.pack()

    buttonSubmit = tk.Button(frame_button, text="Ok")
    buttonSubmit.pack(side="right")
    buttonSubmit.bind("<Button>", callback)

    return frame_button

def createInput(limite: Toplevel, label: str, width=30) -> tk.Entry:
    frame = tk.Frame(limite)
    frame.pack()

    label = tk.Label(frame, text=label)
    label.pack(side="left")

    _input = tk.Entry(frame, width=width)
    _input.pack(side="left")

    return _input

def createCombobox(limite: Toplevel, options: List[str]) -> ttk.Combobox:
    frame = tk.Frame(limite)
    frame.pack(pady=3)

    label = tk.Label(frame, text="Avaliação: ")
    label.pack(side="left")

    options = tk.StringVar()

    combo = ttk.Combobox(frame, width=15, values=options, textvariable=options)
    combo.pack(side="left")

    return combo
