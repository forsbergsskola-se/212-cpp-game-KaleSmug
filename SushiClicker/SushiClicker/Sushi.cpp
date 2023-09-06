#include "Sushi.h"
#include <iostream>
#include "Window.h"

Sushi::Sushi(Image* sushiImage, Window* window) : image{ sushiImage } {
    image->w = 250;
    image->h = 250;
    image->x = window->getWidth() / 2 - (image->w / 2);
    image->y = window->getHeight() / 2 - (image->h / 2);
    sushiHitbox.x = (int)image->x;
    sushiHitbox.y = (int)image->y;
    sushiHitbox.w = (int)image->w;
    sushiHitbox.h = (int)image->h;
}
SDL_Rect Sushi::GetSushiHitbox()
{
    return sushiHitbox;
}
;
void Sushi::updateScore(int newScore) {
    if (newScore % 10 == 0) {
        //1.1f is half of what we increase the size by, meaning the code below centers the sprite
        image->x -= image->w * 0.1f;
        image->y -= image->h * 0.1f;
        image->w *= 1.2f;
        image->h *= 1.2f;
        sushiHitbox.x = (int)image->x;
        sushiHitbox.y = (int)image->y;
        sushiHitbox.w = (int)image->w;
        sushiHitbox.h = (int)image->h;
    }

    std::cout << "Image width: " << width << ", height: " << height << std::endl;
    raiseSushiChanged(newScore);
}
void Sushi::increase() {
    count++;
    updateScore(count);
}