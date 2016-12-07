#include "listing.h"

                /*--------------JE VOUS CONSEIL DE METTRE VOTRE TERMINAL EN PLEIN ECRAN AVANT DE LANCER LE PROGRAMME------------*/

int main()
{
                        /*----------------------------(Question 1)---------------------------*/
    
    char chaine1[tailleMAX]; /*ce tableau de caractere nous sert a remplire les listes de caracteres*/
    int nombredefois;
    char character;
    List list1 = new_list(); 
    printf("   /1/Nous allons commencer par la premiere fonction de comparaison/1/.\n\n");
    printf("Celle-ci compare une liste de caractére et un caratere!!.\n");
    printf("Attention !!!Nous fixerons une limite de 20 caracteres par liste. \n\n\n");
    printf("                 A vous de jouer !!!! \n\n\n");
    printf("Entrer la chaine de caractere de votre choix-> ");
    lire(chaine1, tailleMAX);/*j'utilise cette fonction pour demander a l'utilisateur d'inséré la liste de caractere de sont choix*/
    list1 = push_word_list(list1, chaine1);/*fonction qui insere le tableau de caractere dans la liste vide*/
    printf("Entrer le caractere a comparer avec la liste de votre choix-> ");
    scanf("%c", &character);
    nombredefois = cpt_same_letter(list1, character);
    printf(">>le nombre de fois que le caractere [%c] se repéte dans la liste est-> %d \n\n", character, nombredefois);
    choix(character);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

                        /*-------------------------(Question 2)-----------------------------*/

    list1 = new_list();
    List list2 = new_list();
    printf("             /2/Passons maintenant au deuxiéme algorithme.!!!!/2/\n\n");
    printf("Celle ci compare deux listes et décide si la premiere liste est incluse dans la deuxieme.!!\n\n\n");
    printf("                 Let's Go !!!\n\n\n");
    printf("Entrer la premiére chaine de caractere de votre choix-> ");
    lire(chaine1, tailleMAX);
    list1 = push_word_list(list1, chaine1);
    printf("Entrer la deuxieme chaine de caractere de votre choix-> ");
    lire(chaine1, tailleMAX);
    list2 = push_word_list(list2, chaine1);
    printf(">>");
    cmp_list(list1, list2);
    printf("\n");
    choix(character);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

                        /*-------------------------(Question 3)-----------------------------*/
    int vrai_ou_faux;
    list1 = new_list();
    list2 = new_list();
    printf("          /3/Faite de la place pour le troisiéme algorithme !!!!/3/\n\n");
    printf("Celle ci compare deux liste: \n");
    printf("  -si la premiere liste est plus grande léxicographiquement que la deuxieme alors on renvoie faux.\n");
    printf("  -si la premiere liste est plus petite léxicographiquement que la deuxieme alors on renvoie vrai.\n\n\n");
    printf("                 C'est parti !!!!\n\n\n");
    printf("Entrer la premiére chaine de caractere de votre choix-> ");
    lire(chaine1, tailleMAX);
    list1 = push_word_list(list1, chaine1);
    printf("Entrer la deuxieme chaine de caractere de votre choix-> ");
    lire(chaine1, tailleMAX);
    list2 = push_word_list(list2, chaine1);
    vrai_ou_faux = lexic_cmp_list(list1, list2);
    if(vrai_ou_faux == 0){printf("                   >>FAUX<<\n\n");}
    else{printf("                         >>VRAI<<\n\n");}
    choix(character);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

                        /*-------------------------(Question 4)-----------------------------*/
    list1 = new_list();
    List table[n] = {new_list()};
    printf("                /4/Voici le quatrieme algorithme !!!/4/\n\n");
    printf("Celle ci trie un tableau de listes (on prend l=20 et n=6):\n");
    printf("  -Le trie se fait sur l'ensemble de la liste.\n\n\n");
    printf("                 allons-y !!!!!\n\n\n");
    printf("Entrer la premiére chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[0] = push_word_list(list1, chaine1);
    printf("Entrer la deuxieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[1] = push_word_list(list1, chaine1);
    printf("Entrer la troisieme chaine de caractere de votre choix(liste vide autorisé)-> ");
   lire(chaine1, tailleMAX);
    table[2] = push_word_list(list1, chaine1);
    printf("Entrer la quatrieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[3] = push_word_list(list1, chaine1);
    printf("Entrer la cinquieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[4] = push_word_list(list1, chaine1);
    printf("Entrer la sixieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[5] = push_word_list(list1, chaine1);
    printf("Avons trie:\n");
    print_table_list(table);
    printf("Aprés trie:\n");
    table[n] = sort_table_list(table);
    print_table_list(table);
    printf("\n\n");
    choix(character);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

                       /*-------------------------(Question 5)-----------------------------*/

    list1 = new_list();
    printf("               /5/Voici le cinquieme algorithme !!!!/5/\n\n");
    printf("Le fameux Quicksort !!!(on prend l=20 et n=6).\n");
    printf("  -On trie en fonction de la premiere lettre seulement.\n\n\n");
    printf("                A L'abordage !!!!\n\n\n");
    printf("Entrer la premiére chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[0] = push_word_list(list1, chaine1);
    printf("Entrer la deuxieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[1] = push_word_list(list1, chaine1);
    printf("Entrer la troisieme chaine de caractere de votre choix(liste vide autorisé)-> ");
   lire(chaine1, tailleMAX);
    table[2] = push_word_list(list1, chaine1);
    printf("Entrer la quatrieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[3] = push_word_list(list1, chaine1);
    printf("Entrer la cinquieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[4] = push_word_list(list1, chaine1);
    printf("Entrer la sixieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[5] = push_word_list(list1, chaine1);
    printf("Avons trie:\n");
    print_table_list(table);
    printf("Aprés trie:\n");
    quicksort(table, 0, n-1);
    print_table_list(table);
    printf("\n\n");
    choix(character);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

                       /*-------------------------(Question 6)-----------------------------*/

    list1 = new_list();
    printf("               /6/Voici le Dérniere algorithme !!!!/6/\n\n");
    printf("Le fameux Mergesort!!!(on prend l=20 et n=6).\n");
    printf("  -On trie en fonction de la premiere lettre seulement.\n\n\n");
    printf("                Bientot fini!!!!\n\n\n");
    printf("Entrer la premiére chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[0] = push_word_list(list1, chaine1);
    printf("Entrer la deuxieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[1] = push_word_list(list1, chaine1);
    printf("Entrer la troisieme chaine de caractere de votre choix(liste vide autorisé)-> ");
   lire(chaine1, tailleMAX);
    table[2] = push_word_list(list1, chaine1);
    printf("Entrer la quatrieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[3] = push_word_list(list1, chaine1);
    printf("Entrer la cinquieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[4] = push_word_list(list1, chaine1);
    printf("Entrer la sixieme chaine de caractere de votre choix(liste vide autorisé)-> ");
    lire(chaine1, tailleMAX);
    table[5] = push_word_list(list1, chaine1);
    printf("Avons trie:\n");
    print_table_list(table);
    printf("Aprés trie:\n");
    mergesort(table, 0, n-1);
    print_table_list(table);
    printf("\n\n\n\n\n\n");
    printf("                                    FIN !!!!\n\n");
    printf("                                 A BIENTOT !!!!\n\n\n\n");

    exit(0);
}