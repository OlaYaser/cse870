include_directories(.)
aux_source_directory(. SRC)

# Build executable
add_executable(pbs_demo WIN32 ${SRC} ${MOC} ${WINDOWS_RESOURCES})
qt5_use_modules(pbs_demo ${QT_DEPENDENCIES})
target_link_libraries(pbs_demo pbs ${PBS_LIBS} ${Qt5Core_QTMAIN_LIBRARIES})

# Install
install(TARGETS pbs_demo RUNTIME DESTINATION bin
                             BUNDLE DESTINATION .)
