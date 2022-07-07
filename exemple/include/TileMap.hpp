#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "Rect.hpp"
#include "Window.hpp"
#include <vector>

#define BLOCK_SIZE 25.f

class TileMap
{
  public:
    TileMap() = default;
    explicit TileMap(std::vector<std::vector<int>>, SDL_Texture*);

    virtual void render(Window&, SDL_FPoint offset) noexcept;
    std::vector<Rect> &getTilesRect() noexcept;

    virtual ~TileMap() = default;
  private:
    std::vector<std::vector<int>> _tiles_id;
    std::vector<Rect> _tiles_rect;
    SDL_Texture *_texture_tileset;
};

#endif
