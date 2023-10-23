# Emulating MPS2 Cortex M3 AN385 on QEMU

## Requirements
1. GNU Arm Embedded Toolchain download 
[here](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
2. qemu-system-arm download [here](https://www.qemu.org/download)
3. CMake (Version 3.22.1 or later) download [here](https://cmake.org/install/)


## Customizing and Rebuilding

### Updating the Demo to Disconnect and Reconnect to MQTT Broker
Update `prvMQTTDemoTask()` in 
[source/MutualAuthMQTTExample.c](./source/MutualAuthMQTTExample.c)
to disconnect and reconnect with the MQTT broker.


1. To do this, navigate to the 
[MQTT Publish and Keep Alive Loop](./source/MutualAuthMQTTExample.c#L528) 
1. Update [ulMaxPublishCount](./source/MutualAuthMQTTExample.c#479) from 
`__UINT32_MAX__` to the desired amount of messages you would like to send
before disconnecting and reconnecting.


### Changing Data Being Sent to MQTT broker
Another option is to update the JSON being sent in the 
[MQTT Publish and Keep Alive Loop](./source/MutualAuthMQTTExample.c#L528) 
mentioned above.

To do this, navigate to the JSON that is 
[here](./source/MutualAuthMQTTExample.c#L547) and update `ulPublishCount%2` to
be the variable that contains the data you want sent to the broker. If you want
the value of the variable to change each iteration, you will have to add logic
for that in the MQTT Publish and Keep Alive Loop the JSON is located in. 

### Rebuilding the Demo 
1. Run the following commands to rebuild the demo:

For linux/MacOS:
```
$ cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=./arm-gcc-toolchain.cmake
$ cmake --build ./build
```
For Windows: 
```
$ cmake -G"MinGW Makefiles" -S . -B build -DCMAKE_TOOLCHAIN_FILE:PATH="./arm-gcc-toolchain.cmake"
$ cmake --build ./build
```

2. Copy QuickConnect-Demo located within the build folder and replace the 
binary currently in Quick_Connect_QEMU-\<PlatformName\>.x64/Demo with the updated
binary.

3. Rerun ```$ ./Start_Quick_Connect``` in the terminal after navigating to the
Quick_Connect_QEMU-\<PlatformName\>.x64 folder 

## How to Start Debugging(gdb)

1. First, run ./Start_Quick_Connect from the root of the 
Quick_Connect_QEMU-\<PlatformName\>.x64 to have credentials provisioned to 
your binary and to register your device in the IoT Core.

2. Stop the utility once it asks if you would like to open the visualizer website
and then start the demo with the following command:
```
$ qemu-system-arm -machine mps2-an385 -cpu cortex-m3 \
        -kernel ./Demo/QuickConnect-Demo \
        -netdev user,id=mynet0 \
        -net nic,macaddr=52:54:00:12:34:AD,model=lan9118,netdev=mynet0 \
        -display none -m 16M -nographic -serial stdio \
        -monitor null -semihosting -semihosting-config enable=on,target=native -s -S
```

Appending the -s and -S switches to the previous command does the following:

-s: allow gdb to be attached to the process remotely at port 1234 

-S: start the program in the paused state


3. run the command below from the root of 
Quick_Connect_QEMU-\<PlatformName\>.x64: 
```
arm-none-eabi-gdb -q ./Demo/QuickConnect-Demo
```
4. Pass in the Arguments below
```
target remote :1234
break main
c
```

## Note on Entropy Source
<P>
Within mbedtls_freertos_port.c, mbedtls_platform_entropy_poll utilizes a
pseudo-random number generator. This allows MPS2-AN385 boards emulated via QEMU
to establish a TLS connection, but should be updated if you plan to build a
project off of this demo to improve security.