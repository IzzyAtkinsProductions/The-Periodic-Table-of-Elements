#pragma once
#include "render.h"

int PeriodicTableOfElements() {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  // Create resizable window (no fullscreen flag in SDL3)
  SDL_Window *window = SDL_CreateWindow("Periodic Tablee of Elements", 1920, 1080, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  SDL_Surface* surface;

  if (!window) {
    printf("Window creation failed: %s\n", SDL_GetError());
    return 1;
  }
  // Maximize for "fullscreen desktop" effect (borderless, taskbar visible,
  // resizable)
  SDL_MaximizeWindow(window);
  
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    printf("Renderer creation failed: %s\n", SDL_GetError());
    return 1;
  }

  
  bool running = true;
  SDL_Event event;
  
  while (running) {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT: {
                running = false;
                break;
            }

            case SDL_EVENT_MOUSE_BUTTON_DOWN: {
                MainBlockSelection(event);
                break;
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 10, 5, 36, 255); // Background
    SDL_RenderClear(renderer);

    Render(window, renderer);

    SDL_RenderPresent(renderer);
    // SDL_Delay(16); // ~60 FPS
  }
  
  // surface = SDL_GetWindowSurface(window);
  // SDL_UpdateWindowSurface(window);
  //   if (IMG_SaveJPG(surface, "C:/Users/izzyk/OneDrive/Desktop/table.jpg", 90) < 0) {
  //       SDL_Log("Failed to save JPEG: %s", SDL_GetError());
  //   } else {
  //       SDL_Log("Saved screenshot.jpg successfully!");
  //   }
  
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  TTF_Quit();
  SDL_Quit();
}
