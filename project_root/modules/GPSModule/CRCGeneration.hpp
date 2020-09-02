#define CRC32_POLYNOMIAL			0xEDB88320L

unsigned long CRC32Value(int i) {
	int j;
	unsigned long ulCRC;
	ulCRC = i;
	for (j = 8; j > 0; j--) {
		if (ulCRC & 1)
			ulCRC = (ulCRC >> 1) ^ CRC32_POLYNOMIAL;
		else
			ulCRC >>= 1;
	}
	return ulCRC;
}
/* --------------------------------------------------------------------------
Calculates the CRC-32 of a block of data all at once
-------------------------------------------------------------------------- */

//unsigned long ulCount,  // Number of bytes in the data block //how long the binary data (not including CRC) 108?
//unsigned char *ucBuffer // pass in entire binary string
unsigned long CalculateBlockCRC32(unsigned long ulCount, unsigned char *ucBuffer) {
	unsigned long ulTemp1;
	unsigned long ulTemp2;
	unsigned long ulCRC = 0;
	while (ulCount-- != 0) {
		ulTemp1 = (ulCRC >> 8) & 0x00FFFFFFL;
		ulTemp2 = CRC32Value(((int)ulCRC ^ *ucBuffer++) & 0xff);
		ulCRC = ulTemp1 ^ ulTemp2;
	}
	return(ulCRC);	//returns CRC value
}

//Note: Data Block ucBuffer should contain all data bytes of the full data record except the checksum bytes.
