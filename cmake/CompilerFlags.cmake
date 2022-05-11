
if (CMAKE_CXX_COMPILER_ID MATCHES "AppleClang")
    add_compile_options(-Wall -Wextra -pedantic)
    set(
        PER_TARGET_COMPILE_FLAGS
        -Wcast-qual
        -Wconversion
        -Wdisabled-optimization
        -Winline
        -Wmissing-field-initializers
        -Wmissing-noreturn
        -Wredundant-decls
        -Wunreachable-code
        -Wfloat-equal
        -Winit-self
        -Wuninitialized
        -Wshadow
        -Wmissing-include-dirs
        -Wmissing-format-attribute
        -Wswitch
        -fPIC
    )
endif()

macro(add_compiler_diagnostics project_name)
    target_compile_options(
        ${project_name}
        PRIVATE
        "$<$<CONFIG:DEBUG>:${PER_TARGET_COMPILE_FLAGS}>"
        "$<$<CONFIG:RELEASE>:${PER_TARGET_COMPILE_FLAGS}>"
    )
endmacro()
