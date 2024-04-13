all:
	clang -c -g -fsanitize=address -Wall src/glad.c -o src/glad.o
	clang++ -c -g -fsanitize=address -Wall \
		src/main.cpp -o src/main.o
	clang++ -fsanitize=address -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl \
		src/*.o -o src/main
run:
	./src/main
