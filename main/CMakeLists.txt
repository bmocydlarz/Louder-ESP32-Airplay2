set( SRC_FILES
    "main.c"
    "alac_magic_cookie.c"
    "settings.c"
    "audio/audio_receiver.c"
    "audio/audio_stream.c"
    "audio/audio_stream_realtime.c"
    "audio/audio_stream_buffered.c"
    "audio/audio_decoder.c"
    "audio/audio_buffer.c"
    "audio/audio_timing.c"
    "audio/audio_crypto.c"
    "rtsp/rtsp_server.c"
    "rtsp/rtsp_conn.c"
    "rtsp/rtsp_message.c"
    "rtsp/rtsp_handlers.c"
    "rtsp/rtsp_fairplay.c"
    "rtsp/rtsp_crypto.c"
    "rtsp/rtsp_events.c"
    "plist/plist_xml.c"
    "plist/bplist_parser.c"
    "plist/bplist_builder.c"
    "plist/base64.c"
    "hap/hap.c"
    "hap/hap_pair_verify.c"
    "hap/hap_pair_setup.c"
    "hap/hap_crypto.c"
    "hap/srp.c"
    "hap/tlv8.c"
    "network/wifi.c"
    "network/mdns_airplay.c"
    "network/ptp_clock.c"
    "network/ntp_clock.c"
    "network/socket_utils.c"
    "network/web_server.c"
    "network/ota.c"
    "network/dns_server.c"
    "led.c"
)

# Select audio output implementation at compile time
if(CONFIG_SPDIF_OUTPUT)
    list(APPEND SRC_FILES "audio/audio_output_spdif.c")
else()
    list(APPEND SRC_FILES "audio/audio_output.c")
endif()

set( INC_DIRS
    "." 
    "audio" 
    "rtsp" 
    "plist" 
    "hap" 
    "network"
)

set( DEPS
    nvs_flash
    esp_wifi
    esp_netif
    esp_event
    esp_ringbuf
    esp_timer
    esp_http_server
    app_update
    cjson
    mbedtls
    esp_driver_ledc
    esp_driver_gpio    # <--- Ajouté
    esp_driver_i2s     # <--- Ajouté
    esp_driver_i2c     # <--- Ajouté (pour ton ampli plus tard)
    boards
)

idf_component_register(
    SRCS ${SRC_FILES}
    INCLUDE_DIRS ${INC_DIRS}
    PRIV_REQUIRES ${DEPS} 
)

# On force l'accès aux dossiers internes de mbedtls
idf_component_get_property(mbedtls_dir mbedtls COMPONENT_LIB)
target_include_directories(${COMPONENT_LIB} PRIVATE "/Users/baptiste/esp-idf/components/mbedtls/mbedtls/include/mbedtls")

# FORCE l'inclusion des headers mbedtls pour audio_crypto.c
idf_component_get_property(mbedtls_include mbedtls COMPONENT_OVERRIDDEN_DIR)
target_include_directories(${COMPONENT_LIB} PRIVATE "${mbedtls_include}/include")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-error=stringop-truncation")