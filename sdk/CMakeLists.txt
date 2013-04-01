include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB SRC *.cpp)
file(GLOB HEADERS *.h)

add_library(pbs ${SRC})
qt5_use_modules(pbs ${QT_DEPENDENCIES})
set_target_properties(pbs PROPERTIES
                                   DEFINE_SYMBOL PBS
                                   VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}
                                   SOVERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}
                                   LINK_INTERFACE_LIBRARIES ""
                                   AUTOMOC TRUE)

install(FILES ${HEADERS} DESTINATION include/pbs)
install(TARGETS pbs RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
