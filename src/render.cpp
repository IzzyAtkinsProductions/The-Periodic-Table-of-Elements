#include "render.h"

int symbolSize = 60;
std::string blockFont = "C:/Users/izzyk/OneDrive/Documents/Code/Personal/C++/Periodic_Table/fonts/Giphurs-Bold.ttf";

inline int AlignAtomicNumber(i8 atomicNumber){
    if(std::to_string(atomicNumber).length()  == 1) return -100;
    else if(std::to_string(atomicNumber).length()  == 2) return -95;
    else if(std::to_string(atomicNumber).length()  == 3) return -90;
}

void Font::DrawFont(){
    font = TTF_OpenFont(blockFont.c_str(), fontSize);

    if (!font) {
        printf("Failed to load font: %s\n", SDL_GetError());
        // font = TTF_OpenFont("assets/Roboto-Regular.ttf", 64); // fallback if you bundle one
    }

    SDL_Color white = {255, 255, 255, 255};  
    textSurface = TTF_RenderText_Blended(font, text.c_str(), strlen(text.c_str()), white);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    int text_w = textSurface->w;
    int text_h = textSurface->h;
    SDL_DestroySurface(textSurface); 

    // Draw text centered on the rectangle
    SDL_FRect textRect = {
        rect.x + (rect.w - text_w) / 2 + xOffset,
        rect.y + (rect.h - text_h) / 2 + yOffset,
        (float)text_w,
        (float)text_h
    };

    SDL_RenderTexture(renderer, textTexture, NULL, &textRect);
}

Font::~Font(){
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
}

ColorValues GetChemicalGroupColor(ColorGroup category){
    uint8_t r, g, b;

    switch(category){ 
        case ALKALI_METAL: {
            r = 0;
            g = 71;
            b = 89;
            break;
        }

        case ALKALINE_EARTH_METAL: {
            r = 82;
            g = 2;
            b = 2;
            break;
        }

        case REACTIVE_NON_METAL: {
            r = 2;
            g = 86;
            b = 181;
            break;
        }
        
        case TRANSITION_METAL: {
            r = 39;
            g = 42;
            b = 46;
            break;
        }
        
        case POST_TRANSITION_METAL: {
            r = 0;
            g = 46;
            b = 9;
            break;
        }
        
        case METALLOID: {
            r = 123;
            g = 4;
            b = 65;
            break;
        }
        
        case ACTINIDE: {
            r = 55;
            g = 41;
            b = 74;
            break;
        }
        
        case LANTHANIDE: {
            r = 51;
            g = 23;
            b = 1;
            break;
        }
        
        case NOBLE_GAS: {
            r = 80;
            g = 8;
            b = 135;
            break;
        }
    
        case UNKNOWN_PROPERTY: {
            r = 0;
            g = 0;
            b = 0;
            break;
        }
        default:
            break;
    }
    return {r, g, b};
} 


void DrawFilledCircle(SDL_Renderer *renderer, int cx, int cy, int radius){
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        SDL_RenderLine(renderer, cx - x, cy + y, cx + x, cy + y);
        SDL_RenderLine(renderer, cx - x, cy - y, cx + x, cy - y);
        SDL_RenderLine(renderer, cx - y, cy + x, cx + y, cy + x);
        SDL_RenderLine(renderer, cx - y, cy - x, cx + y, cy - x);

        y += 1;
        err += 1 + 2*y;
        if (2*(err - x) + 1 > 0) {
            x -= 1;
            err += 1 - 2*x;
        }
    }
}

