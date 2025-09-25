#include "game_types.h"
#include <SDL.h>
#include "Window.h"
#include "UI.h"
#include <stdio.h>
#include <SDL_ttf.h>
#undef main

#define MY_FONT "F:/M1_A&R/Base_INFO/TP/TP_1_avance/TP_1_avance/fonts/BBC.ttf"


//int * fillMatrix(int DIMWX, int DIMWY );

struct GrillJeu Init_jeu(int DIMWX, int DIMWY)
{
    struct GrillJeu GrilleJeu_fun;
    //int min = -1;
    int max = 8;
    int valeur_initial_case = 0;

    //int** matrixIN = new int*[DIMWX] ;


    GrilleJeu_fun.DX = DIMWX;
    GrilleJeu_fun.DY = DIMWY;
    // printf("GrilleJeu_fun DX ::", GrilleJeu_fun.DX);
    std::cout << "matrix DIM" << std::endl;
    std::cout << "DM_X est " << GrilleJeu_fun.DX;
    std::cout << " DM_Y est " << GrilleJeu_fun.DY << std::endl;
    //std::cout << "Enter function ----------" <<  std::endl ;

    std::cout << std::endl;

    int** arr = new int* [GrilleJeu_fun.DX];
    //CG_mat Temp_CaseGrille = GrilleJeu_fun.matrix.CaseGrille;
    for (int i = 0; i < GrilleJeu_fun.DX; ++i) {
        //GrilleJeu_fun.matrix.CaseGrille[i] = new int[DIMWX];
        arr[i] = new int[GrilleJeu_fun.DY];

        for (int j = 0; j < GrilleJeu_fun.DY; ++j) {
            //int rd_num = rand() % (max - min + 1) + min;
            //int result = rd_num;   // result     == 1.005592
            //matrixIN[i][j] = result;
            //std::cout << "  " << 0 ;
            //GrilleJeu_fun.matrix.CaseGrille[i][j] = valeur_initial_case;
            //arr[i][j] = 0;
            GrilleJeu_fun.matrix.CaseGrille[i][j].mines = 0;
            GrilleJeu_fun.matrix.CaseGrille[i][j].decouverte = false;

            //std::cout << GrilleJeu_fun.matrix.CaseGrille[i][j] ;
            //std::cout << arr[i][j] << "  " ;
        }
        //std::cout  <<  std::endl ;

    }

    return GrilleJeu_fun;

}

struct GrillJeu pos_bombes(struct GrillJeu GrillJeu_element, int Max_bombes)
{
    //struct GrillJeu GrillJeu_element;
    int min_x = 0;
    int max_x = GrillJeu_element.DX;
    int min_y = 0;
    int max_y = GrillJeu_element.DY;
    int valeur_initial_case = 0;


    for (int AN_bombe = 0; AN_bombe < Max_bombes; AN_bombe++) {
        //GrilleJeu_fun.matrix.CaseGrille[i] = new int[DIMWX];
        //arr[i] = new int[GrillJeu_element.DX];
        int i;
        int j;
        int rd_num1 = rand() % (max_x - min_x + 1) + min_x;
        int rd_num2 = rand() % (max_y - min_y + 1) + min_y;
        i = rd_num1;   // result     == 1.005592
        j = rd_num2;   // result     == 1.005592

        if (GrillJeu_element.matrix.CaseGrille[i][j].mines != -1) {
            GrillJeu_element.matrix.CaseGrille[i][j].mines = -1;
        }
        AN_bombe++;
    }

    return GrillJeu_element;

}

