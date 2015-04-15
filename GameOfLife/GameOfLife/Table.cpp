#include "stdafx.h"
#include "Table.h"


Table::Table()
{
}

Table::Table(CSize size) : size(size)
{
	for (LONG i = 0; i < size.cx; ++i) {
		CArray<Cell> temp;
		for (LONG j = 0; j < size.cy; ++j) {
			temp.Add(Cell());
		}
		cells.Add(temp);
	}
}

Table::Table(const Table& o) : size(o.size), cells(o.cells)
{
}

Table& Table::operator = (const Table& o) {
	if (this != &o) {
		size = o.size;
		CArray<Cell> temp;
		for (LONG i = 0; i < size.cx; ++i) {
			CArray<Cell> temp;
			temp.Copy(o.cells[i]);
			cells.Add(temp);
		}
	}
	return *this;
}

Table::~Table()
{
}

void Table::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);

	if (archive.IsStoring()) {
		archive << size;
		cells.Serialize(archive);
	}
	else
	{
		archive >> size;
		cells.Serialize(archive);
	}
}

IMPLEMENT_SERIAL(Table, CObject, 1)