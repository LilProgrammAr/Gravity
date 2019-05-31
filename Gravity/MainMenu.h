#pragma once
#ifndef CLASS_MAIN_MENU_H
#define CLASS_MAIN_MENU_H

#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////

class MainMenu : public Scene
{
public:
	MainMenu(const core::Config& cfg);
	virtual ~MainMenu() = default;

	void draw();
	core::EventList checkEvent() override;
	void pause() override {}
	void resume() override {}


private:
	gui::GuiButton
		Gravity,
		newSimulation,
		//settings,
		quit;

};

#endif //CLASS_MAIN_MENU_H