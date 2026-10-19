CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Wshadow
CPPFLAGS ?= -Iinclude -Iplatform/host
BUILD_DIR ?= build
SOURCES = src/sensor_service.c src/app.c platform/host/fake_sensor.c tests/test_main.c
TEST_BIN = $(BUILD_DIR)/test_automotive_c_demo
.PHONY: all test clean
all: test
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
$(TEST_BIN): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SOURCES) -o $@
test: $(TEST_BIN)
	./$(TEST_BIN)
clean:
	rm -rf $(BUILD_DIR)
