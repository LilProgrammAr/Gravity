#pragma once
#ifndef CLASS_GUI_WIDGET_H
#define CLASS_GUI_WIDGET_H	

#include <SFML/Graphics.hpp>
#include "Core/core.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////
namespace gui {

	class GuiWidget
	{
	public:
		GuiWidget() = default;
		GuiWidget(const core::Config& cfg);
		virtual ~GuiWidget() = default;

		bool loadFromFile(std::string path) noexcept;
		void loadConfig(const core::Config& obj) noexcept;

		virtual void draw() = 0;
		sf::Vector2u getSize();

		void setPosition(const core::Vector2f& pos);
		sf::Vector2f getPosition() noexcept;

	protected:
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		core::Config cfg;
	};
}
#endif //CLASS_GUI_WIDGET_H