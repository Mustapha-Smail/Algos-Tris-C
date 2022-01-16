#ifndef SMAIL_MUSTAPHA_C
#define SMAIL_MUSTAPHA_C

void SMAIL_swap(int *xp, int *yp); 
void SMAIL_bubblesort1(int *tab, int taille); 
void SMAIL_bubblesort(int *tab, int taille);    // BUBBLE
void SMAIL_bubblesort3(int *tab, int taille); 
void SMAIL_cocktailshakersort(int *tab, int taille);  // COCKTAIL
int SMAIL_maximum(int *tab, int taille); 
void SMAIL_countingsort(int *tab, int taille); // COMPTAGE
void SMAIL_retourner(int *tab, int indice); 
int SMAIL_indice_maximum(int *tab, int taille); 
void SMAIL_pancakesort(int *tab, int taille);  // CREPES
void SMAIL_cyclesort(int *tab, int taille);  // CYCLE
void SMAIL_fusion(int *tab, int debut, int milieu, int fin); 
void SMAIL_fusion_sort(int *tab, int debut, int fin); 
void SMAIL_fusionsort(int *tab, int taille);  // FUSION
void SMAIL_gnome(int *tab, int b_sup); 
void SMAIL_gnomesort(int *tab, int taille);  // GNOME
void SMAIL_insertionsort(int *tab, int taille); // INSERTION
int SMAIL_plus_large(int *tab, int taille); 
void SMAIL_radixsort(int *tab, int taille);  // RADIX 
int SMAIL_partition(int *tab, int pivot, int debut, int fin); 
void SMAIL_rapide_sort(int *tab, int debut, int fin); 
void SMAIL_quicksort(int *tab, int taille);  // RAPIDE 
void SMAIL_selectionsort(int *tab, int taille);  // SELECTION

#endif