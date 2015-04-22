#pragma once
#include <vector>
#include "Cell.h"

class Table : public CObject
{
	CSize size;
	std::vector<std::vector<Cell>> cells;
public:
	DECLARE_SERIAL(Table)
	Table();
	Table(CSize size);
	Table(const Table& o);
	~Table();
	void Serialize(CArchive& archive);

	Table& operator=(const Table& o);

};

