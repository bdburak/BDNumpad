/*TODO
 * copy all the neccecrary files and values and store them somewhere
 * correct the row col input misshap
 * move over col 1 to pb10 and the rest as well
 * add led output pins
 * add numlock functionality
 * add led animations and configuration
 * tidy up
 * */

#include "main.h"
#include "usb_device.h"
#include "usbd_hid.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
//https://youtu.be/tj1_hsQ5PR0?t=337   burda kaldin pdf indirdin
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

keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};

//uint8_t USBD_HID_SendReport(USBD_HandleTypeDef  *pdev,uint8_t *report,uint16_t len)

/**
  * @brief  pressKey
  *         Go through all keyboardHID keys and set one that is 0
  * @param  hid: keyboardHID instance
  * @param  usageId: intended keyboard usageId
  * @retval none
  */
void pressKey(keyboardHID* hid, const uint8_t usageId)
{
	if((*hid).KEYCODE1 == 0)
	{
		(*hid).KEYCODE1 = usageId;
		return;
	}
	else if((*hid).KEYCODE2 == 0)
	{
		(*hid).KEYCODE2 = usageId;
		return;
	}
	else if((*hid).KEYCODE3 == 0)
	{
		(*hid).KEYCODE3 = usageId;
		return;
	}
	else if((*hid).KEYCODE4 == 0)
	{
		(*hid).KEYCODE4 = usageId;
		return;
	}
	else if((*hid).KEYCODE5 == 0)
	{
		(*hid).KEYCODE5 = usageId;
		return;
	}
	else if((*hid).KEYCODE6 == 0)
	{
		(*hid).KEYCODE6 = usageId;
		return;
	}
	return;

}

/**
  * @brief  pressButtonKey
  *         set modifier key to usageId
  * @param  hid: keyboardHID instance
  * @param  usageId: intended keyboard usageId
  * @retval none
  */
void pressModifierKey(keyboardHID* hid, const uint8_t usageId)
{
	if((*hid).MODIFIER == 0)
	{
		(*hid).MODIFIER = usageId;
		return;
	}
	return;

}

void pressNumlock(uint8_t *report)
{

}

/*
 * -her 10 ms de bir buffer gonderilecek ve bosaltilacak
 * -tek tek tuslar kontrol edilcek ve hengio tusa basildiusa o pressKey
 * gondercek usageId ile
 * -eger hid buffer dolmussa zaten ekleyemicek
 * -bi numlock ile yon ozelligi eklenebilir belki
 * -
 * */
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

keysAndCodes keys = {0x4A, 0x4D, 0x4C, 0x38, 0x25,
		             0x4B, 0x1E, 0x1F, 0x20, 0x56,
		             0x4E, 0x21, 0x22, 0x23, 0x57,
		             0x52, 0x24, 0x25, 0x26, 0x28,
		             0x50, 0x51, 0x4F, 0x27, 0x37
};


/**
  * @brief  readRow1
  *         reads pins on row 1 and presses the corresponding key
  * @param  none
  * @retval none
  */
