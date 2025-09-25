// Button.h
#pragma once
#include <SDL.h>
#include <iostream>
#include "game_types.h"
#include "Rectangle.h"

class UI;

class Button : public Rectangle {
public:
    Button(UI& UIManager, const SDL_Rect& Rect,int id_x, int id_y, CaseGrille button_CaseGrill)
        : UIManager{ UIManager }, id_x_m(id_x), id_y_m(id_y), button_CaseGrill_m(button_CaseGrill),
        Rectangle{ Rect }
    {
        SetColor({ 200, 200, 200, 255 }); // Orange
    }

    void HandleEvent(SDL_Event& E) {
        // Was the pointer hovering over the button
        // before the event has handled?
        bool wasPointerHovering{ isPointerHovering };

        // Handle the event by deferring to the
        // base implementation
        Rectangle::HandleEvent(E);

        // Has that event changed the
        // isPointerHovering value?
        /*if (!wasPointerHovering && isPointerHovering) {
            std::cout << "Hello mouse\n";
        }*/
    }


    // This doesn't exist, but I wish it did
    void OnMouseEnter() override {
        std::cout << "Hello mouse\n";
        std::cout << "I have here " << button_CaseGrill_m.mines << std::endl;
        std::cout << "I' am the (i: " << id_x_m +1 << " ,j:" << id_y_m +1 <<")"<< std::endl;
    }

    void OnMouseExit() override {
        std::cout << "Goodbye mouse\n";
    }

    void OnLeftClick() override;
    void OnRightClick();
    void Slect_Box();
    void PutFlag();


    int id_x_m = 0;
    int id_y_m = 0;
    // int contained_number_m = 0;
    CaseGrille button_CaseGrill_m;
    

private:
    UI& UIManager;
    //SDL_Text contained_number_tx_m = button_CaseGrill_m.mines;
    
};
