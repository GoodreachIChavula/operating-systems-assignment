CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -pthread
TARGET = eduos

all: $(TARGET)

$(TARGET): main_sim.c process_manager.c
	$(CC) $(CFLAGS) main_sim.c process_manager.c -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o pcb_snapshot.json
