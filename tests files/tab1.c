
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Définition des dimensions de la fenêtre
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Fonction pour initialiser SDL
bool initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur lors de l'initialisation de SDL: %s", SDL_GetError());
        return false;
    }

    return true;
}

// Fonction pour charger une image
SDL_Surface* loadImage(const char* path)
{
    SDL_Surface* loadedImage = SDL_LoadBMP(path);
    if (loadedImage == NULL)
    {
        printf("Impossible de charger l'image %s: %s", path, SDL_GetError());
        return NULL;
    }

    return loadedImage;
}

// Fonction pour afficher une image sur la fenêtre
void renderImage(SDL_Surface* image, int x, int y, SDL_Surface* windowSurface)
{
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = image->w;
    destRect.h = image->h;

    SDL_BlitSurface(image, NULL, windowSurface, &destRect);
}

int main()
{
    // Initialisation de SDL
    if (!initSDL())
    {
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Animation d'un chat dansant",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Erreur lors de la création de la fenêtre: %s", SDL_GetError());
        return 1;
    }

    // Création de la surface de la fenêtre
    SDL_Surface* windowSurface = SDL_GetWindowSurface(window);

    // Chargement de l'image du chat
    SDL_Surface* catImage = loadImage("chat.bmp");

    // Variables pour la boucle de jeu
    bool quit = false;
    SDL_Event event;

    // Position du chat sur l'écran
    int x = 0;
    int y = 0;

    // Boucle de jeu
    while (!quit)
    {
        // Gestion des événements
        while (SDL_PollEvent(&event))
        {
            // L'utilisateur a cliqué sur la croix de fermeture de la fenêtre
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Effacement de la fenêtre
        SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0));

        // Affichage du chat
        renderImage(catImage, x, y, windowSurface);

        // Mise à jour de la fenêtre
        SDL_UpdateWindowSurface(window);

        // Déplacement du chat à chaque itération de la boucle
        x += 1;
        y += 1;

        // Animation en boucle du chat
        if (x > SCREEN_WIDTH - catImage->w || y > SCREEN_HEIGHT - catImage->h)
        {
            x = 0;
            y = 0;
        }

        // Pause pour ralentir l'animation
        SDL_Delay(10);
    }

    // Libération de la mémoire
    SDL_FreeSurface(catImage);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
