/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	//ft.Begin();
}

void Game::Go()
{
	float elapsed = 0.0f;
	do {
		elapsed += ft.Mark();
	} while (elapsed <= delay);

	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

}

void Game::ComposeFrame()
{
	int srcX = (frameNum % 4)  * srcBlockSizeX;
	//int srcX = 0;
	int srcY = 2 * srcBlockSizeY;
	frameNum++;

	//gfx.DrawSprite(posX, posY, { 32,64,48,96 }, surf);
	//gfx.DrawSprite(posX, posY, { srcX,srcX + srcBlockSizeX,srcY,srcY + srcBlockSizeY }, { 100,400,100,400 },surf);
	//gfx.DrawSprite(wnd.mouse.GetPosX(), wnd.mouse.GetPosY(), { srcX,srcX + srcBlockSizeX,srcY,srcY + srcBlockSizeY }, gfx.GetScreenRect(), surf);
	//gfx.DrawSprite(wnd.mouse.GetPosX(), wnd.mouse.GetPosY(), { 32,64,48,96 }, gfx.GetScreenRect(), surf, Colors::Magenta);
	gfx.DrawSprite(wnd.mouse.GetPosX(), wnd.mouse.GetPosY(), { srcX,srcX + srcBlockSizeX,srcY,srcY + srcBlockSizeY }, gfx.GetScreenRect(), surf, Colors::Magenta);
	
	//RectI region = { 100,400,100,400 };
	//.DrawRect(region, Colors::Gray);

	//RectI srcRect = { 32,64,48,96 };

	//gfx.DrawSprite(wnd.mouse.GetPosX(), wnd.mouse.GetPosY(), { 32,64,48,96 }, region , surf, Colors::Magenta);
	/*posX += 5;
	posY += 5;*/
}
