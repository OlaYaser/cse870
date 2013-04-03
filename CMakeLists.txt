project(pbs)
cmake_minimum_required(VERSION 2.8.9)

# Find Qt
set(QT_DEPENDENCIES Concurrent Core Gui Network Sql Svg Widgets Xml Multimedia)
foreach(QT_DEPENDENCY ${QT_DEPENDENCIES})
  find_package(Qt5${QT_DEPENDENCY})
endforeach()
set(PBS_LIBS ${Qt5Core_QTMAIN_LIBRARIES})

include_directories(${CMAKE_SOURCE_DIR}/sdk/)

# Build library
add_subdirectory(sdk)

# Build applications
add_subdirectory(app)

# Package
set(CPACK_BINARY_BUNDLE       OFF)
set(CPACK_BINARY_DEB          OFF)
set(CPACK_BINARY_DRAGNDROP    OFF)
set(CPACK_BINARY_NSIS         OFF)
set(CPACK_BINARY_OSXX11       OFF)
set(CPACK_BINARY_PACKAGEMAKER OFF)
set(CPACK_BINARY_RPM          OFF)
set(CPACK_BINARY_STGZ         OFF)
set(CPACK_BINARY_TBZ2         OFF)
set(CPACK_BINARY_TGZ          OFF)
set(CPACK_BINARY_TZ           OFF)
set(CPACK_BINARY_ZIP          OFF)
set(CPACK_SOURCE_TGZ          OFF)
set(CPACK_SOURCE_TZ           OFF)
set(CPACK_SOURCE_ZIP          OFF)

if(CMAKE_HOST_WIN32)
  set(CPACK_BINARY_ZIP ON)
  set(CPACK_BINARY_NSIS ON)

  # NSIS
  set(CPACK_NSIS_MODIFY_PATH ON)
  set(CPACK_NSIS_MUI_ICON ${NATIVE_ICON})
  set(CPACK_NSIS_MUI_UNIICON ${NATIVE_ICON})
  if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
    set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
  endif()
elseif(CMAKE_HOST_APPLE)
  set(CPACK_BINARY_TBZ2 ON)
  set(CPACK_BINARY_BUNDLE ON)

  #set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_BINARY_DIR}/README.txt")

  set(CPACK_BUNDLE_NAME ${CPACK_PACKAGE_NAME})
  set(CPACK_BUNDLE_ICON ${NATIVE_ICON})
  set(CPACK_BUNDLE_PLIST ${CMAKE_CURRENT_BINARY_DIR}/Info.plist)
  set(CPACK_BUNDLE_STARTUP_COMMAND ${BR_SHARE_DIR}/bundle.sh)
else()
  set(CPACK_BINARY_TBZ2 ON)
  set(CPACK_BINARY_DEB ON)

endif()

include(CPack)
