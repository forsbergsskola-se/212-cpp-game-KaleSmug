#ifndef SUSHI_H
#define SUSHI_H
#include <SDL_image.h>
#include "Image.h"
#include "Observer.h"
#include "Window.h"

class Sushi : public ISushiSubject {
private:
    int count;
    int width;
    int height;
    Image* image;
    SDL_Rect sushiHitbox{ (int)image->x,(int)image->y,(int)image->w, (int)image->h };

    void updateScore(int newScore);

public:
    Sushi(Image*, Window*);

    SDL_Rect GetSushiHitbox();

    void increase();
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

#endif // SUSHI_H