#pragma once
#include "Cell.h"

class Table : public CObject
{
	CSize size;
	CArray<CArray<Cell>> cells;
public:
	DECLARE_SERIAL(Table)
	Table();
	Table(CSize size);
	Table(const Table& o);
	~Table();
	void Serialize(CArchive& archive);

	Table& operator=(const Table& o);

private:
	void copyTable(const Table& o);
};

