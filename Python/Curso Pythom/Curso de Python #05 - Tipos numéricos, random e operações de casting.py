from ast import For
import random

num_i = 10
num_f = 1.1
num_c = 1j  # numero complexo
num_r = [random.randrange(0, 10), random.randrange(11, 20)]
x = num_i
y = int(num_f)


print("- Valor: " + str(x) + "\n- Tipo: " + str(type(x)) + "\n")
print("- Valor: " + str(num_f) + "\n- Tipo: " + str(type(num_f)) + "\n")
print("- Valor: " + str(y) + "\n- Tipo: " + str(type(y)) + "\n")
print("- Valor: " + str(num_r) + "\n- Tipo: " + str(type(num_r)) + "\n")
