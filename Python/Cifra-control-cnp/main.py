NUMAR_CONTROL = '279146358279'
cnp = input('Introduceti CNP-ul fara ultima cifra:')
cifra_control = 0

for i in range(0, 12):
    cifra_control += int(NUMAR_CONTROL[i])*int(cnp[i])

print(cifra_control, cifra_control%11, sep='\n')