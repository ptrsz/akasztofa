//
//  kommunikacio.h
//  akasztofa
//
//  Created by Peter Szombathelyi on 2012.11.11..
//  Copyright (c) 2012 Peter Szombathelyi. All rights reserved.
//

#ifndef akasztofa_kommunikacio_h
#define akasztofa_kommunikacio_h

void intro(void) {

    printf("Udvozlom a kedves jatekost az Akasztofa jatekban!\n\n");
    printf("A jatekban meg kell adnia egy betuszamot, es a program ez alapjan kitalal egy szot. \nOnnek ezt kell megfejtenie, a betuszam ketszeresenek megfelelo\nmaximum probalkozassal!.\n");
    
    int i = 0;
    while (i<20) {
        printf("*");
        ++i;
    }
    printf("\n");
}


#endif
