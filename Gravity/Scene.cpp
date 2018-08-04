#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////

Scene::Scene(const Config & obj) : 
	cfg(obj),
	gs(GameSettings{true, sf::ContextSettings(), 100}) {}
