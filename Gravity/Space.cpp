#include "Space.h"
#include <random>
#include <cmath>

////////////////////////////////////////////////////////////////////////////////

template<typename vector_t>
void normalize(vector_t& vec);

Space::Space(const core::Config& cfg) : Scene(cfg)
{
	std::default_random_engine re;
	std::uniform_int_distribution<> uid_mass{ 50, 100 };
	std::uniform_int_distribution<> uid_posx{ 0, int(cfg.window->getSize().x) };
	std::uniform_int_distribution<> uid_posy{ 0, int(cfg.window->getSize().y) };

	bodies.reserve(core::START_COUNT);
	for (int i = 0; i < bodies.capacity(); ++i)
		bodies.emplace_back(uid_mass(re));
	for (auto& bodie : bodies) {
		bodie.setPosition(uid_posx(re), uid_posy(re));
	}
}

void Space::draw()
{
	computeScene();
	for (auto& bodie : bodies)
		bodie.draw(*(cfg.window));
}

void Space::computeScene()
{
	for (int i = 0; i < bodies.size(); ++i) {
		for (int j = i + 1; j < bodies.size(); ++j) {
			auto dir = bodies[j].getPosition() - bodies[i].getPosition();
			float r_sqrd = dir.x * dir.x + dir.y * dir.y;
			float F = core::G * bodies[i].getMass() * bodies[j].getMass() / r_sqrd;
			if (r_sqrd < 1e-3)
				r_sqrd = 0.1;
			normalize(dir);
			bodies[j].move(-dir * F);
			bodies[i].move(dir * F);
		}
	}

	for (auto& bodie : bodies)
		bodie.update();
}

core::EventList Space::checkEvent()
{
	if (cfg.event->type == sf::Event::KeyPressed &&
		cfg.event->key.code == sf::Keyboard::Escape)
		return core::EventList::EXIT;
	else return core::EventList::IDLE;
}

template<typename vector_t>
void normalize(vector_t& vec) {
	auto norm = std::hypotf(vec.x, vec.y);
	vec.x /= norm;
	vec.y /= norm;
}