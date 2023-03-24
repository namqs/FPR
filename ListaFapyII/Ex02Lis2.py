'''
Escrever um algoritmo que calcula o peso em determinado planeta

Code - PLanet - Gravity
1 - Mercurio  - 0,37
2 - Venus     - 0,88
3 - Marte     - 0,38
4 - Jupiter   - 2,64
5 - Saturno   - 1,15
6 - Urano     - 1,17

Formula: peso plaenta = (pesoterra/10) * gravidadeplaneta
'''

PesoTerra = input ('Qual o seu peso na terra?')
Planeta = input ('Digite o codigo do planeta escolhido: ')

if Planeta == 1:
    NovoPeso = float (PesoTerra) * 0.37 / 10
    print('Seu peso em Mercurio seria: ' + str(NovoPeso) + '.')
elif Planeta == 2:
    NovoPeso = float (PesoTerra) * 0.88 / 10
    print('Seu peso em Venus seria: ' + str(NovoPeso)+ '.')
elif Planeta == 3:
    NovoPeso = float (PesoTerra) * 0.38 / 10
    print('Seu peso em Marte seria: ' + str(NovoPeso) + '.')
elif Planeta == 4:
    NovoPeso = float (PesoTerra) * 2.64 / 10
    print('Seu peso em Jupiter seria: ' + str(NovoPeso) + '.')
elif Planeta == 5:
    NovoPeso = float (PesoTerra) * 1.15 / 10
    print('Seu peso em Saturno seria: ' + str(NovoPeso) + '.')
else:
    NovoPeso = float (PesoTerra) * 1.17 / 10
    print('Seu peso em Urano seria: ' + str(NovoPeso) + '.')
