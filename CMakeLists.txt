cmake_minimum_required (VERSION 3.12)
project (RandomPrintWithAsio)
add_executable (AsioPrintRandom
	main.cpp
	Printer.cpp
        Printer.hpp
)

target_include_directories (AsioPrintRandom PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries (AsioPrintRandom ws2_32 wsock32)
