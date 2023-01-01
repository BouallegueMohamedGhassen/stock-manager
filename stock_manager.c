#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
typedef struct produit {
   char nom ;
   char description ;
   int nbr ; 
}produit;
typedef struct stock {
   produit data ;
   struct stock * next ;
};
int rechercheShift(struct stock * liste , struct produit ele){
    struct stock * pCourant ;
    pCourant = liste ;
    while (pCourant->next != NULL) 
    { 
      if (pCourant->data.nom == ele.nom){
        return 1 ;
      }
      else{
        pCourant = pCourant->next ;
      }
    }
    return 0 ;
}
void ajout_produit(struct stock * liste, struct produit ele )
{  if (rechercheShift(liste,ele) == 0 ) 
   {
    /* Création du nouvel élément */
    struct stock * nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    ele.nbr =1;
    nouveau->data  = ele ;


    /* Insertion de produit au stock */
    nouveau->next = liste;
    return nouveau;
   }
  else {
    struct stock * pCourant;
    pCourant = liste;
    while (pCourant->data.nom != ele.nom)
    { pCourant = pCourant->next ;
    }
    Pcourant->data.nbr=Pcourant->data.nbr + 1 ;
      
       }  
}
void supp_produit(struct stock * liste, struct produit ele){
     if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste != NULL)
    {   struct stock * pCourant ;
        pCourant = liste ;
        if (rechercheShift(liste,ele)){
            while (pCourant->data.nom != ele.nom){ 
                pCourant = pCourant->next ;
                }
            if (pCourant->data.nbr = 1){    
               produit *aSupprimer = pCourant->data;
               pCourant->next = pCourant->next->next;
               free(aSupprimer);}
            else{
                pCourant->data.nbr = pCourant->data.nbr - 1;
            }   

                }
       
    }
}


#define MAX_SIZE 80
void historique( ) {

    time_t timestamp = time( NULL );
    struct tm * pTime = localtime( & timestamp );

    char buffer[ MAX_SIZE ];
    strftime( buffer, MAX_SIZE, "%d/%m/%Y %H:%M:%S", pTime );
            

}
int main(){
    int n ;
    struct stock * liste ;
    struct produit  ele ;
    struct memory {
        char nom_p;
        time_t date_entr;
        time_t date_sort;
    }; 
    struct memory t[1000];
    int i,j ;
    struct memory m ;
    printf("HELLO IN STOCK_MANAGER ^^ \n how can i help you Sir \nplease choose a number: \n 1 :  see the stock \n 2 : see Historic  \n 3 : add product \n 4 : description of a product \n 5 : delete product \n 6 : research of a product  ");
    scanf(n);
    i=0;
    switch(n) {
     case 1:
        struct stock * pCourant ;
        pCourant = liste ;
         while (pCourant->next != NULL){ 
            printf("%s",pCourant->data);
            pCourant = pCourant->next ;
            }
        break;
     case 2:
            for(j = 0; j < i+1 ; j++)
              {
              scanf("%s # %s # %s \n",&t[j].nom_p,&t[j].date_entr,&t[j].date_sort);
              
              }
         
    
        break;
     case 3:
        printf("le nom de produit");
        scanf("%s",ele.nom);
        printf("la decription");
        scanf("%s",ele.description);
        ajout_produit(liste,ele);
        m.nom_p=ele.nom;
        m.date_sort=NULL;
        m.date_entr=historique();
        t[i]=m;
        i=i+1;
        break;
     case 4:
        printf("donner le nom de produit : ");
        char ch;
        scanf(ch);
        struct stock * pCourant ;
        pCourant = liste ;
            while (pCourant->data.nom != ch){ 
                pCourant = pCourant->next ;
                }
         printf("%s",pCourant->data.description);
        break;   
     case 5:
       printf("donner le produit x");
       scanf(ch);
        struct stock * pCourant ;
        pCourant = liste ;
            while (pCourant->data.nom != ch){ 
                pCourant = pCourant->next ;
                }
       supp_produit(liste,pCourant->data);
        break;
     
     default:
      printf("donner le nom de produit : ");
      scanf(ch);
      struct stock * pCourant ;
        pCourant = liste ;
            while (pCourant->next != NULL){ 
                if(pCourant->data.nom == ch){
                    printf("%s",pCourant->data);

                }
                else{
                 pCourant = pCourant->next ;
                }
            if (pCourant->data.nom != ch   ){
            printf(" ce produit n'est pas dans le stock ");
            }

                }
    return 0 ;
    }
}
            
 


