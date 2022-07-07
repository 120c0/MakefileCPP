#include "TileMap.hpp"

TileMap::TileMap(std::vector<std::vector<int>> tiles_id, SDL_Texture *texture_tileset)
  : _tiles_id(tiles_id), _texture_tileset(texture_tileset)
{
}

void TileMap::render(Window &window, SDL_FPoint offset) noexcept
{
  this->_tiles_rect.clear();
  for(int y = 0; y < (int) this->_tiles_id.size(); y++)
  {
    for(int x = 0, id = this->_tiles_id[y][x]; x < (int) this->_tiles_id[y].size(); x++, id = this->_tiles_id[y][x])
    {
      if(id == 1)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({0.f, 0.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y }, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 2)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({8.f, 0.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 3)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({16.f, 0.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 4)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({24.f, 0.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 5)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({0.f, 8.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 6)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({8.f, 8.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 7)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({16.f, 8.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 8)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({24.f, 8.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 9)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({0.f, 16.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 10)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({8.f, 16.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 11)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({16.f, 16.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 12)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({24.f, 16.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 13)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({0.f, 24.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 14)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({8.f, 24.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 15)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({16.f, 24.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id == 16)
        SDL_RenderCopy(window.getSDL_Renderer(), this->_texture_tileset, Rect({24.f, 24.f}, 8.f, 8.f), Rect({BLOCK_SIZE * y + offset.x, 500.f - BLOCK_SIZE * x + offset.y}, BLOCK_SIZE, BLOCK_SIZE));
      if(id != 0 && id != 7 && id != 11 && id != 13)
      {
        this->_tiles_rect.push_back(Rect({BLOCK_SIZE * y, 500.f - BLOCK_SIZE * x}, BLOCK_SIZE, BLOCK_SIZE));
      }        
    }
  }
}
std::vector<Rect> &TileMap::getTilesRect() noexcept
{
  return this->_tiles_rect;
}
