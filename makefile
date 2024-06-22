default:
	@/usr/bin/cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S/home/william/compiler/MyCompiler -B/home/william/compiler/MyCompiler/build -G Ninja
	@/usr/bin/cmake --build /home/william/compiler/MyCompiler/build --config Debug --target all --
run:
	@./build/MyCompiler
generate_run: default run
clean:
	@rm -rf ./build
	@rm -rf ./out/*
test:
	@cp ./demo/1 ./demo/1.cpp
	@g++ ./demo/1.cpp -o ./out/1.exe
	@./out/1.exe