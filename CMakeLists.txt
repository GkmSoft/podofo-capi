#
# PoDoFo Capi provides C API for PoDoFo C++ library
# Copyright (C) 2006 by Dominik Seichter
# domseichter@web.de
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU Library General Public License as
# published by the Free Software Foundation; either version 2 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Library General Public
# License along with this program; if not, write to the
# Free Software Foundation, Inc.,
# 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
# In addition, as a special exception, the copyright holders give
# permission to link the code of portions of this program with the
# OpenSSL library under certain conditions as described in each
# individual source file, and distribute linked combinations
# including the two.
# You must obey the GNU General Public License in all respects
# for all of the code used other than OpenSSL.  If you modify
# file(s) with this exception, you may extend this exception to your
# version of the file(s), but you are not obligated to do so.  If you
# do not wish to do so, delete this exception statement from your
# version.  If you delete this exception statement from all source
# files in the program, then also delete it here.
#

project(podofo_capi)

cmake_minimum_required(VERSION 2.8)

find_package(PythonInterp 3.4 REQUIRED)
find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

add_definitions(-DPODOFO_HAVE_OPENSSL)

set(PODOFO_INCLUDE_DIR "" CACHE PATH "Include directory for PoDoFo library")
set(PODOFO_LIBRARY_DEBUG "" CACHE FILEPATH "Path to PoDoFo debug library")
set(PODOFO_LIBRARY_RELEASE "" CACHE FILEPATH "Path to PoDoFo release library")

set(FREETYPE_INCLUDE_DIR "" CACHE PATH "Include directory for Freetype library")
set(FREETYPE_LIBRARY_RELEASE "" CACHE FILEPATH "Path to Freetype release library")

set(PNG_INCLUDE_DIR "" CACHE PATH "Include directory for Png library")
set(PNG_LIBRARY_RELEASE "" CACHE FILEPATH "Path to Png release library")

set(Z_INCLUDE_DIR "" CACHE PATH "Include directory for Z library")
set(Z_LIBRARY_RELEASE "" CACHE FILEPATH "Path to Z release library")

set(XML2_INCLUDE_DIR "" CACHE PATH "Include directory for XML library")
set(XML2_LIBRARY_RELEASE "" CACHE FILEPATH "Path to XML release library")

set(FONTCONFIG_INCLUDE_DIR "" CACHE PATH "Include directory for Fontconfig library")
set(FONTCONFIG_LIBRARY_RELEASE "" CACHE FILEPATH "Path to Fontconfig release library")

set(OPENSSL_INCLUDE_DIR "" CACHE PATH "Include directory for openssl library")
set(OPENSSL_LIBRARY_RELEASE "" CACHE FILEPATH "Path to openssl release library")

if(NOT PODOFO_INCLUDE_DIR OR NOT (PODOFO_LIBRARY_DEBUG OR PODOFO_LIBRARY_RELEASE))
  message(FATAL_ERROR "PoDoFo library is not found. Please specify exact pathes to PoDoFo library.")
endif()

include_directories(
  ${podofo_capi_SOURCE_DIR}/src/
  ${PODOFO_INCLUDE_DIR}
  ${FREETYPE_INCLUDE_DIR}
  ${PNG_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}/
  ${boost_shared_ptr_SOURCE_DIR}/source/
)

add_subdirectory(examples)

add_library(podofo_capi SHARED
  ${podofo_capi_SOURCE_DIR}/src/AutoGenWrap.cpp
)

target_link_libraries(podofo_capi debug ${PODOFO_LIBRARY_DEBUG} optimized ${PODOFO_LIBRARY_RELEASE})
target_link_libraries(podofo_capi optimized ${FREETYPE_LIBRARY_RELEASE})
target_link_libraries(podofo_capi optimized ${PNG_LIBRARY_RELEASE})
target_link_libraries(podofo_capi optimized ${FONTCONFIG_LIBRARY_RELEASE})
target_link_libraries(podofo_capi optimized ${Z_LIBRARY_RELEASE})
target_link_libraries(podofo_capi optimized ${XML2_LIBRARY_RELEASE})
target_link_libraries(podofo_capi optimized ${OPENSSL_LIBRARY_RELEASE})

find_file(BCAPI_SCRIPT Capi.py PATHS ${podofo_capi_SOURCE_DIR}/bcapi/source/ NO_DEFAULT_PATH)

if(NOT BCAPI_SCRIPT)
  message(FATAL_ERROR "Beautiful-capi component is not found. Please update git submodules.")
endif()

add_custom_command(
  OUTPUT
    ${podofo_capi_SOURCE_DIR}/src/AutoGenWrap.cpp
  COMMAND
    ${PYTHON_EXECUTABLE}
    ${podofo_capi_SOURCE_DIR}/bcapi/source/Capi.py
    -i ${podofo_capi_SOURCE_DIR}/src/podofo.xml
    -p ${podofo_capi_SOURCE_DIR}/src/podofo_params.xml
    -o ${podofo_capi_SOURCE_DIR}/include
    -s ${podofo_capi_SOURCE_DIR}/src/snippets
    -w ${podofo_capi_SOURCE_DIR}/src/AutoGenWrap.cpp
  MAIN_DEPENDENCY
    ${podofo_capi_SOURCE_DIR}/src/podofo.xml
  DEPENDS
    ${podofo_capi_SOURCE_DIR}/src/podofo_params.xml
  WORKING_DIRECTORY
    ${podofo_capi_SOURCE_DIR}/bcapi/source/
)
