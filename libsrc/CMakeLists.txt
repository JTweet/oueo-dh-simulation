add_library(dh dh.cpp ${HEADER_LIST})
target_include_directories(dh PUBLIC ../include)

add_library(gmp STATIC IMPORTED)
set_target_properties(gmp PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/gmp/lib/libgmp.a"
)

add_library(sodium STATIC IMPORTED)
set_target_properties(sodium PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libsodium/lib/libsodium.a"
)

target_link_libraries(dh PUBLIC gmp sodium)
