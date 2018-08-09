#include "GuiButton.h"

////////////////////////////////////////////////////////////////////////////////

gui::GuiButton::GuiButton(const Config & cfg) : GuiWidget(cfg) {}

gui::GuiButton::GuiButton(const Config & cfg, char *& filepath) :
	GuiWidget(cfg, filepath) {}

void gui::GuiButton::draw()
{
	cfg.window->draw(sprite);
}

void gui::GuiButton::checkEvent()
{
	switch (state) {
	case GuiState::IDLE:
		//if (sf::Mouse::getPosition(*(cfg.window)).x <= )

		break;
	case GuiState::HOVERED:

		break;
	case GuiState::PRESSED:

		break;
	case GuiState::RELEASED:

		break;
	case GuiState::BUTTON_CLICKED:

		break;
	}
}
