cmake_minimum_required(VERSION 3.14)
project(AlgorithmWarehouse)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./src srclist)
aux_source_directory(./src/Tree treelist)
aux_source_directory(./src/TempAlg template)
aux_source_directory(./src/Graph graphlist)

add_executable(AlgorithmWarehouse main.cpp ${srclist} ${treelist} ${template} ${graphlist})
