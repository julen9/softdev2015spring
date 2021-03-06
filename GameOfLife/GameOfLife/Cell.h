#pragma once
class Cell : public CObject
{
public:
	enum State{
		LIVING, DEAD
	};
private:
	State state;
public:
	DECLARE_SERIAL(Cell)
	Cell();
	Cell(const Cell& o);
	~Cell();
	void Serialize(CArchive& archive);

	void setState(State s);
	bool is(State s);

	Cell& operator=(const Cell& o);
};

