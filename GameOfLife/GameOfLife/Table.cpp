#include "stdafx.h"
#include "Table.h"


Table::Table()
{
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