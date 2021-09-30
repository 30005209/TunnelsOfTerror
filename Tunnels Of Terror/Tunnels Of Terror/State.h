#ifndef _STATE
#define _STATE

#include <vector> //only to be used to contain dispenser states and nothing else
#include <iostream>
#include <string>
#include "Player.h"
#include "Room.h"
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

class Room : public State, public Transition
{
public:
	Room(StateContext* Context) : State(Context) {}
};

#endif