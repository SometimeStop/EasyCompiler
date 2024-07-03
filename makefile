default:
	@/usr/bin/cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S/home/william/compiler/MyCompiler -B/home/william/compiler/MyCompiler/build -G Ninja
	@/usr/bin/cmake --build /home/william/compiler/MyCompiler/build --config Debug --target all --
run: llvm
	@./build/MyCompiler
generate_run: default run
clean:
	@rm -rf ./build
	@rm -rf ./out/*
test:
	@g++ ./demo/test.cpp -o ./out/test.exe
	@./out/test.exe
llvm:
	@cp ./demo/1 ./demo/1.c
	@clang -emit-llvm -c -S ./demo/1.c -o ./out/1.ll
	@echo [LLVM] llvm gen finished
arm:
	@cp ./demo/1 ./demo/1.c
	@clang -S -O3 -g0 -o out/1.asm demo/1.c --target=armv7a -mfloat-abi=soft
bin:
	@cp ./demo/1 ./demo/1.c
	@arm-linux-gnueabi-gcc-12 -o out/1_arm.exe demo/1.c -march=armv7-a