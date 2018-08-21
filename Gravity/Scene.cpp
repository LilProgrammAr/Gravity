#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////

Scene::Scene(const core::Config & obj) : 
	cfg(obj),
	gs(core::GameSettings{true, sf::ContextSettings(), 100}) {}
