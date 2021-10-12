//#ifndef _STATE
//#define _STATE
//
//#include <vector> //only to be used to contain dispenser states and nothing else
//#include <iostream>
//#include <string>
////#include "Player.h"
////#include "Item.h"
//
//using std::string;
//using std::vector;
//using std::cout;
//using std::cin;
//using std::endl;
//
//enum state { ENTRANCE, DAMP_CAVERN, GUARD, BARRACKS, WELL_ROOM, KITCHEN, ICE_BOX, LARDER, BOTTLE, GREAT_HALL, TROLLS, LIBRARY, MYSTERIOUS };
//enum stateParameter { INVENTORY };
//
//class StateContext;
//
//class State
//{
//protected:
//
//	StateContext* CurrentContext;
//
//public:
//
//	State(StateContext* Context)
//	{
//		CurrentContext = Context;
//	}
//	virtual ~State(void)
//	{
//	}
//
//};
//
//class StateContext
//{
//protected:
//
//	State* CurrentState = nullptr;
//	int stateIndex = 0;
//
//public:
//
//	vector<State*> availableStates;
//	vector<int> stateParameters;
//
//	virtual ~StateContext()
//	{
//		for (int index = 0; index < this->availableStates.size(); index++) delete this->availableStates[index];
//		this->availableStates.clear();
//		this->stateParameters.clear();
//	}
//
//	virtual void setState(state newState)
//	{
//		this->CurrentState = availableStates[newState];
//		this->stateIndex = newState;
//	}
//
//	virtual int getStateIndex(void)
//	{
//		return this->stateIndex;
//	}
//
//	virtual void setStateParam(stateParameter SP, int value)
//	{
//		this->stateParameters[SP] = value;
//	}
//
//	virtual int getStateParam(stateParameter SP)
//	{
//		return this->stateParameters[SP];
//	}
//};
//
//class Transition
//{
//public:
//	virtual bool travelNorth(void) { cout << "No path that way!" << endl; return false; }
//	virtual bool travelSouth(void) { cout << "No path that way!" << endl; return false; }
//	virtual bool travelEast(void) { cout << "No path that way!" << endl; return false; }
//	virtual bool travelWest(void) { cout << "No path that way!" << endl; return false; }
//};
//
//class Entity : public State, public Transition
//{
//public:
//	Entity(StateContext* Context) : State(Context){	};
//
//};
//
//class Room : public Entity
//{
//public:
//	Room(StateContext* Context) : Entity(Context) {};
//	
//};
//
//class Entrance : public Room
//{
//public:
//	Entrance(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelSouth(void);
//	bool travelEast(void);
//	bool travelWest(void);
//	
//};
//
//class DCavern : public Room
//{
//public:
//	DCavern(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelSouth(void);
//	bool travelEast(void);
//	bool travelWest(void);
//};
//
//class Guard : public Room
//{
//public:
//	Guard(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelEast(void);
//};
//
//class Barracks : public Room
//{
//public:
//	Barracks(StateContext* Context) : Room(Context) {};
//	bool travelSouth(void);
//};
//
//class Well : public Room
//{
//public:
//	Well(StateContext* Context) : Room(Context) {};
//	bool travelSouth(void);
//	bool travelEast(void);
//};
//
//class Kitchen : public Room
//{
//public:
//	Kitchen(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelSouth(void);
//	bool travelEast(void);
//	bool travelWest(void);
//};
//
//class IceBox : public Room
//{
//public:
//	IceBox(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//};
//
//class Larder : public Room
//{
//public:
//	Larder(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelSouth(void);
//	bool travelWest(void);
//};
//
//class Bottle : public Room
//{
//public:
//	Bottle(StateContext* Context) : Room(Context) {};
//	bool travelSouth(void);
//	bool travelEast(void);
//};
//
//class GreatHall : public Room
//{
//public:
//	GreatHall(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelSouth(void);
//	bool travelEast(void);
//	bool travelWest(void);
//};
//
//class Trolls : public Room
//{
//public:
//	Trolls(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelSouth(void);
//	bool travelEast(void);
//};
//
//class Library : public Room
//{
//public:
//	Library(StateContext* Context) : Room(Context) {};
//	bool travelSouth(void);
//	bool travelEast(void);
//};
//
//class Mysterious : public Room
//{
//public:
//	Mysterious(StateContext* Context) : Room(Context) {};
//	bool travelNorth(void);
//	bool travelSouth(void);
//	bool travelWest(void);
//};
//#endif