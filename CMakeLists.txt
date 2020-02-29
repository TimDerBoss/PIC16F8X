cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include("cmake/HunterGate.cmake")
HunterGate(
	URL "https://github.com/ruslo/hunter/archive/v0.23.51.tar.gz"
	SHA1 "d6f582a4d127af6ac01d9be842636da3935043d4"
	LOCAL
)

project(PIC18)

set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.
add_executable(PIC18 main.cpp LSTParser.cpp InstructionBase.cpp RegisterData.cpp Instructions.cpp InstructionHandler.cpp CPU.cpp)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

hunter_add_package(wxWidgets)
find_package(wxWidgets REQUIRED core base)


include(${wxWidgets_USE_FILE})
target_link_libraries(PIC18 fmt::fmt ${OpenGlLinkers} ${wxWidgets_LIBRARIES})
