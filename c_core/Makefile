all:
	gcc -Wall -Wextra -std=c11 main_sim.c process_manager.c -o eduos

race:
	gcc thread_demo_race.c -o race_demo -lpthread

fixed:
	gcc thread_demo_fixed.c -o fixed_demo -lpthread

clean:
	del /Q *.exe
