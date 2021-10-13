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
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelWest(void);
	bool travelEast(void);
};

bool DampCavern::travelNorth()
{
	cout << "Heading from the Damp Cavern to the Well Room" << endl;
	this->CurrentContext->setState(WELL_ROOM);
	return true;
}

bool DampCavern::travelSouth()
{
	cout << "Heading from the Damp Cavern to the Entrance" << endl;
	this->CurrentContext->setState(ENTRANCE);
	return true;
}

bool DampCavern::travelWest()
{
	cout << "Heading from the Damp Cavern to the Guard Room" << endl;
	this->CurrentContext->setState(GUARD);
	return true;
}

bool DampCavern::travelEast()
{
	cout << "Heading from the Damp Cavern to the Kitchen" << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

class Guard : public RoomState
{
public:
	Guard(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
	bool travelEast(void);
};

bool Guard::travelNorth()
{
	cout << "Heading from the Guard Room to the Barracks" << endl;
	this->CurrentContext->setState(BARRACKS);
	return true;
}

bool Guard::travelEast()
{
	cout << "Heading from the Guard Room to the Damp Cavern" << endl;
	this->CurrentContext->setState(DAMP_CAVERN);
	return true;
};

class Barracks : public RoomState
{
public:
	Barracks(StateContext* Context) : RoomState(Context) {};
	bool travelSouth(void);
};

bool Barracks::travelSouth()
{
	cout << "Heading from the Barracks to the Guard Room" << endl;
	this->CurrentContext->setState(GUARD);
	return true;
}

class Well : public RoomState
{
public:
	Well(StateContext* Context) : RoomState(Context) {};
	bool travelSouth(void);
	bool travelEast(void);
};

bool Well::travelSouth()
{
	cout << "Heading from the Well to the Damp Cavern" << endl;
	this->CurrentContext->setState(DAMP_CAVERN);
	return true;
}

bool Well::travelEast()
{
	cout << "Heading from the Well to the Larder" << endl;
	this->CurrentContext->setState(LARDER);
	return true;
}

class Kitchen : public RoomState
{
public:
	Kitchen(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelEast(void);
	bool travelWest(void);
};

bool Kitchen::travelNorth()
{
	cout << "Heading from the Kitchen to the Great Hall" << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

bool Kitchen::travelSouth()
{
	cout << "Heading from the Kitchen to the Ice Box" << endl;
	this->CurrentContext->setState(ICE_BOX);
	return true;
}

bool Kitchen::travelEast()
{
	cout << "Heading from the Kitchen to the Larder" << endl;
	this->CurrentContext->setState(LARDER);
	return true;
}

bool Kitchen::travelWest()
{
	cout << "Heading from the Kitchen to the Damp Cavern" << endl;
	this->CurrentContext->setState(DAMP_CAVERN);
	return true;
}

class IceBox : public RoomState
{
public:
	IceBox(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
};

bool IceBox::travelNorth()
{
	cout << "Heading from the Ice Box to the Kitchen" << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

class Larder : public RoomState
{
public:
	Larder(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelWest(void);
};

bool Larder::travelNorth()
{
	cout << "Traveling from the Larder to the Bottle Room" << endl;
	this->CurrentContext->setState(BOTTLE);
	return true;
}

bool Larder::travelSouth()
{
	cout << "Travelling from the Larder to the Well Room" << endl;
	this->CurrentContext->setState(WELL_ROOM);
	return true;
}

bool Larder::travelWest()
{
	cout << "Travelling from the Larder to the Kitchen" << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

class Bottle : public RoomState
{
public:
	Bottle(StateContext* Context) : RoomState(Context) {};
	bool travelSouth(void);
	bool travelWest(void);
};

bool Bottle::travelSouth()
{
	cout << "Travelling from the Bottle Room to the Larder" << endl;
	this->CurrentContext->setState(LARDER);
	return true;
}

bool Bottle::travelWest()
{
	cout << "Travelling from the Bottle Room to the Great Hall" << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

class GreatHall : public RoomState
{
public:
	GreatHall(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelEast(void);
	bool travelWest(void);
};

bool GreatHall::travelNorth()
{
	cout << "Travelling from the Great Hall to the Bottle Room" << endl;
	this->CurrentContext->setState(BOTTLE);
	return true;
}

bool GreatHall::travelSouth()
{
	cout << "Travelling from the Great Hall to the Kitchen" << endl;
	this->CurrentContext->setState(KITCHEN);
	return true;
}

bool GreatHall::travelEast()
{
	cout << "Travelling from the Great Hall to the Mysterious Room" << endl;
	this->CurrentContext->setState(MYSTERIOUS);
	return true;
}

bool GreatHall::travelWest()
{
	cout << "Travelling from the Great Hall to the Troll's Room" << endl;
	this->CurrentContext->setState(TROLLS);
	return true;
}

class Trolls : public RoomState
{
public:
	Trolls(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelEast(void);
};

bool Trolls::travelNorth()
{
	cout << "Travelling from the Trolls' Room to the Library" << endl;
	this->CurrentContext->setState(LIBRARY);
	return true;
}

bool Trolls::travelSouth()
{
	cout << "Travelling from the Trolls' Room to the Great Hall" << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

bool Trolls::travelEast()
{
	cout << "Travelling from the Trolls' Room to the Mysterious Room" << endl;
	this->CurrentContext->setState(MYSTERIOUS);
	return true;
}

class Library : public RoomState
{
public:
	Library(StateContext* Context) : RoomState(Context) {};
	bool travelSouth(void);
	bool travelEast(void);
};

bool Library::travelSouth()
{
	cout << "Travelling from the Library to the Trolls Room" << endl;
	this->CurrentContext->setState(TROLLS);
	return true;
}

bool Library::travelEast()
{
	cout << "Travelling from the Library to the Mysterious Room" << endl;
	this->CurrentContext->setState(MYSTERIOUS);
	return true;
}

class Mysterious : public RoomState
{
public:
	Mysterious(StateContext* Context) : RoomState(Context) {};
	bool travelNorth(void);
	bool travelSouth(void);
	bool travelWest(void);
};

bool Mysterious::travelNorth()
{
	cout << "Travelling from the Mysterious Room to the Library" << endl;
	this->CurrentContext->setState(LIBRARY);
	return true;
}

bool Mysterious::travelSouth()
{
	cout << "Travelling from the Mysterious Room to the Great Hall" << endl;
	this->CurrentContext->setState(GREAT_HALL);
	return true;
}

bool Mysterious::travelWest()
{
	cout << "Travelling from the Mysterious Room to the Trolls' Room" << endl;
	this->CurrentContext->setState(TROLLS);
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
		this->availableStates.push_back(new Guard(this));
		this->availableStates.push_back(new Barracks(this));
		this->availableStates.push_back(new Well(this));
		this->availableStates.push_back(new Kitchen(this));
		this->availableStates.push_back(new IceBox(this));
		this->availableStates.push_back(new Larder(this));
		this->availableStates.push_back(new Bottle(this));
		this->availableStates.push_back(new GreatHall(this));
		this->availableStates.push_back(new Trolls(this));
		this->availableStates.push_back(new Library(this));
		this->availableStates.push_back(new Mysterious(this));

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

	bool travelEast()
	{
		currentRoomState = (RoomState*)this->CurrentState;
		return this->currentRoomState->travelEast();
	}

	bool travelWest()
	{
		currentRoomState = (RoomState*)this->CurrentState;
		return this->currentRoomState->travelWest();
	}

};

int main()
{
	LevelManager DM;

	bool hasNotQuit = true;
	int input = 99999;

	while (hasNotQuit)
	{
		cin.clear();
		cin >> input;
		switch (input)
		{
		case 8:
			DM.travelNorth();
			break;

		case 6:
			DM.travelEast();
			break;

		case 4:
			DM.travelWest();
			break;

		case 2:
			DM.travelSouth();
			break;

		case 5:
			hasNotQuit = false;
			break;
		}
	}


	cin.clear();
	cin.get();	
	
	return 0;
}