void DrawCircleWithBorder(
    SDL_Renderer *renderer,
    int cx, 
    int cy,
    int radius,
    SDL_Color fill_color
){  
    int border_width = 2;

    // Draw the filled circle first (acts as background)
    if (fill_color.a > 0) {
        SDL_SetRenderDrawColor(renderer,
            fill_color.r, fill_color.g, fill_color.b, fill_color.a);

        int x = radius;
        int y = 0;
        int err = 0;

        while (x >= y) {
            // Fill horizontal lines in all 8 octants
            SDL_RenderLine(renderer, cx - x, cy + y, cx + x, cy + y);
            SDL_RenderLine(renderer, cx - x, cy - y, cx + x, cy - y);
            SDL_RenderLine(renderer, cx - y, cy + x, cx + y, cy + x);
            SDL_RenderLine(renderer, cx - y, cy - x, cx + y, cy - x);

            y += 1;
            err += 1 + 2*y;
            if (2*(err - x) + 1 > 0) {
                x -= 1;
                err += 1 - 2*x;
            }
        }
    }

    // Draw the border by drawing multiple concentric circles
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int t = 0; t < border_width; t++) {
        int r = radius - t;
        if (r < 0) break;

        int x = r;
        int y = 0;
        int err = 0;

        while (x >= y) {
            SDL_RenderPoint(renderer, cx + x, cy + y);
            SDL_RenderPoint(renderer, cx + y, cy + x);
            SDL_RenderPoint(renderer, cx - y, cy + x);
            SDL_RenderPoint(renderer, cx - x, cy + y);
            SDL_RenderPoint(renderer, cx - x, cy - y);
            SDL_RenderPoint(renderer, cx - y, cy - x);
            SDL_RenderPoint(renderer, cx + y, cy - x);
            SDL_RenderPoint(renderer, cx + x, cy - y);

            y += 1;
            err += 1 + 2*y;
            if (2*(err - x) + 1 > 0) {
                x -= 1;
                err += 1 - 2*x;
            }
        }
    }
}

void DrawBlock(
    SDL_Window *window, 
    SDL_Renderer *renderer, 
    ColorGroup color, 
    i8 atomicNumber,
    float atomicMass,
    const char* symbol,
    const char* name,
    const char* chemGroup,
    int x, int y, int w, int h,
    bool main
){
    int win_w, win_h;
    SDL_GetWindowSizeInPixels(window, &win_w, &win_h);
    ColorValues value = GetChemicalGroupColor(color);
   
    SDL_FRect rect;
    float padding = 60;
    // rect.w = text_w + padding * 2;
    // rect.h = text_h + padding * 1.5f;
    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;
    
    SDL_SetRenderDrawColor(renderer, value.r, value.g, value.b, 1);
    if (!SDL_RenderFillRect(renderer, &rect)) {  // SDL3: Returns bool, check for success
        printf("Render fill failed: %s\n", SDL_GetError());
    }

    // Border (outline)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    if (!SDL_RenderRect(renderer, &rect)) {
        printf("Render draw failed: %s\n", SDL_GetError());
    }

    Font(renderer, rect, 60, symbol, blockFont).DrawFont();

    if(main == true){
        Font(renderer, rect, 20, name, blockFont, 0, 50).DrawFont();
        Font(renderer, rect, 20, chemGroup, blockFont, 0, 75).DrawFont();
        Font(renderer, rect, 30, std::to_string(atomicNumber).c_str(), blockFont, AlignAtomicNumber(atomicNumber), -100).DrawFont();
        Font(renderer, rect, 20, std::to_string(atomicMass).c_str(), blockFont, 50, -100).DrawFont();
    }
}

SDL_Texture* DrawChemGroupName(
    SDL_Renderer *renderer,
    const char *text,
    int cx,
    int cy,
    int radius,
    int gap
){
    if (!text || strlen(text) == 0) return NULL;

    TTF_Font *font = TTF_OpenFont("C:/Users/izzyk/OneDrive/Documents/Fonts/Lateef.ttf", 60);

    if (!font) {
        printf("Failed to load font: %s\n", SDL_GetError());
        // font = TTF_OpenFont("assets/Roboto-Regular.ttf", 64); // fallback if you bundle one
    }
    // Render text to surface
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text, strlen(text), {255, 255, 255, 255});
    if (!textSurface) {
        SDL_Log("TTF_RenderText_Blended failed: %s", SDL_GetError());
        return NULL;
    }

    // Convert to texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_DestroySurface(textSurface);
    if (!texture) {
        SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        return NULL;
    }

    // SDL3: Direct access to width/height (texture->w and texture->h are public)
    int w = texture->w;
    int h = texture->h;

    // Destination rectangle: right of circle + gap, vertically centered
    SDL_FRect dst = {
        (float)(cx + radius + gap),
        (float)(cy - h / 2),
        (float)w,
        (float)h
    };

    // Actually draw it
    SDL_RenderTexture(renderer, texture, NULL, &dst);

    return texture;
}


