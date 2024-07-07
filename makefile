default:
	@/usr/bin/cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S/home/william/compiler/MyCompiler -B/home/william/compiler/MyCompiler/build -G Ninja
	@/usr/bin/cmake --build /home/william/compiler/MyCompiler/build --config Debug --target all --
run:
	@./build/MyCompiler
generate_run: default run
clean:
	@rm -rf ./out/*
test: bin
	@qemu-riscv64-static ./out/1_exe
	@echo [qemu-riscv64-static] code run complete, no errors!
dryrun:
	@qemu-riscv64-static ./out/1_exe
llvm:
	@cp ./demo/1 ./demo/1.c
	@clang -emit-llvm -c -S ./demo/1.c -o ./out/1.ll
	@echo [LLVM] llvm gen finished
arm:
	@cp ./demo/1 ./demo/1.c
	@clang -S -O3 -g0 -o out/1.asm demo/1.c --target=armv7a -mfloat-abi=soft
bin: run
	@cp ./demo/1 ./demo/1.c
	@riscv64-linux-gnu-gcc -static -g -o ./out/1_exe ./out/1_self.s ./demo/std.c
	@echo [riscv64-base-code-generator] code generate complete, no syntax error detected
verify:
	@cp ./demo/1 ./demo/1.c
	@gcc -o ./out/1_verify ./demo/std.c ./demo/1.c
	@./out/1_verify
