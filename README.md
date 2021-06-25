# Small_ESP8266_WS2812B_Arduino_library-
The Adafruit Neopixel library is amazing! However, it's very bloated, this makes it
difficult to modify the code and add features in a neater and more graceful way. This
repository isolates the esp8266 protocol used in the Neopixel Library. It works pretty ok,
except there is flickering. I only tested this on the esp01. Logically it should work, I suspect
that because there is less code, it runs a little faster, somehow affecting the protocol. Since
the random flicker is very very minor, I suspect there should be a very small change in the directive constants
in  ws2812b_protocol.h . If I had more experience with electronics and an oscilloscope, I could tackle this issue
in better detail. 


Assumming there is nothing wrong with the logic of the algorithm and assuming all that needs to change are the
constants:

- #define CYCLES_800_T0H  (F_CPU / 2500000) // 0.4us
- #define CYCLES_800_T1H  (F_CPU / 1250000) // 0.8us
- #define CYCLES_800      (F_CPU /  800000) // 1.25us per bit

(for example making 2500000 bigger)

and suppose for all three of the constants i have 3 choices:

- b - to make bigger
- n - no change
- s - to make smaller


so one possible edit i can do is 

- #define CYCLES_800_T0H  (F_CPU / 2500010) //b - made bigger
- #define CYCLES_800_T1H  (F_CPU / 1250000) //n - no change
- #define CYCLES_800      (F_CPU /  800000) //n - no change

so we can symbolically represent this change in our notes as the tuple (b,n,n)

if we want to see all possible edits we can make to this file we do the cartesian product of {b,n,s} with itself 
(where {b,n,s} are the set of possible edits described above)

|{b,n,s}^3| = 27 possible edit classes can be made to this file


notice i used the term  classes, this is because we might need to try different values if we plan to, let say,
make one one of the values bigger:

this below is already one situation

- #define CYCLES_800_T0H  (F_CPU / 2500010) //b - made bigger
- #define CYCLES_800_T1H  (F_CPU / 1250000) //n - no change
- #define CYCLES_800      (F_CPU /  800000) //n - no change 

if above doesnt work we might try to make it bigger

- #define CYCLES_800_T0H  (F_CPU / 2500020) //b - made bigger
- #define CYCLES_800_T1H  (F_CPU / 1250000) //n - no change
- #define CYCLES_800      (F_CPU /  800000) //n - no change 


and we might do this for a couple of bigger values until we give up and try other stuff.

Anyways, im only doing this because I have no deep knowledge of the timings or the protocol. Since
the code works 95% well, I'm guessing the change must be made here.
