class Equipe:
    def __init__(self, curso, estudantes):
        self.curso = curso
        self.estudantes = estudantes

    @classmethod
    def addEstudante(cls, estudante):
        if not hasattr(cls, 'estudantes'):
            cls.estudantes = []
        cls.estudantes.append(estudante)

    @classmethod
    def getEstudantes(cls):
        if not hasattr(cls, 'estudantes'):
            cls.estudantes = []
        return cls.estudantes


class Curso:
    def __init__(self, sigla, nome):
        self.sigla = sigla
        self.nome = nome


class Estudante:
    def __init__(self, nroMatric, nome, curso):
        self.nroMatric = nroMatric
        self.nome = nome
        self.curso = curso