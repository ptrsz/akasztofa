//
//  beolvasas.h
//  akasztofa
//
//  Created by Peter Szombathelyi on 2012.11.11..
//  Copyright (c) 2012 Peter Szombathelyi. All rights reserved.
//

#ifndef akasztofa_beolvasas_h
#define akasztofa_beolvasas_h

/*lancolt lista megoldas*/

/*lista definialasa*/
typedef struct szolista {
    char *szo;
    struct szolista *kov;
    
} szolista;

/*hozzafuzo fuggveny*/
int hanyszovan = 0; //globalis valtozo a lista elemszamanak tarolasara

szolista *hozzafuz(szolista *eleje,char *mit){
    szolista *mozgo, *uj;
    ++hanyszovan;
    uj=(szolista*) malloc(sizeof(szolista));
    uj->szo=(char *) malloc(strlen(mit)*sizeof(char)); 
    strcpy(uj->szo,mit);
    uj->kov=NULL;
    
    if (eleje==NULL)     
        return uj;
    
    for (mozgo=eleje; mozgo->kov!=NULL; mozgo=mozgo->kov)
        ; //mozgas
    mozgo->kov=uj;
    
    return eleje;
    
}

/*veletlen szo valasztasa*/
char *veletlen(szolista *eleje,int db){
    srand ( time(NULL) );
    int i,hanyadik = rand()%db + 1;
    szolista *mozgo = eleje;
    char *randomszo;
    i=0;
    while (i != hanyadik) {
        randomszo = mozgo->szo;
        mozgo = mozgo->kov;
        ++i;
    }
    return randomszo;
    
}

/*felszabaditas*/
void szabadit(szolista *eleje){
    while (eleje!=NULL) {
        szolista *temp=eleje->kov;
        free(eleje);
        free(eleje->szo);
        eleje=temp;
    }
}

#endif
