#include "stdafx.h"
#include "Table.h"


Table::Table()
{
}

Table::Table(CSize size) : size(size)
{
	cells.SetSize(size.cx);
	for (LONG i = 0; i < size.cx; ++i) {
		cells[i].SetSize(size.cy);
	}
}

Table::Table(const Table& o)
{
	copyTable(o);
}

Table& Table::operator = (const Table& o) {
	if (this != &o) {
		copyTable(o);
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

void Table::copyTable(const Table& o) {
	size = o.size;
	cells.SetSize(size.cx);
	for (LONG i = 0; i < size.cx; ++i) {
		cells[i].SetSize(size.cy);
		for (LONG j = 0; j < size.cy; ++j) {
			cells[i][j] = o.cells[i][j];
		}
	}
}

IMPLEMENT_SERIAL(Table, CObject, 1)