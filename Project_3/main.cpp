#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <memory>
#include "Guild.h"
using namespace std;

void GuildInfo(const shared_ptr<Guild> guild);
void AddAdventurer(const shared_ptr<Guild> guild);
void Attack(const shared_ptr<Guild> guild);

int main() 
{
    sleep(4);
    cout << "Welcome to Grand Theft Auto: Hogwarts Edition." << endl;
    sleep(1);
    cout << "\n\nEnter a name for your guild/ groups name: " << endl;
	string name;
	getline(cin, name);
	auto guild = make_shared<Guild>(name);
    
	int choice = -1;
	while (choice != 0) 
	{
        cout << "\n\nHello " << guild->getName() << ", Please Pick One or Else"<< endl;
        cout << "______________________________________________" << endl;
        sleep(1);
		cout << "1) Display Guild Information" << endl;
        sleep(1);
		cout << "2) Please Add A Adventurer" << endl;
        sleep(1);
		cout << "3) Attack" << endl;
		cin >> choice;

		switch (choice) 
		{
		case 1: GuildInfo(guild); break;
		case 2: AddAdventurer(guild); break;
		case 3: Attack(guild); break;
		default: return 0; break;
		}
	}
	return 0;
}

void GuildInfo(const shared_ptr<Guild> guild)
{
	
	cout << guild->getInfo();
	
}

void AddAdventurer(const shared_ptr<Guild> guild) 
{
	

    cout << "Enter a name for your adventurer: " << endl;
	string name;
	cin >> name;

	 cout << "Please Wait..." << endl;
    sleep(5);
	cout << "What type of Adventurer would you like to add?" << endl;
    sleep(1);
	cout << "1) Mage" << endl;
    sleep(1);
	cout << "2) Ranger" << endl;
    sleep(1);
	cout << "3) Paladin" << endl;
    sleep(1);
	cout << "4) Warrior" << endl;

	int choice = -1;
	cin >> choice;
	switch (choice)
	{ 
		case 1: 
		{
			auto charPtr = make_shared<Mage>(name);
			guild->AddNPC(charPtr);
			break;
		}
		case 2: 
		{
			auto charPtr = make_shared<Ranger>(name);
			guild->AddNPC(charPtr);
			break;
		}
		case 3: 
		{
			auto charPtr = make_shared<Paladin>(name);
			guild->AddNPC(charPtr);
			break;
		}
		case 4:
		{
			auto charPtr = make_shared<Warrior>(name);
			guild->AddNPC(charPtr);
			break;
		}
		default: cout << "Invalid choice! Pick a Valid Choice or Else"; break;
	}
	
}

void Attack(const shared_ptr<Guild> guild)
{
	

	cout << "1) Mages Attack" << endl;
	cout << "2) Rangers Attack" << endl;
	cout << "3) Warriors Attacks" << endl;
	cout << "4) Paladins Attack" << endl;
	cout << "5) All Hell Broke Lose, Attack with Everything You Got" << endl;

	int choice = -1;
	cin >> choice;

	switch (choice)
	{
		case 1: cout << guild->MagesAttack() << endl;
            break;
		case 2: cout << guild->RangersAttack() << endl;
            break;
		case 3: cout << guild->WarriorsAttack() << endl;
            break;
		case 4: cout << guild->PaladinsAttack() << endl;
            break;
		case 5: cout << guild->AllAdventurersAttack() << endl;
            break;
		default: cout << "Why Are You Running Away, Don't Be A Coward!!!!!!" << endl;
            exit(0);
            break;
	}

		
}
