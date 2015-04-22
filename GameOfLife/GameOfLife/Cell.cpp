#include "stdafx.h"
#include "Cell.h"


Cell::Cell() : state(DEAD)
{
}


Cell::~Cell()
{
}

void Cell::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);

	if (archive.IsStoring())
		archive << (int)state;
	else {
		int s;
		archive >> s;
		state = (State)s;
	}
}


Cell::Cell(const Cell& o) : state(o.state)
{
}

Cell& Cell::operator = (const Cell& o) {
	if (this != &o) {
		state = o.state;
	}
	return *this;
}

IMPLEMENT_SERIAL(Cell, CObject, 1)

void Cell::setState(State s){
	state = s;
}


bool Cell::is(State s){
	return state == s;
}