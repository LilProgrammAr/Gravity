#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////

core::GameSettings Scene::gs = core::GameSettings{
	sf::VideoMode::getDesktopMode(),
	"Gravity",
	sf::ContextSettings(),
	sf::Style::Fullscreen,
	100,
	120
};

Scene::Scene(const core::Config & obj) :
	cfg(obj) {}