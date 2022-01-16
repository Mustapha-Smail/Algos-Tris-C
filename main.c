#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SMAIL_Mustapha.h"
#include "tableaux.h"

int NB_FUNCS = 10; 

struct functions
{
    char nom[255];
    void (*function)(int *, int);
};
typedef struct functions functions;

functions funcs[] = {
    {"countingsort", &SMAIL_countingsort},
    {"gnomesort", &SMAIL_gnomesort},
    {"fusionsort", &SMAIL_fusionsort},
    {"quicksort", &SMAIL_quicksort},
    // {"radixsort", &SMAIL_radixsort}, // Il y'a une erreur de gestion de mémoire dans l'algo de radix, il genere des erreurs
    {"insertionsort", &SMAIL_insertionsort},
    {"selectionsort", &SMAIL_selectionsort},
    {"cocktailshakersort", &SMAIL_cocktailshakersort},
    {"pancakesort", &SMAIL_pancakesort},
    {"cyclesort", &SMAIL_cyclesort},
    {"bubblesort", &SMAIL_bubblesort}
};

int *copie_tableau(int *tab, int taille)
{
    int *copie = (int *)malloc(sizeof(int) * taille);

    for (int i = 0; i < taille; i++)
    {
        copie[i] = tab[i];
    }

    return copie;
}

float temps(int *tab, int taille, void (*tri)(int *, int))
{
    clock_t tic = clock();
    tri(tab, taille);
    clock_t toc = clock();

    float time = (float)(toc - tic) / CLOCKS_PER_SEC;
    return time;
}


void comparer(char filename[], int* (*tableau)(int)){
    int taille = 10000; 

    FILE* fp; 
    fp = fopen(filename, "w+"); 
    
    if(fp == NULL){
        printf("ouverture impossible\n"); 
        exit(1); 
    }
    
    fprintf(fp, "%s", "taille"); 
    for (int i = 0; i < NB_FUNCS; i++)
    {
        fprintf(fp,"%s", ", "); 
        fprintf(fp, "%s", funcs[i].nom); 
    }
    fprintf(fp, "%s", "\n"); 
    


    while (taille <= 100000)
    {
        int *tab = tableau(taille); 
        char buff[100];
        
        printf("taille: %d.....\n", taille); 
        fprintf(fp, "%d", taille); 
        
        for (int i = 0; i < NB_FUNCS; i++)
        {
            printf("%s\n", funcs[i].nom); 
            fprintf(fp,"%s", ", "); 
            int* copie = copie_tableau(tab, taille); 
            float time = temps(copie, taille, funcs[i].function);
            free(copie); 
            fprintf(fp, "%f", time); 
        }
        
        fprintf(fp, "%s", "\n"); 
        free(tab); 
        taille += 10000; 
    }
    
    fclose(fp); 
}


void generer_graphes(char filename[], char image_name[])
{
    char * commande =( char *) malloc ( sizeof ( char ) *2000) ;
    commande = strcat(commande, " gnuplot -e \" set terminal png size 900,600;");
    commande = strcat(commande, "set title 'Comparaison des algo de tri sur des tableau ");
    commande = strcat(commande, image_name);
    commande = strcat(commande, "';");
    commande = strcat(commande, "set key outside ;");
    commande = strcat(commande, "set xlabel 'Taille des tableaux ';");
    commande = strcat(commande, "set ylabel 'Temps en secondes';");
    commande = strcat(commande, "set datafile separator ',' ;");
    commande = strcat(commande, "set style fill solid 0.3; ");
    commande = strcat(commande, "set style data line ;");
    commande = strcat(commande, " plot for [i =2:11] '");
    commande = strcat(commande, filename);
    commande = strcat(commande, "' using i: xtic (1) title columnheader linewidth 3\" > ");
    commande = strcat(commande, image_name);
    commande = strcat(commande, ".png");
    system(commande);
}

int main(int argc, char const *argv[])
{
    // Generer les fichiers (taille, et temps d'execution de chaque algo)
    printf("croissants\n"); 
    comparer("croissant_10k_100k.csv", &croissant_tableau); 
    printf("decroissants\n"); 
    comparer("decroissant_10k_100k.csv", &decroissant_tableau); 
    printf("aleatoires\n"); 
    comparer("random_10k_100k.csv", &random_tableau); 
    printf("constants\n"); 
    comparer("constant_10k_100k.csv", &constant_tableau); 
    
    // Generer les graphes de chaque fichier 
    generer_graphes("croissant_10k_100k.csv", "croissants"); 
    generer_graphes("decroissant_10k_100k.csv", "decroissants"); 
    generer_graphes("random_10k_100k.csv", "aleatoires"); 
    generer_graphes("constant_10k_100k.csv", "constants"); 
    
    
    // Lien des graphes generés
    // https://we.tl/t-fUdYZJqG0o
    
    return 0;
}
