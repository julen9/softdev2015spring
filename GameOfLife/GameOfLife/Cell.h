#pragma once
class Cell
{
public:
	enum State{
		LIVING, DEAD
	};
private:
	State state;
public:
	Cell();
	~Cell();
};

