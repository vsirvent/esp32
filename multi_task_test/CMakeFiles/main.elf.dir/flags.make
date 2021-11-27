# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# compile C with /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc
C_FLAGS = -mlongcalls -Wno-frame-address  

C_DEFINES = -DHAVE_CONFIG_H -DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\" -DUNITY_INCLUDE_CONFIG_H -DWITH_POSIX

C_INCLUDES = -I/home/vsirvent/src/esp-idf/components/esp_ringbuf/include -I/home/vsirvent/src/mia/multi_task_test/config -I/home/vsirvent/src/esp-idf/components/newlib/platform_include -I/home/vsirvent/src/esp-idf/components/freertos/include -I/home/vsirvent/src/esp-idf/components/freertos/include/esp_additions/freertos -I/home/vsirvent/src/esp-idf/components/freertos/port/xtensa/include -I/home/vsirvent/src/esp-idf/components/freertos/include/esp_additions -I/home/vsirvent/src/esp-idf/components/esp_hw_support/include -I/home/vsirvent/src/esp-idf/components/esp_hw_support/include/soc -I/home/vsirvent/src/esp-idf/components/esp_hw_support/include/soc/esp32 -I/home/vsirvent/src/esp-idf/components/esp_hw_support/port/esp32/. -I/home/vsirvent/src/esp-idf/components/heap/include -I/home/vsirvent/src/esp-idf/components/log/include -I/home/vsirvent/src/esp-idf/components/lwip/include/apps -I/home/vsirvent/src/esp-idf/components/lwip/include/apps/sntp -I/home/vsirvent/src/esp-idf/components/lwip/lwip/src/include -I/home/vsirvent/src/esp-idf/components/lwip/port/esp32/include -I/home/vsirvent/src/esp-idf/components/lwip/port/esp32/include/arch -I/home/vsirvent/src/esp-idf/components/soc/include -I/home/vsirvent/src/esp-idf/components/soc/esp32/. -I/home/vsirvent/src/esp-idf/components/soc/esp32/include -I/home/vsirvent/src/esp-idf/components/hal/esp32/include -I/home/vsirvent/src/esp-idf/components/hal/include -I/home/vsirvent/src/esp-idf/components/hal/platform_port/include -I/home/vsirvent/src/esp-idf/components/esp_rom/include -I/home/vsirvent/src/esp-idf/components/esp_rom/include/esp32 -I/home/vsirvent/src/esp-idf/components/esp_rom/esp32 -I/home/vsirvent/src/esp-idf/components/esp_common/include -I/home/vsirvent/src/esp-idf/components/esp_system/include -I/home/vsirvent/src/esp-idf/components/esp_system/port/soc -I/home/vsirvent/src/esp-idf/components/esp_system/port/public_compat -I/home/vsirvent/src/esp-idf/components/esp32/include -I/home/vsirvent/src/esp-idf/components/xtensa/include -I/home/vsirvent/src/esp-idf/components/xtensa/esp32/include -I/home/vsirvent/src/esp-idf/components/driver/include -I/home/vsirvent/src/esp-idf/components/driver/esp32/include -I/home/vsirvent/src/esp-idf/components/esp_pm/include -I/home/vsirvent/src/esp-idf/components/efuse/include -I/home/vsirvent/src/esp-idf/components/efuse/esp32/include -I/home/vsirvent/src/esp-idf/components/vfs/include -I/home/vsirvent/src/esp-idf/components/esp_wifi/include -I/home/vsirvent/src/esp-idf/components/esp_event/include -I/home/vsirvent/src/esp-idf/components/esp_netif/include -I/home/vsirvent/src/esp-idf/components/esp_eth/include -I/home/vsirvent/src/esp-idf/components/tcpip_adapter/include -I/home/vsirvent/src/esp-idf/components/esp_phy/include -I/home/vsirvent/src/esp-idf/components/esp_phy/esp32/include -I/home/vsirvent/src/esp-idf/components/esp_ipc/include -I/home/vsirvent/src/esp-idf/components/app_trace/include -I/home/vsirvent/src/esp-idf/components/esp_timer/include -I/home/vsirvent/src/esp-idf/components/mbedtls/port/include -I/home/vsirvent/src/esp-idf/components/mbedtls/mbedtls/include -I/home/vsirvent/src/esp-idf/components/mbedtls/esp_crt_bundle/include -I/home/vsirvent/src/esp-idf/components/app_update/include -I/home/vsirvent/src/esp-idf/components/spi_flash/include -I/home/vsirvent/src/esp-idf/components/bootloader_support/include -I/home/vsirvent/src/esp-idf/components/nvs_flash/include -I/home/vsirvent/src/esp-idf/components/pthread/include -I/home/vsirvent/src/esp-idf/components/esp_gdbstub/include -I/home/vsirvent/src/esp-idf/components/esp_gdbstub/xtensa -I/home/vsirvent/src/esp-idf/components/esp_gdbstub/esp32 -I/home/vsirvent/src/esp-idf/components/espcoredump/include -I/home/vsirvent/src/esp-idf/components/espcoredump/include/port/xtensa -I/home/vsirvent/src/esp-idf/components/wpa_supplicant/include -I/home/vsirvent/src/esp-idf/components/wpa_supplicant/port/include -I/home/vsirvent/src/esp-idf/components/wpa_supplicant/esp_supplicant/include -I/home/vsirvent/src/esp-idf/components/ieee802154/include -I/home/vsirvent/src/esp-idf/components/console -I/home/vsirvent/src/esp-idf/components/asio/asio/asio/include -I/home/vsirvent/src/esp-idf/components/asio/port/include -I/home/vsirvent/src/esp-idf/components/cbor/port/include -I/home/vsirvent/src/esp-idf/components/unity/include -I/home/vsirvent/src/esp-idf/components/unity/unity/src -I/home/vsirvent/src/esp-idf/components/cmock/CMock/src -I/home/vsirvent/src/esp-idf/components/coap/port/include -I/home/vsirvent/src/esp-idf/components/coap/libcoap/include -I/home/vsirvent/src/esp-idf/components/es3188/include -I/home/vsirvent/src/esp-idf/components/nghttp/port/include -I/home/vsirvent/src/esp-idf/components/nghttp/nghttp2/lib/includes -I/home/vsirvent/src/esp-idf/components/esp-tls -I/home/vsirvent/src/esp-idf/components/esp-tls/esp-tls-crypto -I/home/vsirvent/src/esp-idf/components/esp_adc_cal/include -I/home/vsirvent/src/esp-idf/components/esp_hid/include -I/home/vsirvent/src/esp-idf/components/tcp_transport/include -I/home/vsirvent/src/esp-idf/components/esp_http_client/include -I/home/vsirvent/src/esp-idf/components/esp_http_server/include -I/home/vsirvent/src/esp-idf/components/esp_https_ota/include -I/home/vsirvent/src/esp-idf/components/esp_lcd/include -I/home/vsirvent/src/esp-idf/components/esp_lcd/interface -I/home/vsirvent/src/esp-idf/components/protobuf-c/protobuf-c -I/home/vsirvent/src/esp-idf/components/protocomm/include/common -I/home/vsirvent/src/esp-idf/components/protocomm/include/security -I/home/vsirvent/src/esp-idf/components/protocomm/include/transports -I/home/vsirvent/src/esp-idf/components/mdns/include -I/home/vsirvent/src/esp-idf/components/esp_local_ctrl/include -I/home/vsirvent/src/esp-idf/components/sdmmc/include -I/home/vsirvent/src/esp-idf/components/esp_serial_slave_link/include -I/home/vsirvent/src/esp-idf/components/esp_websocket_client/include -I/home/vsirvent/src/esp-idf/components/expat/expat/expat/lib -I/home/vsirvent/src/esp-idf/components/expat/port/include -I/home/vsirvent/src/esp-idf/components/wear_levelling/include -I/home/vsirvent/src/esp-idf/components/fatfs/diskio -I/home/vsirvent/src/esp-idf/components/fatfs/vfs -I/home/vsirvent/src/esp-idf/components/fatfs/src -I/home/vsirvent/src/esp-idf/components/freemodbus/common/include -I/home/vsirvent/src/esp-idf/components/idf_test/include -I/home/vsirvent/src/esp-idf/components/idf_test/include/esp32 -I/home/vsirvent/src/esp-idf/components/jsmn/include -I/home/vsirvent/src/esp-idf/components/json/cJSON -I/home/vsirvent/src/esp-idf/components/libsodium/libsodium/src/libsodium/include -I/home/vsirvent/src/esp-idf/components/libsodium/port_include -I/home/vsirvent/src/esp-idf/components/mqtt/esp-mqtt/include -I/home/vsirvent/src/esp-idf/components/openssl/include -I/home/vsirvent/src/esp-idf/components/perfmon/include -I/home/vsirvent/src/esp-idf/components/spiffs/include -I/home/vsirvent/src/esp-idf/components/ulp/include -I/home/vsirvent/src/esp-idf/components/wifi_provisioning/include -I/home/vsirvent/src/mia/multi_task_test/main 

