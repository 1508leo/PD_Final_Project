#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
const int SCREEN_WIDTH = 650;
const int SCREEN_HEIGHT = 128;

int choose_menu=0;
void createWindow(const char* title) {
    SDL_Renderer *renderer = NULL;
    TTF_Font *font = NULL;
    SDL_Window* window =  SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("無法創建視窗: %s\n", SDL_GetError());
        return;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    if (TTF_Init() < 0)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return ;
    }
    font = TTF_OpenFont("Yrsa-BoldItalic.ttf", 18);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    SDL_Color textColor = {255, 255, 255, 255};
}

void create_menu_window(const char* title) {

    SDL_Renderer *renderer = NULL;
    TTF_Font *font = NULL;
    SDL_Window* window =  SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("無法創建視窗: %s\n", SDL_GetError());
        return ;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return ;
    }
    if (TTF_Init() < 0)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return ;
    }
    font = TTF_OpenFont("C:/Users/user/anaconda3/Lib/site-packages/matplotlib/mpl-data/fonts/ttf/DejaVuSerif-Bold.ttf", 18);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    SDL_Texture *texture_reader = NULL;
    SDL_Texture *texture_admin = NULL;
    SDL_Texture *texture_exit = NULL;
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *surface_reader = TTF_RenderText_Solid(font, "reader", textColor);
    SDL_Surface *surface_admin = TTF_RenderText_Solid(font, "admin", textColor);
    SDL_Surface *surface_exit = TTF_RenderText_Solid(font, "exit", textColor);
    texture_reader = SDL_CreateTextureFromSurface(renderer, surface_reader); 
    texture_admin = SDL_CreateTextureFromSurface(renderer, surface_admin);
    texture_exit = SDL_CreateTextureFromSurface(renderer, surface_exit);
    SDL_FreeSurface(surface_reader);
    SDL_FreeSurface(surface_admin);
    SDL_FreeSurface(surface_exit);
    SDL_Rect rect_reader; //create rect
    SDL_Rect rect_admin;
    SDL_Rect button_exit;
    rect_reader.x = 50;
    rect_reader.y = 50;
    rect_reader.w = 100;
    rect_reader.h = 50;

    rect_admin.x = 200;
    rect_admin.y = 50;
    rect_admin.w = 100;
    rect_admin.h = 50;

    button_exit.x = 350;
    button_exit.y = 50;
    button_exit.w = 100;
    button_exit.h = 50;

    SDL_Event choose;
    bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&choose)){
            if(choose.type == SDL_MOUSEBUTTONDOWN){
                int x = choose.button.x;
                int y = choose.button.y;
                if (x > rect_reader.x && x < rect_reader.x + rect_reader.w &&
                    y > rect_reader.y && y < rect_reader.y + rect_reader.h){
                        choose_menu=1;
                        quit = true;
                        break;
                    }
                if (x > rect_admin.x && x < rect_admin.x + rect_admin.w &&
                    y > rect_admin.y && y < rect_admin.y + rect_admin.h){
                        choose_menu=2;
                        quit = true;
                        break;
                    }
                if (x > button_exit.x && x < button_exit.x + button_exit.w &&
                    y > button_exit.y && y < button_exit.y + button_exit.h){
                        choose_menu=3;
                        quit = true;
                        break;
                    }
            }
            SDL_RenderCopy(renderer, texture_reader, NULL, &rect_reader);
            SDL_RenderCopy(renderer, texture_admin, NULL, &rect_admin);
            SDL_RenderCopy(renderer, texture_exit, NULL, &button_exit);
            SDL_RenderPresent(renderer);
        }
    }
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture_reader);
    SDL_DestroyTexture(texture_admin);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}   

void create_reader_Window(const char* title) {
    SDL_Renderer *renderer = NULL;
    TTF_Font *font = NULL;
    SDL_Window* window =  SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("無法創建視窗: %s\n", SDL_GetError());
        return ;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return ;
    }
    if (TTF_Init() < 0)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return ;
    }
    font = TTF_OpenFont("C:/Users/user/anaconda3/Lib/site-packages/matplotlib/mpl-data/fonts/ttf/DejaVuSerif-Bold.ttf", 18);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    SDL_Texture *print_hello_world = NULL;
    SDL_Texture *print_mother_fucker = NULL;
    SDL_Texture *exit = NULL;
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *surface_hello = TTF_RenderText_Solid(font, "hello", textColor);
    SDL_Surface *surface_mother = TTF_RenderText_Solid(font, "mother", textColor);
    SDL_Surface *surface_exit = TTF_RenderText_Solid(font, "exit", textColor);
    print_hello_world = SDL_CreateTextureFromSurface(renderer, surface_hello); 
    print_mother_fucker = SDL_CreateTextureFromSurface(renderer, surface_mother);
    exit = SDL_CreateTextureFromSurface(renderer, surface_exit);
    SDL_FreeSurface(surface_hello);
    SDL_FreeSurface(surface_mother);
    SDL_FreeSurface(surface_exit);
    SDL_Rect rect_reader; //create rect
    SDL_Rect rect_admin;
    SDL_Rect button_exit;
    rect_reader.x = 50;
    rect_reader.y = 50;
    rect_reader.w = 100;
    rect_reader.h = 50;

    rect_admin.x = 200;
    rect_admin.y = 50;
    rect_admin.w = 100;
    rect_admin.h = 50;

    button_exit.x = 450;
    button_exit.y = 50;
    button_exit.w = 100;
    button_exit.h = 50;

    SDL_Event choose;
    bool quit=false;
    while(!quit){
        while(SDL_PollEvent(&choose)){
            if(choose.type == SDL_MOUSEBUTTONDOWN){
                int x = choose.button.x;
                int y = choose.button.y;
                if (x > rect_reader.x && x < rect_reader.x + rect_reader.w &&
                    y > rect_reader.y && y < rect_reader.y + rect_reader.h){
                        choose_menu=0;
                        quit = true;
                        printf("mother fucker\n");
                        break;
                    }
                if (x > rect_admin.x && x < rect_admin.x + rect_admin.w &&
                    y > rect_admin.y && y < rect_admin.y + rect_admin.h){
                        choose_menu=0;
                        quit = true;
                        printf("hello world\n");
                        break;
                    }
                if (x > button_exit.x && x < button_exit.x + button_exit.w &&
                    y > button_exit.y && y < button_exit.y + button_exit.h){
                        choose_menu=0;
                        quit = true;
                        break;
                    }
            }
            SDL_RenderCopy(renderer, print_hello_world, NULL, &rect_reader);
            SDL_RenderCopy(renderer, print_mother_fucker, NULL, &rect_admin);
            SDL_RenderCopy(renderer, exit, NULL, &button_exit);
            SDL_RenderPresent(renderer);
            break;
        }
    }
    TTF_CloseFont(font);
    SDL_DestroyTexture(print_hello_world);
    SDL_DestroyTexture(print_mother_fucker);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

SDL_main(int argc, char *argv[]){
    while(choose_menu!=3){
        if(choose_menu == 0) create_menu_window("Menu");
        if(choose_menu == 1) create_reader_Window("Reader");
    }
}