#include <stdio.h>

// Define the possible states using an enum
typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_STOPPED,
    STATE_ERROR
} State;

// Define the possible events using an enum
typedef enum {
    EVENT_START,
    EVENT_STOP,
    EVENT_RESET,
    EVENT_ERROR_OCCURED
} Event;

// Function to handle state transitions and state-specific behavior
void handle_event(State *current_state, Event event) {
    switch (*current_state) {
        case STATE_IDLE:
            if (event == EVENT_START) {
                printf("Starting...\n");
                *current_state = STATE_RUNNING;
            } else if (event == EVENT_ERROR_OCCURED) {
                printf("Error occurred in idle state\n");
                *current_state = STATE_ERROR;
            }
            break;

        case STATE_RUNNING:
            if (event == EVENT_STOP) {
                printf("Stopping...\n");
                *current_state = STATE_STOPPED;
            } else if (event == EVENT_ERROR_OCCURED) {
                printf("Error occurred in running state\n");
                *current_state = STATE_ERROR;
            }
            break;

        case STATE_STOPPED:
            if (event == EVENT_RESET) {
                printf("Resetting...\n");
                *current_state = STATE_IDLE;
            } else if (event == EVENT_ERROR_OCCURED) {
                printf("Error occurred in stopped state\n");
                *current_state = STATE_ERROR;
            }
            break;

        case STATE_ERROR:
            if (event == EVENT_RESET) {
                printf("Resetting from error...\n");
                *current_state = STATE_IDLE;
            }
            break;

        default:
            printf("Invalid state\n");
            break;
    }
}

int main() {
    State current_state = STATE_IDLE;

    handle_event(&current_state, EVENT_START);
    handle_event(&current_state, EVENT_STOP);
    handle_event(&current_state, EVENT_ERROR_OCCURED);
    handle_event(&current_state, EVENT_RESET);

    return 0;
}
