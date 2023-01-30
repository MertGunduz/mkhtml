add_executable(mkhtml mkhtml.c)

target_link_libraries(mkhtml mkgen mjson mkgenmessages)

# curf part
set( CURL_LIBRARY ${CMAKE_SOURCE_DIR}/lib )
set( CURL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
find_package( CURL )

include_directories( ${CURL_INCLUDE_DIRS} )
link_directories( ${CURL_LIBRARIES} )

target_link_libraries(mkhtml curl)