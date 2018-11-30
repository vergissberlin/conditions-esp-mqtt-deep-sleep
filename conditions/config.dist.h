const char* wifiSsid              = "xxx";
const char* wifiPassword          = "xxx";
const char* wifiHostname          = "conditions";

const int   pinLedTop             = 2;
const int   pinLedBottom          = BUILTIN_LED;
const int   pinLedExtern          = 12;
const int   pinFlash              = 0;
const int   pinBin                = 5;
const int   pinMaintenance        = 4;

const char* otaHostName           = "conditions";
const char* otaPassword           = "passwrd";
const int   otaPort               = 8266;

#define     MQTT_SERVER           "io.adafruit.com"
#define     MQTT_SERVERPORT       1883 // use 8883 for SSL
#define     MQTT_USERNAME         "xxx"
#define     MQTT_KEY              "xxx"
#define     MQTT_FEED_TEMPERATURE "/feeds/conditions.temparature"
#define     MQTT_FEED_HUMIDITY    "/feeds/conditions.humidity"

const int   pinLedTop             = BUILTIN_LED;
const int   pinFlash              = 0;

#define     FORCE_DEEPSLEEP
#define     SERIAL_BAUD          115200
