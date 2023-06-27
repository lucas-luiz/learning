import tkinter as tk
from tkinter import messagebox
from tkinter import Toplevel
from tkinter import ttk
from typing import *
import math

import main as main
import utils as utils
import games as games

class Game:
    def __init__(self, codigo: str, titulo:str, console:str, genero:str, preco: int):
        #TO-DO validações
        self.__codigo = codigo
        self.__titulo = titulo
        self.__console = console
        self.__genero = genero
        self.__preco = preco
        self.__avalicoes = []

    @property
    def titulo(self):
        return self.__titulo

    @property
    def codigo(self):
        return self.__codigo
    
    def addAvaliacao(self, avaliacao: int) -> None:
        self.__avalicoes.append(avaliacao)
    
    def getAvaliacaoMedia(self):
        total = 0
        
        for avaliacao in self.__avalicoes:
            total += avaliacao
        
        media =  total / len(self.__avalicoes)
        return media

class CtrlGames:
    def __init__(self, controller: main.ControlePrincipal):
        self.controller = controller
        self.listaGames: List[Game] = []
    
    def openCadastraGameView(self):
        print('CtrlGames: openCadastraGameView')
        self.limiteCadastro = LimiteCadastraGame(self)

    def openConsultaGameView(self):
        self.limiteConsulta = LimiteConsultaGame(self)
        
    def openAvaliaGameView(self):
        self.limiteAvaliacao = LimiteAvaliaGame(self)
    
    def cadastraGame(self, event):
        print('CtrlGames: cadastraGame: ')

        try:
            codigo = self.limiteCadastro.input_codigo.get()
            titulo = self.limiteCadastro.input_titulo.get()
            console = self.limiteCadastro.input_console.get()
            genero = self.limiteCadastro.input_genero.get()
            preco = int(self.limiteCadastro.input_preco.get())
        except ValueError as error:
            messagebox.showinfo("ERRO: ", 'Dados inválidos')
            return
        
        game = Game(codigo, titulo, console, genero, preco)
        self.listaGames.append(game)
        utils.closeLimite(self.limiteCadastro)
        print('CtrlGames: cadastraGame: game criado: ', game.titulo)

    def consultaGames(self, e):
        avaliacao = self.limiteConsulta.comboboxAvaliacao.get()
        gamesFound = []

        #filter
        for game in self.listaGames:
            if math.ceil(game.getAvaliacaoMedia()) == avaliacao:
                gamesFound.append(game)

        self.limiteExibeConsultaGames = LimiteExibeConsultaGame(self, gamesFound) 
    
    def avaliaGame(self, targetCod, avaliacao):
        for game in self.listaGames:
            if(game.codigo == targetCod):
                game.addAvaliacao(int(avaliacao))

    def clearView(self, event):
        pass

    def closeView(self, event):
        pass
        
class LimiteCadastraGame(Toplevel):
    def __init__(self, controller: CtrlGames):
        Toplevel.__init__(self)
        self.geometry('250x200')
        self.title("Cadastrar")
        self.controller = controller

        self.input_codigo = utils.createTextInput(self, 'codigo: ')
        self.input_titulo = utils.createTextInput(self, 'titulo: ')
        self.input_console = utils.createTextInput(self, 'console: ')
        self.input_genero = utils.createTextInput(self, 'genero: ')
        self.input_preco = utils.createTextInput(self, 'preco: ')

        self.submit_button = utils.createButton(self, self.controller.cadastraGame)

    def mostraJanela(self, titulo, msg):
        tk.messagebox.showinfo(titulo, msg)

class LimiteConsultaGame(Toplevel):
    def __init__(self, controller: CtrlGames):
        avaliacoes = ['1 estrela', '2 estrela', '3 estrela', '4 estrela', '5 estrela']

        #window
        Toplevel.__init__(self)
        self.geometry('400x250')
        self.title("Consultar por avaliação")
        self.ctrl = controller

        #frame dos combobox
        self.frameCombos = tk.Frame(self)
        self.frameCombos.pack(pady=3)

        ###INPUT AVALIACAO

        #label
        self.labelAvaliacao = tk.Label(self.frameCombos,text="Avaliação: ")
        self.labelAvaliacao.pack(side="left")

        #input
        escolhaAvaliacao = tk.StringVar()
        self.comboboxAvaliacao = ttk.Combobox(self.frameCombos, width = 15 ,values=avaliacoes, textvariable = escolhaAvaliacao)
        self.comboboxAvaliacao.pack(side="left")

        #submit
        submitButton = utils.createButton(self, self.ctrl.consultaGames) 

class LimiteExibeConsultaGame(Toplevel):
    def __init__(self, controller: CtrlGames, games: List[Game]):
        str =  ''
        for game in games:
            str += (game.titulo + '\n')
        messagebox.showinfo("Games Encontrados:", str)

class LimiteAvaliaGame(Toplevel):
    def __init__(self, controller: CtrlGames):
        Toplevel.__init__(self)
        self.geometry('250x200')
        self.title("Avaliar game")
        self.controller = controller

        self.input_codigo = utils.createTextInput(self, 'codigo: ')
        self.input_avaliacao = utils.createCombobox(self, ['1 estrela', '2 estrela', '3 estrela', '4 estrela', '5 estrela'])
        self.submmit_button = utils.createButton(self, controller.avaliaGame)
