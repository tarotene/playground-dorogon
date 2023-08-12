install(
    TARGETS cmake_init_exe
    RUNTIME COMPONENT cmake_init_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
