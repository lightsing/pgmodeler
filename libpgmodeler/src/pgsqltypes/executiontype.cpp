/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2019 - Raphael Araújo e Silva <raphael@pgmodeler.io>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

#include "executiontype.h"

ExecutionType::ExecutionType()
{
	type_idx=Offset;
}

ExecutionType::ExecutionType(unsigned type_id)
{
	(*this)=type_id;
}

ExecutionType::ExecutionType(const QString &type_name)
{
	(*this)=type_name;
}

void ExecutionType::getTypes(QStringList &type_list)
{
	BaseType::getTypes(type_list,Offset,TypesCount);
}

unsigned ExecutionType::operator = (unsigned type_id)
{
	BaseType::setType(type_id,Offset,TypesCount);
	return type_idx;
}

unsigned ExecutionType::operator = (const QString &type_name)
{
	unsigned type_id;

	type_id=BaseType::getType(type_name, Offset, TypesCount);
	BaseType::setType(type_id,Offset,TypesCount);
	return type_id;
}

QString ExecutionType::operator ~ ()
{
	return type_list[type_idx];
}