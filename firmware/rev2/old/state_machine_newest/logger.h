enum reasons {overtemperature, undervoltage};
struct eeprom_data_template {
	enum reasons id;
	uint8_t byte0;
	uint8_t byte1;
	uint8_t byte2;
};