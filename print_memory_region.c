#include <stdio.h>

void print_hex_memory(void *mem, int len) {
	unsigned char *p = (unsigned char *)mem;
  
	int remainingOffset = len - ((len / 8) * 8);
	for(int i = 0; i < len / 8; i++){
		for(int j = 1; j <= 8; ++j){
			printf("0x%02X ", p[((i * 8) + j)-1]);
		}
		printf("\t\t");
		for(int j = 1; j <= 8; ++j){
			char copyBuff[] = {
				p[((i * 8) + j)-1],
				'\0'
			};
			// Escape special chars (\t, \n and zero byte with .)
			switch(copyBuff[0]){
				case 0x0A:
					copyBuff[0] = '.';
				case 0x09:
					copyBuff[0] = '.';
				case 0x00:
					copyBuff[0] = '.';
			}
			printf("%s ", copyBuff);
		}
		printf("\n");
	}


	for(int i = 0; i < remainingOffset; i++){
		printf("0x%02X ", p[(((len / 8) * 8) + i)]);
		// Calculate Pad
		for(int j = 0; j < (8 - remainingOffset); ++j){
			printf("\t");
		}

		char copyBuff[] = {
			p[(((len / 8) * 8) + i)],
			'\0'
		};
		// Escape special chars (\t, \n and zero byte with .)
		switch(copyBuff[0]){
			case 0x0A:
				copyBuff[0] = '.';
			case 0x09:
				copyBuff[0] = '.';
			case 0x00:
				copyBuff[0] = '.';
		}
		printf("%s ", copyBuff);
	}
	printf("\n");
}


int main(int argc, char** argv){
    char data[17] = {
        0x11,
        0x85,
        0xFF,
        0xAF,
        0x9F,
        0x8F,
        0x4F,
		0x79,
		

		0x84,
		0x74,
		0xf4,
		0x1f,
		0x82,
		0x17,
		0x14,
		0x54,

		0x9
    };

    print_hex_memory(&data, sizeof(data) / sizeof(data[0]));


}