#include <string>
#include "Actor.h"
#pragma once

class Mage : public Actor
{
	public:
		Mage(std::string name);
		~Mage();

		std::string attack() { return name + " casts The Spell Expecto Portronum at the Enemy!"; }	
};
