#pragma once
#pragma once
#include <SDL.h>
#include <iostream>


class Text {
public:
    Text(std::string contained_text)
    : contained_text_m(contained_text)
    {
        font_m = TTF_OpenFont(MY_FONT, 64);
        if (!font_m) {
            printf("Failed to load font: %s\n", TTF_GetError());
            //return EXIT_FAILURE;
        }
        // Create surface with rendered text
        textColor_m = { 0, 0, 0, 255 }; // black color
        textSurface_m = TTF_RenderText_Solid(font_m, contained_text_m.c_str(), textColor_m);
        if (!textSurface_m) {
            printf("Failed to create text surface: %s\n", TTF_GetError());
            //return EXIT_FAILURE;
        }
        // Create texture from surface
        //textTexture_m = SDL_CreateTextureFromSurface(GameWindow.renderer_m, textSurface);
        //if (!textTexture) {
        //    printf("Failed to create text texture: %s\n", SDL_GetError());
        //    //return EXIT_FAILURE;
        //}
        // Render text
        /*SDL_Rect textRect = { 50, 50, textSurface->w, textSurface->h };
        SDL_RenderCopy(GameWindow.renderer_m, textTexture, NULL, &textRect);*/

    }

    /*virtual void OnMouseEnter() {}
    virtual void OnMouseExit() {}
    virtual void OnLeftClick() {}
    virtual void OnRightClick() {}*/

    void Render(SDL_Surface* Surface) const {
        auto [r, g, b, a] {
            isPointerHovering ? Color : Color
            };
        SDL_FillRect(
            Surface, &Rect,
            SDL_MapRGB(Surface->format, r, g, b)
        );
    }

    /*void HandleEvent(SDL_Event& E) {
        if (E.type == SDL_MOUSEMOTION) {
            bool wasPointerHovering{ isPointerHovering };
            isPointerHovering = isWithinRect(
                E.motion.x, E.motion.y
            );
            if (!wasPointerHovering && isPointerHovering) {
                OnMouseEnter();
            }
            else if (
                wasPointerHovering && !isPointerHovering
                ) {
                OnMouseExit();
            }
        }
        else if (
            E.type == SDL_WINDOWEVENT &&
            E.window.event == SDL_WINDOWEVENT_LEAVE
            ) {
            if (isPointerHovering) OnMouseExit();
            isPointerHovering = false;
        }
        else if (E.type == SDL_MOUSEBUTTONDOWN) {
            if (isPointerHovering &&
                E.button.button == SDL_BUTTON_LEFT
                ) {
                std::cout << "A left-click happened "
                    "on me!\n";
                OnLeftClick();
            }
            else if (isPointerHovering &&
                E.button.button == SDL_BUTTON_RIGHT
                ) {
                std::cout << "A right-click happened "
                    "on me!\n";
                OnRightClick();
            }
        }
    }*/

    void SetColor(const SDL_Color& NewColor) {
        Color = NewColor;
    }

    SDL_Color GetColor() const {
        return Color;
    }

    void SetHoverColor(const SDL_Color& NewColor) {
        HoverColor = NewColor;
    }

    SDL_Color GetHoverColor() const {
        return HoverColor;
    }

    bool isPointerHovering{ false };
private:
    SDL_Rect Rect;
    SDL_Color Color{ 255, 0, 0, 255 };
    SDL_Color HoverColor{ 230, 230, 230, 255 };
    std::string contained_text_m = "";
    TTF_Font* font_m;
    SDL_Surface* textSurface_m;
    SDL_Color textColor_m;
    SDL_Texture* textTexture_m;

    bool isWithinRect(int x, int y) {
        if (x < Rect.x) return false;
        if (x > Rect.x + Rect.w) return false;
        if (y < Rect.y) return false;
        if (y > Rect.y + Rect.h) return false;
        return true;
    }
};