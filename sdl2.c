#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
const int SCREEN_WIDTH = 340;
const int SCREEN_HEIGHT = 128;

int main(int argc, char *args[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    TTF_Font *font = NULL;
    SDL_Texture *texture_reader = NULL;
    SDL_Texture *texture_admin = NULL;
    SDL_Rect rect_reader;
    SDL_Rect rect_admin;
    SDL_Rect button_1;
    int window_status = 1;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() < 0)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Button Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    font = TTF_OpenFont("/usr/share/fonts/truetype/fonts-yrsa-rasa/Yrsa-BoldItalic.ttf", 18);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *surface_reader = TTF_RenderText_Solid(font, "reader", textColor);
    SDL_Surface *surface_admin = TTF_RenderText_Solid(font, "admin", textColor);

    texture_reader = SDL_CreateTextureFromSurface(renderer, surface_reader);
    texture_admin = SDL_CreateTextureFromSurface(renderer, surface_admin);
    SDL_FreeSurface(surface_reader);
    SDL_FreeSurface(surface_admin);
    
    rect_reader.x = 50;
    rect_reader.y = 50;
    rect_reader.w = 100;
    rect_reader.h = 50;

    rect_admin.x = 200;
    rect_admin.y = 50;
    rect_admin.w = 100;
    rect_admin.h = 50;

    SDL_Event e;
    bool quit = false;
    int quit_reader = 0;
    int quit_admin = 0;
    while (!quit)
    {   
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = e.button.x;
                int y = e.button.y;
                if (x > rect_reader.x && x < rect_reader.x + rect_reader.w &&
                    y > rect_reader.y && y < rect_reader.y + rect_reader.h)
                {
                    // reader is clicked, create reader window
                    SDL_Window *reader_window = SDL_CreateWindow("Reader Window", SDL_WINDOWPOS_CENTERED,
                                                                 SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
                    SDL_Renderer *reader_renderer = SDL_CreateRenderer(reader_window, -1, 0);
                    SDL_SetRenderDrawColor(reader_renderer, 255, 255, 255, 255);
                    SDL_RenderClear(reader_renderer);
                    SDL_RenderPresent(reader_renderer);
                    while (!quit_reader)
                    {
                        SDL_Event reader_event;
                        while (SDL_PollEvent(&reader_event))
                        {
                            if (reader_event.type == SDL_QUIT)
                            {
                                quit_reader = 1;
                            }
                        }
                    }
                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(reader_renderer);
                    SDL_DestroyWindow(reader_window);
                }
                if (x > rect_admin.x && x < rect_admin.x + rect_admin.w &&
                    y > rect_admin.y && y < rect_admin.y + rect_admin.h)
                {
                    // admin is clicked, create adminstor window
                    SDL_Window *admin_window = SDL_CreateWindow("Admin Window", SDL_WINDOWPOS_CENTERED,
                                                                SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
                    SDL_Renderer *admin_renderer = SDL_CreateRenderer(admin_window, -1, 0);
                    SDL_SetRenderDrawColor(admin_renderer, 255, 255, 255, 255);
                    SDL_RenderClear(admin_renderer);
                    SDL_RenderPresent(admin_renderer);
                    SDL_Surface *surface_exit = TTF_RenderText_Solid(font, "EXIT", textColor);
                    SDL_FreeSurface(surface_exit);
                    while (!quit_admin)
                    {
                        SDL_DestroyWindow(window);
                        SDL_Event admin_event;
                        switch (admin_event.type) {
                        case SDL_QUIT:
                            quit = true;
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (admin_event.button.button == SDL_BUTTON_LEFT) {
                                int x_admin = admin_event.button.x;
                                int y_admin = admin_event.button.y;
                                    button_1.x = 200;
                                    button_1.y = 50;
                                    button_1.w = 100;
                                    button_1.h = 50;
                                if (x_admin > button_1.x && x_admin < button_1.x + button_1.w &&
                                    y_admin > rect_admin.y && y_admin < button_1.y + button_1.h){
                                        quit_admin=1;
                                        break;
                                    }
                            }
                            break;
                        default:
                            break;
                        }
                    }
                    SDL_DestroyRenderer(admin_renderer);
                    SDL_DestroyWindow(admin_window);
                }
            }
        }
        SDL_RenderCopy(renderer, texture_reader, NULL, &rect_reader);
        SDL_RenderCopy(renderer, texture_admin, NULL, &rect_admin);
        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyTexture(texture_reader);
    SDL_DestroyTexture(texture_admin);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
