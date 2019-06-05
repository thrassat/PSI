#!/usr/bin/python

instructions = []
donnees = [0] * 124 #Taille volontairement réduite pour affichage
registres = [0] * 32
ip = 0

instructions = [(line.rstrip('\n')).split() for line in open ('../compilated.s','r+')]

print (instructions)
print ("ooo")
print ("ooo")
#registres[int(instructions[ LAQUELLE 0 PREMIERE,IP][0 OP A 1 , B 2 , C 3][ SI R QQC METTRE 1])]
#@x [ inde = int(instructions[ip][1][1])
#Rx [  int(instructions[ip][1][1]

while ip < len(instructions):
    if instructions[ip][0] == "AFC":
        registres[int(instructions[ip][1][1])] = int(instructions[ip][2])
    elif instructions[ip][0] == "LOAD":
        registres[int(instructions[ip][1][1])] = donnees[int(instructions[ip][2][1])]
    elif instructions[ip][0] == "STORE":
        donnees[int(instructions[ip][1][1])] = registres[int(instructions[ip][2][1])]
    elif instructions[ip][0] == "MUL":
        registres[int(instructions[ip][1][1])] =  registres[int(instructions[ip][2][1])] *  registres[int(instructions[ip][3][1])]
    elif instructions[ip][0] == "ADD":
        registres[int(instructions[ip][1][1])] =  registres[int(instructions[ip][2][1])] +  registres[int(instructions[ip][3][1])]
    elif instructions[ip][0] == "SUB":
        registres[int(instructions[ip][1][1])] =  registres[int(instructions[ip][2][1])] -  registres[int(instructions[ip][3][1])]
    elif instructions[ip][0] == "DIV":
        registres[int(instructions[ip][1][1])] =  registres[int(instructions[ip][2][1])] /  registres[int(instructions[ip][3][1])]
    elif instructions[ip][0] == "PRINT":
        print("printf : " ,donnees[int(instructions[ip][1][1])])
    elif instructions[ip][0] == "JMP":
        ip=int(instructions[ip][1][1:])-1
    elif instructions[ip][0] == "JMPC":
        if registres[int(instructions[ip][2][1])] == 0:
            ip=int(instructions[ip][1][1:])-1
    elif instructions[ip][0] == "JMPF":
        if int(instructions[ip][2]) != 0:
            ip=int(instructions[ip][1][1])-1
    elif instructions[ip][0] == "COP":
        registres[int(instructions[ip][1][1])] = registres[int(instructions[ip][2][1])]
    elif instructions[ip][0] == "EQU":
        if registres[int(instructions[ip][2][1])] == registres[int(instructions[ip][3][1])]:
            registres[int(instructions[ip][1][1])] = 1
        else:
            registres[int(instructions[ip][1][1])] = 0
    elif instructions[ip][0] == "INF":
        if registres[int(instructions[ip][2][1])] < registres[int(instructions[ip][3][1])]:
            registres[int(instructions[ip][1][1])] = 1
        else:
            registres[int(instructions[ip][1][1])] = 0
            
    elif instructions[ip][0] == "SUP":
        if registres[int(instructions[ip][2][1])] > registres[int(instructions[ip][3][1])]:
            registres[int(instructions[ip][1][1])] = 1
        else:
            registres[int(instructions[ip][1][1])] = 0  
        
    ip+=1

print ("::::::::::::::::::::::::::: Fin d'éxécution :::::::::::::::::::::::::::")
print (":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::")
print ("::::::::::::::::::::::::::: Etat final des registres :::::::::::::::::::::::::::")
print (registres)
print ("::::::::::::::::::::::::::: Etat final des données :::::::::::::::::::::::::::")
print (donnees)

