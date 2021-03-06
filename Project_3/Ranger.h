#include <string>
#include "Actor.h"
#pragma once

class Ranger : public Actor
{
	public:
		Ranger(std::string _name);
		Ranger();
		~Ranger();

		std::string attack() { return name + " shoots Enemies with Arrows, Instant Kill"; }
};
