cmake_minimum_required(VERSION 3.12)
project(220GroupProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoundMapTesting SoundMapTests.cpp ArraySoundMap.cpp Sound.cpp Util.cpp)
add_executable(QuizTesting PresetQuiz.cpp RandomQuiz.cpp ListOfWordsChanger.cpp ListOfWordsChanger.h)
add_executable(UtilTesting UtilTesting.cpp Util.cpp)