void DrawLegend(
    SDL_Renderer *renderer,
    ColorGroup group,
    const char *text,
    int cx,
    int cy
){
    int radius = 20;
    ColorValues value = GetChemicalGroupColor(group);
    DrawCircleWithBorder(renderer, cx, cy, radius, {value.r, value.g, value.b, 255});
    DrawChemGroupName(renderer, text, cx, cy, radius, 25);
}


void RenderLegend(SDL_Renderer* renderer){
    DrawLegend(renderer, ALKALI_METAL, "Alkali Metal", 300, 50);
    DrawLegend(renderer, ALKALINE_EARTH_METAL, "Alkaline Earth Metal", 300, 100);
    DrawLegend(renderer, TRANSITION_METAL, "Transition Metal", 300, 150);
    DrawLegend(renderer, REACTIVE_NON_METAL, "Reactive Non Metal", 300, 200);
    DrawLegend(renderer, POST_TRANSITION_METAL, "Post-Transition Metal", 300, 250);

    DrawLegend(renderer, ACTINIDE, "Actinide", 900, 50);
    DrawLegend(renderer, METALLOID, "Metalloid", 900, 100);
    DrawLegend(renderer, NOBLE_GAS, "Noble Gas", 900, 150);
    DrawLegend(renderer, LANTHANIDE, "Lanthanide", 900, 200);
    DrawLegend(renderer, UNKNOWN_PROPERTY, "Unknown Property", 900, 250);
}

void RenderTable(SDL_Window *window, SDL_Renderer *renderer){
    for(int i = 0; i < ARRAY_SIZE(elements); i++){
        DrawBlock(
            window,
            renderer,   
            elements[i].color,
            elements[i].atomicNumber,
            elements[i].atomicMass,
            elements[i].symbol.c_str(),
            elements[i].name.c_str(),
            elements[i].chemicalGroupBlock.c_str(),
            elements[i].xPos, 
            elements[i].yPos
        ); 
    }
}

void RenderMainBlock(SDL_Window *window, SDL_Renderer *renderer){
    std::string query = ReadConfig(configPath, "main block");

    for(int i = 0; i < ARRAY_SIZE(elements); i++){
        if(query == elements[i].symbol || query == elements[i].name || query == std::to_string(elements[i].atomicNumber)){
            DrawBlock(
                window,
                renderer,   
                elements[i].color,
                elements[i].atomicNumber,
                elements[i].atomicMass,
                elements[i].symbol.c_str(),    
                elements[i].name.c_str(),
                elements[i].chemicalGroupBlock.c_str(),
                50, 
                730,
                250,
                250,
                true
            ); 
        }
    }
}

void MainBlockSelection(SDL_Event event){
    std::string symbol;
    float mouse_x = event.motion.x;
    float mouse_y = event.motion.y;

    for(int i = 0; i < ARRAY_SIZE(elements); i++){
        float mouseX = event.button.x;
        float mouseY = event.button.y;
        if (
            mouseX >= elements[i].xPos && mouseX <= elements[i].xPos + RECT_SIZE &&
            mouseY >= elements[i].yPos && mouseY <= elements[i].yPos + RECT_SIZE 
        ){
            symbol = elements[i].symbol;
            system("cls");
            Filter(symbol);
            UpdateConfig(configPath, "main block", symbol);
        }
    }

    std::cout << "\n\n\n\n\n\n";
    PeriodicTable* block = GetBlockObject(symbol);
    block->DrawAsciiBlock();
}

void Render(SDL_Window* window, SDL_Renderer* renderer){
    RenderLegend(renderer);
    RenderTable(window, renderer);
    RenderMainBlock(window, renderer);
}
