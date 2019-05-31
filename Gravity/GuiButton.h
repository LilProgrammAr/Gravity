#pragma once
#ifndef CLASS_GUI_BUTTON_H
#define CLASS_GUI_BUTTON_H

#include "GuiWidget.h"

////////////////////////////////////////////////////////////////////////////////

namespace gui {
	class GuiButton : public GuiWidget
	{
	public:
		GuiButton();
		GuiButton(const core::Config& cfg);
		~GuiButton() = default;

		void draw() override;
		bool isClicked();
		void notifyIf(std::function<bool()>);
				
	private:
		bool was_pressed;
		bool was_larged;
		bool handleHover();
		std::function<bool()> notify_if;

	};
}

#endif //CLASS_GUI_BUTTON_H