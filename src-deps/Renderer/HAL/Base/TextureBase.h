#pragma once

class TextureBase {
public:
    void getDescription();
    bool isLoaded();
    void createTexture(TextureDescription const&);
}