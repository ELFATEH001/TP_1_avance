#pragma once
#include <SDL.h>
#include "Rectangle.h"
#include "Button.h"
#include <vector>
#include "game_types.h"

class UI {
public:
    UI(struct GrillJeu GrillJeu_ins, int DX, int DY)
        : GrillJeu_ins_m(GrillJeu_ins), DX_m(DX), DY_m(DY)
    {
        
        for (int j = 0; j < DX_m ; j++)
        {
            for (int i = 0; i < DY_m; i++)
            {
                
                Button temp_rec{ *this,  SDL_Rect{actual_builder_posx_m, actual_builder_posy_m, Button_size_x_m, Button_size_y_m}, i,j,GrillJeu_ins.matrix.CaseGrille[i][j]};
                button_matrix_m.push_back(temp_rec);
                actual_builder_posy_m += (int)Button_BT_dis_m;
            }
            actual_builder_posx_m += Button_BT_dis_m;
            actual_builder_posy_m = start_point_m[1];
        }
        std::cout << "Matrix is Done ___ Yay" << std::endl;            
    }
    void Render(SDL_Surface* Surface) const {
        /*A.Render(Surface);
        B.Render(Surface);
        C.Render(Surface);*/
        for (auto& rectangle_to_draw : button_matrix_m)
        {
            rectangle_to_draw.Render(Surface);
        }

    }

    void HandleEvent(SDL_Event& E) {
        A.HandleEvent(E);
        B.HandleEvent(E);
        // C.HandleEvent(E);
        for (auto& rectangle_to_draw : button_matrix_m)
        {
            rectangle_to_draw.HandleEvent(E);
        }
    }

    void SetRectangleColors(const SDL_Color& Color, int pos_x, int pos_y) {
        /*A.SetColor(Color);
        B.SetColor(Color);*/
        for (auto& button_to_draw : button_matrix_m)
        {
            if (button_to_draw.id_x_m == pos_x && button_to_draw.id_y_m == pos_y)
                button_to_draw.SetColor(Color);
            else continue;
        }
    }

    

private:
    int DX_m = 0;
    int DY_m = 0;
    struct GrillJeu GrillJeu_ins_m;
    int Button_size_x_m = 20;
    int Button_size_y_m = 20;
    float Button_BT_dis_m = 25; //(float)Button_size_x_m / 2 ;
    std::vector<int> start_point_m{ Button_size_x_m,Button_size_x_m * 4};
    int actual_builder_posx_m = start_point_m[0];
    int actual_builder_posy_m = start_point_m[1];
    float distance_btw_bt;
    Rectangle A{ SDL_Rect{50, 50, 50, 50} };
    Rectangle B{ SDL_Rect{150, 50, 50, 50} };
    //Button    C{ *this,  SDL_Rect{250, 50, 50, 50} , 0,0,0};
    std::vector<Button> button_matrix_m;
}; 
