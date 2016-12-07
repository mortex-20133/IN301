#include "listing.h"

/*Ces fonction me servent uniquement a executer mes algorithme dans le main()*/

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

void lire(char *chaine, int longueur){
    char *positionEntree = NULL;
    if (fgets(chaine, longueur, stdin) != NULL){
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL){
            *positionEntree = '\0';
        }
        else{viderBuffer();}
    }
    else{viderBuffer();}
}

void choix(char character){
    int a=0;
    printf("voulez vous passer a la question suivante ?(y/n):");
    while(a==0){
        scanf("%s", &character);
        if(character == 'y'){a=1;}
        else if(character == 'n'){exit(0);}
        else{printf("veuillez taper la lettre y pour yes ou n pour no:");}
    }
    viderBuffer();
}

/*----------------------------------------------------------------------*/
/*J'écrirai a coté de quasiment toute les comparaison ou affectation ou autre, ce que sa signifie ou pourquoi j'aurai fait sa.*/
/*La déscription de chaque fonction est décrite briévement dans listing.h.*/

List new_list(void){return NULL;}

/*----------------------------------------------------------------------*/

/*Compléxité : o(1) */
int is_empty_list(List list1){    //return 1 si NULL sinon return 0//
	if (list1 == NULL){return 1;}  
	else{return 0;}               
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(n), "n" étant la taille  maximum de la liste.*/
void print_list(List list1){    
	if(is_empty_list(list1)){  
		printf("[]");          
	}
    else{                              
        while (!is_empty_list(list1)){ 
		printf("[%c]", list1->letter); 
		list1 = list1->next;           //on passe a la liste suivante//
        }
    }
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(5), je prend en compte les affectation et comparaison.*/
List push_front_list(List list1, char character){
	Element *newElement;                            
	newElement = malloc(sizeof(Element));        
	if (is_empty_list(newElement)){              
		fprintf(stderr, "Allocation échouée\n"); 
		exit(EXIT_FAILURE);                      
	}
	if(is_empty_list(list1)){                    
        newElement->letter = character;          
        newElement->next = NULL;}                
	else{
        newElement->letter = character; 
        newElement->next = list1;}
	return newElement;
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(n), n etant la taille de la liste chainéé*/
List push_back_list(List list1, char character){
	Element *newElement;
	newElement = malloc(sizeof(Element));
	if (is_empty_list(newElement)){
		fprintf(stderr, "Allocation échouée\n");
		exit(EXIT_FAILURE);
	}
	newElement->letter = character;
	newElement->next = NULL;
	if(is_empty_list(list1)){return newElement;}
	Element *tmp;
	tmp = list1;//on utilise une variable de type liste pour souvegarder la tete de liste//
	while(!is_empty_list(tmp->next)){tmp = tmp->next;} //on parcour toute la liste.//
	tmp->next = newElement;
	return list1;
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(n), n etant la taille maximal de la liste*/
List push_word_list(List list1, char *chaine){
	int i;
	for (i=0; chaine[i] != '\0'; i++){
		list1 = push_back_list(list1, chaine[i]); //on insere les caractere a la fin de la pile.//
	}
	return list1;
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(n), n etant la taille maximal de la liste*/
int cpt_same_letter(List list1, char character){
	if (is_empty_list(list1)){
		fprintf(stderr, "La liste est vide.\n");
		return 0;
	}            //on compare chaque caractere de la liste avec le caractere qu'on veut comparer//
	int cpt = 0; //on rajoute 1 au compteur a chaque fois que les deux caracteres son égales//      
	while (!is_empty_list(list1)){
		if (list1->letter == character){cpt++;}
		list1 = list1->next;
	}	
	return cpt;
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(n) */
void cmp_list(List list1, List list2)
{
    if (is_empty_list(list1) || is_empty_list(list2)){
        fprintf(stderr, "<<Comparaison impossible.");
        return;
    }
    int i = cpt_same_letter(list2, list1->letter); 
    /*si on trouve aucun caractere en commun avec le premier caractere de la liste, on quitte l'algo.*/
    if(i == 0){printf("La premiere liste n'ai pas contenu dans la deuxieme liste.\n");}
    else{
        List tmp;
        tmp = list1; /* on utilise une liste temporaire pour ne pas perdre le pointeur de tete de liste*/
        while (list2->letter != list1->letter){list2 = list2->next;}
        while((!is_empty_list(list2) && !is_empty_list(tmp)) && (list2->letter == tmp->letter)){
            list2 = list2->next;
            tmp = tmp->next;
        }
        if (is_empty_list(tmp)){/*s la premiere liste est NULL alors on aura parcourue toute la liste, donc tout les caracteres son égaux*/
            printf("La premiere liste est contenu dans la deuxieme liste.\n");return;
        }
        else if (!is_empty_list(tmp) && !is_empty_list(list2)){cmp_list(tmp, list2);}
        /*si la deuxieme liste est vide mais que la premiere non , alors la premiere liste n'ai pas incluse dans la deuxieme*/
        else if(!is_empty_list(tmp) && is_empty_list(list2)){
            printf("La premiere liste n'ai pas contenu dans la deuxieme liste.\n");return;
        }
    }
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(n*n), (n*n) représente n au carré.*/
int lexic_cmp_list(List list1, List list2){/*on va faire des apelles recursives avec toute les conditions.*/
	if (is_empty_list(list1) && is_empty_list(list2)){return 0;}
	else if (!is_empty_list(list1) && is_empty_list(list2)){return 0;}
	else if (!is_empty_list(list2) && is_empty_list(list1)){return 1;}
	else if (list2->letter > list1->letter){return 1;}
	else if (list2->letter < list1->letter){return 0;}
	else if (list2->letter == list1->letter){lexic_cmp_list(list1->next, list2->next);}
}

/*----------------------------------------------------------------------*/

/*la compléxité est : o(n*tailleMAX), n:taille du tableau, tailleMAX:taille de la liste*/
void print_table_list(List table[]){   
    int i;
    if(n == 0){
        fprintf(stderr, "Le tableau de liste est vide.\n");
        return;
    }
    for(i=0; i<n; i++){ /*on apelle en boucle la fonction print_list qui affiche une liste*/
       printf("Case [%d] : ", i+1);
       print_list(table[i]);
       printf("\n");
    }
}

/*----------------------------------------------------------------------*/

/*la compléxité de : o(n*n), (n*n) représente n au carré.*/
List sort_table_list(List table[]){
    List tmp;
    int i,j;
    if(table[n] == NULL){
        printf("Le tableau est vide.\n");
        return 0;
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(lexic_cmp_list(table[i], table[j]) == 0){/*sa compare les caractere de la liste deux a deux, et les pérmute pour les metre en ordre croissant*/
                tmp = table[i];
                table[i] = table[j];
                table[j] = tmp;
            }
        }
    }
    return table[n];
}

/*----------------------------------------------------------------------*/

/*Compléxité : o(n);*/
int partition(List table[], int debut, int fin){
    int cpt = debut; int j = debut;
    List pivot,tmp;
    pivot = table[fin]; /*on place toujour le pivot a la fin de la liste*/
    while(cpt<fin){     /*cpt est le compteur qui parcours le tableau*/
        if(table[cpt]->letter <= table[fin]->letter){/*si la case du compteur est plus petite que le pivot, on permute avec j et cpt*/
            tmp = table[cpt];
            table[cpt] = table[j];
            table[j] = tmp;
            j++;            /*on implémente j seulement quand la case du tableau est plus petite que le pivot*/
        }
        cpt++;  /*cpt parcours le tableau*/
    }
    tmp = table[fin];
    table[fin] = table[j];/*on inverse j et le pivot pour que toute les valeur apres table[j] sois superieur , et les valeur avons son inferieur*/
    table[j] = tmp;
    return j; /*on return j qui est le nouveau pivot*/
}

/*----------------------------------------------------------------------*/

/*compléxité : n*logn .*/
void quicksort(List table[], int debut, int fin){
    List pivot;
    int j; int i;
    for(i=debut; i<n; i++){ /*je fait cette boucle pour metre au debut du tableau toute les liste qui son NULL*/
        if(table[i] == NULL){
            pivot = table[i];
            table[i] = table[debut];
            table[debut] = pivot;
            debut++; /*j'implémente debut pour ne plus toucher au premiere case qui son NULL*/
        }
    }
    if(fin>debut){ /*ici on fait des apelles récurcives pour triés le tableau avec la méthode du pivot*/
        pivot = table[fin];
        j = partition(table, debut, fin);
        quicksort(table, debut, j-1);
        quicksort(table,j+1,fin);
    }
}

/*----------------------------------------------------------------------*/

/*compléxité : o(n).*/
void merge(List table[], int debut, int milieu, int fin){
    Element *fusion[(fin-debut+1)];
    fusion[(fin-debut+1)] = malloc((fin-debut+1)*sizeof(Element));/*on crée une variable de type liste pour faire une copie du tableau de base*/
    int i = debut; int j = milieu+1; int k = 0;
    while((i <= milieu) && (j <= fin)){ /*la boule ne s'arrete pas avons que les deux coté des deux tableau son égaux et de taille superieur a 1.*/
        if(table[i]->letter <= table[j]->letter){ /*on compare chaque tableau entre eu pour determiner le plus petit*/
            fusion[k++] = table[i++]; /*puis on souvegarde les valeurs dans le tableau temporaire "fusion"*/
        }
        else{
            fusion[k++] = table[j++];
        }
    }
    while(i <= milieu){ /* ce cas est plutot déstiné au tableau dont la taille n'ai pas une puissane de 2*/
        fusion[k++] = table[i++];/*si il reste toujours des tableau non triée alors on les affecte directement dans le tableau fusion*/
    }
    while(j <= fin){
        fusion[k++] = table[j++];
    }
    i = debut; k = 0;
    while(i<=fin){ /*on fait une simple boucle pour affecter les valeur du tableau triée dans notre encien tableau non triée*/
        table[i++] = fusion[k++];
    }
    free(fusion[(fin-debut+1)]); /*on libere la mémoire alloué préalablement.*/   
}

/*----------------------------------------------------------------------*/

/*Compléxité : nlogn .*/
void mergesort(List table[], int debut, int fin){
    int milieu;
    int cpt;
    List tmp;
    for(cpt=debut; cpt<n; cpt++){ /*je fait cette boucle pour metre au debut du tableau toute les liste qui son NULL en fesant des permutation*/
        if(table[cpt] == NULL){
            tmp = table[cpt];
            table[cpt] = table[debut];
            table[debut] = tmp;
            debut++;    /*j'implémente debut pour ne plus toucher au premiere case qui son NULL*/
        }
    }
    if(fin>debut){
        milieu = (debut+fin)/2; /*on divise le tableau en 2 a chaque apelle recursive, il s'arrete quand tout les tableau vallent 1.*/
        mergesort(table, debut, milieu);
        mergesort(table, milieu+1, fin);
        merge(table, debut, milieu, fin);
    }
}

/*----------------------------------------------------------------------*/