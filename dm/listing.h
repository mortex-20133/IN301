#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 6		// n représente le nombre de case du tableau
#define tailleMAX 20  // tailleMAX représente la taille maximal d'une liste de caractere

typedef struct Element{		/*notre structure de liste.*/
	char letter; 			/*champs caractere.*/
	struct Element *next;	/*pointeur vers la liste suivante.*/
} Element, *List; 

void viderBuffer(); /*toujours vider le buffer pour éviter les buffer overflow provoquant une écriture dans une zone mémoire hors du buffer.*/
void lire(char *chaine, int longueur);/*on lit les caracteres tapper préalablement, et qui on était enregistrer temporairement dans le buffer.*/
void choix(char character);/*cette fonction est utiliser dans le main() pour demander de si vous désirer continuer la démonstration ou pas.*/

List new_list(void);/*initilise la nouvelle liste à NULL.*/
int is_empty_list(List list1);/*vérifie si la liste est NULL(je n'ai pas utiliser les booleen car je n'aime pas sa!.)*/
void print_list(List list1);/*affiche la liste.*/
List push_front_list(List list1, char character);/*insére un caractere en tete de liste.*/
List push_back_list(List list1, char character);/*insere un caractere en fin de liste.*/
List push_word_list(List list1, char *chaine);/*insere une chaine de caractere dans une liste.*/
int cpt_same_letter(List list1, char character);/*compte le nombre de fois que le caractere inséré se répéte dans la liste.*/
void cmp_list(List list1, List list2);/*compare deux liste est déside si la premiere est incluse dans la deuxieme.*/
int lexic_cmp_list(List list1, List list2);/*compare léxicographiquement deux listes.*/
void print_table_list(List table[]);/*affiche un tableau de liste.*/
List sort_table_list(List table[]);/*trie un tableau de liste.*/
int partition(List table[], int debut, int fin);/*partitionne le tableau de liste*/
void quicksort(List table[], int debut, int fin);/*c'est le trie rapide.*/
void merge(List table[], int debut, int milieu, int fin);/*elle fusionne les tableau de liste deux a deux*/
void mergesort(List table[], int debut, int fin);/*c'est le trie fusion (elle partitionne puis fusionne)*/


