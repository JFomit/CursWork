include("/home/jfomit/source/dev/qt/CursWork/OAiPCourseWorkSemester1/build/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/OAiPCourseWorkSemester1-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE /home/jfomit/source/dev/qt/CursWork/OAiPCourseWorkSemester1/build/OAiPCourseWorkSemester1
    GENERATE_QT_CONF
)
