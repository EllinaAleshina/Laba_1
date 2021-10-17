cmake_minimum_required(VERSION 3.5)

project(elllinaaa)

add_executable(elllinaaa main.cpp textOperation.h stack.h textControl.h UI.h MainWindow.cpp MainWindow.h stackElementParent.h form.ui)
# CMAKE
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Qt
set(QT_VERSION 5)
set(QT_LIB Qt${QT_VERSION})
set(QT_COMPONENTS Widgets Multimedia MultimediaWidgets)
set(QT_LIBS ${QT_COMPONENTS})
LIST(TRANSFORM QT_LIBS PREPEND ${QT_LIB}::)
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    string(TOLOWER "platforms/q${CMAKE_SYSTEM_NAME}d${CMAKE_SHARED_LIBRARY_SUFFIX}" QT_PLUGINS)
else ()
    string(TOLOWER "platforms/q${CMAKE_SYSTEM_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}" QT_PLUGINS)
endif ()

find_package(${QT_LIB} COMPONENTS ${QT_COMPONENTS} REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS UI)
set(CMAKE_AUTORCC ON)
