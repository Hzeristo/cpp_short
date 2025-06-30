To build this project, you need Qt on your computer
For Windows users, you need to excute scripts like the following:
(you need to change the path according to your own set)
$env:CMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"
cmake -B build -S .
cmake --build build  

For Linux users, you need to excute scripts like the following:
(you need to change the path according to your own set)
export CMAKE_PREFIX_PATH=/opt/Qt/6.5.0/gcc_64
cmake -B build -S .
cmake --build build

