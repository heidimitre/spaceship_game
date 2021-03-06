#include "position/position.h"
#include "sdl_helper/sdl_helper.h"

void main()
{
    struct position* pos = init_position(40, 400);
    struct SDL_Window *window = NULL;
    struct SDL_Renderer *renderer = NULL;

    window = createWindow();
    renderer = createRenderer(window);
    SDL_Texture *sprite_texture = load_sprite_texture("F-35D.PNG", renderer);

    SDL_Event event;
    int  hasquit = -1;
    
    reset_screen(renderer);
    draw_sprite(renderer, sprite_texture, get_x(pos), get_y(pos));
    while(hasquit != 0)
    {
        while(hasquit != 0 && SDL_PollEvent(&event)!=0)
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    hasquit = 0;
                break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode)
                     {
                        case SDL_SCANCODE_LEFT:
                            accelerate(pos, -100, 0);
                        break;
                        case SDL_SCANCODE_RIGHT:
                            accelerate(pos, 100, 0);
                        break;
                        case SDL_SCANCODE_UP:
                            accelerate(pos, 0, -100);
                        break;
                        case SDL_SCANCODE_DOWN:
                            accelerate(pos, 0, 100);
                        break;

                    }
                break;
                case SDL_KEYUP:
                    switch (event.key.keysym.scancode)
                     {
                        case SDL_SCANCODE_LEFT:
                            accelerate(pos, 100, 0);
                        break;
                        case SDL_SCANCODE_RIGHT:
                            accelerate(pos, -100, 0);
                        break;
                        case SDL_SCANCODE_UP:
                            accelerate(pos, 0, 100);
                        break;
                        case SDL_SCANCODE_DOWN:
                            accelerate(pos, 0, -100);
                        break;

                    }
                break;
            }
            
        }
        SDL_SetRenderDrawColor( renderer, 255, 225, 225, 0 );
        SDL_RenderClear(renderer);
        draw_sprite(renderer, sprite_texture, get_x(pos), get_y(pos));
        SDL_Delay(15);
    }
    destroy_position(pos);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}
