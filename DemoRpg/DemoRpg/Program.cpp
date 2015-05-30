#include <SDL.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include<iostream>
#include <list>
//#include "Chest.h"
//#include "Enemy.h"
//#include "Player.h"
#include "Vase.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
bool Init();
bool LoadMedia();
void Close();
SDL_Texture* LoadTexture(std::string path);
SDL_Window* sdlWindow = NULL;
SDL_Renderer* sdlRenderer = NULL;
SDL_Texture* tileAssetsTexture = NULL;
char currentMap[32][24];
//std::list <People> gamePeopleObjects;

void LoadMapCSV()
{
	char data[24][32];
	std::ifstream file("C:\\Users\\Kristian\\Documents\\Code\\DemoRpg\\res\\Map.csv");
	for (int row = 0; row < 24; ++row)
	{
		std::string line;
		std::getline(file, line);
		if (!file.good())
			break;
		std::stringstream iss(line);
		for (int col = 0; col < 32; ++col)
		{
			std::string val;
			std::getline(iss, val, ',');
			if (!iss.good())
				break;
			std::stringstream convertor(val);
			convertor >> currentMap[col][row];
		}
	}
	//check the values look ok on the console 
	for (int j = 0; j < 24; j++)
	{
		for (int i = 0; i < 32; i++)
		{
			std::cout << (currentMap[i][j]);
		}
		printf("\n");
	}
}

bool Init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{

		/*if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
		printf( "Warning: Linear texture filtering not enabled!" );
		}*/
		sdlWindow = SDL_CreateWindow("RPG GAME", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (sdlWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
			if (sdlRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color 
				SDL_SetRenderDrawColor(sdlRenderer, 0x00, 0x00, 0x00,
					0xFF);
			}
			return success;
		}
	}
}

bool LoadMedia()
{
	bool success = true;
	tileAssetsTexture = LoadTexture("..\\..\\res\\gametiles.bmp");
	if (tileAssetsTexture == NULL)
	{
		success = false;
		printf("Failed to load texture image!\n");
	}
	return success;
}

void Close()
{
	SDL_DestroyTexture(tileAssetsTexture);
	tileAssetsTexture = NULL;
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
	sdlWindow = NULL;
	sdlRenderer = NULL;
	SDL_Quit();
}

SDL_Texture* LoadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error\n", path.c_str());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(sdlRenderer, loadedSurface);
		
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

SDL_Rect GetAssetSheetPosition(char mapTile)
{
	if (mapTile == '1')
	{
		SDL_Rect returnRect = { 32, 0, 32, 32 };
		return returnRect;
	}
	if (mapTile == '2')
	{
		SDL_Rect returnRect = { 0, 0, 32, 32 };
		return returnRect;
	}
	if (mapTile == '3')
	{
		SDL_Rect returnRect = { 64, 0, 32, 32 };
		return returnRect;
	}
	if (mapTile == '4')
	{
		SDL_Rect returnRect = { 96, 0, 32, 32 };
		return returnRect;
	}
	SDL_Rect returnRect = { 0, 0, 32, 32 };
	return returnRect;
}

int main(int argc, char* args[])
{
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		LoadMapCSV();
		if (!LoadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Game Loop 
			bool quit = false;
			SDL_Event e;
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					SDL_RenderClear(sdlRenderer);
					for (int j = 0; j < 24; j++)
					{
						for (int i = 0; i < 32; i++)
						{
							if (currentMap[i][j] != '0')
							{
								SDL_Rect assetSheetPosition = GetAssetSheetPosition(currentMap[i][j]);
								SDL_Rect currentMapPosition = { i * 32, j * 32, 32, 32 };
								SDL_RenderCopy(sdlRenderer,	tileAssetsTexture, &assetSheetPosition, &currentMapPosition);
							}
						}
					}
					//place any other object bitmaps on the map. for loop of gameObject array, then do as above
					//THEN make all people attacking status = false
					SDL_RenderPresent(sdlRenderer);
				}
			}
		}

		Close();

		return 0;
	}
}