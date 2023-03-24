'''
O IMC (Índice de Massa Corporal)
é um critério da Organização Mundial de Saúde
para dar uma indicação sobre a condição de
peso de uma pessoa adulta. A fórmula é:
IMC = peso / altura
2
Elabore um algoritmo que, dados o peso e a
altura de um adulto, determine a sua condição
de acordo com a tabela abaixo:
IMC em adultos        Condição
IMC < 18,5             Abaixo do peso
18,5 ≤ IMC < 25,0      Peso ideal
25,0 ≤ IMC < 30,0      Sobrepeso
30,0 ≤ IMC < 35,0      Obesidade grau I
35,0 ≤ IMC < 40,0      Obesidade grau II
IMC ≥ 40,0             Obesidade grau III
'''

peso = input ('Digite o seu peso: ')
altura = input ('Digite sua altura: ')

IMC = float (peso) / (float(altura) * float(altura))

print (int(IMC))

if IMC < 18.5:
    print('Abaixo do peso')
elif IMC < 25:
    print('Peso ideal')
elif IMC < 30:
    print('Sobrepeso')
elif IMC < 35:
    print('Obesidade Grau 1')
elif IMC < 40:
    print('Obesidade grau 2')
else: 
    print('Obesidade Grau 3')