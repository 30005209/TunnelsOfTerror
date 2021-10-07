#include "State.h"

Room::Room()
{
	this->availableStates.push_back(new Entrance(this));
	this->availableStates.push_back(new DCavern(this));
	this->setState(ENTRANCE);
}

bool Entrance::travelNorth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(DAMP_CAVERN);
	return true;
}

bool DCavern::travelNorth(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(WELL_ROOM);
	return true;
}

bool DCavern::travelSouth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(ENTRANCE);
	return true;
}

bool DCavern::travelEast(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

bool DCavern::travelWest(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(GUARD);
	return true;
}

bool Guard::travelNorth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(BARRACKS);
	return true;
}

bool Guard::travelEast(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(DAMP_CAVERN);
	return true;
}

bool Barracks::travelSouth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(GUARD);
	return true;
}

bool Kitchen::travelNorth(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

bool Kitchen::travelSouth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(ICE_BOX);
	return true;
}

bool Kitchen::travelEast(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(LARDER);
	return true;
}

bool Kitchen::travelWest(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(DAMP_CAVERN);
	return true;
}

bool IceBox::travelNorth(void)
{
	cout << "The journey takes 10 energy." << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

bool Larder::travelNorth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(BOTTLE);
	return true;
}

bool Larder::travelSouth(void)
{
	cout << "The journey takes 10 energy." << endl;
	this->CurrentContext->setState(WELL_ROOM);
	return true;
}

bool Larder::travelWest(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

bool Bottle::travelSouth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(LARDER);
	return true;
}

bool Bottle::travelEast(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

bool GreatHall::travelNorth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(BOTTLE);
	return true;
}

bool GreatHall::travelSouth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

bool GreatHall::travelEast(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(MYSTERIOUS);
	return true;
}

bool GreatHall::travelWest(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(TROLLS);
	return true;
}

bool Trolls::travelNorth(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(LIBRARY);
	return true;
}

bool Trolls::travelSouth(void)
{
	cout << "The journey takes 2 energy." << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

bool Trolls::travelEast(void)
{
	cout << "The journey takes 3 energy." << endl;
	this->CurrentContext->setState(MYSTERIOUS);
	return true;
}

bool Library::travelSouth(void)
{
	cout << "The journey takes 1 energy." << endl;
	this->CurrentContext->setState(TROLLS);
	return true;
}

bool Library::travelEast(void)
{
	cout << "The journey takes 3 energy." << endl;
	this->CurrentContext->setState(MYSTERIOUS);
	return true;
}

bool Mysterious::travelNorth(void)
{
	cout << "The journey takes 3 energy." << endl;
	this->CurrentContext->setState(LIBRARY);
	return true;
}

bool Mysterious::travelSouth(void)
{
	cout << "The journey takes 4 energy." << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

bool Mysterious::travelWest(void)
{
	cout << "The journey takes 3 energy." << endl;
	this->CurrentContext->setState(TROLLS);
	return true;
}
