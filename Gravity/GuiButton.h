#pragma once
#ifndef CLASS_GUI_BUTTON_H
#define CLASS_GUI_BUTTON_H

#include "GuiWidget.h"

////////////////////////////////////////////////////////////////////////////////

namespace gui {
	class GuiButton : public GuiWidget
	{
	public:
		GuiButton(const Config& cfg);
		GuiButton(const Config& cfg, char*& filepath);
		~GuiButton() = default;

		void draw() override;

		void checkEvent() override;

	};
}

#endif //CLASS_GUI_BUTTON_H