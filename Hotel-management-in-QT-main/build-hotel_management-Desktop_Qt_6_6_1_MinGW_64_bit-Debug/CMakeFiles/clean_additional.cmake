# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\hotel_management_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hotel_management_autogen.dir\\ParseCache.txt"
  "hotel_management_autogen"
  )
endif()
