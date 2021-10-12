#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

enum state {	ENTRANCE, DAMP_CAVERN, GUARD, BARRACKS, 
	WELL_ROOM, KITCHEN, ICE_BOX, LARDER, BOTTLE, 
	GREAT_HALL, TROLLS, LIBRARY, MYSTERIOUS, };

enum stateParameter { INVENTORY, DANGER};

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

	virtual void setRoomParam(stateParameter SP, int value)
	{
		this->stateParameters[SP] = value;
	}

	virtual int getRoomParam(stateParameter SP)
	{
		return this->stateParameters[SP];
	}
};

class Transition
{
public:
	
	virtual bool travelNorth(void) { cout << "No path this way!" << endl; return false; }
	virtual bool travelSouth(void) { cout << "No path this way!" << endl; return false; }
	virtual bool travelEast(void)  { cout << "No path this way!" << endl; return false; }
	virtual bool travelWest(void)  { cout << "No path this way!" << endl; return false; }
};

class RoomState : public State, public Transition
{
public:
	RoomState(StateContext* Context) : State(Context) {};
};

class Entrance : public RoomState
{
public:
	Entrance(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
};

bool Entrance::travelNorth()
{
	cout << "Heading from the Entrance to the Damp Cavern" << endl; 
	this->CurrentContext->setState(DAMP_CAVERN);
	return true;
}

class DampCavern : public RoomState
{
public:
	DampCavern(StateContext* Context) : RoomState(Context) {};
	bool travelSouth(void);
};

bool DampCavern::travelSouth()
{
	cout << "Heading from the Damp Cavern to the Entrance" << endl;
	this->CurrentContext->setState(ENTRANCE);
	return true;
}

class Character
{
protected:
	string _description = "Undefined character";
public:
	RoomState* CurrentRoom = nullptr;
	string description(void) { return this->_description; };

	Character() {};

};

class Player : public Character
{
public:
	Player() { _description = "Player"; }
};


class LevelManager : public StateContext, public Transition
{
private:
	RoomState* currentRoomState = nullptr;
	friend Character;

public:
	vector<Character*> characters;

	LevelManager() {
		this->availableStates.push_back(new Entrance(this));
		this->availableStates.push_back(new DampCavern(this));

		this->setState(ENTRANCE);
		//characters.push_back(new Player);
		//characters[0]->CurrentRoom = (RoomState*)this->availableStates[ENTRANCE];
		
	}

	bool travelNorth() 
	{
		currentRoomState = (RoomState*)this->CurrentState;
		return this->currentRoomState->travelNorth();
	}

	bool travelSouth()
	{
		currentRoomState = (RoomState*)this->CurrentState;
		return this->currentRoomState->travelSouth();
	}

};

int main()
{
	LevelManager DM;

	DM.travelNorth();
	DM.travelSouth();


	cin.clear();
	cin.get();	
	
	return 0;
}
