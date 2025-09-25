#pragma once
#include <iostream>
#include <stdio.h>
#include <time.h>

struct CaseGrille {   // Structure declaration
    int  mines;           // -1 si mine, 0..8 pour le nombre de mines dans les cases adjacentes
    bool decouverte;      // si cette case a déjà été choisie par l’utilisateur
    int  drapeau;        //  repérer si un drapeau a été posé sur cette case
};

typedef struct {
    CaseGrille CaseGrille[100][100];
} CG_mat;

struct GrillJeu {   // Structure declaration
    int DX;
    int DY;
    int nb_mines;
    CG_mat matrix;
    bool fin_partie;
    int nb_cases_a_decouvrir;
};


