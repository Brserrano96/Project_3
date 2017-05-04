#include <string>
#pragma once

class Actor
{
	protected: 
		std::string name;

	public:
		Actor(std::string name);
		Actor();
		~Actor();

		std::string getName() { return name; }
		std::string virtual attack() { return getName() + " attacks with pimp hand! Remember Got To Keep Your Pimp Hand Strong! :) "; }
};
