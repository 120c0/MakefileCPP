#include <iostream>
#include <vector>
#include <random>

#include <SDL.h>
#include <SDL_image.h>

#include <ImGui/imgui.h>
#include <ImGui/backends/imgui_impl_sdl.h>
#include <ImGui/backends/imgui_impl_sdlrenderer.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

SDL_Texture *particles_image[6];

std::random_device rd;
std::default_random_engine generator(rd());

std::uniform_real_distribution<float> ffx(0.01f, 2.f);
std::uniform_real_distribution<float> ffy(0.01f, 3.f);

class Particle
{
  public:
    Particle(SDL_FRect r)
      : rect {r}, frame {0.f}, life_time {std::rand() % 2000 + 20}, angle {std::rand() % 360 + 2},
        acy {-ffy(generator)}, fx {ffx(generator)}
    {
      tick_begin = SDL_GetTicks();
    }
    void update()
    {
      if(tick_begin + ((life_time + 1) / 6) * frame < SDL_GetTicks()) frame++;
      rect.x += std::cos(angle) * fx;
      rect.y += (acy += 0.1f);
    }
    bool isDead()
    {
      return tick_begin + life_time < SDL_GetTicks();
    }
    void render(SDL_Renderer *renderer)
    {
      if(!isDead())
        SDL_RenderCopyF(renderer, particles_image[(int) std::round(frame)], NULL, &rect);
    }
  private:
    SDL_FRect rect;
    int tick_begin, life_time, angle;
    float frame, acy, fx;
};

int main(int, const char*[])
{
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
  {
    fprintf(stderr, "Error<SDL_Init>: %s\n", SDL_GetError());
    exit(-1);
  }

  SDL_Window *window = SDL_CreateWindow("Compile", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
  SDL_Event event;
  bool window_is_running = window && renderer;

  SDL_Texture *target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

  for(int i = 0; i < 6; i++)
  {
    SDL_Surface *surface = IMG_Load(("data/images/particles/p/" + std::to_string(i) + ".png").c_str());

    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0, 0));
    particles_image[i] = SDL_CreateTextureFromSurface(renderer, surface);
  }
  int mx, my;
  std::vector<Particle> parts;

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO(); (void) io;

  ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
  ImGui_ImplSDLRenderer_Init(renderer);

  while(window_is_running)
  {
    SDL_GetMouseState(&mx, &my);
    while(SDL_PollEvent(&event))
    {
      ImGui_ImplSDL2_ProcessEvent(&event);
      window_is_running = SDL_QUIT != event.type;
    }

    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    SDL_SetRenderTarget(renderer, target);
    SDL_SetRenderDrawColor(renderer, 0x5, 0x5, 0x5, 0xff);
    SDL_RenderClear(renderer);

    ImGui::Begin("Renderer");


    ImVec2 win_pos = ImGui::GetWindowPos(), win_size = ImGui::GetWindowSize();
    ImGui::Image((ImTextureID) target, win_size);

    ImGui::End();
    ImVec2 win_scale = ImVec2(win_size.x / (SCREEN_WIDTH / 2.f), win_size.y / (SCREEN_HEIGHT / 2.f));

    float
      offset_x = (float) mx / 2.f - (float) win_pos.x / 2.f - win_pos.x + (float) mx,
      offset_y = (float) my / 2.f - (float) win_pos.y / 2.f - win_pos.y + (float) my;
    /*float
      offset_x = ((float) mx / win_scale.x - win_pos.x / win_scale.x) - win_pos.x + mx - (mx / 2),
      offset_y = ((float) my / win_scale.y - win_pos.y / win_scale.y) - win_pos.y + my - (my / 2);*/

    std::cout << "\rScale: " << win_scale.x << ", " << win_scale.y << "\r";

    for(int i = 0; i < 30; i++)
      parts.push_back(Particle({offset_x, offset_y, 5.f, 5.f}));

    int index = 0; 
    for(auto &p : parts)
    {
      p.update();
      p.render(renderer);
      if(p.isDead())
        parts.erase(parts.begin() + index);

      index++;
    }
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0xff);
    SDL_RenderClear(renderer);
    // SDL_RenderCopy(renderer, target, NULL, NULL); 

    ImGui::Render();
    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(renderer);
  }
  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
