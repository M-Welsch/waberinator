# List of all the board related files.
BOARDSRC = board/board.c  #$(CHIBIOS)/os/hal/boards/ST_NUCLEO64_F030R8/board.c

# Required include directories
BOARDINC = board #$(CHIBIOS)/os/hal/boards/ST_NUCLEO64_F030R8

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
