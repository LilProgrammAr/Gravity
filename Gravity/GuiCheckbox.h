#pragma once
#ifndef CLASS_GUI_CHECKBOX_H
#define CLASS_GUI_CHECKBOX_H

#include "GuiWidget.h"

////////////////////////////////////////////////////////////////////////////////

namespace gui {

	class GuiCheckbox : public GuiWidget
	{
	public:

		GuiCheckbox();
		GuiCheckbox(const core::Config& cfg);
		~GuiCheckbox() = default;

		void draw() override;
		bool isChecked();
		void setCheched(bool checked);

		operator bool();

	private:
		bool is_checked;
		bool was_pressed;
	};

}

#endif //CLASS_GUI_CHECKBOX_H