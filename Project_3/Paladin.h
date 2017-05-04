#include <string>
#include "Actor.h"
#pragma once

class Paladin : public Actor
{
	public:
		Paladin(std::string _name);
		Paladin();
		~Paladin();

		std::string attack() { return name + " swings a giant heavy Hammer at his Enemies. Make Them Pity The Fools!"; }
};
