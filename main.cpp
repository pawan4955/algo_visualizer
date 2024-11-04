#include <SDL2/SDL.h>
#include <iostream>
#include<random>
#include<algorithm>
#include<ranges>

void draw_state(std::vector<int>& v,SDL_Renderer* renderer,unsigned int red,unsigned int blue){
  int index=0;
  for(int i :  v){
    if(index==red)
       SDL_SetRenderDrawColor(renderer,255,0,0,255);
    else if(index==blue)
       SDL_SetRenderDrawColor(renderer,0,0,255,255);
    else  
       SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderDrawLine(renderer,index,99,index,i);
    index+=1;
  }
}

int main(int argc, char* argv[]) {
//    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
//         std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
//         return 1;
//     }

//     SDL_Window* window = SDL_CreateWindow("AlgoViz", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
//     if (window == nullptr) {
//         std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Delay(3000); // Wait for 3 seconds

//     SDL_DestroyWindow(window);
//     SDL_Quit();
//     return 0;
std::random_device rd;
std::uniform_int_distribution d(1,100);
std:: vector<int> v;

for(int i=0;i<100;i++){
    v.push_back(d(rd));
}

SDL_Window* window=nullptr;
SDL_Renderer* renderer=nullptr;
SDL_CreateWindowAndRenderer(70*10,70*10,0,&window,&renderer);
SDL_RenderSetScale(renderer,5,5);


for(unsigned int i=0;i<v.size();i++){
    for(unsigned j=i;j<v.size();j++){
        if(v[j]>v[i]){
            std::swap(v[j],v[i]);
        }
        //clear screen
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        //draw state of sort
        draw_state(v,renderer,i,j);

        //show to window
        SDL_RenderPresent(renderer);
        SDL_Delay(4);
    }
}
for(int i=0;i<100;i++){
  std::  cout<<v[i]<<" ";
}
return 0;

}
