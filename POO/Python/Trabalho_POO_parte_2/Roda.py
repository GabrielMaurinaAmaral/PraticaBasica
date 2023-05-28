from random import choice


class Roda:
    def __init__(self):
        self.__calibragem_pneu: bool = bool(choice([True, False]))

    def set_calibragem(self, c_p: bool) -> None:
        self.__calibragem_pneu = c_p

    def get_calibragem(self) -> bool:
        return self.__calibragem_pneu

    def __str__(self) -> str:
        return f"Calibragem do Pneu: {self.__calibragem_pneu}"
