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
	//Vei2 v;
	//auto v2 = v.GetNormalized();

	for (int i = 0; i < 5; i++)
	{
		surfaces.emplace_back(std::move("Images\\link90x90.bmp")) ;
	}
	OutputDebugStringA("This is a copy assign operation:  ");
	surfaces[1] = surfaces[2];
	OutputDebugStringA("This is a move assign operation:  ");
	surfaces[3] = std::move(surfaces[4]);
	//Surface youfucker(surfaces[2]);
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	// process key messages while any remain
	while (!wnd.kbd.KeyIsEmpty())
	{
		const auto e = wnd.kbd.ReadKey();
		// only interested in space bar presses
		if (e.IsPress() && e.GetCode() == VK_SPACE)
		{
			link.ActivateEffect();
			hit.Play();
		}
	}
	// process arrow keys state
	Vec2 dir = { 0.0f,0.0f };
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dir.y -= 1.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dir.y += 1.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dir.x -= 1.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dir.x += 1.0f;
	}
	link.SetDirection(dir);
	// update character
	link.Update(ft.Mark());
}

void Game::ComposeFrame()
{
	font.DrawText("Becky.\nLemme smash.", wnd.mouse.GetPos() - Vei2{ 50,150 }, Colors::White, gfx);
	link.Draw(gfx);
}
