/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_ATMEL_SAMD_PERIPHERALS_EXTERNAL_INTERRUPTS_H
#define MICROPY_INCLUDED_ATMEL_SAMD_PERIPHERALS_EXTERNAL_INTERRUPTS_H

#include <stdbool.h>
#include <stdint.h>

void turn_on_external_interrupt_controller(void);
void turn_off_external_interrupt_controller(void);
void turn_on_cpu_interrupt(uint8_t eic_channel);
void turn_on_eic_channel(uint8_t eic_channel, uint32_t sense_setting);
void configure_eic_channel(uint8_t eic_channel, uint32_t sense_setting);
void turn_off_eic_channel(uint8_t eic_channel);
void clear_external_interrupt(uint8_t channel);
bool eic_channel_free(uint8_t eic_channel);
bool eic_get_enable(void);
void eic_set_enable(bool value);
void eic_reset(void);

// This must be provided by the code using the peripherals library. It must call
// clear_external_interrupt(channel).
extern void external_interrupt_handler(uint8_t channel);

#endif  // MICROPY_INCLUDED_ATMEL_SAMD_PERIPHERALS_EXTERNAL_INTERRUPTS_H
