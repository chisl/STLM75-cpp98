/*
 * name:        STLM75
 * description: Digital temperature sensor and thermal watchdog
 * manuf:       ST Microelectronics
 * version:     Version 0.1
 * url:         http://www.st.com/resource/en/datasheet/stlm75.pdf
 * date:        2018-01-30
 * author       https://chisl.io/
 * file:        STLM75.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class STLM75_Base and implement the read and write functions! */

/* STLM75: Digital temperature sensor and thermal watchdog */
class STLM75_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG COMMAND                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG COMMAND:
	 * The command register retains pointer information between operations (see Table 5).
	 * Therefore, this register only needs to be updated once for consecutive READ operations
	 * from the same register. All bits in the command register default to '0' at power-up.
	 */
	struct COMMAND
	{
		static const uint16_t __address = 255;
		
		/* Bits reserved_0: */
		/*
		 * The most significant bits (MSBs) of the command register must always be zero. Writing a '1'
		 * into any of these bits will cause the current operation to be terminated.
		 */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'd0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits P: */
		struct P
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t TEMP = 0b00; // 
			static const uint8_t CONF = 0b01; // 
			static const uint8_t T_HYS = 0b10; // 
			static const uint8_t T_OS = 0b11; // 
		};
	};
	
	/* Set register COMMAND */
	void setCOMMAND(uint8_t value)
	{
		write(COMMAND::__address, value, 8);
	}
	
	/* Get register COMMAND */
	uint8_t getCOMMAND()
	{
		return read8(COMMAND::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG TEMP                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TEMP:
	 * The temperature register is a two-byte (16-bit) “Read only” register (see Table 7 on
	 * page 18). Digital temperatures from the T-to-D converter are stored in the temperature
	 * register in two’s complement format, and the contents of this register are updated each time
	 * the T-to-D conversion is finished.
	 * The user can read data from the temperature register at any time. When a T-to-D
	 * conversion is completed, the new data is loaded into a comparator buffer to evaluate fault
	 * conditions and will update the temperature register if a read cycle is not ongoing. If a READ
	 * is ongoing, the previous temperature will be read. Accessing the STLM75 continuously
	 * without waiting at least one conversion time between communications will prevent the
	 * device from updating the temperature register with a new temperature conversion result.
	 * Consequently, the STLM75 should not be accessed continuously with a wait time of less
	 * than tCONV (max).
	 * All unused bits following the digital temperature will be zero. The MSB position of the
	 * temperature register always contains the sign bit for the digital temperature, and Bit14
	 * contains the temperature MSB. All bits in the temperature register default to zero at powerup.
	 * 
	 */
	struct TEMP
	{
		static const uint16_t __address = 0;
		
		/* Bits TD: */
		/* Temperature data bits.  */
		struct TD
		{
			static const uint16_t mask = 0b1111111110000000; // [7,8,9,10,11,12,13,14,15]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint16_t dflt = 0b0000000; // 7'b0
			static const uint16_t mask = 0b0000000001111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register TEMP */
	void setTEMP(uint16_t value)
	{
		write(TEMP::__address, value, 16);
	}
	
	/* Get register TEMP */
	uint16_t getTEMP()
	{
		return read16(TEMP::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG CONF                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG CONF:
	 * The configuration register is used to store the device settings such as device operation
	 * mode, OS operation mode, OS polarity, and OS fault queue.
	 * The configuration register allows the user to program various options such as thermostat
	 * fault tolerance, thermostat polarity, thermostat operating mode, and shutdown mode. The
	 * user has READ/WRITE access to all of the bits in the configuration register except the MSB
	 * (Bit7), which is reserved as a “Read only” bit (see Table 6). The entire register is volatile and
	 * thus powers-up in its default state only.
	 */
	struct CONF
	{
		static const uint16_t __address = 1;
		
		/* Bits reserved_0: */
		/* must be set to '0'. Reserved  */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits unused_1: */
		/* must be set to '0'.  */
		struct unused_1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b01100000; // [5,6]
		};
		/* Bits FT: */
		/* fault tolerance1 bit  */
		struct FT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00011000; // [3,4]
		};
		/* Bits POL: */
		/* output polarity. The OS is active-low ('0').  */
		struct POL
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits M: */
		/* Indicates operation mode; (see Comparator mode and Interrupt mode on page 13).  */
		struct M
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t COMPARATOR_MODE = 0b0; // 
			static const uint8_t INTERRUPT_MODE = 0b1; // 
		};
		/* Bits SD: */
		struct SD
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register CONF */
	void setCONF(uint8_t value)
	{
		write(CONF::__address, value, 8);
	}
	
	/* Get register CONF */
	uint8_t getCONF()
	{
		return read8(CONF::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG T_OS                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG T_OS:
	 * The TOS register is a two-byte (16-bit) READ/WRITE register that stores the userprogrammable
	 * upper trip-point temperature for the thermal alarm in two’s complement
	 * format (see Table 8 on page 19). This register defaults to 80 °C at power-up (i.e., 0101 0000
	 * 0000 0000).
	 * The format of the TOS register is identical to that of the temperature register. The MSB
	 * position contains the sign bit for the digital temperature and Bit14 contains the temperature
	 * MSB.
	 * For 9-bit conversions, the trip-point temperature is defined by the 9 MSBs of the TOS
	 * register, and all remaining bits are “Don’t cares”.
	 */
	struct T_OS
	{
		static const uint16_t __address = 2;
		
		/* Bits T_OS: */
		struct T_OS_
		{
			/* MODE rw */
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register T_OS */
	void setT_OS(uint16_t value)
	{
		write(T_OS::__address, value, 16);
	}
	
	/* Get register T_OS */
	uint16_t getT_OS()
	{
		return read16(T_OS::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG T_HYS                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG T_HYS:
	 * THYS register is a two-byte (16-bit) READ/WRITE register that stores the userprogrammable
	 * lower trip-point temperature for the thermal alarm in two’s complement
	 * format (see Table 8). This register defaults to 75 °C at power-up (i.e., 0100 1011 0000
	 * 0000).
	 * The format of this register is the same as that of the temperature register. The MSB position
	 * contains the sign bit for the digital temperature and bit14 contains the temperature MSB.
	 */
	struct T_HYS
	{
		static const uint16_t __address = 2;
		
		/* Bits SB: */
		/* Two's complement sign bit.  */
		struct SB
		{
			/* MODE rw */
			static const uint16_t mask = 0b1000000000000000; // [15]
		};
		/* Bits SD: */
		/* Temperature data.  */
		struct SD
		{
			/* MODE rw */
			static const uint16_t mask = 0b0111111110000000; // [7,8,9,10,11,12,13,14]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint16_t dflt = 0b0000000; // 7'b0
			static const uint16_t mask = 0b0000000001111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register T_HYS */
	void setT_HYS(uint16_t value)
	{
		write(T_HYS::__address, value, 16);
	}
	
	/* Get register T_HYS */
	uint16_t getT_HYS()
	{
		return read16(T_HYS::__address, 16);
	}
	
};
