cmake_minimum_required(VERSION 3.12)
project(HelloWorldPrinter
    VERSION 1.0.0
    DESCRIPTION "C++ library that prints 'hello world 1326!'"
    LANGUAGES CXX
)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Опции сборки
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_EXAMPLES "Build example programs" ON)
option(BUILD_TESTS "Build tests" ON)
option(INSTALL_HEADERS "Install header files" ON)

# Настройка выходных директорий
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Основная библиотека
add_library(helloprinter 
    src/helloprinter.cpp
)

# Заголовочные файлы библиотеки
target_include_directories(helloprinter
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Свойства библиотеки
set_target_properties(helloprinter PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "include/helloprinter.h"
)

# Примеры
if(BUILD_EXAMPLES)
    add_executable(example examples/example.cpp)
    target_link_libraries(example helloprinter)
    set_target_properties(example PROPERTIES OUTPUT_NAME "helloprinter_example")
    
    # Дополнительный пример
    add_executable(simple_example examples/simple.cpp)
    target_link_libraries(simple_example helloprinter)
endif()

# Тесты
if(BUILD_TESTS)
    enable_testing()
    
    add_executable(test_helloprinter tests/test_helloprinter.cpp)
    target_link_libraries(test_helloprinter helloprinter)
    
    add_test(NAME helloprinter_test COMMAND test_helloprinter)
    
    # Конфигурация для Catch2 или Google Test (опционально)
    # find_package(GTest REQUIRED)
    # target_link_libraries(test_helloprinter GTest::gtest GTest::gtest_main)
endif()

# Установка
if(INSTALL_HEADERS)
    include(GNUInstallDirs)
    
    install(TARGETS helloprinter
        EXPORT helloprinter-targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
    
    # Установка заголовочных файлов
    install(DIRECTORY include/ 
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h"
    )
    
    # Установка примеров
    if(BUILD_EXAMPLES)
        install(TARGETS example simple_example
            DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
    endif()
    
    # Экспорт для find_package
    install(EXPORT helloprinter-targets
        FILE helloprinter-config.cmake
        NAMESPACE helloprinter::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/helloprinter
    )
    
    # Конфигурационный файл для find_package
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/helloprinter-config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/helloprinter-config.cmake
        @ONLY
    )
endif()

# Конфигурация для CPack
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_CONTACT "infdevscope <splqrinfdev@gmail.com>")
set(CPACK_PACKAGE_VENDOR "HelloWorldPriter Contributors")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
include(CPack)

