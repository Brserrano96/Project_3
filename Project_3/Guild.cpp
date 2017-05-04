#include <iostream>
#include <memory>
#include <iterator>
#include <unistd.h>
#include "Guild.h"

using namespace std;

Guild::Guild(string _name)
{
	this->name = _name;
}
Guild::~Guild() { }

void Guild::AddNPC(shared_ptr<Actor> _npc)
{
	npcs.push_back(_npc);
}

string Guild::getInfo()
{
	string output = "Your Guild/Group has: \n";
	int mageCount = rangerCount = warriorCount = paladinCount = 0;

	for (vector<shared_ptr<Actor>>::iterator it = npcs.begin(); it != npcs.end(); it++)
	{
		if (dynamic_pointer_cast<Mage>(*it) != nullptr)
		{
			mageCount++;
		}
		else if (dynamic_pointer_cast<Ranger>(*it) != nullptr)
		{
			rangerCount++;
		}
		else if (dynamic_pointer_cast<Warrior>(*it) != nullptr)
		{
			warriorCount++;
		}
		else if (dynamic_pointer_cast<Paladin>(*it) != nullptr)
		{
			paladinCount++;
		}
	}
    sleep(1);
	output += mageCount		> 0 ? std::to_string(mageCount) + " Mages\n" : "No Mages! Fool!\n";
	output += rangerCount	> 0 ? std::to_string(rangerCount) + " Rangers\n" : "No Rangers! Fool!\n";
	output += warriorCount	> 0 ? std::to_string(warriorCount) + " Warriors\n" : "No Warriors! Fool!\n";
	output += paladinCount	> 0 ? std::to_string(paladinCount) + " Paladins\n" : "No Paladins! Fool!\n";

	return output;
}

string Guild::MagesAttack()
{
	string output;
	for (vector<shared_ptr<Actor>>::iterator it = npcs.begin(); it != npcs.end(); it++)
	{
		if (dynamic_pointer_cast<Mage>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

string Guild::PaladinsAttack()
{
	string output;
	for (vector<shared_ptr<Actor>>::iterator it = npcs.begin(); it != npcs.end(); it++)
	{
		if (dynamic_pointer_cast<Paladin>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

string Guild::RangersAttack()
{
	string output;
	for (vector<shared_ptr<Actor>>::iterator it = npcs.begin(); it != npcs.end(); it++)
	{
		if (dynamic_pointer_cast<Ranger>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

string Guild::WarriorsAttack()
{
	string output;
	for (vector<shared_ptr<Actor>>::iterator it = npcs.begin(); it != npcs.end(); it++)
	{
		if (dynamic_pointer_cast<Warrior>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

string Guild::AllAdventurersAttack()
{
	string output = "Congrats, You Now Are Able To Attack With EveryOne, Make Them Pity The Fool!!!!! \n";
	if (npcs.size() > 0)
	{
		for (auto person : npcs)
		{
			output += person->attack() + "\n";
		}
	}

	return output;
}
