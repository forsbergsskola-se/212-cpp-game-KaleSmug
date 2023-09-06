#pragma once
#include <SDL.h>
#include "Observer.h"
class Image
{

    //The image we will load and show on the screen
    SDL_Surface* imageSurface{};

    bool success;
public:
    float x, y;
    int w, h;

    Image(SDL_Surface* surface);

    ~Image();

    bool WasSuccesfull() { return success; }
    SDL_Surface* GetResource() { return imageSurface; }

    Image& operator =(Image& other) = delete;
    Image& operator =(Image&& other) = default;
public:

};