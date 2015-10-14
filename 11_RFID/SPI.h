                                         /* SPI EEPROM 25LC256 Library */
#include <avr/io.h>
#include "pinDefines.h"


                                 /* Which pin selects EEPROM as slave? */
#define SLAVE_SELECT    SPI_SS_PORT &= ~(1 << SPI_SS)
#define SLAVE_DESELECT  SPI_SS_PORT |= (1 << SPI_SS)

// Instruction Set -- from data sheet
#define EEPROM_READ      0b00000011                     /* read memory */
#define EEPROM_WRITE     0b00000010                 /* write to memory */

#define EEPROM_WRDI      0b00000100                   /* write disable */
#define EEPROM_WREN      0b00000110                    /* write enable */

#define EEPROM_RDSR      0b00000101            /* read status register */
#define EEPROM_WRSR      0b00000001           /* write status register */

// EEPROM Status Register Bits -- from data sheet
// Use these to parse status register
#define EEPROM_WRITE_IN_PROGRESS    0
#define EEPROM_WRITE_ENABLE_LATCH   1
#define EEPROM_BLOCK_PROTECT_0      2
#define EEPROM_BLOCK_PROTECT_1      3

#define EEPROM_BYTES_PER_PAGE       64
#define EEPROM_BYTES_MAX            0x7FFF

// Functions

                  /* Init SPI to run EEPROM with phase, polarity = 0,0 */
void initSPI(void);

                  /* Generic.  Just loads up HW SPI register and waits */
void SPI_tradeByte(uint8_t byte);

                     /* splits 16-bit address into 2 bytes, sends both */
void RFID_setRegister(uint8_t  data,uint8_t address) ;

uint8_t RFID_readRegister(uint8_t address);



uint8_t RFID_doWait(uint8_t command);
