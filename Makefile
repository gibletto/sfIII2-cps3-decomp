# Street Fighter III 2nd Impact - CPS3 program ROM (same steps as build.bat)
BIN = bin
PYTHON ?= python
# relative: SHC refuses an SHC_LIB longer than 116 characters
export SHC_LIB ?= bin
export SHC_TMP ?= C:\TEMP

# the compiler revision that built 2nd Impact (see README.md, Compiler)
export MDL_MUL_CONST = 31
export XJUMP_2I = 18
export MDL_IV_AUTOINC = 1
export MDL_MOD_CONST = 3
export MDL_IMM_REG = 191
export MDL_EQ_CONST = 3
export MDL_GCSE = 26
export GEN_STORE_RHS_INDEX = 1
export GEN_LAST_IDX = 4
export ASM_CALL_SLACK = 6
export MDL_IV_START0 = 6
export MDL_IV_ADDR = 1
export PEP_SWITCH_END = 1
export MDL_IV_WEB_ORDER = 1

CFLAGS = -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include
OPT = -optimize=1 -speed

# modules compiled with other settings
NOINLINE = CMD_MAIN entry_2 manage_2 sel_pl win_2
OPT0 = coin_sw coin_sw_2 colortest cram_bank dma_que eeprom family iotest_out scrn_ctrl simmram_slot soundtest spr_list \
	spr_pool spr_pool_2 sys_config sys_config_2 sys_config_3 sys_test sys_test_2 sys_test_2a sys_test_2b sys_test_2c sys_test_3 sys_test_4 \
	sys_test_5
CONSTTBL = CMD_MAIN Com_Pl EFF48 EFF55 EFF69 EFF71 EFF72 EFF74 EFF85 EFF86 EFFI4MV Eff93 \
	Game_Main Manage RANKING SYS_sub appear bg000 bgst000 bgst010 bgst020 bgst030 bgst040 bgst050 \
	bgst060 bgst070 bgst080 bgst090 bgst100 bgst110 bgst120 bgst130 bgst140 bgst150 bgst160 color3rd \
	demo00 demo02_code eff35 eff36 eff94 effe6 efff5 efff7 effg8 effh5 end_1 end_10 \
	end_11 end_12 end_13 end_2 end_3 end_4 end_5 end_6 end_7 end_8 end_9 end_main \
	end_main_c end_staff endbg00 endbg01 endbg02 endbg03 endbg04 endbg05 endbg06 endbg07 endbg08 endbg09 \
	endbg10 endbg11 endbg12 endbg13 endbg14 endbg15 entry_2 game_config_en game_config_jp game_config_main lose_pl manage_2 \
	sel_flow sel_pl tate00 win_2 win_pl

$(NOINLINE:%=obj/%.obj): OPT += -noinline
$(OPT0:%=obj/%.obj): OPT = -optimize=0 -nospeed
$(OPT0:%=obj/%.obj): export GEN_NARROW_CONST = 0
$(CONSTTBL:%=obj/%.obj): CFLAGS += -section=const=CTBL

# the link order is sf2i.sub's
SRCS = $(wildcard src/*.c src/*.src data/*.c data/*.src lib/*.src)
OBJS = $(patsubst %,obj/%.obj,$(basename $(notdir $(SRCS))))
vpath %.c src data
vpath %.src src data lib

# the tools take Windows paths (asmsh reads / as an option)
win = '$(subst /,\,$1)'

all: build/prog.bin

# the compiler writes its internal tables to stdout: keep them in a log, show its messages. Each compile gets
# its own temporary directory: two compilers sharing one fail with an internal error under make -j
obj/%.obj: %.c | obj
	@echo $<
	@mkdir -p "$(SHC_TMP)/$(*F)"; SHC_TMP='$(SHC_TMP)\$(*F)' \
		$(BIN)/shc.exe $(call win,$<) $(CFLAGS) $(OPT) -object=$(call win,$@) >$(@:.obj=.log) 2>&1; \
		r=$$?; rm -rf "$(SHC_TMP)/$(*F)"; grep ') : ' $(@:.obj=.log); rm -f $(@:.obj=.log); [ $$r = 0 ]

obj/%.obj: %.src | obj
	$(BIN)/asmsh.exe $(call win,$<) -object=$(call win,$@)

# shc writes no dependency lists, so a header change rebuilds everything
$(OBJS): $(wildcard include/*.h)

obj:
	mkdir -p obj "$(SHC_TMP)"

sf2i.abs: $(OBJS) sf2i.sub
	$(BIN)/lnk.exe -subcommand=sf2i.sub

sf2i.bin: sf2i.abs
	$(BIN)/rof2bin.exe -s=06000000 -e=07000000 -v=FF sf2i.abs

build/cg.bin: rom/sfiii2n.zip
	$(PYTHON) tools/cps3rom2.py extract $< $@

build/prog.bin: sf2i.bin build/cg.bin
	$(PYTHON) tools/cps3rom2.py pack sf2i.bin build/cg.bin rom/sfiii2n.zip build

clean:
	rm -rf obj build sf2i.abs sf2i.map sf2i.bin

.PHONY: all clean
