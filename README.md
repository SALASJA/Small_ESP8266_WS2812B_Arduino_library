# Small_ESP8266_WS2812B_Arduino_library-
The Adafruit Neopixel library is amazing! However, it's very bloated, this makes it
difficult to modify the code and add features in a neater and more graceful way. This
repository isolates the esp8266 protocol used in the Neopixel Library. It works pretty ok,
except there is flickering. I only tested this on the esp01. Logically it should work, I suspect
that because there is less code, it runs a little faster, somehow affecting the protocol. Since
the random flicker is very very minor, I suspect there should be a very small change in the directive constants
in  ws2812b_protocol.h . If I had more experience with electronics and an oscilloscope, I could explain all
of this in better detail. 
