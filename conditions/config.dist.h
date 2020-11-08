const char* wifiSsid              = "xxx";
const char* wifiPassword          = "xxx";
const uint32_t deviceId           = ESP.getChipId();

const int   pinLed                = 2;
const int   pinFlash              = 0;
const char* mqttServer            = "mqtt.xxx.de";
const int   mqttPort              = 1883;
const char* mqttUsername          = "xxx";
const char* mqttPassword          = "xxx";
      char* mqttFeed              = "/conditions/%s";           // %s will be replaced by the device id
const char* mqttWillTopic         = "/offline";
const int   mqttQos               = 1;
const int   mqttRetain            = 0;


const int   deepSleepMinutes      = 15;
const int   serialBautRate        = 115200;

#define     ENABLE_DEEPSLEEP      false

#define     DHTPIN                14         // (2 on ESP01) Pin which is connected to the DHT sensor.
#define     DHTTYPE               DHT22     // DHT11 or DHT 21 or DHT22
