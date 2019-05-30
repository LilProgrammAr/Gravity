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

	addingObject = false;

	main_menu.loadFromFile(core::RES_PATH + "Simulation scene/main_menu_icon.png");
	add_body.loadFromFile(core::RES_PATH + "Simulation scene/add_object_icon.png");
	main_menu.loadConfig(cfg);
	add_body.loadConfig(cfg);
	main_menu.setPosition(core::Vector2f(
		cfg.window->getSize().x - main_menu.getSize().x,
		cfg.window->getSize().y - main_menu.getSize().y));
	add_body.setPosition(core::Vector2f(
		cfg.window->getSize().x - main_menu.getSize().x * 2.5,
		cfg.window->getSize().y - main_menu.getSize().y));

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
	main_menu.draw();
	add_body.draw();
}

void Space::addObject()
{
	addingObject = true;
	temp_object = std::make_unique<CelestialBody>(core::DEFAULT_MASS);
}

void Space::computeScene()
{
	for (int i = 0; i < bodies.size(); ++i) {
		for (int j = i + 1; j < bodies.size(); ++j) {

			auto dir = bodies[j].getPosition() - bodies[i].getPosition();
			float r_sqrd = dir.x * dir.x + dir.y * dir.y;
			float F = core::G * bodies[i].getMass() * bodies[j].getMass() / r_sqrd;
			int r_sum = bodies[i].getRadius() + bodies[j].getRadius();

			normalize(dir);
			bodies[j].move(-dir * F * static_cast<float>(cfg.clock->getElapsedTime().asMilliseconds()) * core::SPEED_MULT);
			bodies[i].move(dir * F * static_cast<float>(cfg.clock->getElapsedTime().asMilliseconds()) * core::SPEED_MULT);

			/////////////////////////////////////////////////////////////////////////
			//Collision detection
			if (r_sqrd <= r_sum * r_sum) {
				float i_to_j = bodies[i].getMass() / bodies[j].getMass() * 1;
				float j_to_i = 1 / i_to_j;

				if (i_to_j > 1) {
					bodies[i].addMass(bodies[j].getMass() * 0.9);
					bodies.erase(bodies.begin() + j);
					++j;
					//continue;
				}
				else {
					bodies[j].addMass(bodies[i].getMass() * 0.9);
					bodies.erase(bodies.begin() + i);
					++i;
					//continue;
				}
			}
			////////////////////////////////////////////////////////////////////////
			//Out-of-borders detection
			else {
				auto pos_i = bodies[i].getPosition();
				auto pos_j = bodies[j].getPosition();
				if (pos_i.x < 0 || pos_i.x > cfg.window->getSize().x ||
					pos_i.y < 0 || pos_i.y > cfg.window->getSize().y) {
					bodies.erase(bodies.begin() + i);
					++i;
				}
				if (pos_j.x < 0 || pos_j.x > cfg.window->getSize().x ||
					pos_j.y < 0 || pos_j.y > cfg.window->getSize().y) {
					bodies.erase(bodies.begin() + j);
					++j;
				}
			}
			////////////////////////////////////////////////////////////////////////

		}
	}

	for (auto& bodie : bodies)
		bodie.update();

	if (addingObject) {
		add_object();
	}
}

void Space::add_object()
{
	temp_object->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*(cfg.window))));
	temp_object->draw(*(cfg.window));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
		temp_object->addMass(core::MASS_STEP);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
		temp_object->addMass(-core::MASS_STEP);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		bodies.push_back(*temp_object);
		temp_object.release();
		addingObject = false;
	}
}

core::EventList Space::checkEvent()
{
	if (main_menu.isClicked()) return core::EventList::MAIN_MENU;
	if (add_body.isClicked()) return core::EventList::ADD_PLANET;
	return core::EventList::IDLE;
}

template<typename vector_t>
void normalize(vector_t& vec) {
	auto norm = std::hypotf(vec.x, vec.y);
	vec.x /= norm;
	vec.y /= norm;
}