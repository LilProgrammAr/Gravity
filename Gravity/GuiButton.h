#pragma once
#ifndef CLASS_GUI_BUTTON_H
#define CLASS_GUI_BUTTON_H

#include "GuiWidget.h"

////////////////////////////////////////////////////////////////////////////////

namespace gui {
	class GuiButton : public GuiWidget
	{
	public:
		GuiButton() = default;
		GuiButton(const core::Config& cfg);
		~GuiButton() = default;

		void draw() override;
		bool isClicked();
				
	private:
		bool wasPressed;
		bool wasLarged;
		bool handleHover();

	};
}

#endif //CLASS_GUI_BUTTON_H