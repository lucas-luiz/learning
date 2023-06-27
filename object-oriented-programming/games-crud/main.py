import tkinter as tk
from tkinter import messagebox
from tkinter import Toplevel
from tkinter import ttk
from typing import *

import utils as utils
import games as games
      
class ControlePrincipal():       
    def __init__(self):
        self.ctrlGames = games.CtrlGames(self)
        self.limite = LimitePrincipal(self) 

    def cadastraGame(self):
        self.ctrlGames.openCadastraGameView()
    
    def consultaGame(self):
        self.ctrlGames.openConsultaGameView()

    def avaliaGame(self):
        self.ctrlGames.openAvaliaGameView()

class LimitePrincipal():
    def __init__(self, controller: ControlePrincipal):
        self.controller = controller
        self.root = tk.Tk()
        self.root.geometry('300x250')
        
        self.menubar = tk.Menu(self.root)        

        self.gamesMenu = tk.Menu(self.menubar)
        self.gamesMenu.add_command(label="Cadastrar", command=self.controller.cadastraGame)
        self.gamesMenu.add_command(label="Consultar", command=self.controller.consultaGame)
        self.gamesMenu.add_command(label="Avaliar", command=self.controller.avaliaGame)        

        self.menubar.add_cascade(label="Game", menu=self.gamesMenu)
               
        self.root.config(menu=self.menubar)        
        self.root.title("Games")
        self.root.mainloop()

if __name__ == '__main__':
    c = ControlePrincipal()

