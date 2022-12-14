/* MẠCH___________ARDUINO
 *  vcc-----------5v
 * GND___________GND
 * TX____________2
 * RX ko cần cấp
 */

#include <rdm6300.h>

#define RDM6300_RX_PIN 2
#define READ_LED_PIN 13

Rdm6300 rdm6300;

void setup()
{
	Serial.begin(115200);

	pinMode(READ_LED_PIN, OUTPUT);
	digitalWrite(READ_LED_PIN, LOW);

	rdm6300.begin(RDM6300_RX_PIN);

	Serial.println("\nPlace RFID tag near the rdm6300...");
}

void loop()
{
	/* if non-zero tag_id, update() returns true- a new tag is near! */
	if (rdm6300.update())
		Serial.println(rdm6300.get_tag_id(), DEC);

	digitalWrite(READ_LED_PIN, rdm6300.is_tag_near());

	delay(10);
}