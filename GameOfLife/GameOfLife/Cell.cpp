#include "stdafx.h"
#include "Cell.h"


Cell::Cell()
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

IMPLEMENT_SERIAL(Cell, CObject, 1)