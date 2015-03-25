#pragma once
#include "Cell.h"

class Table
{
	CSize size;
	CArray<CArray<Cell>> cells;
public:
	Table();
	~Table();
};

