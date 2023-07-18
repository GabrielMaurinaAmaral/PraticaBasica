from abc import ABC, abstractmethod
import abc
# classe interface
class Interface_IPVA(metaclass=abc.ABCMeta):
    # variaveis static
    CARRO_PASSEIO = 1.3
    MOTOCICLETA = 0.75
    CARRO_ESPORTIVO = 3.15
    VALOR_BASE = 500
    # função abstrata que sera herdada para os veiculos motorizados
    @abstractmethod
    def calcular_ipva(self):
        pass