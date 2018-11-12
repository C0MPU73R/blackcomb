#ifndef CRAFTCLONE_TEXTUREATLAS_H
#define CRAFTCLONE_TEXTUREATLAS_H

#include <string>
#include "Texture.h"
#include "../misc/Coords.h"

class TextureAtlas {
public:
    TextureAtlas(std::string textureFilename, int textureWidth, int textureHeight);
    Texture getTexture();
    UVRect getCoordsForTexture(int texture);

private:
    Texture atlas;
    int textureWidth;
    int textureHeight;
    int numColumns;
    int numRows;
    float centerOffsetX, centerOffsetY;
};

#endif //CRAFTCLONE_TEXTUREATLAS_H