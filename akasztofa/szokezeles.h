//
//  szokezeles.h
//  akasztofa
//
//  Created by Peter Szombathelyi on 2012.11.11..
//  Copyright (c) 2012 Peter Szombathelyi. All rights reserved.
//

#ifndef akasztofa_szokezeles_h
#define akasztofa_szokezeles_h

/*szokezelo fuggvenyek*/
// a voltmar fuggvenyt a strstr beepitett fuggvennyel helyettesitettem!
int voltmar(char mi,char *miben){
    int i;
    for (i=0; i<strlen(miben); i++) {
        if (mi == miben[i]) {
            return 1;
        }
    }
    return 0;
}

int kitalalta(char *szo,char *voltak){
    int i;
    for (i = 0; szo[i]; ++i) {
        if(strchr(voltak, szo[i]) == NULL) return 0;
    }
    return 1;


}


/*minden tipp utan az eddigi allapotok szerint ujrarajzolja a palyat*/
void rajz(char *szo,char *voltak){
    int i;
    for (i=0; szo[i] != '\0'; ++i) {
        if (strchr(voltak, szo[i]) == NULL) {
            printf("_ ");
        }
        else printf("%c",szo[i]);
    }

}

/*kezdeti vonalkiiras*/
void kezdet(int betuszam){
    int i;
    for (i=0; i<betuszam; i++) {
        printf("_ ");
    }
    printf("\n");
}

/*Tipp bekerese*/
int beker(char tipp[2]){
    char c;
    c = getchar();
    while (c == '\n') c = getchar();
    if ( ((tolower(c)) > 122 ) || (tolower(c) < 97)){
        return 1;
    }
    tipp[0] = c;
    tipp[1] = '\0';
    return 0;
}



#endif
