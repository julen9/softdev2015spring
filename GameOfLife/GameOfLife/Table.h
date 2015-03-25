#pragma once
#include "Cell.h"

class Table : public CObject
{
	CSize size;
	CArray<CArray<Cell>> cells;
public:
	DECLARE_SERIAL(Table)
	Table();
	~Table();
	void Serialize(CArchive& archive);
};

