//
// Created by LE, Duc Anh on 7/7/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_FOUNDATION_H
#define CLOUD_E_PLUS_FOUNDATION_FOUNDATION_H

#include "Foundation/Enum/CommonBufferSize.h"

// Basic
#include "Foundation/Column.h"
#include "Foundation/Cell.h"
#include "Foundation/Identity.h"
#include "Foundation/Entity.h"
#include "Foundation/EntityProxy.h"
#include "Foundation/EntityMap.h"
#include "Foundation/EntityLoader.h"
#include "Foundation/EntityStore.h"
#include "Foundation/EntityQuery.h"
#include "Foundation/EntitySourceDriver.h"

// Data
#include "Foundation/Data/Data.h"
#include "Foundation/Data/Comparer/Comparer.h"
#include "Foundation/Data/Helper/TypeHelper.h"
#include "Foundation/Data/Helper/ValueHelper.h"
#include "Foundation/Data/ValueToPrimatives.hpp"

// Store
#include "Foundation/Store/AbstractEntity.h"
#include "Foundation/Store/Comparer/Comparer.h"
#include "Foundation/Store/Extra/EntityOutputFormatter.h"

// Query
#include "Foundation/Query/Query.h"
#include "Foundation/Query/Helper/CriteriaHelper.h"
#include "Foundation/Query/Helper/ProxyHelper.h"
#include "Foundation/Query/Helper/SqlHelper.h"

// Exception
#include "Foundation/Exception/cldeException.h"
#include "Foundation/Exception/cldeEntityException.h"
#include "Foundation/Exception/cldeEntityStoreRoutineException.h"
#include "Foundation/Exception/cldeDataSourceRoutineException.h"
#include "Foundation/Exception/cldeNonSupportedDataTypeException.h"
#include "Foundation/Exception/cldeNonSupportedFunctionException.h"

#endif //CLOUD_E_PLUS_FOUNDATION_FOUNDATION_H
