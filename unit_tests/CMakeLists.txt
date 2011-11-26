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
