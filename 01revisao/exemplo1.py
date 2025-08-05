print("exemplo de vetor de numeros inteiros")
vetor = []
TAM = 5
#rotina que o usuario digita TAM
#vetor com vetor
for i in range(TAM):
    numero = input("digite um numero inteiro: ")
    vetor.append(numero)

#vetor como uma lista
    print("numeros: ", end=" ")
    for i in range(TAM):
        print(vetor[i], end=" ")