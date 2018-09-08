#pragma once
#ifndef CLASS_SETTINGS_SCENE_H
#define CLASS_SETTINGS_SCENE_H

////////////////////////////////////////////////////////////////////////////////

#include "Scene.h"

class SettingsMenu :
	public Scene
{
public:
	SettingsMenu(const core::Config&);
	~SettingsMenu() = default;

	void draw();
	core::EventList checkEvent();

	void applySettings(const core::GameSettings&);

private:

	gui::GuiButton
		Settings,
		fullscreen,
		resolution,
		apply,
		accept,
		cancel;
	gui::GuiCheckbox fullsceen_checkbox;

};

#endif //CLASS_SETTINGS_SCENE_H