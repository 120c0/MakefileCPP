#include <iostream>
#include <vector>

#include "Window.hpp"
#include "Event.hpp"
#include "Rect.hpp"
#include "TileMap.hpp"

#include <SDL2/SDL_image.h>

SDL_Texture *texture_tileset;
float player_velocity_y = 0.f;

  inline std::vector<Rect> getCollisionHit(Rect &entity, std::vector<Rect> tiles_rect)
{
  std::vector<Rect> tiles_hit;
  for(auto &tile : tiles_rect)
    if(SDL_HasIntersection(entity, tile))
      tiles_hit.push_back(tile);
  return tiles_hit;
}
inline void collision(Rect &entity, std::vector<Rect> tiles_rect, float entity_movement[2])
{
  entity.getSDL_FRect().x += entity_movement[0];
  std::vector<Rect> tiles_hit = getCollisionHit(entity, tiles_rect);
  for(auto &tile : tiles_hit)
  {
    if(entity_movement[0] > 0)
    {
      entity.getSDL_FRect().x = tile.getSDL_FRect().x - entity.getSDL_FRect().w;
    }
    if(entity_movement[0] < 0)
    {
      entity.getSDL_FRect().x = tile.getSDL_FRect().x + tile.getSDL_FRect().w;
    }
  }
  entity.getSDL_FRect().y += entity_movement[1];
  tiles_hit = getCollisionHit(entity, tiles_rect);
  for(auto &tile : tiles_hit)
  {
    if(entity_movement[1] > 0)
    {
      entity.getSDL_FRect().y = tile.getSDL_FRect().y - entity.getSDL_FRect().h;
      ::player_velocity_y = 0.f;
    }
    if(entity_movement[1] < 0)
    {
      entity.getSDL_FRect().y = tile.getSDL_FRect().y + tile.getSDL_FRect().h;
      ::player_velocity_y = 0.f;
    }
  }
}

int main()
{
  Window window("SDL2 Random World", {500, 500});
  Event event;

  ::texture_tileset = IMG_LoadTexture(window.getSDL_Renderer(), "../assets/tileset.png");
  
  std::vector<std::vector<int>> tilemap_ids;

  int max_y = std::rand() % 30 + 10;
  for(int x = 0; x < 256; x++, max_y += std::rand() % 2 == 1 ? -1 : 1)
  {
    std::vector<int> row;
    for(int y = 0; y < max_y; y++)
    {
      if(y < max_y - 5)
        row.push_back(3);
      else if(y > max_y - 5)
        row.push_back(2);
    }
    row.push_back(1);
    if(std::rand() % 4 == 1) row.push_back(7);
    else if(std::rand() % 5 == 1) row.push_back(11);
    else if(std::rand() % 8 == 1) row.push_back(13);


    tilemap_ids.push_back(row);
  }


  TileMap tilemap(tilemap_ids, ::texture_tileset);
  bool player_move_right = false, player_move_left = false;
  

  SDL_FPoint offset = {0.f, 0.f};
  Rect player_rect({0.f, 0.f}, 20.f, 60.f);

  while(window.getWindowIsRunning())
  {
    offset.x += (500.f / 2.f - player_rect.getSDL_FRect().x - offset.x); 
    offset.y += (500.f / 2.f - player_rect.getSDL_FRect().y - offset.y);
    
    while(event.pollEvent())
    {
      if(event.getSDL_Event().type == SDL_QUIT)
      {
        window.close();
      }
      if(event.getSDL_Event().type == SDL_KEYDOWN)
      {
        if(event.getSDL_Event().key.keysym.sym == SDLK_a) player_move_left = true;
        if(event.getSDL_Event().key.keysym.sym == SDLK_d) player_move_right = true;
        if(event.getSDL_Event().key.keysym.sym == SDLK_w) ::player_velocity_y = -5.f;
      }
      if(event.getSDL_Event().type == SDL_KEYUP)
      {
        if(event.getSDL_Event().key.keysym.sym == SDLK_a) player_move_left = false;
        if(event.getSDL_Event().key.keysym.sym == SDLK_d) player_move_right = false;
      }
    }

    float player_movement[2] = {
      player_move_right ? 2.f : player_move_left ? -2.f : 0.f,
      ::player_velocity_y += ::player_velocity_y > 10.f ? 0.f : 0.2f
    };

    collision(player_rect, tilemap.getTilesRect(), player_movement);
    window.clear({135, 206, 235, 255});

    tilemap.render(window, offset);
    
    SDL_SetRenderDrawColor(window.getSDL_Renderer(), 0xff, 0xff, 0xff, 0xff);
    SDL_RenderFillRectF(window.getSDL_Renderer(), Rect({player_rect.getSDL_FRect().x + offset.x, player_rect.getSDL_FRect().y + offset.y}, player_rect.getSDL_FRect().w, player_rect.getSDL_FRect().h));
    
    window.display();
  }

  return EXIT_SUCCESS;
}
