#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "total.h"
const int SCREEN_WIDTH = 650;
const int SCREEN_HEIGHT = 128; // width height

int choose_menu=0;
int choose_admin=0;
int choose_reader = 0;

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
    font = TTF_OpenFont("C:/Windows/WinSxS/amd64_microsoft-windows-font-truetype-cambria_31bf3856ad364e35_10.0.18362.1_none_c4ff0ed18149069c/cambriai.ttf", 18);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    SDL_Texture *texture_reader = NULL;
    SDL_Texture *texture_admin = NULL;
    SDL_Texture *texture_exit = NULL;
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *surface_reader = TTF_RenderText_Solid(font, "Reader", textColor);
    SDL_Surface *surface_admin = TTF_RenderText_Solid(font, "Admin", textColor);
    SDL_Surface *surface_exit = TTF_RenderText_Solid(font, "Exit", textColor);
    texture_reader = SDL_CreateTextureFromSurface(renderer, surface_reader); 
    texture_admin = SDL_CreateTextureFromSurface(renderer, surface_admin);
    texture_exit = SDL_CreateTextureFromSurface(renderer, surface_exit);
    SDL_FreeSurface(surface_reader);
    SDL_FreeSurface(surface_admin);
    SDL_FreeSurface(surface_exit);
    SDL_Rect rect_reader; //create rect
    SDL_Rect rect_admin;
    SDL_Rect button_exit;
    rect_reader.x = 30;
    rect_reader.y = 50;
    rect_reader.w = 150;
    rect_reader.h = 70;

    rect_admin.x = 200;
    rect_admin.y = 50;
    rect_admin.w = 130;
    rect_admin.h = 70;

    button_exit.x = 380;
    button_exit.y = 50;
    button_exit.w = 120;
    button_exit.h = 70;

    SDL_Event choose;
    bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&choose)){
            if (choose.type == SDL_QUIT) {
                choose_menu = -1;
                quit = true;
                break; 
            }
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
    SDL_Window* window =  SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
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
    font = TTF_OpenFont("C:/Windows/WinSxS/amd64_microsoft-windows-font-truetype-cambria_31bf3856ad364e35_10.0.18362.1_none_c4ff0ed18149069c/cambriai.ttf", 18);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    SDL_Texture* arr_text[15]={NULL};
    SDL_Texture *print_hello_world = NULL;
    SDL_Texture *print_mother_fucker = NULL;
    SDL_Texture *exit = NULL;
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface* arr_surface[15] = {NULL};
    (arr_surface[0]) = TTF_RenderText_Solid(font, "What would you like to do?", textColor);
    (arr_surface[1]) = TTF_RenderText_Solid(font, "-------------------------------", textColor);
    (arr_surface[2]) = TTF_RenderText_Solid(font, "1.Search by book name", textColor);
    (arr_surface[3]) = TTF_RenderText_Solid(font, "2.Search by author", textColor);
    (arr_surface[4]) = TTF_RenderText_Solid(font, "3.Search by publisher", textColor);
    (arr_surface[5]) = TTF_RenderText_Solid(font, "4.Search by call number", textColor);
    (arr_surface[6]) = TTF_RenderText_Solid(font, "5.Search by ISBN", textColor);
    (arr_surface[7]) = TTF_RenderText_Solid(font, "6.Search by viewer count", textColor);
    (arr_surface[8]) = TTF_RenderText_Solid(font, "7.Reserve a book", textColor);
    (arr_surface[9]) = TTF_RenderText_Solid(font, "8.Show all books", textColor);
    (arr_surface[10]) = TTF_RenderText_Solid(font,"9.Check personal information", textColor);
    (arr_surface[11]) = TTF_RenderText_Solid(font,"10.Exit", textColor);
    for(int i=0; i<=11; i++){
        arr_text[i]=SDL_CreateTextureFromSurface(renderer, arr_surface[i]); 
    }
    for(int i=0 ; i<=11; i++){
        SDL_FreeSurface(arr_surface[i]);
    }
    SDL_Rect review_library; //create rect
    SDL_Rect arr_rect[15];

    for(int i=0;i<=11;i++){
        arr_rect[i].x = 0;
        arr_rect[i].y = 50*i;
        arr_rect[i].h = 50;
        arr_rect[i].w = 300;
    }
    arr_rect[7].w=350;
    arr_rect[5].w=350;
    arr_rect[10].w=350;
    arr_rect[11].w = 100;
    SDL_Event choose;
    bool quit=false;
    while(!quit){
        while(SDL_PollEvent(&choose)){
            if (choose.type == SDL_QUIT) {
                quit = true;
                choose_menu = -1;
                break; 
            }
            if(choose.type == SDL_MOUSEBUTTONDOWN){
                int x = choose.button.x;
                int y = choose.button.y;
                for(int i = 2;i<=11;i++){
                    if (x > arr_rect[i].x && x < arr_rect[i].x + arr_rect[i].w &&
                    y > arr_rect[i].y && y < arr_rect[i].y + arr_rect[i].h){
                        choose_reader=400+(i+1)*10;
                        quit = true;
                        break;
                    }
                }
            }
            if(quit == true) break;
            for(int i = 0;i<=11;i++){
                SDL_RenderCopy(renderer, arr_text[i], NULL, &arr_rect[i]);
            }
            SDL_RenderPresent(renderer);
        }
    }
    TTF_CloseFont(font);
    for(int i = 0;i<=11;i++){
        SDL_RenderCopy(renderer, arr_text[i], NULL, &arr_rect[i]);
        SDL_DestroyTexture(arr_text[i]);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}


void create_admin_Window(const char* title) {
    SDL_Renderer *renderer = NULL;
    TTF_Font *font = NULL;
    SDL_Window* window =  SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
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
    if (renderer == NULL){
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return ;
    }
    font = TTF_OpenFont("C:/Windows/WinSxS/amd64_microsoft-windows-font-truetype-cambria_31bf3856ad364e35_10.0.18362.1_none_c4ff0ed18149069c/cambriai.ttf", 18);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return ;
    }
    SDL_Texture* arr_text[10]={NULL};
    SDL_Texture *print_hello_world = NULL;
    SDL_Texture *print_mother_fucker = NULL;
    SDL_Texture *exit = NULL;
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface* arr_surface[10] = {NULL};
    (arr_surface[0]) = TTF_RenderText_Solid(font, "What would you like to do?", textColor);
    (arr_surface[1]) = TTF_RenderText_Solid(font, "-------------------------------", textColor);
    (arr_surface[2]) = TTF_RenderText_Solid(font, "1.Review library", textColor);
    (arr_surface[3]) = TTF_RenderText_Solid(font, "2.Add book or delete book", textColor);
    (arr_surface[4]) = TTF_RenderText_Solid(font, "3.Check borrowing", textColor);
    (arr_surface[5]) = TTF_RenderText_Solid(font, "4.Check reader information", textColor);
    (arr_surface[6]) = TTF_RenderText_Solid(font, "5.Check administrator information", textColor);
    (arr_surface[7]) = TTF_RenderText_Solid(font, "6.Lend book", textColor);
    (arr_surface[8]) = TTF_RenderText_Solid(font, "7.Add administrator", textColor);
    (arr_surface[9]) = TTF_RenderText_Solid(font, "8.Exit", textColor);
    for(int i=0; i<10; i++){
        arr_text[i]=SDL_CreateTextureFromSurface(renderer, arr_surface[i]); 
    }
    for(int i=0 ; i<10; i++){
        SDL_FreeSurface(arr_surface[i]);
    }
    SDL_Rect review_library; //create rect
    SDL_Rect arr_rect[10];

    for(int i=0;i<10;i++){
        arr_rect[i].x = 0;
        arr_rect[i].y = 50*i;
        arr_rect[i].h = 50;
        arr_rect[i].w = 500;
    }
    arr_rect[0].w = 500;
    arr_rect[2].w = 230;
    arr_rect[3].w = 350;
    arr_rect[4].w = 340;
    arr_rect[6].w = 550;
    arr_rect[7].w = 200;
    arr_rect[8].w = 300;
    arr_rect[9].w = 100;
    SDL_Event choose;
    bool quit=false;
    while(!quit){
        while(SDL_PollEvent(&choose)){
            if (choose.type == SDL_QUIT) {
                quit = true;
                break; 
            }
            if(choose.type == SDL_MOUSEBUTTONDOWN){
                int x = choose.button.x;
                int y = choose.button.y;
                for(int i = 2;i<10;i++){
                    if (x > arr_rect[i].x && x < arr_rect[i].x + arr_rect[i].w &&
                    y > arr_rect[i].y && y < arr_rect[i].y + arr_rect[i].h){
                        choose_admin=300+(i-1)*10;
                        quit = true;
                        break; 
                    }
                }
            }
            if(quit == true) break;
            for(int i = 0;i<10;i++){
                SDL_RenderCopy(renderer, arr_text[i], NULL, &arr_rect[i]);
            }
            SDL_RenderPresent(renderer);
        }
    }
    TTF_CloseFont(font);
    for(int i = 0;i<10;i++){
        SDL_RenderCopy(renderer, arr_text[i], NULL, &arr_rect[i]);
        SDL_DestroyTexture(arr_text[i]);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

SDL_main(int argc, char *argv[]){
    while(choose_menu!=3){
        if(choose_menu == 0){
            create_menu_window("Menu");
        } 
        if(choose_menu == 1){
            create_reader_Window("Reader");
            switch (choose_reader){
            case BUTTON_SEARCH:
                printf("search_book_name()\n");
                //search_book_name();
                break;
            case BUTTON_BOOK_NAME:
                printf("search_book_name()\n");
                //search_book_name();
                break;
            case BUTTON_AUTHOR:
                printf("search_author()\n");
                //search_author();
                break;
            case BUTTON_PUBLISHER:
                printf("search_publisher()\n");
                //search_publisher();
                break;
            case BUTTON_CALL_NUMBER:
                printf("search_call_number()\n");
                //search_call_number();
                break;
            case BUTTON_ISBN:
                //search_isbn();
                printf("search_isbn()\n");
                break;
            case BUTTON_POPULAR:
                //search_popular();
                printf("search_popular()\n");
                break;
            case BUTTON_RESERVE:
                //reserve_book();
                printf("reserve_book()\n");
                break;
            case BUTTON_INFORMATION:
                //check_personal_information();
                printf("check_personal_information()\n");
                break;
            case BUTTON_SHOW_BOOK:
                printf("show_book()\n");
                //show_book();
                break;
            case 520:
                choose_menu=0;
                break;
            default:
                break;
            }
        } 
        if(choose_menu == 2){
            create_admin_Window("Admin");
            switch (choose_admin){
            case BUTTON_REVIEW:
                //review_library();
                printf("review_library();\n");
                break;
            case BUTTON_ADD_DELETE:
                //add_book();
                printf("add_book();\n");
                break;
            case BUTTON_CHECK_BORROWING:
                //check_borrowing();
                printf("check_borrowing()\n");
                break;
            case BUTTON_CHECK_RE:
                //check_re_information();
                printf("check_re_information()\n");
                break;
            case BUTTON_CHECK_AD:
                //check_ad_information();
                printf("check_ad_information()\n");
                break;
            case BUTTON_LEND:
                //lend_book();
                printf("lend_book()\n");
                break;
            case BUTTON_ADD_AD:
                //add_administrator();
                printf("add_administrator()\n");
                break;
            case 380:
                choose_menu = 0;
                break;
            default:
                break;
            }
        } 
    }
}