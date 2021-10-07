#ifndef _STATE
#define _STATE

#include <vector> //only to be used to contain dispenser states and nothing else
#include <iostream>
#include <string>
#include "Player.h"
#include "Item.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

enum state { ENTRANCE, DAMP_CAVERN, GUARD, BARRACKS, WELL_ROOM, KITCHEN, ICE_BOX, LARDER, BOTTLE, GREAT_HALL, TROLLS, LIBRARY, MYSTERIOUS };
enum stateParameter { INVENTORY };

class StateContext;

class State
{
protected:

	StateContext* CurrentContext;

public:

	State(StateContext* Context)
	{
		CurrentContext = Context;
	}
	virtual ~State(void)
	{
	}

};

class StateContext
{
protected:

	State* CurrentState = nullptr;
	int stateIndex = 0;
	vector<State*> availableStates;
	vector<int> stateParameters;

public:

	virtual ~StateContext()
	{
		for (int index = 0; index < this->availableStates.size(); index++) delete this->availableStates[index];
		this->availableStates.clear();
		this->stateParameters.clear();
	}

	virtual void setState(state newState)
	{
		this->CurrentState = availableStates[newState];
		this->stateIndex = newState;
	}

	virtual int getStateIndex(void)
	{
		return this->stateIndex;
	}

	virtual void setStateParam(stateParameter SP, int value)
	{
		this->stateParameters[SP] = value;
	}

	virtual int getStateParam(stateParameter SP)
	{
		return this->stateParameters[SP];
	}
};

class Transition
{
public:
	virtual bool travelNorth(void) { cout << "No path that way!" << endl; return false; }
	virtual bool travelSouth(void) { cout << "No path that way!" << endl; return false; }
	virtual bool travelEast(void) { cout << "No path that way!" << endl; return false; }
	virtual bool travelWest(void) { cout << "No path that way!" << endl; return false; }
};

class Entity : public State, public Transition
{
public:
	Entity(StateContext* Context) : State(Context){	};

};

class Room : public StateContext, public Transition
{
private:
	Entity* CurrentState = nullptr;
public:
	Room();
	
};

class Entrance : public Entity
{
public:
	Entrance(StateContext* Context) : Entity(Context) { cout << "You are at the Entrance" << endl; };
	bool travelNorth(void);
	
};

class DCavern : public Entity
{
public:
	DCavern(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelEast(void);
	bool travelWest(void);
};

class Guard : public Entity
{
public:
	Guard(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
	bool travelEast(void);
};

class Barracks : public Entity
{
public:
	Barracks(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelSouth(void);
};

class Kitchen : public Entity
{
public:
	Kitchen(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelEast(void);
	bool travelWest(void);
};

class IceBox : public Entity
{
public:
	IceBox(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
};

class Larder : public Entity
{
public:
	Larder(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelWest(void);
};

class Bottle : public Entity
{
public:
	Bottle(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelSouth(void);
	bool travelEast(void);
};

class GreatHall : public Entity
{
public:
	GreatHall(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelEast(void);
	bool travelWest(void);
};

class Trolls : public Entity
{
public:
	Trolls(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelEast(void);
};

class Library : public Entity
{
public:
	Library(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelSouth(void);
	bool travelEast(void);
};

class Mysterious : public Entity
{
public:
	Mysterious(StateContext* Context) : Entity(Context) { cout << "You are at the Damp Cavern" << endl; };
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelWest(void);
};
#endif