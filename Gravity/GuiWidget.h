#pragma once
#ifndef CLASS_GUI_WIDGET_H
#define CLASS_GUI_WIDGET_H	

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "vector2.h"

////////////////////////////////////////////////////////////////////////////////
namespace gui {

	enum class GuiState : unsigned char {
		IDLE = 0,
		HOVERED,
		PRESSED,
		RELEASED,
		BUTTON_CLICKED,
		CHECK_BOX_CHECKED,
		CHECK_BOX_UNCHECKED
	};

	class GuiWidget
	{
	public:
		GuiWidget(const Config& cfg);
		GuiWidget(const Config& cfg, char*& filepath);
		virtual ~GuiWidget() = default;

		bool loadFromFile(char*& path) noexcept;
		void loadConfig(const Config& obj) noexcept;

		virtual void draw() = 0;
		virtual void checkEvent() = 0;

		void setPosition(const vector2f& pos);
		sf::Vector2f getPosition() noexcept;

	protected:
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		GuiState state;

		Config cfg;
	};
}
#endif //CLASS_GUI_WIDGET_H