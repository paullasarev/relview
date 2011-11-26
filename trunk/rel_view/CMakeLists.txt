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
