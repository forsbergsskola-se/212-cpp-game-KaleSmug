#pragma once
#include "Image.h"
#include <memory>
#include "TextRender.h"

extern class IImageLoader;
class Window
{


    //The window we'll be rendering to
    SDL_Window* window{};

    //The surface contained by the window
    SDL_Surface* screenSurface{};

    bool success;

    IImageLoader* imageLoader;
    int width, height;

public:
    SDL_Renderer* renderer{};
    void clear();
    void present();

    Window(int width, int height, IImageLoader* imageLoader);
    ~Window();

    int getWidth() { return width; }
    int getHeight() { return height; }
    bool WasSuccessfull() { return success; }
    void Render(Image* image);
    void Render(TextRenderer& image);
    std::unique_ptr<Image> LoadImage(const char* path);
};