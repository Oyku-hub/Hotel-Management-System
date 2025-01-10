# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QTHotel_Management_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QTHotel_Management_autogen.dir\\ParseCache.txt"
  "QTHotel_Management_autogen"
  )
endif()
