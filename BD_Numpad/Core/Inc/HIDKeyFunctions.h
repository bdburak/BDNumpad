/*
 * HIDKeyFunctions.h
 *
 *  Created on: Aug 13, 2023
 *      Author: manag
 */

#ifndef INC_HIDKEYFUNCTIONS_H_
#define INC_HIDKEYFUNCTIONS_H_


typedef struct {
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
} keyboardHID;

void pressKey(keyboardHID* hid, const uint8_t usageId);
void pressModifierKey(keyboardHID* hid, const uint8_t usageId);
void pressNumlock(uint8_t *report);



typedef struct {
	uint8_t key1_1;
	uint8_t key1_2;
	uint8_t key1_3;
	uint8_t key1_4;
	uint8_t key1_5;
	uint8_t key2_1;
	uint8_t key2_2;
	uint8_t key2_3;
	uint8_t key2_4;
	uint8_t key2_5;
	uint8_t key3_1;
	uint8_t key3_2;
	uint8_t key3_3;
	uint8_t key3_4;
	uint8_t key3_5;
	uint8_t key4_1;
	uint8_t key4_2;
	uint8_t key4_3;
	uint8_t key4_4;
	uint8_t key4_5;
	uint8_t key5_1;
	uint8_t key5_2;
	uint8_t key5_3;
	uint8_t key5_4;
	uint8_t key5_5;

} keysAndCodes;

void readRow1();
void readRow2();
void readRow3();
void readRow4();
void readRow5();

void readAllPins();

#endif /* INC_HIDKEYFUNCTIONS_H_ */
