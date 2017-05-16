# This is not a full standalone CMake configuration for the hello world
# example.
#
# To build it outside the PoDoFo source tree, you must set your build system
# make the PoDoFo headers available and must link to the PoDoFo library
# and any libraries it depends on (see the README,
#     "5. Using PoDoFo in Your Application") .
#
# Note that you don't need the headers for PoDoFo's dependencies in your
# header search path.

project(helloworld)

ADD_EXECUTABLE(helloworld 
    helloworld.cpp
)

include_directories(
    ${podofo_capi_SOURCE_DIR}/../include/
    ${helloworld_SOURCE_DIR}/../../include/
)

add_dependencies(helloworld podofo_capi)
target_link_libraries(helloworld podofo_capi)