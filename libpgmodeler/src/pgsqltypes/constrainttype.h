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

/**
\ingroup libpgmodeler/pgsqltypes
\class ConstraintType
\brief Implements the operations to manipulate constraint types.
**/

#ifndef CONSTRAINT_TYPE
#define CONSTRAINT_TYPE

#include "basetype.h"

class ConstraintType: public BaseType{
	private:
		static QStringList type_names;

	public:
		static constexpr unsigned PrimaryKey = 1,
		ForeignKey = 2,
		Check = 3,
		Unique = 4,
		Exclude= 5;

		ConstraintType(const QString &type_name);
		ConstraintType(unsigned type_id);
		ConstraintType();

		static QStringList getTypes();
		unsigned operator = (unsigned type_id);
		unsigned operator = (const QString &type_name);
		virtual QString operator ~();
};

#endif 