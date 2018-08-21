#pragma once
#ifndef CLASS_MAIN_MENU_H
#define CLASS_MAIN_MENU_H

#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////

class MainMenu : public Scene
{
public:
	MainMenu(const core::Config& cfg);
	~MainMenu() = default;

	void draw();
	core::EventList checkEvent();
private:
	gui::GuiButton
		gravity,
		newSimulation,
		settings,
		quit;

};

#endif //CLASS_MAIN_MENU_H