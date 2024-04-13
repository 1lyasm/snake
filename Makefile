all:
	clang++ -g -fsanitize=address -Weverything \
		-lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl \
		src/main.cpp -o main
run:
	./main
