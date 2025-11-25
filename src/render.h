#pragma once
#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include "utils.h"
#include "table.h"

#define RECT_SIZE 100
static std::string currentBlock = ReadConfig(configPath, "main block");

struct ColorValues {
    uint8_t r, g, b;
};

struct Dimensions {
    int w, h;
};

class Font {
private:
    TTF_Font* font;
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;

public:
    SDL_Renderer *renderer;
    SDL_FRect rect;
    int fontSize;
    std::string text;
    std::string fontPath;
    int xOffset = 0;
    int yOffset = 0;

    Font();

    Font(
        SDL_Renderer *renderer,
        SDL_FRect rect, 
        int fontSize, 
        std::string text, 
        std::string fontPath, 
        int xOffset = 0,
        int yOffset = 0

    ):  fontSize(fontSize), 
        renderer(renderer),
        rect(rect), 
        text(text), 
        fontPath(fontPath), 
        xOffset(xOffset),
        yOffset(yOffset){}
    
    void DrawFont();
    SDL_Texture* GetTexture(){ return textTexture;};

    Dimensions GetTextureDimensions(){ 
        return {textTexture->w, textTexture->h}; 
    };

    ~Font();
};
 
ColorValues GetChemicalGroupColor(ColorGroup category);
void DrawFilledCircle(SDL_Renderer *renderer, int center_x, int center_y, int radius);
void DrawCircleWithBorder(
    SDL_Renderer *renderer,
    int cx, 
    int cy,
    int radius,
    SDL_Color fill_color
);

void DrawBlock(
    SDL_Window *window, 
    SDL_Renderer *renderer, 
    ColorGroup color, 
    i8 atomicNumber,
    float atomicMass,
    const char* symbol, 
    const char* name,
    const char* chemGroup,
    int x, int y,
    int w = RECT_SIZE,
    int h = RECT_SIZE,
    bool main = false
);

void RenderTable(SDL_Window *window, SDL_Renderer *renderer);

SDL_Texture* DrawChemGroupName(
    SDL_Renderer *renderer,
    const char *text,
    SDL_Color text_color,
    int circle_x,
    int circle_y,
    int radius
);

void DrawLegend(
    SDL_Renderer *renderer,
    ColorGroup group,
    const char *text,
    int cx,
    int cy
);

void RenderLegend(SDL_Renderer* renderer);
void Render(SDL_Window* window, SDL_Renderer* renderer);
void RenderMainBlock(SDL_Window *window, SDL_Renderer *renderer);
void MainBlockSelection(SDL_Event event);
