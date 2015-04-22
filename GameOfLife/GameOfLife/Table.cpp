#include "stdafx.h"
#include "Table.h"


Table::Table()
{
}

Table::Table(CSize size) : size(size)
{
	cells.resize(size.cx);
	for (LONG i = 0; i < size.cx; ++i) {
		cells[i].resize(size.cy);
	}
}

Table::Table(const Table& o) : size(o.size), cells(o.cells)
{
}

Table& Table::operator = (const Table& o) {
	if (this != &o) {
		size = o.size;
		cells = o.cells;
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
		for (LONG i = 0; i < size.cx; ++i) {
			for (LONG j = 0; j < size.cy; ++j) {
				cells[i][j].Serialize(archive);
			}
		}
	}
	else
	{
		archive >> size;
		for (LONG i = 0; i < size.cx; ++i) {
			for (LONG j = 0; j < size.cy; ++j) {
				cells[i][j].Serialize(archive);
			}
		}
	}
}

IMPLEMENT_SERIAL(Table, CObject, 1)