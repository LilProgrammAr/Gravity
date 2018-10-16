#include "Space.h"
#include <random>

Space::Space(const core::Config& cfg) : Scene(cfg)
{
	std::default_random_engine re;
	std::uniform_int_distribution<> uid{ 0, 100 };

	bodies.reserve(50);
	for (int i = 0; i < bodies.capacity(); ++i)
		bodies.emplace_back(uid(re));
}
