import Simulador

def main():
    menu = Simulador()
    opcao = 0
    id = 0
    id_pneu = 0
    gasolina = 0.0

    while opcao != 13:
        print("\nMENU - Escolha uma das opcoes abaixo")
        print("1  - Incluir veiculo na pista")
        print("2  - Remover veiculo na pista")
        print("3  - Abastecer veiculo")
        print("4  - Movimentar veiculo")
        print("5  - Movimentar todos os veiculos")
        print("6  - Imprimir todos os dados de um veiculo")
        print("7  - Imprimir todos os dados de todos os veiculos")
        print("8  - Esvaziar/calibrar um pneu especifico")
        print("9  - Esvaziar/calibrar todos os pneus de um veiculo especifico")
        print("10 - Imprimir pista de corrida")
        print("11 - Gravar veiculos em arquivo")
        print("12 - Ler veiculos do arquivo")
        print("13 - Sair da aplicacao\n")

        opcao = int(input("Digite sua opcao: "))

        if opcao == 1:
            menu.incluir_veiculo()

        elif opcao == 2:
            id = int(input("Em qual veiculo você quer remover? Informe o ID: "))
            menu.remover_veiculo(id)

        elif opcao == 3:
            id = int(input("Em qual veiculo você quer abastecer? Informe o ID: "))
            gasolina = float(input("Quantos litros de gasolina você quer colocar no tanque: "))
            menu.abastecer_veiculo(id, gasolina)

        elif opcao == 4:
            id = int(input("Em qual veiculo você quer mover? Informe o ID: "))
            menu.mover_veiculo(id)

        elif opcao == 5:
            menu.mover_todos_veiculos()

        elif opcao == 6:
            id = int(input("Mostrar dados de qual veiculo? Informe o ID: "))
            menu.mostrar_dados_veiculo(id)

        elif opcao == 7:
            menu.mostrar_dados_todos_veiculos()

        elif opcao == 8:
            id = int(input("Qual veiculo você quer mexer nos pneus? Informe o ID: "))
            id_pneu = int(input("Qual pneu você quer esvaziar/calibrar (1, 2, 3 ou 4): "))
            menu.veiculo_mexer_pneu(id, id_pneu - 1)

        elif opcao == 9:
            id = int(input("Qual veiculo você quer mexer nos pneus? Informe o ID: "))
            menu.veiculo_mexer_todos_pneus(id)

        elif opcao == 10:
            menu.imprimir_pista()

        elif opcao == 11:
            menu.gravar_arquivo()

        elif opcao == 12:
            menu.ler_arquivo()

    print("Encerrando a aplicacao.")


if __name__ == "__main__":
    main()
