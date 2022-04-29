add_executable(musical-buzzer
        musical-buzzer.c
        )
        
add_executable(musical-buzzer_complete
        musical-buzzer_complete.c
)

# pull in common dependencies
target_link_libraries(musical-buzzer pico_stdlib hardware_pwm)
target_link_libraries(musical-buzzer_complete pico_stdlib hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(musical-buzzer)
pico_add_extra_outputs(musical-buzzer_complete)

# add url via pico_set_program_url
example_auto_set_url(musical-buzzer)
example_auto_set_url(musical-buzzer_complete)
