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
Cell& Table::at(const int& x, const int &y){

	int tx = ((x % size.cx) + size.cx) % size.cx;
	int ty = ((y % size.cy) + size.cy) % size.cy;
	return cells[tx].at(ty);
}

int Table::getEnv(int x, int y) {
	int n = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (at(x + i, y + j).is(Cell::LIVING) && !(i == 0 && j == 0)) {
				n++;
			}
		}
	}
	return n;
}


void Table::update() {
	std::vector<std::vector<Cell> > buf = cells;
	for (LONG i = 0; i < size.cx; ++i) {
		for (LONG j = 0; j < size.cy; ++j) {
			int n = getEnv(i, j);
			if (cells[i][j].is(Cell::LIVING)) {
				if (n<2)
					buf[i][j].setState(Cell::DEAD);
				else if (n>3)
					buf[i][j].setState(Cell::DEAD);
			}
			else if (cells[i][j].is(Cell::DEAD)) {
				if (n == 3)
					buf[i][j].setState(Cell::LIVING);
			}
		}
	}
	cells = buf;
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


CSize& Table::getSize(){
	return size;
}
