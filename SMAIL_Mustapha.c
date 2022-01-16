#include <stdlib.h>
#include <stdio.h>
#include "SMAIL_Mustapha.h"

//--------------------------------------------------------------------------------//

void SMAIL_swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SMAIL_bubblesort1(int *tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                SMAIL_swap(&tab[j], &tab[j + 1]);
            }
        }
    }
}

//--------------------------------------------------------------------------------//

void SMAIL_bubblesort(int *tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille - 1 - i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                SMAIL_swap(&tab[j], &tab[j + 1]);
            }
        }
    }
}

//--------------------------------------------------------------------------------//

void SMAIL_bubblesort3(int *tab, int taille)
{
    int i = 0, continuer = 1;
    while (i < taille && continuer == 1)
    {
        continuer = 0;
        for (int j = 0; j < taille - 1 - i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                SMAIL_swap(&tab[j], &tab[j + 1]);
                continuer = 1;
            }
        }
    }
}

//--------------------------------------------------------------------------------//

void SMAIL_cocktailshakersort(int *tab, int taille)
{
    int echange = 1, debut = 0, fin = taille - 2;

    while (echange == 1)
    {
        echange = 0;
        for (int i = debut; i <= fin; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                SMAIL_swap(&tab[i], &tab[i + 1]);
                echange = 1;
            }
        }

        for (int i = fin; i > debut; i--)
        {
            if (tab[i] < tab[i - 1])
            {
                SMAIL_swap(&tab[i], &tab[i - 1]);
                echange = 1;
            }
        }
        fin -= 1;
        debut += 1;
    }
}

//--------------------------------------------------------------------------------//

int SMAIL_maximum(int *tab, int taille)
{
    int max = tab[0];
    for (int i = 1; i < taille; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }

    return max;
}

void SMAIL_countingsort(int *tab, int taille)
{
    int x = 0, max = SMAIL_maximum(tab, taille);
    int *comptage = (int *)calloc(sizeof(int), max + 1);

    for (int i = 0; i < taille; i++)
    {
        comptage[tab[i]]++;
    }

    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j < comptage[i]; j++)
        {
            tab[x] = i;
            x += 1;
        }
    }
}

//--------------------------------------------------------------------------------//

void SMAIL_retourner(int *tab, int indice)
{
    int i = 0;
    while (i < indice)
    {
        SMAIL_swap(&tab[i], &tab[indice]);
        indice--;
        i++;
    }
}

int SMAIL_indice_maximum(int *tab, int taille)
{
    int indice = 0;

    for (int i = 0; i < taille; i++)
    {
        if (tab[i] > tab[indice])
        {
            indice = i;
        }
    }

    return indice;
}

void SMAIL_pancakesort(int *tab, int taille)
{
    int i = taille;

    while (i > 1)
    {
        int maximum_indice = SMAIL_indice_maximum(tab, i);
        SMAIL_retourner(tab, maximum_indice);
        SMAIL_retourner(tab, i - 1);
        i--;
    }
}

//--------------------------------------------------------------------------------//

void SMAIL_cyclesort(int *tab, int taille)
{
    int ecritures = 0, debut, element, pos, temp, i;

    for (debut = 0; debut < taille - 1; debut++)
    {
        element = tab[debut];
        pos = debut;
        for (i = debut + 1; i < taille; i++)
            if (tab[i] < element)
                pos++;
        if (pos == debut)
            continue;
        while (element == tab[pos])
            pos += 1;
        if (pos != debut)
        {
            SMAIL_swap(&element, &tab[pos]);
            ecritures++;
        }
        while (pos != debut)
        {
            pos = debut;
            for (i = debut + 1; i < taille; i++)
                if (tab[i] < element)
                    pos += 1;
            while (element == tab[pos])
                pos += 1;
            if (element != tab[pos])
            {
                temp = element;
                element = tab[pos];
                tab[pos] = temp;
                ecritures++;
            }
        }
    }
}

//--------------------------------------------------------------------------------//

void SMAIL_fusion(int *tab, int debut, int milieu, int fin)
{
    int taille1 = milieu - debut + 1;
    int taille2 = fin - milieu ;

    int gauche[taille1], droite[taille2];
    int i, j, k;

    for (i = 0; i < taille1; i++)
        gauche[i] = tab[debut + i];
    for (j = 0; j < taille2; j++)
        droite[j] = tab[milieu + 1 + j];

    i = 0, j = 0, k = debut;

    while (i < taille1 && j < taille2)
    {
        if (gauche[i] <= droite[j])
        {
            tab[k] = gauche[i];
            i++;
        }
        else
        {
            tab[k] = droite[j];
            j++;
        }
        k++;
    }

    while (i < taille1)
    {
        tab[k] = gauche[i];
        i++;
        k++;
    }

    while (j < taille2)
    {
        tab[k] = droite[j];
        j++;
        k++;
    }
}

