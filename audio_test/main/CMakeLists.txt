set(src
    main.cpp
    Codecs/AudioDriver.cpp
    Codecs/ES8388/ES8388.cpp)

set(includes
    .
    Codecs)

idf_component_register(SRCS ${src}
                       INCLUDE_DIRS ${includes})

