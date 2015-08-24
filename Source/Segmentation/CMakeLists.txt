cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(segmentation STATIC
        Join/TInner.hpp
        Join/TCross.hpp
        Join/TLeft.hpp
        Join/TRight.hpp
        Join/TFull.hpp
        Transformation/EntityTransformer.cpp
        Transformation/EntityTransformer.h
        Transformation/CellTransformer.cpp
        Transformation/CellTransformer.h
        Transformation/TypeCaster.cpp
        Transformation/TypeCaster.h
        Transformation/Caster/DoubleCaster.cpp
        Transformation/Caster/DoubleCaster.h
        Transformation/Caster/Int64Caster.cpp
        Transformation/Caster/Int64Caster.h
        Transformation/Caster/Int32Caster.cpp
        Transformation/Caster/Int32Caster.h
        Transformation/Caster/FloatCaster.cpp
        Transformation/Caster/FloatCaster.h
        Transformation/Caster/Int16Caster.cpp
        Transformation/Caster/Int16Caster.h
        Transformation/Caster/UInt16Caster.cpp
        Transformation/Caster/UInt16Caster.h
        Transformation/Caster/UInt32Caster.cpp
        Transformation/Caster/UInt32Caster.h
        Transformation/Caster/UInt64Caster.cpp
        Transformation/Caster/UInt64Caster.h
        Transformation/Caster/BooleanCaster.cpp
        Transformation/Caster/BooleanCaster.h
        Transformation/Caster/ByteCaster.cpp
        Transformation/Caster/ByteCaster.h
        Transformation/Caster/StringCaster.cpp
        Transformation/Caster/StringCaster.h
        Transformation/Caster/VarCharCaster.cpp
        Transformation/Caster/VarCharCaster.h
        Exception/SegmentationException.cpp
        Exception/SegmentationException.h
        Exception/TransformationException.cpp
        Exception/TransformationException.h
        CasterFactory.cpp
        CasterFactory.h
        Segmentation.h
)