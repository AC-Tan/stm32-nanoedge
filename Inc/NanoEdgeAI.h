/* =============
Copyright (c) 2021, STMicroelectronics

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other materials provided with the distribution.

* Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
  products derived from this software without specific prior written permission.

*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER / OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*
*/

#ifndef __NANOEDGEAI_H__
#define __NANOEDGEAI_H__

/* Includes */
#include <stdint.h>

/* Define */
#define NEAI_ID "63d5f4229e2c80ba76150b56"
#define AXIS_NUMBER 3
#define DATA_INPUT_USER 512
#define CLASS_NUMBER 2

#ifndef __NEAI_STATE__
#define __NEAI_STATE__
enum neai_state { 
    NEAI_OK = 0,
    NEAI_INIT_FCT_NOT_CALLED = 123,
    NEAI_BOARD_ERROR,
    NEAI_KNOWLEDGE_BUFFER_ERROR,
    NEAI_NOT_ENOUGH_CALL_TO_LEARNING, //This is a fail-safe to prevent users from learning one or even no signals.
    NEAI_MINIMAL_RECOMMENDED_LEARNING_DONE,
    NEAI_UNKNOWN_ERROR};
#endif
/* Function prototypes */
#ifdef __cplusplus
extern "C" {
#endif
	enum neai_state neai_classification_init(const float knowledge_buffer[]);
	enum neai_state neai_classification(uint16_t input_buffer[], uint16_t output_buffer[], uint16_t *id_class);
#ifdef __cplusplus
}
#endif

#endif

/* =============
Here some sample declaration added in your main program for the use of the NanoEdge AI library.
You can directly copy these declarations or modify the names.
* WARNING: respect the sizes of the different buffers.

uint16_t id_class = 0; // Point to id class (see argument of neai_classification fct)
float input_user_buffer[DATA_INPUT_USER * AXIS_NUMBER]; // Buffer of input values
float output_class_buffer[CLASS_NUMBER]; // Buffer of class probabilities
const char *id2class[CLASS_NUMBER + 1] = { // Buffer for mapping class id to class name
	"unknown",
	"Stable",
	"Move",
};
*/