void SMAIL_fusion_sort(int *tab, int debut, int fin)
{
    if (debut < fin)
    {
        int milieu = /*debut +*/ (fin + debut) / 2;

        SMAIL_fusion_sort(tab, debut, milieu);
        SMAIL_fusion_sort(tab, milieu + 1, fin);

        SMAIL_fusion(tab, debut, milieu, fin);
    }
}

void SMAIL_fusionsort(int *tab, int taille){
    SMAIL_fusion_sort(tab,   0, taille -1 ); 
}

    //--------------------------------------------------------------------------------//

void SMAIL_gnome(int *tab, int b_sup)
{
    int position = b_sup;
    while (position > 0 && tab[position - 1] > tab[position])
    {
        SMAIL_swap(&tab[position - 1], &tab[position]);
        position--;
    }
}

void SMAIL_gnomesort(int *tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        SMAIL_gnome(tab, i);
    }
}

//--------------------------------------------------------------------------------//

void SMAIL_insertionsort(int *tab, int taille)
{
    for (int i = 1; i < taille; i++)
    {
        int x = tab[i], j = i;
        while (j > 0 && tab[j - 1] > x)
        {
            tab[j] = tab[j - 1];
            j -= 1;
        }

        tab[j] = x;
    }
}

//--------------------------------------------------------------------------------//

int SMAIL_plus_large(int *tab, int taille)
{
    int large = tab[0];
    for (int i = 1; i < taille; i++)
    {
        if (tab[i] > large)
            large = tab[i];
    }
    return large;
}

void SMAIL_radixsort(int *tab, int taille)
{
    int **sceaux;
    int *sceaux_compteur;
    sceaux = (int **)malloc(sizeof(int *) * taille);
    sceaux_compteur = (int *)calloc(taille, sizeof(int));

    for (int i = 0; i < taille; i++)
    {
        sceaux[i] = (int *)malloc(sizeof(int) * taille);
    }

    int i, j, k, reste, nb_digits = 0, diviseur = 1, large, p;
    large = SMAIL_plus_large(tab, taille);
    while (large > 0)
    {
        nb_digits++;
        large /= 10;
    }
    for (p = 0; p < nb_digits; p++)
    {
        for (i = 0; i < taille; i++)
            sceaux_compteur[i] = 0;
        for (i = 0; i < taille; i++)
        {
            reste = (tab[i] / diviseur) % 10;
            sceaux[reste][sceaux_compteur[reste]] = tab[i];
            sceaux_compteur[reste] += 1;
        }

        i = 0;
        for (k = 0; k < taille; k++)
        {
            for (j = 0; j < sceaux_compteur[k]; j++)
            {
                tab[i] = sceaux[k][j];
                i++;
            }
        }
        diviseur *= 10;
    }
}

//--------------------------------------------------------------------------------//

int SMAIL_partition(int *tab, int pivot, int debut, int fin)
{
    SMAIL_swap(&tab[pivot], &tab[fin]);
    int j = debut;
    for (int i = debut; i < fin; i++)
    {
        if (tab[i] <= tab[fin])
        {
            SMAIL_swap(&tab[i], &tab[j]);
            j += 1;
        }
    }
    SMAIL_swap(&tab[fin], &tab[j]);
    return j;
}

void SMAIL_rapide_sort(int *tab, int debut, int fin)
{
    int pivot, indice_pivot;
    if ((fin - debut) > 0)
    {
        pivot = debut;
        pivot = SMAIL_partition(tab, pivot, debut, fin);
        SMAIL_rapide_sort(tab, debut, pivot - 1);
        SMAIL_rapide_sort(tab, pivot + 1, fin);
    }
}

void SMAIL_quicksort(int *tab, int taille){
    SMAIL_rapide_sort(tab, 0, taille -1); 
}

    //--------------------------------------------------------------------------------//

void SMAIL_selectionsort(int *tab, int taille)
{
    for (int i = 0; i < taille - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < taille; j++)
        {
            if (tab[j] < tab[min])
            {
                min = j;
            }
        }

        if (i != min)
        {
            SMAIL_swap(&tab[i], &tab[min]);
        }
    }
}
