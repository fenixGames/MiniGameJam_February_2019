cmake_minimum_required (VERSION 3.10)

SET(PROJECT_NAME MiniGame_Jam_February_2019)
project (${PROJECT_NAME})

set (CMAKE_CXX_STANDARD 11)
SET(
	SOURCES 
		main.cpp
		src/node.cpp
		src/window.cpp
		src/exceptions.cpp
		src/scene.cpp
		src/viewport.cpp
		src/events/event_handler.cpp
		src/score.cpp
		src/raccoon.cpp
		src/slot.cpp
		src/physics/geometry.cpp
		src/graphics/sprite.cpp
		src/graphics/text.cpp
		src/graphics/graphic.cpp
)
SET(INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
if (WIN32)
	include_directories("C:/SDL2/include" "C:/SDL2-Image/include" "C:/SDL2_ttf/include")
	find_library(SDL2_LIBRARY SDL2 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	find_library(SDL2_MAIN_LIBRARY SDL2main PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	find_library(SDL2_IMAGE_LIBRARY SDL2_image PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	find_library(SDL2_TTF_LIBRARY SDL2_ttf PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	set(DLL_INSTALLED_LIBS 
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2_image.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2_ttf.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libfreetype-6.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libjpeg-9.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libpng16-16.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/libtiff-5.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/zlib1.dll"
	)

else (WIN32)
	set(DLL_INSTALLED_LIBS "")
	include_directories("/usr/include" "/usr/local/include" "/usr/local/include/SDL2")
	find_library(SDL2_LIBRARY SDL2 PATHS "/lib" "/usr/lib" "/usr/local/lib")
	find_library(SDL2_MAIN_LIBRARY SDL2main PATHS "/lib" "/usr/lib" "/usr/local/lib")
	find_library(SDL2_IMAGE_LIBRARY SDL2_image PATHS "/lib" "/usr/lib" "/usr/local/lib")

endif (WIN32)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL2_MAIN_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL2_TTF_LIBRARY})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
INSTALL(FILES ${DLL_INSTALLED_LIBS} DESTINATION ${INSTALL_DIR})
INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION ${INSTALL_DIR})
