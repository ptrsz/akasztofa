#include <stdio.h>
#include <string.h>
#include <time.h>
#include "kommunikacio.h"
#include "szokezeles.h"
#include "beolvasas.h"



int main()
{
    intro();
    
    
    /*bekerem a betuszamot*/
    int betuszam;
    printf("Betuszam: ");
    scanf("%d",&betuszam);
    /*beszoritjuk a jatekost a kezelheto meretek koze*/
    
    while( (betuszam < 1) ||  (betuszam >= 25)){
        printf("Betuszam:");
        scanf("%d",&betuszam);
    }
    
    printf("A kivalasztott betuszam: %d \n",betuszam);
    
    //lista elokeszitese, hogy felfuzhessem a szavakat
    szolista *eleje = NULL;
    //puffer sztring, a fajlbol beolvasasnal hasznalom
    char puff[25];/*maximum 25 karakteres szavakat kezelek*/
    //fajl beolvasas
    FILE *fp;
    fp = fopen("szotar.txt","rt"); /*létrehoztam magamnak egy txt-t */
    
    while (fscanf(fp, "%s",puff) != EOF) {
        if (strlen(puff) == betuszam) {
            hozzafuz(eleje,puff);
            /*if (eleje == NULL) {
                printf("Sajnos hiba lepett fel. A program kilep. (szobeolvasasi hiba)");
                return 1;
            }*/
        }
        
    }
    /*ha nincs megfelelo szo lepj ki*/
    if ( eleje ==NULL ) printf("Sajnos nincs megfelelo szo az adatbazisban."); return 2;
    
    /*elokeszuletek*/
   
    /*kezdeti vonalkirajzolas*/
    kezdet(betuszam);
    int korlat = 0;
    char tipp[2];        // azert kell string a tippnek, mert az strcat,strstr fuggveny igy tudja kezelni
    
    /*generaljunk egy veletlen szot*/
    char *rszo = veletlen(eleje, hanyszovan);
    
    //szabaditsuk fel a listat
    szabadit(eleje); /*kitoroltuk a listat, de nem gond mer mar nincis ra szukseg, csak a szora*/
    
    /*lekorlatozzuk a probalkozast*/
    /* a jatek indul*/
    char voltak[betuszam*2];
    while (korlat != betuszam*2) {
        printf("\nTipp:");

        while (beker(tipp)) {
            printf("Betut kerek! Betu:");
        }
        while (strstr(tipp, voltak)!= NULL) { 
            printf("Ez a betu mar volt!\nTipp:");
            scanf("%c",&tipp[0]);
            tipp[1]='\0';
            
        }
        strcat(voltak, tipp);
        rajz(rszo,voltak);
        if (kitalalta(rszo,voltak)) {
            break;
        }
        

        
        ++korlat;
        
            
            
    }
    
    if(kitalalta(rszo, voltak))printf("\nGratulalok, on Nyert!Koszonom a jatekot!");
    else printf("\nSajnalom, ezt elbuktad.\nA program leall.");
        
    return 0;
}

