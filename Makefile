CXX=g++
GNU=-std=gnu++11
headers=headers/
src=sources/
obj=obj/
projet=dev

${projet} : ${obj}main.o ${obj}Motor.o
	${CXX} ${GNU} -o ${projet} -g ${obj}main.o ${obj}Motor.o

${obj}main.o : ${src}main.cpp
	${CXX} ${GNU} -o ${obj}main.o -c ${src}main.cpp

${obj}Motor.o : ${src}Motor.cpp ${headers}Motor.hpp
	${CXX} ${GNU} -o ${obj}Motor.o -c ${src}Motor.cpp

clean:
	rm -f ${obj}*
mrproper: clean
	rm ./${projet}
