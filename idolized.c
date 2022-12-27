#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int armure[5] = {0,0,0,0};
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
    int actionJoueurRune = 0;
    int sowilo = 0;
    int runeTurnSowilo = 0;
    int runeTurn = 0;
    int jera = 0;
    int berkana = 0;
    int algiz = 0;
    void delay(int);
    puts("Welcome in Idolized Battle - Entrusting This World to Idols ~ Idolatrize World\nSelect the number of HP of Byakuren beetwen 50 000 and 2 000 000 000");
    do {
        fflush(stdin);
        scanf("%d", &pvBoss);
        pvBossMax = pvBoss;
        if (pvBoss <= 49999) {
            puts("Byakuren need to have a minimum of 50 000 HP");
        }
        else if (pvBoss >= 2000000001) {
            puts("Calm down! you outpass the limit of HP");
        }
    } while (pvBoss <= 49999 || pvBoss >= 2000000001);
    system("cls");
    printf("The number of HP is %d\n", pvBoss);
    puts("Enjoy!");
    while (pvBoss > 0) {
        printf("Press the number of the action and enter:\n \n1: Attack                                                        2: Greedier as you can (- %d pieces) \n3: Heal (-25 mana)                                               4: Evolution (-%d pieces, +100 hp max, +25 mana max \n",
              50 + coin / 4 ,50 + evolution * 5);
        printf("5: Domination (-%d mana -%d piece +25 force)                     6: Hush (-1000 mana -2500 pieces)\n7: Idolatrize spirit power charge (-%d mana)                    8: Idolatrize spirit power release\n",
               45 + Domination * 5, 45 + Domination * 5, 100 + 50 * idolatrizeCharge);
        puts("9: Stats                                                         10: Shop(comming soon)\n11: Catalog(coming soon)                                                    12: Rune's menu (coming soon)");
        fflush(stdin);
        scanf("%d", &actionJoueur);
        switch (actionJoueur) {
            case 0:
                break;
            case 1:
                system("cls");
                if (manaJoueur < 100 + manaMaxBonus) {
                    manaJoueur += 10 + manaMaxBonus * 100 / 500;
                    printf("+", 10 + manaMaxBonus * 100 / 500, " mana \n");
                } else {
                    manaJoueur = manaMax + manaMaxBonus;
                }
                printf("Byakuren lose %d HP! You earn %d coin \n", forceJoueur * Domination,
                       coinBonus + 5);
                printf("You got attacked, you lose %d HP \n \n", 50 + forceBoss);
                coin += 5 + coinBonus;
                pvJoueur -= 50 + forceBoss;
                pvBoss -= forceJoueur * Domination;
                if (manaJoueur >= 100 + manaMaxBonus) {
                    manaJoueur = 100 + manaMaxBonus;
                }
                printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                runeTurnSowilo++;
                turn++;
                break;
            case 2:
                if (coin >= 50 + coin / 4) {
                    system("cls");
                    printf("You spend your money, Byakuren lose %d HP! \n",
                           forceJoueur * Domination * coin);
                    printf("You got attacked, you lose %d HP \n \n", 50 + forceBoss);
                    pvJoueur -= 50 + forceBoss;
                    coin -= 50 + coin / 4;
                    pvBoss -= forceJoueur * Domination * coin;
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    turn++;
                } else {
                    system("cls");
                    puts("You don't have enough money \n");
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
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
                        printf("You recover %d HP! \n \n", 200 + pvMaxBonus * 100 / 400);
                        printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                        turn++;
                    } else {
                        system("cls");
                        puts("You don't have enough mana \n");
                        printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    }
                } else {
                    if (manaJoueur >= 25) {
                        system("cls");
                        pvJoueur = pvMax + pvMaxBonus;
                        manaJoueur -= 25;
                        printf("Max HP! %d / %d\n \n", pvJoueur, 1000 + pvMaxBonus);
                        printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                        turn++;
                    } else {
                        puts("You don't have enough mana \n");
                        printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                        printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    }
                }
                break;
            case 4:
                if (coin >= 50 + evolution * 5) {
                    system("cls");
                    puts("You get stronger, +25 mana max and 150 hp max");
                    printf("You got attacked, you lose %d HP \n \n", 50 + forceBoss);
                    pvJoueur -= 50 + forceBoss;
                    coin -= 50 + evolution * 5;
                    evolution++;
                    pvMaxBonus += 150;
                    manaMaxBonus += 25;
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    turn++;
                } else {
                    system("cls");
                    puts("You don't have enough coin \n");
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                }
                break;
            case 5:
                if (manaJoueur >= 45 + Domination * 5 && coin >= 45 + Domination * 5) {
                    system("cls");
                    puts("You get stronger, +25 strength");
                    printf("You got attacked, you lose %d HP \n \n", 50 + forceBoss);
                    pvJoueur -= 50 + forceBoss;
                    coin -= 50 + Domination * 5;
                    manaJoueur -= 50 + Domination * 5;
                    forceJoueur += 25;
                    Domination += 1;
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    turn++;
                } else {
                    system("cls");
                    puts("You don't have enough coin/mana \n");
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                }
                break;
            case 6:
                if (manaJoueur >= 1000 && coin >= 2500) {
                    system("cls");
                    manaJoueur -= 1000;
                    coin -= 2500;
                    puts("You release a huge amount of power!");
                    hush = pvBoss * 0.25;
                    printf("Byakuren lose %d HP! \n \n", hush);
                    pvBoss -= hush;
                    hush = 0;
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    turn++;
                } else {
                    system("cls");
                    puts("You don't have enough coin/mana \n");
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                }
                break;
            case 7:
                if (manaJoueur >= 100 + 50 * idolatrizeCharge) {
                    system("cls");
                    manaJoueur -= 100 + 50 * idolatrizeCharge;
                    idolatrizeCharge++;
                    printf("+1 divine spirit, You have %d divine spirit \n \n", idolatrizeCharge);
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    turn++;
                } else {
                    system("cls");
                    puts("You don't have enough mana \n");
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                }
                break;
            case 8:
                if (idolatrizeCharge >= 1) {
                    system("cls");
                    printf("You release all your divine spirit... Byakuren lose %d HP! \n",
                           250 * idolatrizeCharge * forceJoueur * Domination);
                    printf("You got attacked, You lose %d HP! \n", 250 + forceBoss);
                    pvJoueur = 500;
                    pvBoss -= 250 * idolatrizeCharge * forceJoueur * Domination;
                    idolatrizeCharge = 0;
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    turn++;
                } else {
                    system("cls");
                    puts("You don't have any divine spirit");
                    printf("Player --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
                    printf("Mana --> %d / %d              Coin --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
                    
                }
                break;
            case 9:
                system("cls");
                printf("Player --> %d / %d        Byakuren --> %d / %d \n", pvJoueur, 1000 + pvMaxBonus, pvBoss, pvBossMax);
                printf("Mana ----> %d / %d           Coin --> %d \n", manaJoueur, 100 + manaMaxBonus, coin);
                printf("Strength ---> %d                Byakuren strength ---> %d \n", forceJoueur, forceBoss);
                printf("Domination --> %d\n", Domination);
                printf("----------------\n-----Armure-----\n----------------\n");
                printf("-----> HELMET \n-> \n");
                printf("-----> CHESTPLATE \n-> \n");
                printf("-----> LEGGINGS \n-> \n");
                printf("-----> BOOTS \n-> \n");
                break;

            case 10000:
                system("cls");
                printf("--------------------------\n---------THE SHOP---------\n--------------------------\n");
                printf("Voulez-vous acheter cet objet?\n---> \n");
                break;

            case 11000:
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

            case 12000:
                do {
                    system("cls");
                    printf("quelle rune voulez-vous utilisez?\n");
                    printf("1: La rune de Sowilo --> %d       2: La rune de Algiz --> %d\n", sowilo, algiz);
                    printf("3: La rune de Jera   --> %d       4: La rune de Berkana --> %d\n \n", jera, berkana);
                    actionJoueurRune = 1;
                    scanf("%d", &actionJoueurRune);
                } while (actionJoueurRune < 1 || actionJoueurRune > 4);
                if (sowilo >= 1 && actionJoueurRune == 1){
                    printf("Vous utilisez la rune de Sowilo...\nElle inflige %d degat\n", forceJoueur * Domination * 25);
                    actionJoueurRune = 0;
                }
                else {
                    printf("Vous n'avez pas de rune de Sowilo\n");
                    actionJoueurRune = 0;
                }

            default:
                system("cls");
                printf("\nvaleur invalide... \n");

        }
        if (runeTurnSowilo == 2 ){
            system("cls");
            printf("Vous obtenez une rune de Sowilo\n");
            sowilo += 1;
            runeTurnSowilo = 0;
        }

        if (turn >= 50) {
            system("cls");
            forceBoss += 15;
            coinBonus += 8;
            puts("Byakuren devient plus forte, + 5 piece par attaque \n \n");
            printf("Byakuren utilise;\nGreat Magic <<Devil's Recitation>>\n -%d PV\n", 250 + forceBoss);
            pvJoueur -= 250 + forceBoss;
            printf("Joueur --> %d / %d      Byakuren --> %d  PV \n", pvJoueur, 1000 + pvMaxBonus, pvBoss);
            printf("Mana --> %d / %d              pieces --> %d   \n \n", manaJoueur, 100 + manaMaxBonus,coin);
            turn = 0;
        }
            if (pvJoueur <= 0) {
                if (berkana >= 1) {
                    system("cls");
                    pvJoueur = 250;
                    printf("la rune de berkana vous protege...\n");
                    berkana -= 1;
                }
                else {
                    system("cls");
                    puts("Vous avez perdu... reviens quand tu sera pret! \n");
                    delay(2);
                    return 0;
                }
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
