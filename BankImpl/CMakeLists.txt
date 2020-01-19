cmake_minimum_required(VERSION 3.13)
project(BankImpl)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Boost_tests)
add_subdirectory(BankImpl_lib)
add_executable(BankImpl main.cpp BankImpl_lib/Data.cpp BankImpl_lib/KontoBankowe.cpp BankImpl_lib/Kredyt.cpp BankImpl_lib/Lokata.cpp BankImpl_lib/Osoba.cpp BankImpl_lib/Pracownik.cpp BankImpl_lib/Przelew.cpp BankImpl_lib/Uzytkownik.cpp BankImpl_lib/ZlecenieStale.cpp)
