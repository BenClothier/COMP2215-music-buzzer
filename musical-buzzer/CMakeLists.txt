add_executable(musical-buzzer
        musical-buzzer.c
        )

# pull in common dependencies
target_link_libraries(musical-buzzer pico_stdlib hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(musical-buzzer)

# add url via pico_set_program_url
example_auto_set_url(musical-buzzer)
