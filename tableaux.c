#include <stdlib.h>
#include <stdio.h>
#include "tableaux.h"

int* random_tableau(int taille){
    int *tab = (int *)malloc(sizeof(int) * taille);

    for (int i = 0; i < taille; i++)
    {
        tab[i] = rand() % taille;
    }

    return tab;
}

int* constant_tableau(int taille){
    int *tab = (int *)malloc(sizeof(int) * taille);
    int val = rand() % taille; 
    for (int i = 0; i < taille; i++)
    {
        tab[i] = val;
    }

    return tab;
}

int* croissant_tableau(int taille){
    int *tab = (int *)malloc(sizeof(int) * taille);

    for (int i = 0; i < taille; i++)
    {
        tab[i] = i;
    }

    return tab;
}

int* decroissant_tableau(int taille){
    int *tab = (int *)malloc(sizeof(int) * taille);

    for (int i = 0; i < taille; i++)
    {
        tab[i] = taille - i - 1;
    }

    return tab;
}