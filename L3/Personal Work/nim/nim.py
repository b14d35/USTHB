import random
import shutil


# Supprimer l'ancien score d'une personne  la fin de la partie
def remove_score(name):
    a = open('score.txt', 'r')
    b = open('temp.txt', 'w')
    temp = a.readline().replace('\n', '')
    while temp:
        ze = temp.split(' ')
        if name != ze[0]:
            b.write(temp+'\n')
        print temp
        temp = a.readline().replace('\n', '')
    a.close()
    b.close()
    shutil.move('temp.txt', 'score.txt')


# Ajouter le score d'une personne  la fin d'une partie
def new_score(name, high, last):
    a = open('score.txt', 'a')
    a.write(name+" "+high+" "+last+"\n")
    a.close()


# Renvoi si le score d'une personne existe
def score(name):
    a = open('score.txt', 'r')
    temp = a.readline().replace('\n', '')
    while temp:
        ze = temp.split(' ')
        if name == ze[0]:
            a.close()
            return ze
        temp = a.readline().replace('\n', '')
    a.close()
    return []


# Affichage de la matrice
def show(x, y):
    i = 1
    s = max(y)
    while i <= x:
        print str(i) + " | " + "*" * y[i-1] + " " * (s - y[i-1]) + " | " + str(y[i-1])
        i += 1


# Somme des boulles restantes
def som(x, y):
    i = 1
    while i <= x:
        if y[i-1] != 1:
            return True
        i += 1
    return False


# Calculer le score
def scor(nb):
    sco = 0
    i = 1
    while i <= nb:
        sco += i * pow(10, i)
        i += 1
    return sco


continuer = 1
while continuer == 1:
    Player1 = (raw_input("Entrez le nom du Player1 : ")).replace(' ', '')
    Player2 = (raw_input("Entrez le nom du Player2 : ")).replace(' ', '')
    while Player2 == Player1:
        Player2 = raw_input("Entrez le nom du Player2 : ")
    P1 = score(Player1)
    P2 = score(Player2)
    if not P1:
        P1.append(Player1)
        P1.append(str(0))
        P1.append(str(0))
    if not P2:
        P2.append(Player2)
        P2.append(str(0))
        P2.append(str(0))
    x = random.randrange(3, 8)
    y = []
    i = 1
    while i <= x:
        y.append(random.randrange(5, 24))
        i += 1
    nbCoup = 1
    who = 1
    looser = 0
    winner = 0
    while som(x, y):
        print "\nPlayer1 : " + P1[0] + "  VS  " + "Player2 : " + P2[0]
        show(x, y)
        t = ""
        print '\n'
        if who == 1:
            t = raw_input(P1[0] + " Choisissez du genre NbrTas-NbrPierres :")
        if who == 2:
            t = raw_input(P2[0] + " Choisissez du genre NbrTas-NbrPierres :")
        z = t.split('-')
        tas = int(z[0])
        pier = int(z[1])
        if tas <= x:
            if pier <= y[tas-1]:
                y[tas-1] -= pier
                if y[tas-1] == 0:
                    looser = who
                    if looser == 1:
                        winner = 2
                    else:
                        winner = 1
                    break
                if who == 1:
                    who = 2
                else:
                    who = 1
                    nbCoup += 1
    if looser != 0:
        if who == 2:
            nbCoup -= 1
    sc = scor(nbCoup)
    if looser != 0:
        if not som(x, y):
            if who == 1:
                looser = 2
                winner = 1
            if who == 2:
                looser = 1
                winner = 2
    remove_score(P1[0])
    remove_score(P2[0])
    high = 0
    if winner == 1:
        new_score(P2[0], P2[1], str(0))
        if sc < int(P1[1]):
            high = sc
        else:
            high = int(P1[1])
        new_score(P1[0], str(high), str(sc))
        print "\nLe joueur " + P1[0] + " gagne la partie d'un score de " + str(sc) + " points\n"
    else:
        new_score(P1[0], P1[1], str(0))
        if sc < int(P2[1]):
            high = sc
        else:
            high = int(P2[1])
        new_score(P2[0], str(high), str(sc))
        print "\nLe joueur " + P2[0] + " gagne la partie d'un score de " + str(sc) + " points\n"
    valide = 0
    while valide == 0:
        par = raw_input("\nRecommencer une nouvelle partie : O/N")
        if par == "O" or par == "o":
            continuer = 1
            valide = 1
        if par == "N" or par == "n":
            continuer = 0
            valide = 1