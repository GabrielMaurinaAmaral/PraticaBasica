matriz = [
    ["ana", "amanda"],
    ["breno", "bruno"],
    ["carlos", "carol"]
]

matriz[1][1] = "brenda"
matriz.append(["diana", "dilma"])
for l, c in matriz:
    print("linha: " + l + " | coluna: "+c)
