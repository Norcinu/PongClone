#ifndef SEG_STATES_H
#define SEG_STATES_H

#include <stdint.h>

#define DLLEXPORT __declspec(dllexport)

enum STATE_MODE {
	Unitialised = 0,
	Initialised,
	Running,
	CleaningUp,
	Finished
};


struct seg_state {
	uint8_t id;
	enum STATE_MODE mode;
};

DLLEXPORT int state_init_system();
DLLEXPORT void state_enter(struct seg_state* state);
DLLEXPORT void state_update(struct seg_state* state);
DLLEXPORT void state_exit(struct seg_state* state);


#endif
