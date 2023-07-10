import tkinter as tk
from tkinter import messagebox
from tkinter import ttk
from typing import *
import pickle

from utils import *
from models import *
from views import *
from views import LimitePrincipal

class ControlePrincipal():
    def __init__(self):
        self.controleEstudante = ControleEstudantes()
        self.controleCursos = ControleCursos()
        self.controleEquipes = ControleEquipes()

        c1 = Curso("CCO", "Ciência da Computação")
        c2 = Curso("SIN", "Sistemas de Informação")
        c3 = Curso("EEL", "Engenharia Elétrica")
        self.controleCursos.adicionaCurso(c1)
        self.controleCursos.adicionaCurso(c2)
        self.controleCursos.adicionaCurso(c3)

        self.controleEstudante.adicionaEstudante(1001, "José da Silva", c1)
        self.controleEstudante.adicionaEstudante(1002, "João de Souza", c1)
        self.controleEstudante.adicionaEstudante(1003, "Rui Santos", c2)
        #TODO inserir mais 7

        self.carregarDados() 

        self.limite = LimitePrincipal(self)

    def carregarDados(self):
        try:
            with open('equipes.pkl', 'rb') as file:
                self.listaEquipe = pickle.load(file)
        except FileNotFoundError:
            self.listaEquipe = []

    def salvarDados(self):
        with open('equipes.pkl', 'wb') as file:
            pickle.dump(self.listaEquipe, file)

class ControleEstudantes():
    def __init__(self):
        self.listaEstudantes: List[Estudante] = []

    def adicionaEstudante(self, nroMat: int, nome: str, curso: Curso):
        self.listaEstudantes.append(Estudante(nroMat, nome, curso))
        
class ControleCursos():
    def __init__(self):
        self.listaCursos = []

    def adicionaCurso(self, sigla: str, nome: str):
        self.listaCursos.append(Curso(sigla, nome))

class ControleEquipes():
    def __init__(self):
        self.listaEquipes = []

    def adicionaEquipe(self, curso: Curso, estudantes: List[Estudante]):
        self.listaEquipes.append(Equipe(curso, estudantes))
  
def main():
    controlador = ControlePrincipal()

if __name__ == '__main__':
    main()
