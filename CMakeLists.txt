cmake_minimum_required(VERSION 3.16) # Qt6 needs CMake 3.16+
project(BatteryIndicator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Put executables in build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Enable automatic handling of moc, uic, rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF) # currently not using .ui files
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Widgets)

set(QML_DIR "qml/")
set(SRC_DIR "src/")
set(RESOURCES_DIR "resources/")

add_executable(BatteryIndicator
    ${RESOURCES_DIR}resources.qrc
    ${SRC_DIR}main.cpp
    ${SRC_DIR}MainWindow.cpp
    ${SRC_DIR}MainWindow.h
)

# Order matters here, the target must exist before attaching a QML module to it.
set(plain_qml_files
    ${QML_DIR}Main.qml
    ${QML_DIR}BatteryIndicator.qml
)
set(qml_singletons
    #TBD
)
set_source_files_properties(${qml_singletons}
    PROPERTIES QT_QML_SINGLETON_TYPE TRUE)
qt_add_qml_module(BatteryIndicator
    URI com.BatteryIndicator
    VERSION 1.0
    QML_FILES
        ${plain_qml_files}
        ${qml_singletons}
)

target_link_libraries(BatteryIndicator PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::Widgets)
