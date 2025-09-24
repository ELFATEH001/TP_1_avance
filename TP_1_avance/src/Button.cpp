#pragma once
#include "Button.h"
#include "UI.h"

void Button::OnLeftClick() {
    //UIManager.SetRectangleColors(
    //    { 0, 255, 0, 255 } // Green
    //);
    Slect_Box();
}
void Button::OnRightClick() {
    //UIManager.SetRectangleColors(
    //    { 0, 255, 0, 255 } // Green
    //);
    PutFlag();
}

void Button::Slect_Box()
{
    UIManager.SetRectangleColors(
        { 255, 255, 0, 255 }, // Yellow
        id_x_m,
        id_y_m
    );
}

void Button::PutFlag()
{
    UIManager.SetRectangleColors(
        { 0, 255, 0, 255 }, // Green
        id_x_m,
        id_y_m
    );
}