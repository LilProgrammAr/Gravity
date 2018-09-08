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
		bool was_pressed;
		bool was_larged;
		bool handleHover();

	};
}

#endif //CLASS_GUI_BUTTON_H