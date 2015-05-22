# Introduction #

[Qt](Qt.md) comes with the **QMake** tool for handling cross platform building.

**Qmake** is specialized for use with [Qt](Qt.md) and has built-in features for working with [Qt](Qt.md) tools, such as a meta object compiler and UI designer.

However, there are other build systems available such as _autotools_, _SCons_ and _[CMake](CMake.md)_. All tools have some pros and cons, and choice is a matter of taste and additional requirements.

Here is some 'pros' for [CMake](CMake.md) build system:
  * is really portable
  * uses native build and develop tools for the target platform
  * can easily generate script for complex set of interrelated projects
  * unlike qmake, does not hide the additional steps of the project construction and makes it easy to look at the intermediate project files
  * work fine with native IDE such as MS Visual Studio
  * can be used in heterogeneous environment, not locked to the [Qt](Qt.md) world

# Example project #

Directory structure:
  * project\_directory
    * rel\_view
    * unit\_tests
    * build

The **'rel\_view'** project is a main part and should be built using intermediate library.

The **'unit\_tests'** project is built by linking with 'rel\_view' intermediate library.

[CMake](CMake.md) generate a lot of additional files and auxiliary subdirectories, so it would be good to place all of them into separate **'build'** directory.

The entire project may be downloaded as [QtCmakeMimimalProject.zip](http://relview.googlecode.com/files/QtCmakeMimimalProject.zip) (5kb).


# Top CMakeLists.txt file #

```

cmake_minimum_required (VERSION 2.8)

project (RELVIEW)

enable_testing()

add_subdirectory (rel_view ${CMAKE_CURRENT_BINARY_DIR}/rel_view)
add_subdirectory (unit_tests ${CMAKE_CURRENT_BINARY_DIR}/unit_tests)

```

Notes:
  * 'add\_subdirectory' instruct [CMake](CMake.md) to recurse specified subdirectory, and the second argument is need to place all build infrastructure in subdirs of 'build' directory
  * 'enable\_testing' prepares possibility of [CTest](CMake#CTest.md) usage

# Subdirectory rel\_view CMakeLists.txt file #

```
find_package (Qt4 REQUIRED QtCore QtGui QtXml)

set (EXENAME rel_view)
set (LIBNAME rel_view_lib)

set (HEADERS 
        mainwindow.h
    )

set (SOURCES 
        mainwindow.cpp
    )

set (FORMS
        mainwindow.ui
    )
    
qt4_wrap_cpp (MOC_SOURCES ${HEADERS})
qt4_wrap_ui (FORMS_HEADERS ${FORMS})

include (${QT_USE_FILE})

add_definitions (${QT_DEFINITIONS})

add_library (${LIBNAME} ${SOURCES} ${MOC_SOURCES} ${FORMS_HEADERS}) 

add_executable (${EXENAME} WIN32 main.cpp)

target_link_libraries (${EXENAME} ${LIBNAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY})

include_directories (. ${CMAKE_CURRENT_BINARY_DIR})
```


# Subdirectory unit\_tests CMakeLists.txt file #

```
find_package (Qt4 REQUIRED QtCore QtGui QtXml QtTest)

set (LIBNAME rel_view_lib)
set (LIBDIR rel_view)
set (EXENAME unit_tests)

set (HEADERS 
        test_mainwindow.h
    )

set (SOURCES 
        test_mainwindow.cpp
    )

include_directories (. ${RELVIEW_SOURCE_DIR}/${LIBDIR})

link_directories (${RELVIEW_BINARY_DIR}/${LIBDIR})

qt4_wrap_cpp (MOC_SOURCES ${HEADERS})

include (${QT_USE_FILE})

add_definitions (${QT_DEFINITIONS})

add_executable (${EXENAME} main.cpp ${SOURCES} ${MOC_SOURCES})

target_link_libraries (${EXENAME} ${LIBNAME} ${QT_LIBRARIES})

add_test(cpp ${EXENAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

```

# [CMake](CMake.md) call details #

Here is 'gensln.bat' script:
```

cd build
cmake -G "Visual Studio 9 2008" ..
cd ..
```

Notes:
  * [CMake](CMake.md) generate all scripts and build infrastructure at the _**current**_ directory, so 'cd' to target and call them
  * currently, [Qt](Qt.md) binary library for Windows available only for 'MS Visual Studio 2008', so script explicitly choose  appropriate cmake 'generator'
  * after the generation, into 'build' directory will be placed 'RELVIEW.sln' MS Visual Studio 2008 solution file