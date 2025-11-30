substring = input()
palavra = input()
i = 0
for i in range(0, len(palavra)):
    if(substring[0] == palavra[i]):
        index = i
        break

erros = 0
i = 0

for j in range(index, len(palavra)):
    #print(f"erros: {erros}, index: {index}, palavra: {palavra}")
    if substring[i] == palavra[j]:
        i+=1
        #erros = 0
        if i == len(substring):
            break
    elif substring[i] != palavra[j]:
        erros+=1
    if erros > 1: 
        break

if erros <= 1:
    print("MUITO FACIL\n")
else:
    print("NAO MUITO FACIL\n")
