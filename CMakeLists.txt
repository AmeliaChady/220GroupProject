cmake_minimum_required(VERSION 3.12)
project(220GroupProject)

set(CMAKE_CXX_STANDARD 14)


add_executable(UserInterface UserInterface.cpp Util.cpp)

add_executable(SoundMapTesting SoundMapTests.cpp ArraySoundMap.cpp Sound.cpp Util.cpp)
add_executable(UtilTesting UtilTesting.cpp Util.cpp)
add_executable(QuestionTesting Question.cpp QuestionTesting.cpp ArrayList.inl ArraySoundMap.cpp ListOfWords.cpp Sound.cpp Util.cpp)
add_executable(QuizTesting RandomQuiz.cpp PresetQuiz.cpp)
