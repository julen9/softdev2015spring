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
	~Cell();
	void Serialize(CArchive& archive);
};

