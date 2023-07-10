import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from main import *
from main import ControlePrincipal


class LimitePrincipal:
    def __init__(self, controller: ControlePrincipal):
        self.controller = controller
        self.root = tk.Tk()
        self.root.geometry('300x250')

        self.menubar = tk.Menu(self.root)

        self.equipesMenu = tk.Menu(self.menubar)
        self.equipesMenu.add_command(label="Criar Equipe", command=self.criarEquipe)
        self.equipesMenu.add_command(label="Consultar Equipe", command=self.consultarEquipe)

        self.dadosMenu = tk.Menu(self.menubar)
        self.dadosMenu.add_command(label="Imprimir Dados", command=self.imprimirDados)

        self.menubar.add_cascade(label="Equipes", menu=self.equipesMenu)
        self.menubar.add_cascade(label="Dados", menu=self.dadosMenu)

        self.root.config(menu=self.menubar)
        self.root.title("Campeonato UNIFEI")
        self.root.mainloop()

    def criarEquipe(self):
        LimiteCriarEquipe(self.controller)

    def consultarEquipe(self):
        LimiteConsultarEquipe(self.controller)

    def imprimirDados(self):
        LimiteImprimirDados(self.controller)

class LimiteCriarEquipe:
    def __init__(self, controller: ControleEquipes):
        self.controller = controller
        self.limite = tk.Toplevel()
        self.limite.geometry('300x150')
        self.limite.title("Criar Equipe")

        self.frameCurso = tk.Frame(self.limite)
        self.frameCurso.pack()

        self.labelCurso = tk.Label(self.frameCurso, text="Curso:")
        self.labelCurso.pack(side="left")

        self.comboCurso = ttk.Combobox(self.frameCurso, values=[curso.sigla for curso in self.controller.listaCurso])
        self.comboCurso.pack(side="left")

        self.frameEstudante = tk.Frame(self.limite)
        self.frameEstudante.pack()

        self.labelEstudante = tk.Label(self.frameEstudante, text="Número de Matrícula:")
        self.labelEstudante.pack(side="left")

        self.entryEstudante = tk.Entry(self.frameEstudante, width=20)
        self.entryEstudante.pack(side="left")

        self.buttonAdd = tk.Button(self.limite, text="Adicionar Estudante", command=self.adicionarEstudante)
        self.buttonAdd.pack()

        self.buttonCreate = tk.Button(self.limite, text="Cria Equipe", command=self.criarEquipe)
        self.buttonCreate.pack()

    def adicionarEstudante(self):
        numeroMatricula = self.entryEstudante.get()
        if not numeroMatricula.isdigit():
            messagebox.showerror("Erro", "Número de matrícula inválido!")
            return

        cursoSelecionado = self.comboCurso.get()
        curso = next((c for c in self.controller.listaCurso if c.sigla == cursoSelecionado), None)
        if not curso:
            messagebox.showerror("Erro", "Curso inválido!")
            return

        estudante = next((e for e in self.controller.listaEstudante if e.nroMatric == int(numeroMatricula)), None)
        if not estudante:
            messagebox.showerror("Erro", "Estudante não encontrado!")
            return

        if estudante.curso != curso:
            messagebox.showerror("Erro", "Estudante não está matriculado no curso selecionado!")
            return

        equipe.Equipe.addEstudante(estudante)
        messagebox.showinfo("Sucesso", "Estudante adicionado à equipe!")

    def criarEquipe(self):
        cursoSelecionado = self.comboCurso.get()
        curso = next((c for c in self.controller.listaCurso if c.sigla == cursoSelecionado), None)
        if not curso:
            messagebox.showerror("Erro", "Curso inválido!")
            return

        equipeObj = equipe.Equipe(curso, equipe.Equipe.getEstudantes())
        self.controller.listaEquipe.append(equipeObj)
        self.controller.salvarDados()
        messagebox.showinfo("Sucesso", "Equipe criada!")

        self.limite.destroy()

class LimiteConsultarEquipe:
    def __init__(self, controller: ControlePrincipal):
        self.controller = controller
        self.limite = tk.Toplevel()
        self.limite.geometry('300x150')
        self.limite.title("Consultar Equipe")

        self.frameSigla = tk.Frame(self.limite)
        self.frameSigla.pack()

        self.labelSigla = tk.Label(self.frameSigla, text="Sigla do Curso:")
        self.labelSigla.pack(side="left")

        self.entrySigla = tk.Entry(self.frameSigla, width=10)
        self.entrySigla.pack(side="left")

        self.buttonConsultar = tk.Button(self.limite, text="Consultar", command=self.consultarEquipe)
        self.buttonConsultar.pack()

    def consultarEquipe(self):
        siglaCurso = self.entrySigla.get()
        equipeObj = next((e for e in self.controller.listaEquipe if e.curso.sigla == siglaCurso), None)
        if not equipeObj:
            messagebox.showerror("Erro", "Não existe equipe desse curso!")
            return

        estudantes = equipeObj.getEstudantes()
        if not estudantes:
            messagebox.showerror("Erro", "Equipe sem estudantes!")
            return

        messagebox.showinfo("Estudantes", "\n".join([estudante.nome for estudante in estudantes]))

class LimiteImprimirDados:
    def __init__(self, controller: ControlePrincipal):
        self.controller = controller
        self.limite = tk.Toplevel()
        self.limite.geometry('200x100')
        self.limite.title("Dados do Campeonato")

        numEquipes = len(self.controller.listaEquipe)
        numEstudantes = sum([len(e.getEstudantes()) for e in self.controller.listaEquipe])
        mediaEstudantesPorEquipe = numEstudantes / numEquipes if numEquipes > 0 else 0

        self.labelNumEquipes = tk.Label(self.limite, text=f"Número de equipes: {numEquipes}")
        self.labelNumEquipes.pack()

        self.labelNumEstudantes = tk.Label(self.limite, text=f"Número total de estudantes: {numEstudantes}")
        self.labelNumEstudantes.pack()

        self.labelMediaEstudantes = tk.Label(self.limite, text=f"Média de estudantes por equipe: {mediaEstudantesPorEquipe:.2f}")
        self.labelMediaEstudantes.pack()
