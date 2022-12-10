#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int buy() {

}
int main () {
    int pvJoueur = 1000;
    int pvMax = 1000;
    int pvMaxBonus = 0;
    int manaMaxBonus = 0;
    int pvBossMax = 0;
    int actionJoueur = 0;
    int coin = 0;
    int coinBonus = 0;
    int idolatrizeCharge  = 0;
    int hush  = 0;
    int turn = 0;
    int forceBoss = 0;
    int evolution = 0;
    int manaJoueur = 100;
    int manaMax = 100;
    int forceJoueur = 100;
    int Domination = 1;
    int pvBoss = 500;
    void delay(int);
    puts("Bienvenue a toi dans Idolized Battle - Entrusting This World to Idols ~ Idolatrize World\nChoisissez le nombre de PV du boss entre 101 et 2 147 483 647");
    do {
        fflush(stdin);
        scanf("%d", &pvBoss);
        pvBossMax = pvBoss;
        if (pvBoss <= 101) {
            puts("Le Boss doit avoir un minimum de vie pour tank une attaque, sinon cela ne sert a rien de jouer");
        }
        else if (pvBoss >= 2147483647) {
            puts("ca fait un peu beaucoup nan?");
        }
    } while (pvBoss <= 101 || pvBoss >= 2147483647);
    system("cls");
    printf("le nombre de pv du boss est de %d PV... \n", pvBoss);
    puts("Amuse toi bien...");
    while (pvBoss > 0) {
        printf("Appuyez sur le numero correspondant a l'action puis sur entree\nListe des actions:\n \n1: Attaque                                                       2: Greedier as you can (-20 pieces) \n3: Heal (-25 mana)                                               4: Evolution (-%d pieces, +100 hp max, +25 mana max \n",
               50 + evolution * 5);
        printf("5: Domination (-%d mana -%d piece +25 force)                     6: Hush (-1000 mana -2500 pieces)\n7: Idolatrize spirit power charge (-%d mana)                    8: Idolatrize spirit power release\n",
               45 + Domination * 5, 45 + Domination * 5, 100 + 100 * idolatrizeCharge);
        puts("9: Stats                                                         10: Shop\n11: Catalogue");
        fflush(stdin);
        scanf("%d", &actionJoueur);
        switch (actionJoueur) {
            case 1:
                system("cls");
                if (manaJoueur < 100 + manaMaxBonus) {
                    manaJoueur += 10 + manaMaxBonus * 100 / 500;
                    printf("+", 10 + manaMaxBonus * 100 / 500, " mana \n");
                } else {
                    manaJoueur = manaMax + manaMaxBonus;
                }
                printf("Vous attaquez le boss vous lui enlevez %d PV! et gagnez %d piece \n", forceJoueur * Domination,
                       coinBonus + 5);
                printf("Vous vous faites attaquez - %d Pv \n \n", 50 + forceBoss);
                coin += 5 + coinBonus;
                pvJoueur -= 50 + forceBoss;
                pvBoss -= forceJoueur * Domination;
                if (manaJoueur >= 100 + manaMaxBonus) {
                    manaJoueur = 100 + manaMaxBonus;
                }
                printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                turn++;
                break;
            case 2:
                if (manaJoueur >= 50 && coin >= 50) {
                    system("cls");
                    printf("Vous utilisez la magie interdite vous lui enlevez %d PV! \n",
                           forceJoueur * Domination * coin);
                    printf("Vous vous faites attaquer -%d PV \n \n", 50 + forceBoss);
                    pvJoueur -= 50 + forceBoss;
                    coin -= 20;
                    pvBoss -= forceJoueur * Domination * coin;
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    turn++;
                } else {
                    system("cls");
                    puts("vous n\'avez pas assez de mana/piece \n");
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                }
                break;
            case 3:
                if (pvJoueur < 1000 + pvMaxBonus) {
                    if (manaJoueur >= 25) {
                        system("cls");
                        pvJoueur += 200 + pvMaxBonus * 100 / 500;
                        manaJoueur -= 25;
                        if (pvJoueur >= 1000 + pvMaxBonus) {
                            pvJoueur = 1000 + pvMaxBonus;
                        }
                        printf("Vous gagnez %d PV! \n \n", 200 + pvMaxBonus * 100 / 400);
                        printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                        turn++;
                    } else {
                        system("cls");
                        puts("plus assez de mana \n");
                        printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    }
                } else {
                    if (manaJoueur >= 25) {
                        system("cls");
                        pvJoueur = pvMax + pvMaxBonus;
                        manaJoueur -= 25;
                        printf("PV au MAX!! %d / %d\n \n", pvJoueur + pvMaxBonus, 1000 + pvMaxBonus);
                        printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                        turn++;
                    } else {
                        puts("plus assez de mana \n");
                        printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    }
                }
                break;
            case 4:
                if (coin >= 50 + evolution * 5) {
                    system("cls");
                    puts("Vous vous renforcez, +25 mana et 100 pv");
                    printf("Vous vous faites attaquez -%d Pv \n \n", 50 + forceBoss);
                    pvJoueur -= 50 + forceBoss;
                    coin -= 50 + evolution * 5;
                    evolution++;
                    pvMaxBonus += 100;
                    manaMaxBonus += 25;
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    turn++;
                } else {
                    system("cls");
                    puts("plus assez de pieces \n");
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                }
                break;
            case 5:
                if (manaJoueur >= 45 + Domination * 5 && coin >= 45 + Domination * 5) {
                    system("cls");
                    puts("Vous vous renforcez, +25 force +1 domination");
                    printf("Vous vous faites attaquez -%d Pv \n \n", 50 + forceBoss);
                    pvJoueur -= 50 + forceBoss;
                    coin -= 50 + Domination * 5;
                    manaJoueur -= 50 + Domination * 5;
                    forceJoueur += 25;
                    Domination += 1;
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    turn++;
                } else {
                    system("cls");
                    puts("plus assez de pieces/mana \n");
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                }
                break;
            case 6:
                if (manaJoueur >= 1000 && coin >= 2500) {
                    system("cls");
                    manaJoueur -= 1000;
                    coin -= 2500;
                    puts("Vous sentez un grand pouvoir affluer en vous... \n Et vous le liberez...");
                    hush = pvBoss * 0.25;
                    printf("Vous avez infligé %d PV! \n \n", hush);
                    pvBoss -= hush;
                    hush = 0;
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    turn++;
                } else {
                    system("cls");
                    puts("plus assez de pieces/mana \n");
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                }
                break;
            case 7:
                if (manaJoueur >= 100 + 100 * idolatrizeCharge) {
                    system("cls");
                    manaJoueur -= 100 + 100 * idolatrizeCharge;
                    idolatrizeCharge++;
                    printf("Vous accumulez des esprits divins... vous en avez %d \n \n", idolatrizeCharge);
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    turn++;
                } else {
                    system("cls");
                    puts("Vous n'avez pas assez de mana \n");
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                }
                break;
            case 8:
                if (idolatrizeCharge >= 1) {
                    system("cls");
                    printf("Vous liberez les esprits divin que vous avez accumulez... %d PV! \n",
                           10000 * idolatrizeCharge * forceJoueur * Domination);
                    printf("Vous vous faites attaquez - %d PV! \n", 250 + forceBoss);
                    pvJoueur = 500;
                    pvBoss -= 1000 * idolatrizeCharge * forceJoueur * Domination;
                    idolatrizeCharge = 0;
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                    turn++;
                } else {
                    system("cls");
                    puts("vous avez aucun esprit divin");
                    printf("Joueur --> %d / %d      Boss --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d               pieces --> %d   \n \n", manaJoueur, coin);
                }
                break;
            case 9:
                system("cls");
                printf("Joueur --> %d / %d        Boss --> %d / %d \n", pvJoueur, 1000 + pvMaxBonus, pvBoss, pvBossMax);
                printf("Mana ----> %d / %d           pieces --> %d \n", manaJoueur, 100 + manaMaxBonus, coin);
                printf("Force ---> %d                Force boss ---> %d \n \n", forceJoueur, forceBoss);
                printf("----------------\n-----Armure-----\n----------------\n");
                printf("-----> CASQUE \n-> \n");
                printf("-----> TORSE \n-> \n");
                printf("-----> JAMBIERE \n-> \n");
                printf("-----> BOTTES \n-> \n");
                break;

            case 10:
                system("cls");
                printf("--------------------------\n---------THE SHOP---------\n--------------------------\n");
                printf("Voulez-vous acheter cet objet?\n---> \n");
                break;

            case 11:
                system("cls");
                break;

            case 42694269:
                system("cls");
                puts("--------------------------------\n-------Welcome-to-Eientei-------\n--------------------------------\n");
                puts("Comment t'as trouve notre Eientei?");
                puts("btw tous ceux qui trouvent Eientei doivent mourrir, cya o/");
                pvJoueur = 1;
                manaJoueur = 24;
                break;

            default:
                printf("\nvaleur invalide... \n");

        }
        if (pvJoueur <= 0) {
            system("cls");
            puts("Vous avez perdu... reviens quand tu sera pret! \n");
            delay(2);
            return 0;
        }

        if (turn >= 50) {
            forceBoss += 25;
            coinBonus += 5;
            puts("Le boss devient plus fort, + 5 piece par attaque \n");
            turn = 0;
        }
    }
    system("cls");
    puts("Merci d'etre arrive au bout de ce jeu...");
    delay(2);
    system("cls");
    puts("Idolized battle 01");
    delay(1);
    puts("Credit");
    puts("Developpement \nBaptiste aka Yukulel");
    puts("Official English Translator & Bug Destroyer\nFlan aka @Mockonaa");
    delay(2);
    puts("Bug bounty...");
    delay(2);
    puts("Suggestions...");
    delay(4);
    puts("Et vous...");
    delay(5);
    return 0;
}


void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}
