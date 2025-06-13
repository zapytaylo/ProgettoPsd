# Compilatore e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# File sorgenti
SRC = main.c attivita.c
HEADERS = attivita.h
TARGET = gestione_studio

# File per testing
TEST_RUNNER_SRC = test_runner.c
TEST_RUNNER_EXE = test_runner
TEST_INPUT = input.txt
EXPECTED_OUTPUT = oracolo.txt
ACTUAL_OUTPUT = output.txt

# Regola principale
all: $(TARGET)

# Compila il programma principale
$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Compila il test runner
$(TEST_RUNNER_EXE): $(TEST_RUNNER_SRC)
	$(CC) $(CFLAGS) -o $(TEST_RUNNER_EXE) $(TEST_RUNNER_SRC)

# Esegui i test
test: $(TARGET) $(TEST_RUNNER_EXE)
	./$(TEST_RUNNER_EXE)

# Rimuove i file compilati e temporanei
clean:
	rm -f $(TARGET) $(TEST_RUNNER_EXE) $(ACTUAL_OUTPUT)

.PHONY: all test clean