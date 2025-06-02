cmake_minimum_required(VERSION 3.19)
project(OAiPCourseWorkSemester1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)

qt_standard_project_setup()

qt_add_resources(RES_FILES "ImgFile.qrc")

qt_add_executable(OAiPCourseWorkSemester1
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    mylayout.h mylayout.cpp
    myserver.h myserver.cpp
    mainplayer.h mainplayer.cpp mainplayer.ui
    paintscene.h paintscene.cpp
    workwithpixmap.h workwithpixmap.cpp
    clientplayer.h clientplayer.cpp clientplayer.ui
    myloginmeniu.h myloginmeniu.cpp myloginmeniu.ui
    writepuzzle.h writepuzzle.cpp writepuzzle.ui


)

target_sources(OAiPCourseWorkSemester1 PRIVATE ${RES_FILES})

target_link_libraries(OAiPCourseWorkSemester1
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)

include(GNUInstallDirs)

install(TARGETS OAiPCourseWorkSemester1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET OAiPCourseWorkSemester1
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
