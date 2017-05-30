#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	size_t len;
	uint8_t *raw;
} data_t;

volatile int fate;

void data_free(data_t* data) {
	if (data->raw != NULL) {
		free(data->raw);
	}
	free(data);
	data = NULL;
}

data_t* data_read() {
	data_t* data = malloc(sizeof(data_t));
	if (NULL == data) return NULL;
	data->len = 0;
	//data->raw = NULL;

	if (fate <= 0) {
		data_free(data);
		return NULL;
	}

	data->len = fate;
	data->raw = malloc(fate);

	return data;
}

int main(int argc, char** argv) {
	data_t *data = data_read();
	if ( data != NULL ) {
		printf("1. data_read succeeded: data len = %lu\n", data->len);
		data_free(data);
	} else {
		printf("1. data_read falied with fate = %d\n", fate);
	}

	fate = 256;
	data = data_read();
	if ( data != NULL ) {
		printf("2. data_read succeeded: data len = %lu\n", data->len);
		data_free(data);
	} else {
		printf("2. data_read falied with fate = %d\n", fate);
	}

	fate = 0;
	data = data_read();
	if ( data != NULL ) {
		printf("3. data_read succeeded: data len = %lu\n", data->len);
		data_free(data);
	} else {
		printf("3. data_read falied with fate = %d\n", fate);
	}

	return 0;
}
