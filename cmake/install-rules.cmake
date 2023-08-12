install(
    TARGETS drogon_init_exe
    RUNTIME COMPONENT drogon_init_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
