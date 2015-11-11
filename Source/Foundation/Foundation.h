/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLDEPLUS_FOUNDATION_FOUNDATION_H
#define CLDEPLUS_FOUNDATION_FOUNDATION_H

#include "Enum/CommonBufferSize.h"

// Basic
#include "Column.h"
#include "Cell.h"
#include "Identity.h"
#include "Entity.h"
#include "EntityProxy.h"
#include "EntityMap.h"
#include "EntityStore.h"
#include "EntityQuery.h"
#include "EntitySourceDriver.h"

// Data
#include "Data/Value.h"
#include "Data/Primitive.h"
#include "Data/TypeEnums.h"
#include "Data/ValueFactory.h"
#include "Data/Comparer/Comparer.h"
#include "Data/Helper/TypeHelper.h"
#include "Data/Helper/ValueHelper.h"
#include "Data/Helper/PrimitiveHelper.h"

// Store
#include "Store/AbstractEntity.h"
#include "Store/Comparer/Comparer.h"
#include "Store/Helper/EntityOutputFormatter.h"

// Query
#include "Query/Query.h"
#include "Query/Helper/CriteriaHelper.h"
#include "Query/Helper/ProxyHelper.h"
#include "Query/Helper/SqlHelper.h"

// Excepti
#include "Exception/CLDEException.h"
#include "Exception/CLDEEntityException.h"
#include "Exception/CLDEEntityStoreRoutineException.h"
#include "Exception/CLDEDataSourceRoutineException.h"
#include "Exception/CLDENonSupportedDataTypeException.h"
#include "Exception/CLDENonSupportedFunctionException.h"

#endif //CLDEPLUS_FOUNDATION_FOUNDATION_H