void readRow1(){

	//enabling the row 1
	HAL_GPIO_WritePin(row1_GPIO_Port, row1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(row2_GPIO_Port, row2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(row3_GPIO_Port, row3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(row4_GPIO_Port, row4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(row5_GPIO_Port, row5_Pin, GPIO_PIN_RESET);

	//read row 1:
	//read row1col1
	if (HAL_GPIO_ReadPin(col1_GPIO_Port, col1_Pin))
		pressKey(&keyboardhid, keys.key1_1);
	//read row1col2
	if (HAL_GPIO_ReadPin(col2_GPIO_Port, col2_Pin))
		pressKey(&keyboardhid, keys.key1_2);
	//read row1col3
	if (HAL_GPIO_ReadPin(col3_GPIO_Port, col3_Pin))
		pressKey(&keyboardhid, keys.key1_3);
	//read row1col4
	if (HAL_GPIO_ReadPin(col4_GPIO_Port, col4_Pin))
		pressKey(&keyboardhid, keys.key1_4);
	//read row1col5
	if (HAL_GPIO_ReadPin(col5_GPIO_Port, col5_Pin))
		pressKey(&keyboardhid, keys.key1_5);
}


/**
  * @brief  readRow2
  *         reads pins on row 2 and presses the corresponding key
  * @param  none
  * @retval none
  */
void readRow2(){

	//enabling the row 2
	HAL_GPIO_WritePin(row1_GPIO_Port, row1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(row2_GPIO_Port, row2_Pin, GPIO_PIN_SET);
	//don't need to reset 3,4,5

	//read row 2:
	//read row2col1
	if (HAL_GPIO_ReadPin(col1_GPIO_Port, col1_Pin))
		pressKey(&keyboardhid, keys.key2_1);
	//read row2col2
	if (HAL_GPIO_ReadPin(col2_GPIO_Port, col2_Pin))
		pressKey(&keyboardhid, keys.key2_2);
	//read row2col3
	if (HAL_GPIO_ReadPin(col3_GPIO_Port, col3_Pin))
		pressKey(&keyboardhid, keys.key2_3);
	//read row2col4
	if (HAL_GPIO_ReadPin(col4_GPIO_Port, col4_Pin))
		pressKey(&keyboardhid, keys.key2_4);
	//read row2col5
	if (HAL_GPIO_ReadPin(col5_GPIO_Port, col5_Pin))
		pressKey(&keyboardhid, keys.key2_5);

}
/**
  * @brief  readRow3
  *         reads pins on row 3 and presses the corresponding key
  * @param  none
  * @retval none
  */
void readRow3(){

	//enabling the row 3
	HAL_GPIO_WritePin(row2_GPIO_Port, row2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(row3_GPIO_Port, row3_Pin, GPIO_PIN_SET);
	//don't need to reset 1,4,5

	//read row 3:
	//read row3col1
	if (HAL_GPIO_ReadPin(col1_GPIO_Port, col1_Pin))
		pressKey(&keyboardhid, keys.key3_1);
	//read row3col2
	if (HAL_GPIO_ReadPin(col2_GPIO_Port, col2_Pin))
		pressKey(&keyboardhid, keys.key3_2);
	//read row3col3
	if (HAL_GPIO_ReadPin(col3_GPIO_Port, col3_Pin))
		pressKey(&keyboardhid, keys.key3_3);
	//read row3col4
	if (HAL_GPIO_ReadPin(col4_GPIO_Port, col4_Pin))
		pressKey(&keyboardhid, keys.key3_4);
	//read row3col5
	if (HAL_GPIO_ReadPin(col5_GPIO_Port, col5_Pin))
		pressKey(&keyboardhid, keys.key3_5);

}
/**
  * @brief  readRow4
  *         reads pins on row 4 and presses the corresponding key
  * @param  none
  * @retval none
  */
void readRow4(){

	//enabling the row 3
	HAL_GPIO_WritePin(row3_GPIO_Port, row2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(row4_GPIO_Port, row3_Pin, GPIO_PIN_SET);
	//don't need to reset 1,2,5

	//read row 4:
	//read row4col1
	if (HAL_GPIO_ReadPin(col1_GPIO_Port, col1_Pin))
		pressKey(&keyboardhid, keys.key4_1);
	//read row4col2
	if (HAL_GPIO_ReadPin(col2_GPIO_Port, col2_Pin))
		pressKey(&keyboardhid, keys.key4_2);
	//read row4col3
	if (HAL_GPIO_ReadPin(col3_GPIO_Port, col3_Pin))
		pressKey(&keyboardhid, keys.key4_3);
	//read row4col4
	if (HAL_GPIO_ReadPin(col4_GPIO_Port, col4_Pin))
		pressKey(&keyboardhid, keys.key4_4);
	//read row4col5
	if (HAL_GPIO_ReadPin(col5_GPIO_Port, col5_Pin))
		pressKey(&keyboardhid, keys.key4_5);

}

/**
  * @brief  readRow5
  *         reads pins on row 5 and presses the corresponding key
  * @param  none
  * @retval none
  */
void readRow5(){

	//enabling the row 5
	HAL_GPIO_WritePin(row4_GPIO_Port, row2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(row5_GPIO_Port, row3_Pin, GPIO_PIN_SET);
	//don't need to reset 1,2,3

	//read row 5:
	//read row1col1
	if (HAL_GPIO_ReadPin(col1_GPIO_Port, col1_Pin))
		pressKey(&keyboardhid, keys.key5_1);
	//read row5col2
	if (HAL_GPIO_ReadPin(col2_GPIO_Port, col2_Pin))
		pressKey(&keyboardhid, keys.key5_2);
	//read row5col3
	if (HAL_GPIO_ReadPin(col3_GPIO_Port, col3_Pin))
		pressKey(&keyboardhid, keys.key5_3);
	//read row5col4
	if (HAL_GPIO_ReadPin(col4_GPIO_Port, col4_Pin))
		pressKey(&keyboardhid, keys.key5_4);
	//read row5col5
	if (HAL_GPIO_ReadPin(col5_GPIO_Port, col5_Pin))
		pressKey(&keyboardhid, keys.key5_5);

}
/**
  * @brief  readAllPins
  *         reads all pins and presses the corresponding key
  * @param  none
  * @retval none
  */
void readAllPins(){
	readRow1();
	HAL_Delay(1);
	readRow2();
	HAL_Delay(1);
	readRow3();
	HAL_Delay(1);
	readRow4();
	HAL_Delay(1);
	readRow5();
	HAL_Delay(1);

	USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof(keyboardhid));
	keyboardhid.KEYCODE1 = 0;
	keyboardhid.KEYCODE2 = 0;
	keyboardhid.KEYCODE3 = 0;
	keyboardhid.KEYCODE4 = 0;
	keyboardhid.KEYCODE5 = 0;
	keyboardhid.KEYCODE6 = 0;

}
