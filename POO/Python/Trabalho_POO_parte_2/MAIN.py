from Simulador import *
import time

menu = Simulador(20)
opcao = 0
dado_int_1 = 0
dado_int_2 = 0
dado_float = 0.0
dado_string = ""

while opcao != 15:
    print("\nMENU - Escolha uma das opcoes abaixo")
    print("1  - Incluir veiculo na pista")
    print("2  - Remover veiculo na pista")
    print("3  - Abastecer veiculo")
    print("4  - Movimentar veiculo")
    print("5  - Movimentar veiculos por tipo")
    print("6  - Movimentar todos os veiculos")
    print("7  - Imprimir todos os dados de todos os veiculos")
    print("8  - Imprimir todos os dados de veiculos por tipo")
    print("9  - Calibrar um pneu especifico")
    print("10 - Calibrar todos os pneus de um veiculo especifico")
    print("11 - Esvaziar todos os pneus de um veiculo especifico")
    print("12 - Imprimir pista de corrida")
    print("13 - Gravar veiculos em arquivo")
    print("14 - Ler veiculos do arquivo")
    print("15 - Sair da aplicacao\n")

    try:
        opcao = int(input("Digite sua opcao: "))

        if opcao == 1:
            print("\tB - Bicicleta")
            print("\tM - Motocicleta")
            print("\tC - Carro Passeio")
            print("\tE - Carro esportivo")
            dado_string = str(
                input("\tQue tipo de veiculo você quer incluir?"))
            if dado_string in ["E", "B", "M", "C"]:
                try:
                    menu.incluir_veiculo(dado_string)
                except ValueError:
                    print("Opção não existente")
            else:
                print("Opção inválida")

        elif opcao == 2:
            dado_int_1 = int(
                input("Em qual veiculo você quer remover? Informe o ID: "))
            menu.remover_veiculo(dado_int_1)

        elif opcao == 3:
            dado_int_1 = int(
                input("Em qual veiculo você quer abastecer? Informe o ID: "))
            menu.abastecer_veiculo(dado_int_1)

        elif opcao == 4:
            dado_int_1 = int(
                input("Em qual veiculo você quer mover? Informe o ID: "))
            menu.mover_veiculo(dado_int_1)

        elif opcao == 5:
            dado_int_1 = int(input("Que tipo de veiculo vc quer mover? "))
            print("\tB - Bicicleta")
            print("\tM - Motocicleta")
            print("\tC - Carro Passeio")
            print("\tE - Carro esportivo")
            dado_string = str(input("\tQue tipo de veiculo vc quer incluir?"))
            menu.mover_veiculos_tipo(dado_string)

        elif opcao == 6:
            menu.mover_todos_veiculos()

        elif opcao == 7:
            menu.mostrar_dados_todos_veiculos()

        elif opcao == 8:
            dado_string = int(
                input("Mostrar dados de qual veiculo? Informe o ID: "))
            menu.mostrar_dados_veiculos_tipo(dado_string)

        elif opcao == 9:
            dado_int_1 = int(
                input("Qual veiculo você quer mexer nos pneus? Informe o ID: "))
            dado_int_2 = int(input("Qual pneu você quer esvaziar/calibrar: "))
            menu.veiculo_mexer_pneu(dado_int_1)

        elif opcao == 9:
            dado_int_1 = int(
                input("Qual veiculo você quer mexer nos pneus? Informe o ID: "))
            menu.veiculo_mexer_todos_pneus(dado_int_1)

        elif opcao == 12:
            menu.imprimir_pista()

        elif opcao == 13:
            menu.gravar_arquivo()

        elif opcao == 14:
            menu.ler_arquivo()

    except ValueError:
        print("Opcao não existente tente novamente")
    time.sleep(1)

print("Encerrando a aplicacao.")
