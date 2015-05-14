#include <iostream>
#include "Architecture/Foundation/Column.h"
#include "Architecture/Foundation/Identity.h"

using namespace std;
using namespace Cloude::Architecture::Foundation;

int main() {

	Column colId("Id", "_id", DbType::Int64);
	Column colName("Name", "name", DbType::String);

	int itemId = 15;
	string name = "Duc-Anh";

	Field Id(colId, &itemId);
	Field Name(colName, &name);

	Identity ident{ &Id, &Name };

	auto fldsMap = ident.FieldsMap();
	auto fldId = (const Field *)fldsMap["Id"];
	auto fldName = (const Field *)fldsMap["Name"];

	cout << *((int *)fldId->getValue()) << " is " << *((string *)fldName->getValue()) << endl;

	return 0;
};