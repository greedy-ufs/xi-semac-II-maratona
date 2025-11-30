
def resolve( pontos,  porcoes)-> str:
    soma = 0
    for porcao in porcoes:
        soma += int(porcao)

    if (soma % 5 == 0 ):
        print("SIM\n")
    else:
        print("NAO\n")


pontos = int(input())
porcoes = input().split(" ")

resolve(pontos, porcoes)