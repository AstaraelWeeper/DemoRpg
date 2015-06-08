#include <SDL.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include<iostream>
#include <list>
#include "Chest.h"
#include "Enemy.h"
#include "Knight.h"
#include "Boss.h"
#include "People.h"
#include "Player.h"
#include "Vase.h"
#include "Door.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
bool Init();
bool LoadMedia();
void Close();
void InitialiseItems();
void InitialiseEnemies();
SDL_Texture* LoadTexture(std::string path);
SDL_Window* sdlWindow = NULL;
SDL_Renderer* sdlRenderer = NULL;
SDL_Texture* tileAssetsTexture = NULL;
char currentMap[32][24];
Uint8 mapAlphaValues[32][24]; //0 is tranparent (show black background), 255 is visible
SDL_Rect searchArea;
std::list <People*> gamePeopleObjects;
std::list<Items*> gameItemObjects;
Player player (10,10); //give starting positions. add enemies to array, add items to array. Put all this in a method

enum KeyPressDirections
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_LEFT,
    KEY_PRESS_UP,
    KEY_PRESS_RIGHT,
    KEY_PRESS_DOWN,
};

enum facingDirections
{
	Left = 1,
	Up,
	Right,
	Down,
};

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
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) ); //need to get the right RGB for the pink
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
	else //??was missing
	{
	SDL_Rect returnRect = { 0, 0, 32, 32 };
	return returnRect;
	}
}
void initialiseAlphaValues()
{
	for (int j = 0; j < 24; j++) //render map
	{
		for (int i = 0; i < 32; i++)
		{
			mapAlphaValues[i][j] = 255;
		}
	}
}
void InitialiseEnemies()
{
	Knight enemy1 = Knight(2, 6);
	Knight enemy2 = Knight(30, 12);
	Knight enemy3 = Knight(9, 4);
	Knight enemy4 = Knight(10, 18);
	Knight enemy5 = Knight(10, 22);
	Knight enemy6 = Knight(13, 8);
	Knight enemy7 = Knight(17, 18);
	Knight enemy8 = Knight(17, 21);
	Knight enemy9 = Knight(23, 14);
	Knight enemy10 = Knight(24, 2);
	Knight enemy11 = Knight(26, 20);
	Boss boss = Boss(2, 18);
}

void InitialiseItems() //make global
{
	//doors x 9 normal, 1 boss
	Door door1 = Door(3, 4, false);
	Door door2 = Door(6, 12, false);
	Door door3 = Door(6, 19, false);
	Door door4 = Door(16, 7, false);
	Door door5 = Door(14, 20, false);
	Door door6 = Door(19, 7, false);
	Door door7 = Door(22, 5, false);
	Door door8 = Door(26, 15, false);
	Door door9 = Door(28, 20, false);
	Door bossDoor = Door(24, 21, true);

	Vase vase1 = Vase(7, 22);
	Vase vase2 = Vase(9, 2);
	Vase vase3 = Vase(20, 12);
	Vase vase4 = Vase(22, 17);

	Chest chest1 = Chest(7, 2, false);
	Chest chest2 = Chest(14, 12, false);
	Chest chest3 = Chest(29, 2, false);
	Chest chestKey = Chest(28, 9, true);

}

void UpdateSearchArea(facingDirections facingDirection)//probably should be a check for anything and then handled
{
	int playerPositionX = player.GetXPosition();
	int playerPositionY = player.GetYPosition();
	switch (facingDirection)
	{
	  case Left:
		searchArea = { playerPositionX - 32, playerPositionY, 32, 32 };
		break;
	  case Up:
		  searchArea = { playerPositionX, playerPositionY - 32, 32, 32 };
		  break;
	  case Right:
		  searchArea = { playerPositionX + 32, playerPositionY, 32, 32 };
		  break;
	  case Down:
		  searchArea = { playerPositionX, playerPositionY + 32, 32, 32 };
		  break;
	}
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
			initialiseAlphaValues;
			//init objects
			InitialiseItems();
			InitialiseEnemies();
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

					else if (e.type == SDL_KEYDOWN) //update player based on input
					{

					 switch( e.key.keysym.sym )
                        {
					        case SDLK_SPACE://attack button
							player.Attack();
							int facingDirection = player.GetFacingDirection;
							UpdateSearchArea(static_cast<facingDirections>(facingDirection));
							//loop through enemies and vases
							break;

                            case SDLK_UP:
                            player.Move(KEY_PRESS_UP);
                            break;

                            case SDLK_DOWN:
                            player.Move(KEY_PRESS_DOWN);
                            break;

                            case SDLK_LEFT:
								player.Move(KEY_PRESS_LEFT);
                            break;

                            case SDLK_RIGHT:
								player.Move(KEY_PRESS_RIGHT);
                            break;

							case SDLK_RETURN:
								int facingDirection = player.GetFacingDirection;
								UpdateSearchArea(static_cast<facingDirections>(facingDirection));
								//loop through doors and chests
								break;

                            default:
                            break;
                        }
					}
					//update enemies
					//update items
					SDL_RenderClear(sdlRenderer);
					for (int j = 0; j < 24; j++) //render map
					{
						for (int i = 0; i < 32; i++)
						{
							if (currentMap[i][j] != '0')
							{
								SDL_Rect assetSheetPosition = GetAssetSheetPosition(currentMap[i][j]);
								SDL_Rect currentMapPosition = { i * 32, j * 32, 32, 32 };
								//get alpha value and set
								SDL_RenderCopy(sdlRenderer,	tileAssetsTexture, &assetSheetPosition, &currentMapPosition);
							}
						}
					}
					//place any other object bitmaps on the map. for loop of gameObject array, then do as above
					for(std::list<People*>::iterator it = gamePeopleObjects.begin(); it != gamePeopleObjects.end(); ++it)
					{
						SDL_Rect itemAssetSheetPosition = (*it)->GetAssetSheetPosition();
						SDL_Rect itemMapPosition = (*it)->GetMapPosition();
						SDL_RenderCopy(sdlRenderer,	tileAssetsTexture, &itemAssetSheetPosition, &itemMapPosition);
					}
					for (std::list<Items*>::iterator it = gameItemObjects.begin(); it != gameItemObjects.end(); ++it)
					{
						SDL_Rect itemAssetSheetPosition = (*it)->GetAssetSheetPosition();
						SDL_Rect itemMapPosition = (*it)->GetMapPosition();
						SDL_RenderCopy(sdlRenderer,	tileAssetsTexture, &itemAssetSheetPosition, &itemMapPosition);
					}
				
					SDL_RenderPresent(sdlRenderer);
				}
			}
		}

		Close();

		return 0;
	}
}