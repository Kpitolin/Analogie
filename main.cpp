//
//  main.cpp
//  LogApacheFinal
//
//  Created by KEVIN on 06/02/2014.
//  Copyright (c) 2014 KEVIN. All rights reserved.
//
#include <iostream>
#include "CreateurFichier.h"
int main(int argc, char * argv[])
{
    CreateurFichier c1 (argc, argv);
    return c1.creeFichier();
}

