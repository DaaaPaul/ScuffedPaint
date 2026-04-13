#include <iostream>
#include "MiniFB.h"

int main() {
    mfb_window* window = mfb_open_ex("my display", 800, 600, MFB_WF_RESIZABLE);
    if (window == NULL) {
		return -1;
	}

    uint32_t* buffer = reinterpret_cast<uint32_t*>(malloc(800 * 600 * 4));

    mfb_update_state state;
    do {
        // TODO: add some fancy rendering to the buffer of size 800 * 600
		for(int i = 0; i < 800 * 600; i++) {
			buffer[i] = MFB_RGB(255, 0, 0);
		}

        state = mfb_update_ex(window, buffer, 800, 600);

        if (state != MFB_STATE_OK)
            break;
    } while(mfb_wait_sync(window));

    free(buffer);
    buffer = NULL;
    window = NULL;

	return 0;
}