int bombes_counter_NC(struct GrillJeu GrillJeu_element, int special_pos_type, int i, int j) {
    int counter = 0;


    // special_pos_type = special positon type
    // we have:
    // 1 : simple : anywhere exclude i=0, j = 0, i = DimX, j = DimY
    // 2 : edge   : else

    struct GrillJeu GrilleJeu_fun = GrillJeu_element;


    if (special_pos_type == 0)
    {
        // GrillJeu_element.matrix.CaseGrille[i][j].mines = 9;
        if (i == 0 && j == 0)
        {
            for (int i_c = 0; i_c <= 1; i_c++)
            {
                for (int j_c = 0; j_c <= 1; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }
        else if (i == GrillJeu_element.DX - 1 && j == GrillJeu_element.DY - 1)
        {
            for (int i_c = -1; i_c <= 0; i_c++)
            {
                for (int j_c = -1; j_c <= 0; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }
        else if (i == GrillJeu_element.DX - 1 && j == 0)
        {
            for (int i_c = -1; i_c <= 0; i_c++)
            {
                for (int j_c = 0; j_c <= 1; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }
        else if (i == 0 && j == GrillJeu_element.DY - 1)
        {
            for (int i_c = 0; i_c <= 1; i_c++)
            {
                for (int j_c = -1; j_c <= 0; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }

        else {
            counter = 9;
        }


    }
    else if (special_pos_type == 1)
    {
        if (i == 0)
        {
            for (int i_c = 0; i_c <= 1; i_c++)
            {
                for (int j_c = -1; j_c <= 1; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }
        else if (i == GrillJeu_element.DX - 1)
        {
            for (int i_c = -1; i_c <= 0; i_c++)
            {
                for (int j_c = -1; j_c <= 1; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }
        else if (j == 0)
        {
            for (int i_c = -1; i_c <= 1; i_c++)
            {
                for (int j_c = 0; j_c <= 1; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }
        else if (j == GrillJeu_element.DY - 1)
        {
            for (int i_c = -1; i_c <= 1; i_c++)
            {
                for (int j_c = -1; j_c <= 0; j_c++)
                {
                    if (i_c == 0 && j_c == 0)
                    {
                        continue;
                    }
                    else {

                        if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                        {
                            counter++;
                        }

                    }
                }

            }
        }

        else {
            counter = 9;
        }
    }
    else {
        for (int i_c = -1; i_c <= 1; i_c++)
        {
            for (int j_c = -1; j_c <= 1; j_c++)
            {
                if (i_c == 0 && j_c == 0)
                {
                    continue;
                }
                else {
                    //int i_in = i+i_c;
                    //int j_in = j+j_c;
                    if (GrilleJeu_fun.matrix.CaseGrille[i + i_c][j + j_c].mines == -1)
                    {
                        counter++;
                    }

                }
            }

        }
    }
    return counter;

}

struct GrillJeu Remplissage(struct GrillJeu GrillJeu_element)
{


    //CG_mat Temp_CaseGrille = GrilleJeu_fun.matrix.CaseGrille;
    for (int i = 0; i < GrillJeu_element.DX; ++i) {

        for (int j = 0; j < GrillJeu_element.DY; ++j) {
            if (GrillJeu_element.matrix.CaseGrille[i][j].mines != -1) {
                if (i == 0 || j == 0 || i == GrillJeu_element.DX - 1 || j == GrillJeu_element.DY - 1) {
                    // GrillJeu_element.matrix.CaseGrille[i][j].mines = 9;
                    if (i == 0 && j == 0 || i == GrillJeu_element.DX - 1 && j == GrillJeu_element.DY - 1 || i == GrillJeu_element.DX - 1 && j == 0 || i == 0 && j == GrillJeu_element.DY - 1) {
                        GrillJeu_element.matrix.CaseGrille[i][j].mines = bombes_counter_NC(GrillJeu_element, 0, i, j); // type 0  : corner
                    }
                    else
                    {
                        GrillJeu_element.matrix.CaseGrille[i][j].mines = bombes_counter_NC(GrillJeu_element, 1, i, j); // type 1  : edge
                    }
                }
                else {

                    GrillJeu_element.matrix.CaseGrille[i][j].mines = bombes_counter_NC(GrillJeu_element, 2, i, j);     // type 2  : else
                }
            }
            else {
                continue;
                //GrillJeu_element.matrix.CaseGrille[i][j].mines= -1;
            }

        }
        //std::cout  <<  std::endl ;

    }

    return GrillJeu_element;

}


int main(int argc, char** argv)
{
    // Game matrix dimension
    int DIMWX = 10;
    int DIMWY = 10;
    int Max_bombes = 20;

    // setting the srand for different games
    srand(time(NULL));

    //std::cout <<"DM_X est " << DIMWX << " DM_Y est " << DIMWY  <<  std::endl ;
    struct GrillJeu matrix_result;
    matrix_result = Init_jeu(DIMWX, DIMWY);
    matrix_result = pos_bombes(matrix_result, Max_bombes);
    matrix_result = Remplissage(matrix_result);
    // std::cout <<"my_game DX est " << my_game.DX << " my_game DY est " << my_game.DY  <<  std::endl ;

    //my_game.matrix = matrix_result;

    for (int i = 0; i < DIMWX; i++) {
        //std::cout << "new line" ;
        for (int j = 0; j < DIMWY; j++) {
            if (matrix_result.matrix.CaseGrille[i][j].mines == -1)
                std::cout << matrix_result.matrix.CaseGrille[i][j].mines << "  ";
            //std::cout << "(" << matrix_result.matrix.CaseGrille[i][j].decouverte ;
            else {
                std::cout << " " << matrix_result.matrix.CaseGrille[i][j].mines << "  ";
            }
        }

        std::cout << std::endl;
    }

    // SDL setup
    SDL_Init(SDL_INIT_VIDEO);
    // Initialize SDL_ttf
    if (TTF_Init() < 0) {
        printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    TTF_Font* font = TTF_OpenFont(MY_FONT, 64); // specify the path to your font file and font size
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    


    Window GameWindow;
    UI UIManager(matrix_result, DIMWX, DIMWY);
    
    //SDL_Renderer* renderer = SDL_CreateRenderer(GameWindow, -1, 0);
    // Create surface with rendered text
    SDL_Color textColor = { 0, 0, 0, 255 }; // black color
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Hello World!", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(GameWindow.renderer_m, textSurface);
    // Render text
    SDL_Rect textRect = { 50, 50, textSurface->w, textSurface->h }; // rectangle where the text is drawn 
    SDL_RenderCopy(GameWindow.renderer_m, textTexture, NULL, &textRect);
    
    
    SDL_Event E;

    // the main game loop
    while (true) {
        while (SDL_PollEvent(&E)) {
            UIManager.HandleEvent(E);
            if (E.type == SDL_QUIT) {
                SDL_Quit();
                return 0;
            }
        }

        GameWindow.Render();
        SDL_RenderPresent(GameWindow.renderer_m);
        UIManager.Render(GameWindow.GetSurface());
        GameWindow.Update();
    }

    return 0;
}

