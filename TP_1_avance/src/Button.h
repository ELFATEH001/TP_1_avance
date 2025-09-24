// Button.h
#pragma once
#include <SDL.h>
#include <iostream>
#include "Rectangle.h"

class UI;

class Button : public Rectangle {
public:
    Button(UI& UIManager, const SDL_Rect& Rect)
        : UIManager{ UIManager },
        Rectangle{ Rect }
    {
        SetColor({ 255, 165, 0, 255 }); // Orange
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
    }

    void OnMouseExit() override {
        std::cout << "Goodbye mouse\n";
    }

    void OnLeftClick() override;

private:
    UI& UIManager;
};
