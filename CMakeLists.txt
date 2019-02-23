cmake_minimum_required (VERSION 3.10)
project (Werewolves_vs_Vampires)

set (CMAKE_CXX_STANDARD 11)
SET(
	SOURCES 
		main.cpp
		src/node.cpp
		src/window.cpp
		src/exceptions.cpp
		src/scene.cpp
		src/viewport.cpp
		src/event_handler.cpp
		src/piece.cpp
		src/physics/geometry.cpp
		src/graphics/sprite.cpp
		src/graphics/graphic.cpp
)
SET(INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
if (WIN32)
	include_directories("C:/SDL2/include" "C:/SDL2-Image/include")
	find_library(SDL2_LIBRARY SDL2 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	find_library(SDL2_MAIN_LIBRARY SDL2main PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	find_library(SDL2_IMAGE_LIBRARY SDL2_image PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libSDL2")
	set(DLL_INSTALLED_LIBS 
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2.dll"
		"${CMAKE_CURRENT_SOURCE_DIR}/libSDL2/SDL2_image.dll"
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

add_executable(Werewolves_vs_Vampires ${SOURCES})
target_link_libraries(Werewolves_vs_Vampires ${SDL2_LIBRARY})
target_link_libraries(Werewolves_vs_Vampires ${SDL2_MAIN_LIBRARY})
target_link_libraries(Werewolves_vs_Vampires ${SDL2_IMAGE_LIBRARY})

INSTALL(TARGETS Werewolves_vs_Vampires DESTINATION ${INSTALL_DIR})
INSTALL(FILES ${DLL_INSTALLED_LIBS} DESTINATION ${INSTALL_DIR})
INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION ${INSTALL_DIR})