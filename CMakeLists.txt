#cmake_minimum_required(VERSION 3.10)
#project(fiveProjects)
## crud set cmake items set(SOURCE_FILE main.cpp Student.cpp)
##todo list set(SOURCE_FILE TaskSource.cpp  Task.cpp)
## book management 
#set(SOURCE_FILE BookManagement.cpp  Book.cpp)
#add_executable(hello ${SOURCE_FILE})
cmake_minimum_required(VERSION 3.16)

project(mongo_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MONGO_CXX_DIR "C:/mongo-cxx-driver-install")
set(MONGO_C_DIR "C:/mongo-c-driver-install")

# افزودن مسیرهای include
include_directories(
    ${MONGO_CXX_DIR}/include
    ${MONGO_C_DIR}/include
)

# افزودن مسیرهای کتابخانه‌ها
link_directories(
    ${MONGO_CXX_DIR}/lib
    ${MONGO_C_DIR}/lib
)

# پیدا کردن Boost
set(BOOST_ROOT "C:/Program Files/boost/boost_1_87_0")
set(Boost_NO_SYSTEM_PATHS ON)
find_package(Boost REQUIRED)

# افزودن مسیرهای Boost
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_PREFIX_PATH "C:/mongo-cxx-driver-install/lib/cmake")

# افزودن فایل اصلی پروژه
add_executable(mongo_test main.cpp)
include_directories(
    C:/mongo-cxx-driver-install/include
    C:/mongo-cxx-driver-install/include/mongocxx/v_noabi
    C:/mongo-cxx-driver-install/include/bsoncxx/v_noabi
    C:/mongo-c-driver-install/include
)
link_directories(
    C:/mongo-cxx-driver-install/lib
    C:/mongo-c-driver-install/lib
)


# لینک کردن کتابخانه‌های mongocxx و bsoncxx
target_link_libraries(mongo_test
    mongocxx-v_noabi-rhb-x64-v142-md
    bsoncxx-v_noabi-rhb-x64-v142-md
)


# target_link_libraries(mongo_test Boost::boost)




