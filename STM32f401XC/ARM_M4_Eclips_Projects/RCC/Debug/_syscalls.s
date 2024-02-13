	.syntax unified
	.cpu cortex-m4
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 1
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.syntax unified
	.file	"_syscalls.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.__initialize_args,"ax",%progbits
	.align	2
	.weak	__initialize_args
	.thumb
	.thumb_func
	.type	__initialize_args, %function
__initialize_args:
.LFB16:
	.file 1 "../system/src/newlib/_syscalls.c"
	.loc 1 58 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.LVL0:
	.loc 1 73 0
	movs	r3, #1
	str	r3, [r0]
	.loc 1 74 0
	ldr	r3, .L2
	str	r3, [r1]
	bx	lr
.L3:
	.align	2
.L2:
	.word	.LANCHOR0
	.cfi_endproc
.LFE16:
	.size	__initialize_args, .-__initialize_args
	.section	.text.raise,"ax",%progbits
	.align	2
	.weak	raise
	.thumb
	.thumb_func
	.type	raise, %function
raise:
.LFB17:
	.loc 1 87 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
.LVL1:
	push	{r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 88 0
	bl	__errno
.LVL2:
	.loc 1 88 0
	movs	r3, #88
	str	r3, [r0]
	.loc 1 90 0
	mov	r0, #-1
	pop	{r3, pc}
	.cfi_endproc
.LFE17:
	.size	raise, .-raise
	.section	.text.kill,"ax",%progbits
	.align	2
	.weak	kill
	.thumb
	.thumb_func
	.type	kill, %function
kill:
.LFB18:
	.loc 1 97 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
.LVL3:
	push	{r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 98 0
	bl	__errno
.LVL4:
	.loc 1 98 0
	movs	r3, #88
	str	r3, [r0]
	.loc 1 100 0
	mov	r0, #-1
	pop	{r3, pc}
	.cfi_endproc
.LFE18:
	.size	kill, .-kill
	.weak	__dso_handle
	.comm	errno,4,4
	.section	.bss.name.4289,"aw",%nobits
	.align	2
	.type	name.4289, %object
	.size	name.4289, 1
name.4289:
	.space	1
	.section	.bss.__dso_handle,"aw",%nobits
	.align	2
	.type	__dso_handle, %object
	.size	__dso_handle, 4
__dso_handle:
	.space	4
	.section	.data.argv.4290,"aw",%progbits
	.align	2
	.set	.LANCHOR0,. + 0
	.type	argv.4290, %object
	.size	argv.4290, 8
argv.4290:
	.word	name.4289
	.word	0
	.text
.Letext0:
	.file 2 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\_types.h"
	.file 3 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\types.h"
	.file 4 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\signal.h"
	.file 5 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\signal.h"
	.file 6 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\errno.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x1c3
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF1100
	.byte	0xc
	.4byte	.LASF1101
	.4byte	.LASF1102
	.4byte	.Ldebug_ranges0+0
	.4byte	0
	.4byte	.Ldebug_line0
	.4byte	.Ldebug_macro0
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF1078
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.4byte	.LASF1079
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.4byte	.LASF1080
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.4byte	.LASF1081
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.4byte	.LASF1082
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.4byte	.LASF1083
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.4byte	.LASF1084
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.4byte	.LASF1085
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF1086
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.4byte	.LASF1087
	.uleb128 0x4
	.4byte	.LASF1090
	.byte	0x2
	.byte	0x32
	.4byte	0x29
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF1088
	.uleb128 0x5
	.byte	0x4
	.uleb128 0x6
	.byte	0x4
	.4byte	0x90
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.4byte	.LASF1089
	.uleb128 0x4
	.4byte	.LASF1091
	.byte	0x3
	.byte	0xbe
	.4byte	0x76
	.uleb128 0x7
	.4byte	.LASF1103
	.byte	0x1
	.byte	0x39
	.4byte	.LFB16
	.4byte	.LFE16-.LFB16
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xf4
	.uleb128 0x8
	.4byte	.LASF1092
	.byte	0x1
	.byte	0x39
	.4byte	0xf4
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x8
	.4byte	.LASF1093
	.byte	0x1
	.byte	0x39
	.4byte	0xfa
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x9
	.4byte	.LASF1094
	.byte	0x1
	.byte	0x40
	.4byte	0x106
	.uleb128 0x5
	.byte	0x3
	.4byte	name.4289
	.uleb128 0x9
	.4byte	.LASF1095
	.byte	0x1
	.byte	0x46
	.4byte	0x116
	.uleb128 0x5
	.byte	0x3
	.4byte	argv.4290
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x29
	.uleb128 0x6
	.byte	0x4
	.4byte	0x100
	.uleb128 0x6
	.byte	0x4
	.4byte	0x8a
	.uleb128 0xa
	.4byte	0x90
	.4byte	0x116
	.uleb128 0xb
	.4byte	0x81
	.byte	0
	.byte	0
	.uleb128 0xa
	.4byte	0x8a
	.4byte	0x126
	.uleb128 0xb
	.4byte	0x81
	.byte	0x1
	.byte	0
	.uleb128 0xc
	.4byte	.LASF1096
	.byte	0x4
	.byte	0x1d
	.4byte	0x29
	.4byte	.LFB17
	.4byte	.LFE17-.LFB17
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x158
	.uleb128 0xd
	.ascii	"sig\000"
	.byte	0x1
	.byte	0x56
	.4byte	0x29
	.4byte	.LLST0
	.uleb128 0xe
	.4byte	.LVL2
	.4byte	0x1bb
	.byte	0
	.uleb128 0xc
	.4byte	.LASF1097
	.byte	0x5
	.byte	0xab
	.4byte	0x29
	.4byte	.LFB18
	.4byte	.LFE18-.LFB18
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x199
	.uleb128 0xd
	.ascii	"pid\000"
	.byte	0x1
	.byte	0x60
	.4byte	0x97
	.4byte	.LLST1
	.uleb128 0xd
	.ascii	"sig\000"
	.byte	0x1
	.byte	0x60
	.4byte	0x29
	.4byte	.LLST2
	.uleb128 0xe
	.4byte	.LVL4
	.4byte	0x1bb
	.byte	0
	.uleb128 0xf
	.4byte	.LASF1098
	.byte	0x1
	.byte	0x1e
	.4byte	0x29
	.uleb128 0x5
	.byte	0x3
	.4byte	errno
	.uleb128 0xf
	.4byte	.LASF1099
	.byte	0x1
	.byte	0x1f
	.4byte	0x88
	.uleb128 0x5
	.byte	0x3
	.4byte	__dso_handle
	.uleb128 0x10
	.4byte	.LASF1104
	.4byte	.LASF1104
	.byte	0x6
	.byte	0xf
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.uleb128 0x2119
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",%progbits
.Ldebug_loc0:
.LLST0:
	.4byte	.LVL1
	.4byte	.LVL2-1
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL2-1
	.4byte	.LFE17
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST1:
	.4byte	.LVL3
	.4byte	.LVL4-1
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL4-1
	.4byte	.LFE18
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST2:
	.4byte	.LVL3
	.4byte	.LVL4-1
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL4-1
	.4byte	.LFE18
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.4byte	0
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB16
	.4byte	.LFE16-.LFB16
	.4byte	.LFB17
	.4byte	.LFE17-.LFB17
	.4byte	.LFB18
	.4byte	.LFE18-.LFB18
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LFB16
	.4byte	.LFE16
	.4byte	.LFB17
	.4byte	.LFE17
	.4byte	.LFB18
	.4byte	.LFE18
	.4byte	0
	.4byte	0
	.section	.debug_macro,"",%progbits
.Ldebug_macro0:
	.2byte	0x4
	.byte	0x2
	.4byte	.Ldebug_line0
	.byte	0x3
	.uleb128 0
	.uleb128 0x1
	.byte	0x5
	.uleb128 0x1
	.4byte	.LASF0
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF1
	.byte	0x5
	.uleb128 0x3
	.4byte	.LASF2
	.byte	0x5
	.uleb128 0x4
	.4byte	.LASF3
	.byte	0x5
	.uleb128 0x5
	.4byte	.LASF4
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF5
	.byte	0x5
	.uleb128 0x7
	.4byte	.LASF6
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF7
	.byte	0x5
	.uleb128 0x9
	.4byte	.LASF8
	.byte	0x5
	.uleb128 0xa
	.4byte	.LASF9
	.byte	0x5
	.uleb128 0xb
	.4byte	.LASF10
	.byte	0x5
	.uleb128 0xc
	.4byte	.LASF11
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF12
	.byte	0x5
	.uleb128 0xe
	.4byte	.LASF13
	.byte	0x5
	.uleb128 0xf
	.4byte	.LASF14
	.byte	0x5
	.uleb128 0x10
	.4byte	.LASF15
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF16
	.byte	0x5
	.uleb128 0x12
	.4byte	.LASF17
	.byte	0x5
	.uleb128 0x13
	.4byte	.LASF18
	.byte	0x5
	.uleb128 0x14
	.4byte	.LASF19
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF20
	.byte	0x5
	.uleb128 0x16
	.4byte	.LASF21
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF22
	.byte	0x5
	.uleb128 0x18
	.4byte	.LASF23
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF24
	.byte	0x5
	.uleb128 0x1a
	.4byte	.LASF25
	.byte	0x5
	.uleb128 0x1b
	.4byte	.LASF26
	.byte	0x5
	.uleb128 0x1c
	.4byte	.LASF27
	.byte	0x5
	.uleb128 0x1d
	.4byte	.LASF28
	.byte	0x5
	.uleb128 0x1e
	.4byte	.LASF29
	.byte	0x5
	.uleb128 0x1f
	.4byte	.LASF30
	.byte	0x5
	.uleb128 0x20
	.4byte	.LASF31
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF32
	.byte	0x5
	.uleb128 0x22
	.4byte	.LASF33
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF34
	.byte	0x5
	.uleb128 0x24
	.4byte	.LASF35
	.byte	0x5
	.uleb128 0x25
	.4byte	.LASF36
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF37
	.byte	0x5
	.uleb128 0x27
	.4byte	.LASF38
	.byte	0x5
	.uleb128 0x28
	.4byte	.LASF39
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF40
	.byte	0x5
	.uleb128 0x2a
	.4byte	.LASF41
	.byte	0x5
	.uleb128 0x2b
	.4byte	.LASF42
	.byte	0x5
	.uleb128 0x2c
	.4byte	.LASF43
	.byte	0x5
	.uleb128 0x2d
	.4byte	.LASF44
	.byte	0x5
	.uleb128 0x2e
	.4byte	.LASF45
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF46
	.byte	0x5
	.uleb128 0x30
	.4byte	.LASF47
	.byte	0x5
	.uleb128 0x31
	.4byte	.LASF48
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF49
	.byte	0x5
	.uleb128 0x33
	.4byte	.LASF50
	.byte	0x5
	.uleb128 0x34
	.4byte	.LASF51
	.byte	0x5
	.uleb128 0x35
	.4byte	.LASF52
	.byte	0x5
	.uleb128 0x36
	.4byte	.LASF53
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF54
	.byte	0x5
	.uleb128 0x38
	.4byte	.LASF55
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF56
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF57
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF58
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF59
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF60
	.byte	0x5
	.uleb128 0x3e
	.4byte	.LASF61
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF62
	.byte	0x5
	.uleb128 0x40
	.4byte	.LASF63
	.byte	0x5
	.uleb128 0x41
	.4byte	.LASF64
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF65
	.byte	0x5
	.uleb128 0x43
	.4byte	.LASF66
	.byte	0x5
	.uleb128 0x44
	.4byte	.LASF67
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF68
	.byte	0x5
	.uleb128 0x46
	.4byte	.LASF69
	.byte	0x5
	.uleb128 0x47
	.4byte	.LASF70
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF71
	.byte	0x5
	.uleb128 0x49
	.4byte	.LASF72
	.byte	0x5
	.uleb128 0x4a
	.4byte	.LASF73
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF74
	.byte	0x5
	.uleb128 0x4c
	.4byte	.LASF75
	.byte	0x5
	.uleb128 0x4d
	.4byte	.LASF76
	.byte	0x5
	.uleb128 0x4e
	.4byte	.LASF77
	.byte	0x5
	.uleb128 0x4f
	.4byte	.LASF78
	.byte	0x5
	.uleb128 0x50
	.4byte	.LASF79
	.byte	0x5
	.uleb128 0x51
	.4byte	.LASF80
	.byte	0x5
	.uleb128 0x52
	.4byte	.LASF81
	.byte	0x5
	.uleb128 0x53
	.4byte	.LASF82
	.byte	0x5
	.uleb128 0x54
	.4byte	.LASF83
	.byte	0x5
	.uleb128 0x55
	.4byte	.LASF84
	.byte	0x5
	.uleb128 0x56
	.4byte	.LASF85
	.byte	0x5
	.uleb128 0x57
	.4byte	.LASF86
	.byte	0x5
	.uleb128 0x58
	.4byte	.LASF87
	.byte	0x5
	.uleb128 0x59
	.4byte	.LASF88
	.byte	0x5
	.uleb128 0x5a
	.4byte	.LASF89
	.byte	0x5
	.uleb128 0x5b
	.4byte	.LASF90
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF91
	.byte	0x5
	.uleb128 0x5d
	.4byte	.LASF92
	.byte	0x5
	.uleb128 0x5e
	.4byte	.LASF93
	.byte	0x5
	.uleb128 0x5f
	.4byte	.LASF94
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF95
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF96
	.byte	0x5
	.uleb128 0x62
	.4byte	.LASF97
	.byte	0x5
	.uleb128 0x63
	.4byte	.LASF98
	.byte	0x5
	.uleb128 0x64
	.4byte	.LASF99
	.byte	0x5
	.uleb128 0x65
	.4byte	.LASF100
	.byte	0x5
	.uleb128 0x66
	.4byte	.LASF101
	.byte	0x5
	.uleb128 0x67
	.4byte	.LASF102
	.byte	0x5
	.uleb128 0x68
	.4byte	.LASF103
	.byte	0x5
	.uleb128 0x69
	.4byte	.LASF104
	.byte	0x5
	.uleb128 0x6a
	.4byte	.LASF105
	.byte	0x5
	.uleb128 0x6b
	.4byte	.LASF106
	.byte	0x5
	.uleb128 0x6c
	.4byte	.LASF107
	.byte	0x5
	.uleb128 0x6d
	.4byte	.LASF108
	.byte	0x5
	.uleb128 0x6e
	.4byte	.LASF109
	.byte	0x5
	.uleb128 0x6f
	.4byte	.LASF110
	.byte	0x5
	.uleb128 0x70
	.4byte	.LASF111
	.byte	0x5
	.uleb128 0x71
	.4byte	.LASF112
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF113
	.byte	0x5
	.uleb128 0x73
	.4byte	.LASF114
	.byte	0x5
	.uleb128 0x74
	.4byte	.LASF115
	.byte	0x5
	.uleb128 0x75
	.4byte	.LASF116
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF117
	.byte	0x5
	.uleb128 0x77
	.4byte	.LASF118
	.byte	0x5
	.uleb128 0x78
	.4byte	.LASF119
	.byte	0x5
	.uleb128 0x79
	.4byte	.LASF120
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF121
	.byte	0x5
	.uleb128 0x7b
	.4byte	.LASF122
	.byte	0x5
	.uleb128 0x7c
	.4byte	.LASF123
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF124
	.byte	0x5
	.uleb128 0x7e
	.4byte	.LASF125
	.byte	0x5
	.uleb128 0x7f
	.4byte	.LASF126
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF127
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF128
	.byte	0x5
	.uleb128 0x82
	.4byte	.LASF129
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF130
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF131
	.byte	0x5
	.uleb128 0x85
	.4byte	.LASF132
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF133
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF134
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF135
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF136
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF137
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF138
	.byte	0x5
	.uleb128 0x8c
	.4byte	.LASF139
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF140
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF141
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF142
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF143
	.byte	0x5
	.uleb128 0x91
	.4byte	.LASF144
	.byte	0x5
	.uleb128 0x92
	.4byte	.LASF145
	.byte	0x5
	.uleb128 0x93
	.4byte	.LASF146
	.byte	0x5
	.uleb128 0x94
	.4byte	.LASF147
	.byte	0x5
	.uleb128 0x95
	.4byte	.LASF148
	.byte	0x5
	.uleb128 0x96
	.4byte	.LASF149
	.byte	0x5
	.uleb128 0x97
	.4byte	.LASF150
	.byte	0x5
	.uleb128 0x98
	.4byte	.LASF151
	.byte	0x5
	.uleb128 0x99
	.4byte	.LASF152
	.byte	0x5
	.uleb128 0x9a
	.4byte	.LASF153
	.byte	0x5
	.uleb128 0x9b
	.4byte	.LASF154
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF155
	.byte	0x5
	.uleb128 0x9d
	.4byte	.LASF156
	.byte	0x5
	.uleb128 0x9e
	.4byte	.LASF157
	.byte	0x5
	.uleb128 0x9f
	.4byte	.LASF158
	.byte	0x5
	.uleb128 0xa0
	.4byte	.LASF159
	.byte	0x5
	.uleb128 0xa1
	.4byte	.LASF160
	.byte	0x5
	.uleb128 0xa2
	.4byte	.LASF161
	.byte	0x5
	.uleb128 0xa3
	.4byte	.LASF162
	.byte	0x5
	.uleb128 0xa4
	.4byte	.LASF163
	.byte	0x5
	.uleb128 0xa5
	.4byte	.LASF164
	.byte	0x5
	.uleb128 0xa6
	.4byte	.LASF165
	.byte	0x5
	.uleb128 0xa7
	.4byte	.LASF166
	.byte	0x5
	.uleb128 0xa8
	.4byte	.LASF167
	.byte	0x5
	.uleb128 0xa9
	.4byte	.LASF168
	.byte	0x5
	.uleb128 0xaa
	.4byte	.LASF169
	.byte	0x5
	.uleb128 0xab
	.4byte	.LASF170
	.byte	0x5
	.uleb128 0xac
	.4byte	.LASF171
	.byte	0x5
	.uleb128 0xad
	.4byte	.LASF172
	.byte	0x5
	.uleb128 0xae
	.4byte	.LASF173
	.byte	0x5
	.uleb128 0xaf
	.4byte	.LASF174
	.byte	0x5
	.uleb128 0xb0
	.4byte	.LASF175
	.byte	0x5
	.uleb128 0xb1
	.4byte	.LASF176
	.byte	0x5
	.uleb128 0xb2
	.4byte	.LASF177
	.byte	0x5
	.uleb128 0xb3
	.4byte	.LASF178
	.byte	0x5
	.uleb128 0xb4
	.4byte	.LASF179
	.byte	0x5
	.uleb128 0xb5
	.4byte	.LASF180
	.byte	0x5
	.uleb128 0xb6
	.4byte	.LASF181
	.byte	0x5
	.uleb128 0xb7
	.4byte	.LASF182
	.byte	0x5
	.uleb128 0xb8
	.4byte	.LASF183
	.byte	0x5
	.uleb128 0xb9
	.4byte	.LASF184
	.byte	0x5
	.uleb128 0xba
	.4byte	.LASF185
	.byte	0x5
	.uleb128 0xbb
	.4byte	.LASF186
	.byte	0x5
	.uleb128 0xbc
	.4byte	.LASF187
	.byte	0x5
	.uleb128 0xbd
	.4byte	.LASF188
	.byte	0x5
	.uleb128 0xbe
	.4byte	.LASF189
	.byte	0x5
	.uleb128 0xbf
	.4byte	.LASF190
	.byte	0x5
	.uleb128 0xc0
	.4byte	.LASF191
	.byte	0x5
	.uleb128 0xc1
	.4byte	.LASF192
	.byte	0x5
	.uleb128 0xc2
	.4byte	.LASF193
	.byte	0x5
	.uleb128 0xc3
	.4byte	.LASF194
	.byte	0x5
	.uleb128 0xc4
	.4byte	.LASF195
	.byte	0x5
	.uleb128 0xc5
	.4byte	.LASF196
	.byte	0x5
	.uleb128 0xc6
	.4byte	.LASF197
	.byte	0x5
	.uleb128 0xc7
	.4byte	.LASF198
	.byte	0x5
	.uleb128 0xc8
	.4byte	.LASF199
	.byte	0x5
	.uleb128 0xc9
	.4byte	.LASF200
	.byte	0x5
	.uleb128 0xca
	.4byte	.LASF201
	.byte	0x5
	.uleb128 0xcb
	.4byte	.LASF202
	.byte	0x5
	.uleb128 0xcc
	.4byte	.LASF203
	.byte	0x5
	.uleb128 0xcd
	.4byte	.LASF204
	.byte	0x5
	.uleb128 0xce
	.4byte	.LASF205
	.byte	0x5
	.uleb128 0xcf
	.4byte	.LASF206
	.byte	0x5
	.uleb128 0xd0
	.4byte	.LASF207
	.byte	0x5
	.uleb128 0xd1
	.4byte	.LASF208
	.byte	0x5
	.uleb128 0xd2
	.4byte	.LASF209
	.byte	0x5
	.uleb128 0xd3
	.4byte	.LASF210
	.byte	0x5
	.uleb128 0xd4
	.4byte	.LASF211
	.byte	0x5
	.uleb128 0xd5
	.4byte	.LASF212
	.byte	0x5
	.uleb128 0xd6
	.4byte	.LASF213
	.byte	0x5
	.uleb128 0xd7
	.4byte	.LASF214
	.byte	0x5
	.uleb128 0xd8
	.4byte	.LASF215
	.byte	0x5
	.uleb128 0xd9
	.4byte	.LASF216
	.byte	0x5
	.uleb128 0xda
	.4byte	.LASF217
	.byte	0x5
	.uleb128 0xdb
	.4byte	.LASF218
	.byte	0x5
	.uleb128 0xdc
	.4byte	.LASF219
	.byte	0x5
	.uleb128 0xdd
	.4byte	.LASF220
	.byte	0x5
	.uleb128 0xde
	.4byte	.LASF221
	.byte	0x5
	.uleb128 0xdf
	.4byte	.LASF222
	.byte	0x5
	.uleb128 0xe0
	.4byte	.LASF223
	.byte	0x5
	.uleb128 0xe1
	.4byte	.LASF224
	.byte	0x5
	.uleb128 0xe2
	.4byte	.LASF225
	.byte	0x5
	.uleb128 0xe3
	.4byte	.LASF226
	.byte	0x5
	.uleb128 0xe4
	.4byte	.LASF227
	.byte	0x5
	.uleb128 0xe5
	.4byte	.LASF228
	.byte	0x5
	.uleb128 0xe6
	.4byte	.LASF229
	.byte	0x5
	.uleb128 0xe7
	.4byte	.LASF230
	.byte	0x5
	.uleb128 0xe8
	.4byte	.LASF231
	.byte	0x5
	.uleb128 0xe9
	.4byte	.LASF232
	.byte	0x5
	.uleb128 0xea
	.4byte	.LASF233
	.byte	0x5
	.uleb128 0xeb
	.4byte	.LASF234
	.byte	0x5
	.uleb128 0xec
	.4byte	.LASF235
	.byte	0x5
	.uleb128 0xed
	.4byte	.LASF236
	.byte	0x5
	.uleb128 0xee
	.4byte	.LASF237
	.byte	0x5
	.uleb128 0xef
	.4byte	.LASF238
	.byte	0x5
	.uleb128 0xf0
	.4byte	.LASF239
	.byte	0x5
	.uleb128 0xf1
	.4byte	.LASF240
	.byte	0x5
	.uleb128 0xf2
	.4byte	.LASF241
	.byte	0x5
	.uleb128 0xf3
	.4byte	.LASF242
	.byte	0x5
	.uleb128 0xf4
	.4byte	.LASF243
	.byte	0x5
	.uleb128 0xf5
	.4byte	.LASF244
	.byte	0x5
	.uleb128 0xf6
	.4byte	.LASF245
	.byte	0x5
	.uleb128 0xf7
	.4byte	.LASF246
	.byte	0x5
	.uleb128 0xf8
	.4byte	.LASF247
	.byte	0x5
	.uleb128 0xf9
	.4byte	.LASF248
	.byte	0x5
	.uleb128 0xfa
	.4byte	.LASF249
	.byte	0x5
	.uleb128 0xfb
	.4byte	.LASF250
	.byte	0x5
	.uleb128 0xfc
	.4byte	.LASF251
	.byte	0x5
	.uleb128 0xfd
	.4byte	.LASF252
	.byte	0x5
	.uleb128 0xfe
	.4byte	.LASF253
	.byte	0x5
	.uleb128 0xff
	.4byte	.LASF254
	.byte	0x5
	.uleb128 0x100
	.4byte	.LASF255
	.byte	0x5
	.uleb128 0x101
	.4byte	.LASF256
	.byte	0x5
	.uleb128 0x102
	.4byte	.LASF257
	.byte	0x5
	.uleb128 0x103
	.4byte	.LASF258
	.byte	0x5
	.uleb128 0x104
	.4byte	.LASF259
	.byte	0x5
	.uleb128 0x105
	.4byte	.LASF260
	.byte	0x5
	.uleb128 0x106
	.4byte	.LASF261
	.byte	0x5
	.uleb128 0x107
	.4byte	.LASF262
	.byte	0x5
	.uleb128 0x108
	.4byte	.LASF263
	.byte	0x5
	.uleb128 0x109
	.4byte	.LASF264
	.byte	0x5
	.uleb128 0x10a
	.4byte	.LASF265
	.byte	0x5
	.uleb128 0x10b
	.4byte	.LASF266
	.byte	0x5
	.uleb128 0x10c
	.4byte	.LASF267
	.byte	0x5
	.uleb128 0x10d
	.4byte	.LASF268
	.byte	0x5
	.uleb128 0x10e
	.4byte	.LASF269
	.byte	0x5
	.uleb128 0x10f
	.4byte	.LASF270
	.byte	0x5
	.uleb128 0x110
	.4byte	.LASF271
	.byte	0x5
	.uleb128 0x111
	.4byte	.LASF272
	.byte	0x5
	.uleb128 0x112
	.4byte	.LASF273
	.byte	0x5
	.uleb128 0x113
	.4byte	.LASF274
	.byte	0x5
	.uleb128 0x114
	.4byte	.LASF275
	.byte	0x5
	.uleb128 0x115
	.4byte	.LASF276
	.byte	0x5
	.uleb128 0x116
	.4byte	.LASF277
	.byte	0x5
	.uleb128 0x117
	.4byte	.LASF278
	.byte	0x5
	.uleb128 0x118
	.4byte	.LASF279
	.byte	0x5
	.uleb128 0x119
	.4byte	.LASF280
	.byte	0x5
	.uleb128 0x11a
	.4byte	.LASF281
	.byte	0x5
	.uleb128 0x11b
	.4byte	.LASF282
	.byte	0x5
	.uleb128 0x11c
	.4byte	.LASF283
	.byte	0x5
	.uleb128 0x11d
	.4byte	.LASF284
	.byte	0x5
	.uleb128 0x11e
	.4byte	.LASF285
	.byte	0x5
	.uleb128 0x11f
	.4byte	.LASF286
	.byte	0x5
	.uleb128 0x120
	.4byte	.LASF287
	.byte	0x5
	.uleb128 0x121
	.4byte	.LASF288
	.byte	0x5
	.uleb128 0x122
	.4byte	.LASF289
	.byte	0x5
	.uleb128 0x123
	.4byte	.LASF290
	.byte	0x5
	.uleb128 0x124
	.4byte	.LASF291
	.byte	0x5
	.uleb128 0x125
	.4byte	.LASF292
	.byte	0x5
	.uleb128 0x126
	.4byte	.LASF293
	.byte	0x5
	.uleb128 0x127
	.4byte	.LASF294
	.byte	0x5
	.uleb128 0x128
	.4byte	.LASF295
	.byte	0x5
	.uleb128 0x129
	.4byte	.LASF296
	.byte	0x5
	.uleb128 0x12a
	.4byte	.LASF297
	.byte	0x5
	.uleb128 0x12b
	.4byte	.LASF298
	.byte	0x5
	.uleb128 0x12c
	.4byte	.LASF299
	.byte	0x5
	.uleb128 0x12d
	.4byte	.LASF300
	.byte	0x5
	.uleb128 0x12e
	.4byte	.LASF301
	.byte	0x5
	.uleb128 0x12f
	.4byte	.LASF302
	.byte	0x5
	.uleb128 0x130
	.4byte	.LASF303
	.byte	0x5
	.uleb128 0x131
	.4byte	.LASF304
	.byte	0x5
	.uleb128 0x132
	.4byte	.LASF305
	.byte	0x5
	.uleb128 0x133
	.4byte	.LASF306
	.byte	0x5
	.uleb128 0x134
	.4byte	.LASF307
	.byte	0x5
	.uleb128 0x135
	.4byte	.LASF308
	.byte	0x5
	.uleb128 0x136
	.4byte	.LASF309
	.byte	0x5
	.uleb128 0x137
	.4byte	.LASF310
	.byte	0x5
	.uleb128 0x138
	.4byte	.LASF311
	.byte	0x5
	.uleb128 0x139
	.4byte	.LASF312
	.byte	0x5
	.uleb128 0x13a
	.4byte	.LASF313
	.byte	0x5
	.uleb128 0x13b
	.4byte	.LASF314
	.byte	0x5
	.uleb128 0x13c
	.4byte	.LASF315
	.byte	0x5
	.uleb128 0x13d
	.4byte	.LASF316
	.byte	0x5
	.uleb128 0x13e
	.4byte	.LASF317
	.byte	0x5
	.uleb128 0x13f
	.4byte	.LASF318
	.byte	0x5
	.uleb128 0x140
	.4byte	.LASF319
	.byte	0x5
	.uleb128 0x141
	.4byte	.LASF320
	.byte	0x5
	.uleb128 0x142
	.4byte	.LASF321
	.byte	0x5
	.uleb128 0x143
	.4byte	.LASF322
	.byte	0x5
	.uleb128 0x144
	.4byte	.LASF323
	.byte	0x5
	.uleb128 0x145
	.4byte	.LASF324
	.byte	0x5
	.uleb128 0x146
	.4byte	.LASF325
	.byte	0x5
	.uleb128 0x147
	.4byte	.LASF326
	.byte	0x5
	.uleb128 0x148
	.4byte	.LASF327
	.byte	0x5
	.uleb128 0x149
	.4byte	.LASF328
	.byte	0x5
	.uleb128 0x14a
	.4byte	.LASF329
	.byte	0x5
	.uleb128 0x14b
	.4byte	.LASF330
	.byte	0x5
	.uleb128 0x14c
	.4byte	.LASF331
	.byte	0x5
	.uleb128 0x14d
	.4byte	.LASF332
	.byte	0x5
	.uleb128 0x14e
	.4byte	.LASF333
	.byte	0x5
	.uleb128 0x14f
	.4byte	.LASF334
	.byte	0x5
	.uleb128 0x150
	.4byte	.LASF335
	.byte	0x5
	.uleb128 0x151
	.4byte	.LASF336
	.byte	0x5
	.uleb128 0x152
	.4byte	.LASF337
	.byte	0x5
	.uleb128 0x153
	.4byte	.LASF338
	.byte	0x5
	.uleb128 0x154
	.4byte	.LASF339
	.byte	0x5
	.uleb128 0x155
	.4byte	.LASF340
	.byte	0x5
	.uleb128 0x156
	.4byte	.LASF341
	.byte	0x5
	.uleb128 0x157
	.4byte	.LASF342
	.byte	0x5
	.uleb128 0x158
	.4byte	.LASF343
	.byte	0x5
	.uleb128 0x159
	.4byte	.LASF344
	.byte	0x5
	.uleb128 0x15a
	.4byte	.LASF345
	.byte	0x5
	.uleb128 0x15b
	.4byte	.LASF346
	.byte	0x5
	.uleb128 0x15c
	.4byte	.LASF347
	.byte	0x5
	.uleb128 0x15d
	.4byte	.LASF348
	.byte	0x5
	.uleb128 0x15e
	.4byte	.LASF349
	.byte	0x5
	.uleb128 0x15f
	.4byte	.LASF350
	.byte	0x5
	.uleb128 0x160
	.4byte	.LASF351
	.byte	0x5
	.uleb128 0x161
	.4byte	.LASF352
	.byte	0x5
	.uleb128 0x162
	.4byte	.LASF353
	.byte	0x5
	.uleb128 0x163
	.4byte	.LASF354
	.byte	0x5
	.uleb128 0x164
	.4byte	.LASF355
	.byte	0x5
	.uleb128 0x165
	.4byte	.LASF356
	.byte	0x5
	.uleb128 0x166
	.4byte	.LASF357
	.byte	0x5
	.uleb128 0x1
	.4byte	.LASF358
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF359
	.byte	0x5
	.uleb128 0x3
	.4byte	.LASF360
	.byte	0x5
	.uleb128 0x4
	.4byte	.LASF361
	.byte	0x5
	.uleb128 0x5
	.4byte	.LASF362
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF363
	.byte	0x5
	.uleb128 0x7
	.4byte	.LASF364
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF365
	.file 7 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\_ansi.h"
	.byte	0x3
	.uleb128 0x25
	.uleb128 0x7
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF366
	.file 8 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\newlib.h"
	.byte	0x3
	.uleb128 0xf
	.uleb128 0x8
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF367
	.file 9 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\_newlib_version.h"
	.byte	0x3
	.uleb128 0xe
	.uleb128 0x9
	.byte	0x7
	.4byte	.Ldebug_macro1
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro2
	.byte	0x4
	.file 10 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\config.h"
	.byte	0x3
	.uleb128 0x10
	.uleb128 0xa
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF385
	.file 11 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\ieeefp.h"
	.byte	0x3
	.uleb128 0x4
	.uleb128 0xb
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF386
	.byte	0x4
	.file 12 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\features.h"
	.byte	0x3
	.uleb128 0x5
	.uleb128 0xc
	.byte	0x7
	.4byte	.Ldebug_macro3
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro4
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro5
	.byte	0x4
	.file 13 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\_syslist.h"
	.byte	0x3
	.uleb128 0x26
	.uleb128 0xd
	.byte	0x7
	.4byte	.Ldebug_macro6
	.byte	0x4
	.file 14 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\errno.h"
	.byte	0x3
	.uleb128 0x27
	.uleb128 0xe
	.byte	0x7
	.4byte	.Ldebug_macro7
	.byte	0x3
	.uleb128 0x9
	.uleb128 0x6
	.byte	0x5
	.uleb128 0x9
	.4byte	.LASF445
	.file 15 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\reent.h"
	.byte	0x3
	.uleb128 0xb
	.uleb128 0xf
	.byte	0x5
	.uleb128 0xb
	.4byte	.LASF446
	.file 16 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\lib\\gcc\\arm-none-eabi\\5.4.1\\include\\stddef.h"
	.byte	0x3
	.uleb128 0xe
	.uleb128 0x10
	.byte	0x7
	.4byte	.Ldebug_macro8
	.byte	0x4
	.byte	0x3
	.uleb128 0xf
	.uleb128 0x2
	.byte	0x5
	.uleb128 0x14
	.4byte	.LASF500
	.file 17 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\_types.h"
	.byte	0x3
	.uleb128 0x18
	.uleb128 0x11
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF501
	.file 18 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\_default_types.h"
	.byte	0x3
	.uleb128 0x7
	.uleb128 0x12
	.byte	0x7
	.4byte	.Ldebug_macro9
	.byte	0x4
	.byte	0x4
	.file 19 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\lock.h"
	.byte	0x3
	.uleb128 0x19
	.uleb128 0x13
	.byte	0x7
	.4byte	.Ldebug_macro10
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro11
	.byte	0x3
	.uleb128 0x9f
	.uleb128 0x10
	.byte	0x7
	.4byte	.Ldebug_macro12
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro13
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro14
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro15
	.byte	0x4
	.byte	0x4
	.file 20 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\stat.h"
	.byte	0x3
	.uleb128 0x29
	.uleb128 0x14
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF680
	.file 21 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\time.h"
	.byte	0x3
	.uleb128 0x9
	.uleb128 0x15
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF681
	.byte	0x3
	.uleb128 0xa
	.uleb128 0x7
	.byte	0x4
	.file 22 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\cdefs.h"
	.byte	0x3
	.uleb128 0xb
	.uleb128 0x16
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF682
	.byte	0x3
	.uleb128 0x2d
	.uleb128 0x10
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro16
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro17
	.byte	0x3
	.uleb128 0x10
	.uleb128 0x10
	.byte	0x7
	.4byte	.Ldebug_macro18
	.byte	0x4
	.file 23 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\time.h"
	.byte	0x3
	.uleb128 0x13
	.uleb128 0x17
	.byte	0x7
	.4byte	.Ldebug_macro19
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro20
	.byte	0x3
	.uleb128 0x1c
	.uleb128 0x3
	.byte	0x7
	.4byte	.Ldebug_macro21
	.byte	0x3
	.uleb128 0x3e
	.uleb128 0x10
	.byte	0x4
	.file 24 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\_stdint.h"
	.byte	0x3
	.uleb128 0x40
	.uleb128 0x18
	.byte	0x7
	.4byte	.Ldebug_macro22
	.byte	0x4
	.file 25 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\endian.h"
	.byte	0x3
	.uleb128 0x43
	.uleb128 0x19
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF821
	.file 26 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\_endian.h"
	.byte	0x3
	.uleb128 0x6
	.uleb128 0x1a
	.byte	0x7
	.4byte	.Ldebug_macro23
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro24
	.byte	0x4
	.file 27 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\select.h"
	.byte	0x3
	.uleb128 0x44
	.uleb128 0x1b
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF839
	.file 28 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\_sigset.h"
	.byte	0x3
	.uleb128 0x19
	.uleb128 0x1c
	.byte	0x5
	.uleb128 0x27
	.4byte	.LASF840
	.byte	0x4
	.file 29 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\_timeval.h"
	.byte	0x3
	.uleb128 0x1a
	.uleb128 0x1d
	.byte	0x7
	.4byte	.Ldebug_macro25
	.byte	0x4
	.file 30 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\timespec.h"
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x1e
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF851
	.file 31 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\_timespec.h"
	.byte	0x3
	.uleb128 0x26
	.uleb128 0x1f
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF852
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro26
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro27
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro28
	.file 32 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\types.h"
	.byte	0x3
	.uleb128 0x1d1
	.uleb128 0x20
	.byte	0x4
	.byte	0x6
	.uleb128 0x1d5
	.4byte	.LASF897
	.byte	0x4
	.file 33 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\_locale.h"
	.byte	0x3
	.uleb128 0x20
	.uleb128 0x21
	.byte	0x5
	.uleb128 0x4
	.4byte	.LASF898
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro29
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro30
	.byte	0x4
	.file 34 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\time.h"
	.byte	0x3
	.uleb128 0x2a
	.uleb128 0x22
	.byte	0x7
	.4byte	.Ldebug_macro31
	.file 35 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\machine\\_time.h"
	.byte	0x3
	.uleb128 0x12c
	.uleb128 0x23
	.byte	0x4
	.byte	0x4
	.file 36 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\sys\\times.h"
	.byte	0x3
	.uleb128 0x2b
	.uleb128 0x24
	.byte	0x5
	.uleb128 0x5
	.4byte	.LASF972
	.byte	0x4
	.file 37 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\lib\\gcc\\arm-none-eabi\\5.4.1\\include-fixed\\limits.h"
	.byte	0x3
	.uleb128 0x2c
	.uleb128 0x25
	.byte	0x5
	.uleb128 0x1e
	.4byte	.LASF973
	.file 38 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\lib\\gcc\\arm-none-eabi\\5.4.1\\include-fixed\\syslimits.h"
	.byte	0x3
	.uleb128 0x22
	.uleb128 0x26
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF974
	.byte	0x3
	.uleb128 0x7
	.uleb128 0x25
	.file 39 "e:\\iti_9_months\\embeddedsystems\\tourkey\\tools\\arm gcc\\arm-none-eabi\\include\\limits.h"
	.byte	0x3
	.uleb128 0xa8
	.uleb128 0x27
	.byte	0x7
	.4byte	.Ldebug_macro32
	.byte	0x4
	.byte	0x4
	.byte	0x6
	.uleb128 0x8
	.4byte	.LASF981
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro33
	.byte	0x4
	.byte	0x3
	.uleb128 0x2d
	.uleb128 0x4
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF1025
	.byte	0x3
	.uleb128 0x6
	.uleb128 0x5
	.byte	0x7
	.4byte	.Ldebug_macro34
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro35
	.byte	0x4
	.byte	0x4
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._newlib_version.h.4.ad342815780c8db09778091a421b5b5b,comdat
.Ldebug_macro1:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x4
	.4byte	.LASF368
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF369
	.byte	0x5
	.uleb128 0x7
	.4byte	.LASF370
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF371
	.byte	0x5
	.uleb128 0x9
	.4byte	.LASF372
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.newlib.h.21.0b9fc973bddc8b940a18de2b6ea6adc7,comdat
.Ldebug_macro2:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF373
	.byte	0x5
	.uleb128 0x18
	.4byte	.LASF374
	.byte	0x5
	.uleb128 0x28
	.4byte	.LASF375
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF376
	.byte	0x5
	.uleb128 0x36
	.4byte	.LASF377
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF378
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF379
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF380
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF381
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF382
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF383
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF384
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.features.h.22.5cdadbb3efe495d1c9e38350b8c376c7,comdat
.Ldebug_macro3:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x16
	.4byte	.LASF387
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF388
	.byte	0x5
	.uleb128 0x28
	.4byte	.LASF389
	.byte	0x6
	.uleb128 0x80
	.4byte	.LASF390
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF391
	.byte	0x6
	.uleb128 0x85
	.4byte	.LASF392
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF393
	.byte	0x6
	.uleb128 0x87
	.4byte	.LASF394
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF395
	.byte	0x6
	.uleb128 0x9b
	.4byte	.LASF396
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF397
	.byte	0x5
	.uleb128 0xf2
	.4byte	.LASF398
	.byte	0x5
	.uleb128 0xf8
	.4byte	.LASF399
	.byte	0x5
	.uleb128 0x100
	.4byte	.LASF400
	.byte	0x5
	.uleb128 0x105
	.4byte	.LASF401
	.byte	0x5
	.uleb128 0x110
	.4byte	.LASF402
	.byte	0x5
	.uleb128 0x114
	.4byte	.LASF403
	.byte	0x5
	.uleb128 0x11a
	.4byte	.LASF404
	.byte	0x5
	.uleb128 0x12a
	.4byte	.LASF405
	.byte	0x5
	.uleb128 0x13a
	.4byte	.LASF406
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.config.h.219.65a553ab5bef5482f0d7880b0d33015e,comdat
.Ldebug_macro4:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xdb
	.4byte	.LASF407
	.byte	0x6
	.uleb128 0xe1
	.4byte	.LASF408
	.byte	0x5
	.uleb128 0xe5
	.4byte	.LASF409
	.byte	0x5
	.uleb128 0xf4
	.4byte	.LASF410
	.byte	0x5
	.uleb128 0xf8
	.4byte	.LASF411
	.byte	0x5
	.uleb128 0xff
	.4byte	.LASF412
	.byte	0x5
	.uleb128 0x105
	.4byte	.LASF413
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._ansi.h.23.9f8fcfa20193763fcf364fb91705c94b,comdat
.Ldebug_macro5:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF414
	.byte	0x5
	.uleb128 0x2c
	.4byte	.LASF415
	.byte	0x5
	.uleb128 0x2d
	.4byte	.LASF416
	.byte	0x5
	.uleb128 0x2e
	.4byte	.LASF417
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF418
	.byte	0x5
	.uleb128 0x33
	.4byte	.LASF419
	.byte	0x5
	.uleb128 0x34
	.4byte	.LASF420
	.byte	0x5
	.uleb128 0x35
	.4byte	.LASF421
	.byte	0x5
	.uleb128 0x36
	.4byte	.LASF422
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF423
	.byte	0x5
	.uleb128 0x38
	.4byte	.LASF424
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF425
	.byte	0x5
	.uleb128 0x40
	.4byte	.LASF426
	.byte	0x5
	.uleb128 0x41
	.4byte	.LASF427
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF428
	.byte	0x5
	.uleb128 0x43
	.4byte	.LASF429
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF430
	.byte	0x5
	.uleb128 0x46
	.4byte	.LASF431
	.byte	0x5
	.uleb128 0x47
	.4byte	.LASF432
	.byte	0x5
	.uleb128 0x49
	.4byte	.LASF433
	.byte	0x5
	.uleb128 0x4c
	.4byte	.LASF434
	.byte	0x5
	.uleb128 0x65
	.4byte	.LASF435
	.byte	0x5
	.uleb128 0x7f
	.4byte	.LASF436
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF437
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF438
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._syslist.h.4.cca0a711aaf6863107c5beb8fad7c2bf,comdat
.Ldebug_macro6:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x4
	.4byte	.LASF439
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF440
	.byte	0x5
	.uleb128 0x24
	.4byte	.LASF441
	.byte	0x5
	.uleb128 0x25
	.4byte	.LASF442
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.errno.h.2.ba016d646105af6cad23be83630b6a3f,comdat
.Ldebug_macro7:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF443
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF444
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.stddef.h.39.a38874c8f8a57e66301090908ec2a69f,comdat
.Ldebug_macro8:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x27
	.4byte	.LASF447
	.byte	0x5
	.uleb128 0x28
	.4byte	.LASF448
	.byte	0x5
	.uleb128 0x2a
	.4byte	.LASF449
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF450
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF451
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF452
	.byte	0x5
	.uleb128 0x8c
	.4byte	.LASF453
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF454
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF455
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF456
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF457
	.byte	0x5
	.uleb128 0x91
	.4byte	.LASF458
	.byte	0x6
	.uleb128 0xa1
	.4byte	.LASF459
	.byte	0x5
	.uleb128 0xbb
	.4byte	.LASF460
	.byte	0x5
	.uleb128 0xbc
	.4byte	.LASF461
	.byte	0x5
	.uleb128 0xbd
	.4byte	.LASF462
	.byte	0x5
	.uleb128 0xbe
	.4byte	.LASF463
	.byte	0x5
	.uleb128 0xbf
	.4byte	.LASF464
	.byte	0x5
	.uleb128 0xc0
	.4byte	.LASF465
	.byte	0x5
	.uleb128 0xc1
	.4byte	.LASF466
	.byte	0x5
	.uleb128 0xc2
	.4byte	.LASF467
	.byte	0x5
	.uleb128 0xc3
	.4byte	.LASF468
	.byte	0x5
	.uleb128 0xc4
	.4byte	.LASF469
	.byte	0x5
	.uleb128 0xc5
	.4byte	.LASF470
	.byte	0x5
	.uleb128 0xc6
	.4byte	.LASF471
	.byte	0x5
	.uleb128 0xc7
	.4byte	.LASF472
	.byte	0x5
	.uleb128 0xc8
	.4byte	.LASF473
	.byte	0x5
	.uleb128 0xc9
	.4byte	.LASF474
	.byte	0x5
	.uleb128 0xca
	.4byte	.LASF475
	.byte	0x5
	.uleb128 0xd2
	.4byte	.LASF476
	.byte	0x6
	.uleb128 0xee
	.4byte	.LASF477
	.byte	0x5
	.uleb128 0x10b
	.4byte	.LASF478
	.byte	0x5
	.uleb128 0x10c
	.4byte	.LASF479
	.byte	0x5
	.uleb128 0x10d
	.4byte	.LASF480
	.byte	0x5
	.uleb128 0x10e
	.4byte	.LASF481
	.byte	0x5
	.uleb128 0x10f
	.4byte	.LASF482
	.byte	0x5
	.uleb128 0x110
	.4byte	.LASF483
	.byte	0x5
	.uleb128 0x111
	.4byte	.LASF484
	.byte	0x5
	.uleb128 0x112
	.4byte	.LASF485
	.byte	0x5
	.uleb128 0x113
	.4byte	.LASF486
	.byte	0x5
	.uleb128 0x114
	.4byte	.LASF487
	.byte	0x5
	.uleb128 0x115
	.4byte	.LASF488
	.byte	0x5
	.uleb128 0x116
	.4byte	.LASF489
	.byte	0x5
	.uleb128 0x117
	.4byte	.LASF490
	.byte	0x5
	.uleb128 0x118
	.4byte	.LASF491
	.byte	0x5
	.uleb128 0x119
	.4byte	.LASF492
	.byte	0x6
	.uleb128 0x126
	.4byte	.LASF493
	.byte	0x6
	.uleb128 0x15b
	.4byte	.LASF494
	.byte	0x6
	.uleb128 0x191
	.4byte	.LASF495
	.byte	0x5
	.uleb128 0x196
	.4byte	.LASF496
	.byte	0x6
	.uleb128 0x19c
	.4byte	.LASF497
	.byte	0x5
	.uleb128 0x1a1
	.4byte	.LASF498
	.byte	0x5
	.uleb128 0x1a6
	.4byte	.LASF499
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._default_types.h.6.35ee9e747940367bf2a634907d1c2382,comdat
.Ldebug_macro9:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF502
	.byte	0x5
	.uleb128 0xf
	.4byte	.LASF503
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF504
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF505
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF506
	.byte	0x5
	.uleb128 0x5f
	.4byte	.LASF507
	.byte	0x5
	.uleb128 0x7e
	.4byte	.LASF508
	.byte	0x5
	.uleb128 0x98
	.4byte	.LASF509
	.byte	0x5
	.uleb128 0xae
	.4byte	.LASF510
	.byte	0x5
	.uleb128 0xc0
	.4byte	.LASF511
	.byte	0x6
	.uleb128 0xd6
	.4byte	.LASF512
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.lock.h.2.9bc98482741e5e2a9450b12934a684ea,comdat
.Ldebug_macro10:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF513
	.byte	0x5
	.uleb128 0xb
	.4byte	.LASF514
	.byte	0x5
	.uleb128 0xc
	.4byte	.LASF515
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF516
	.byte	0x5
	.uleb128 0xe
	.4byte	.LASF517
	.byte	0x5
	.uleb128 0xf
	.4byte	.LASF518
	.byte	0x5
	.uleb128 0x10
	.4byte	.LASF519
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF520
	.byte	0x5
	.uleb128 0x12
	.4byte	.LASF521
	.byte	0x5
	.uleb128 0x13
	.4byte	.LASF522
	.byte	0x5
	.uleb128 0x14
	.4byte	.LASF523
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF524
	.byte	0x5
	.uleb128 0x16
	.4byte	.LASF525
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._types.h.125.5cf8a495f1f7ef36777ad868a1e32068,comdat
.Ldebug_macro11:
	.2byte	0x4
	.byte	0
	.byte	0x6
	.uleb128 0x7d
	.4byte	.LASF526
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF527
	.byte	0x6
	.uleb128 0x92
	.4byte	.LASF528
	.byte	0x5
	.uleb128 0x9e
	.4byte	.LASF529
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.stddef.h.161.5349cb105733e8777bfb0cf53c4e3f34,comdat
.Ldebug_macro12:
	.2byte	0x4
	.byte	0
	.byte	0x6
	.uleb128 0xa1
	.4byte	.LASF459
	.byte	0x6
	.uleb128 0xee
	.4byte	.LASF477
	.byte	0x6
	.uleb128 0x15b
	.4byte	.LASF494
	.byte	0x5
	.uleb128 0x160
	.4byte	.LASF530
	.byte	0x6
	.uleb128 0x167
	.4byte	.LASF531
	.byte	0x6
	.uleb128 0x191
	.4byte	.LASF495
	.byte	0x5
	.uleb128 0x196
	.4byte	.LASF496
	.byte	0x6
	.uleb128 0x19c
	.4byte	.LASF497
	.byte	0x5
	.uleb128 0x1a1
	.4byte	.LASF498
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._types.h.183.c226d164ceca1f2ecb9ae9360c54a098,comdat
.Ldebug_macro13:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xb7
	.4byte	.LASF532
	.byte	0x5
	.uleb128 0xba
	.4byte	.LASF533
	.byte	0x5
	.uleb128 0xbd
	.4byte	.LASF534
	.byte	0x5
	.uleb128 0xc0
	.4byte	.LASF535
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.reent.h.17.23b059516345f8f5abfa01ddc379570f,comdat
.Ldebug_macro14:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF536
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF537
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF538
	.byte	0x5
	.uleb128 0x64
	.4byte	.LASF539
	.byte	0x5
	.uleb128 0x6a
	.4byte	.LASF540
	.byte	0x5
	.uleb128 0xb2
	.4byte	.LASF541
	.byte	0x5
	.uleb128 0x138
	.4byte	.LASF542
	.byte	0x5
	.uleb128 0x139
	.4byte	.LASF543
	.byte	0x5
	.uleb128 0x13a
	.4byte	.LASF544
	.byte	0x5
	.uleb128 0x13b
	.4byte	.LASF545
	.byte	0x5
	.uleb128 0x13c
	.4byte	.LASF546
	.byte	0x5
	.uleb128 0x13d
	.4byte	.LASF547
	.byte	0x5
	.uleb128 0x13e
	.4byte	.LASF548
	.byte	0x5
	.uleb128 0x14a
	.4byte	.LASF549
	.byte	0x5
	.uleb128 0x14b
	.4byte	.LASF550
	.byte	0x5
	.uleb128 0x14c
	.4byte	.LASF551
	.byte	0x5
	.uleb128 0x274
	.4byte	.LASF552
	.byte	0x5
	.uleb128 0x28a
	.4byte	.LASF553
	.byte	0x5
	.uleb128 0x2ba
	.4byte	.LASF554
	.byte	0x5
	.uleb128 0x2c8
	.4byte	.LASF555
	.byte	0x5
	.uleb128 0x2c9
	.4byte	.LASF556
	.byte	0x5
	.uleb128 0x2ca
	.4byte	.LASF557
	.byte	0x5
	.uleb128 0x2cb
	.4byte	.LASF558
	.byte	0x5
	.uleb128 0x2cc
	.4byte	.LASF559
	.byte	0x5
	.uleb128 0x2cd
	.4byte	.LASF560
	.byte	0x5
	.uleb128 0x2ce
	.4byte	.LASF561
	.byte	0x5
	.uleb128 0x2d0
	.4byte	.LASF562
	.byte	0x5
	.uleb128 0x2d1
	.4byte	.LASF563
	.byte	0x5
	.uleb128 0x2d2
	.4byte	.LASF564
	.byte	0x5
	.uleb128 0x2d3
	.4byte	.LASF565
	.byte	0x5
	.uleb128 0x2d4
	.4byte	.LASF566
	.byte	0x5
	.uleb128 0x2d5
	.4byte	.LASF567
	.byte	0x5
	.uleb128 0x2d6
	.4byte	.LASF568
	.byte	0x5
	.uleb128 0x2d7
	.4byte	.LASF569
	.byte	0x5
	.uleb128 0x2d8
	.4byte	.LASF570
	.byte	0x5
	.uleb128 0x2d9
	.4byte	.LASF571
	.byte	0x5
	.uleb128 0x2da
	.4byte	.LASF572
	.byte	0x5
	.uleb128 0x2db
	.4byte	.LASF573
	.byte	0x5
	.uleb128 0x2dc
	.4byte	.LASF574
	.byte	0x5
	.uleb128 0x2dd
	.4byte	.LASF575
	.byte	0x5
	.uleb128 0x2de
	.4byte	.LASF576
	.byte	0x5
	.uleb128 0x2df
	.4byte	.LASF577
	.byte	0x5
	.uleb128 0x2e0
	.4byte	.LASF578
	.byte	0x5
	.uleb128 0x2e1
	.4byte	.LASF579
	.byte	0x5
	.uleb128 0x2e2
	.4byte	.LASF580
	.byte	0x5
	.uleb128 0x2e3
	.4byte	.LASF581
	.byte	0x5
	.uleb128 0x2e4
	.4byte	.LASF582
	.byte	0x5
	.uleb128 0x2e5
	.4byte	.LASF583
	.byte	0x5
	.uleb128 0x2e6
	.4byte	.LASF584
	.byte	0x5
	.uleb128 0x2e7
	.4byte	.LASF585
	.byte	0x5
	.uleb128 0x2eb
	.4byte	.LASF586
	.byte	0x5
	.uleb128 0x2f3
	.4byte	.LASF587
	.byte	0x5
	.uleb128 0x2fb
	.4byte	.LASF588
	.byte	0x5
	.uleb128 0x30b
	.4byte	.LASF589
	.byte	0x5
	.uleb128 0x30e
	.4byte	.LASF590
	.byte	0x5
	.uleb128 0x314
	.4byte	.LASF591
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.errno.h.14.6a5939d3ae7434a1e97991a97123b12d,comdat
.Ldebug_macro15:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xe
	.4byte	.LASF592
	.byte	0x5
	.uleb128 0x1d
	.4byte	.LASF593
	.byte	0x5
	.uleb128 0x1f
	.4byte	.LASF594
	.byte	0x5
	.uleb128 0x20
	.4byte	.LASF595
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF596
	.byte	0x5
	.uleb128 0x22
	.4byte	.LASF597
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF598
	.byte	0x5
	.uleb128 0x24
	.4byte	.LASF599
	.byte	0x5
	.uleb128 0x25
	.4byte	.LASF600
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF601
	.byte	0x5
	.uleb128 0x27
	.4byte	.LASF602
	.byte	0x5
	.uleb128 0x28
	.4byte	.LASF603
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF604
	.byte	0x5
	.uleb128 0x2a
	.4byte	.LASF605
	.byte	0x5
	.uleb128 0x2b
	.4byte	.LASF606
	.byte	0x5
	.uleb128 0x2c
	.4byte	.LASF607
	.byte	0x5
	.uleb128 0x30
	.4byte	.LASF608
	.byte	0x5
	.uleb128 0x31
	.4byte	.LASF609
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF610
	.byte	0x5
	.uleb128 0x33
	.4byte	.LASF611
	.byte	0x5
	.uleb128 0x34
	.4byte	.LASF612
	.byte	0x5
	.uleb128 0x35
	.4byte	.LASF613
	.byte	0x5
	.uleb128 0x36
	.4byte	.LASF614
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF615
	.byte	0x5
	.uleb128 0x38
	.4byte	.LASF616
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF617
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF618
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF619
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF620
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF621
	.byte	0x5
	.uleb128 0x3e
	.4byte	.LASF622
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF623
	.byte	0x5
	.uleb128 0x40
	.4byte	.LASF624
	.byte	0x5
	.uleb128 0x41
	.4byte	.LASF625
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF626
	.byte	0x5
	.uleb128 0x43
	.4byte	.LASF627
	.byte	0x5
	.uleb128 0x44
	.4byte	.LASF628
	.byte	0x5
	.uleb128 0x4f
	.4byte	.LASF629
	.byte	0x5
	.uleb128 0x50
	.4byte	.LASF630
	.byte	0x5
	.uleb128 0x5b
	.4byte	.LASF631
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF632
	.byte	0x5
	.uleb128 0x5d
	.4byte	.LASF633
	.byte	0x5
	.uleb128 0x5e
	.4byte	.LASF634
	.byte	0x5
	.uleb128 0x64
	.4byte	.LASF635
	.byte	0x5
	.uleb128 0x6a
	.4byte	.LASF636
	.byte	0x5
	.uleb128 0x6b
	.4byte	.LASF637
	.byte	0x5
	.uleb128 0x70
	.4byte	.LASF638
	.byte	0x5
	.uleb128 0x71
	.4byte	.LASF639
	.byte	0x5
	.uleb128 0x7c
	.4byte	.LASF640
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF641
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF642
	.byte	0x5
	.uleb128 0x82
	.4byte	.LASF643
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF644
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF645
	.byte	0x5
	.uleb128 0x85
	.4byte	.LASF646
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF647
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF648
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF649
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF650
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF651
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF652
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF653
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF654
	.byte	0x5
	.uleb128 0x91
	.4byte	.LASF655
	.byte	0x5
	.uleb128 0x92
	.4byte	.LASF656
	.byte	0x5
	.uleb128 0x93
	.4byte	.LASF657
	.byte	0x5
	.uleb128 0x94
	.4byte	.LASF658
	.byte	0x5
	.uleb128 0x95
	.4byte	.LASF659
	.byte	0x5
	.uleb128 0x96
	.4byte	.LASF660
	.byte	0x5
	.uleb128 0x97
	.4byte	.LASF661
	.byte	0x5
	.uleb128 0x98
	.4byte	.LASF662
	.byte	0x5
	.uleb128 0x99
	.4byte	.LASF663
	.byte	0x5
	.uleb128 0x9a
	.4byte	.LASF664
	.byte	0x5
	.uleb128 0x9e
	.4byte	.LASF665
	.byte	0x5
	.uleb128 0x9f
	.4byte	.LASF666
	.byte	0x5
	.uleb128 0xa0
	.4byte	.LASF667
	.byte	0x5
	.uleb128 0xa1
	.4byte	.LASF668
	.byte	0x5
	.uleb128 0xa2
	.4byte	.LASF669
	.byte	0x5
	.uleb128 0xa7
	.4byte	.LASF670
	.byte	0x5
	.uleb128 0xa8
	.4byte	.LASF671
	.byte	0x5
	.uleb128 0xa9
	.4byte	.LASF672
	.byte	0x5
	.uleb128 0xb1
	.4byte	.LASF673
	.byte	0x5
	.uleb128 0xb2
	.4byte	.LASF674
	.byte	0x5
	.uleb128 0xb3
	.4byte	.LASF675
	.byte	0x5
	.uleb128 0xb4
	.4byte	.LASF676
	.byte	0x5
	.uleb128 0xb5
	.4byte	.LASF677
	.byte	0x5
	.uleb128 0xb9
	.4byte	.LASF678
	.byte	0x5
	.uleb128 0xbb
	.4byte	.LASF679
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.cdefs.h.47.ba62642086d429b4f95c2381cae1c0aa,comdat
.Ldebug_macro16:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF683
	.byte	0x5
	.uleb128 0x30
	.4byte	.LASF684
	.byte	0x5
	.uleb128 0x31
	.4byte	.LASF685
	.byte	0x5
	.uleb128 0x34
	.4byte	.LASF686
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF687
	.byte	0x5
	.uleb128 0x38
	.4byte	.LASF688
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF689
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF690
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF691
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF692
	.byte	0x5
	.uleb128 0x40
	.4byte	.LASF693
	.byte	0x5
	.uleb128 0x41
	.4byte	.LASF694
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF695
	.byte	0x5
	.uleb128 0x4c
	.4byte	.LASF696
	.byte	0x5
	.uleb128 0x4f
	.4byte	.LASF697
	.byte	0x5
	.uleb128 0x55
	.4byte	.LASF698
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF699
	.byte	0x5
	.uleb128 0x5d
	.4byte	.LASF700
	.byte	0x5
	.uleb128 0x69
	.4byte	.LASF701
	.byte	0x5
	.uleb128 0x6a
	.4byte	.LASF702
	.byte	0x5
	.uleb128 0x6e
	.4byte	.LASF703
	.byte	0x5
	.uleb128 0x6f
	.4byte	.LASF704
	.byte	0x5
	.uleb128 0x70
	.4byte	.LASF705
	.byte	0x5
	.uleb128 0x73
	.4byte	.LASF706
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF707
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF708
	.byte	0x5
	.uleb128 0x7e
	.4byte	.LASF709
	.byte	0x5
	.uleb128 0x7f
	.4byte	.LASF710
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF711
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF712
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF713
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF714
	.byte	0x5
	.uleb128 0x92
	.4byte	.LASF715
	.byte	0x5
	.uleb128 0x95
	.4byte	.LASF716
	.byte	0x5
	.uleb128 0x96
	.4byte	.LASF717
	.byte	0x5
	.uleb128 0x97
	.4byte	.LASF718
	.byte	0x5
	.uleb128 0x99
	.4byte	.LASF719
	.byte	0x5
	.uleb128 0x9a
	.4byte	.LASF720
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF721
	.byte	0x5
	.uleb128 0x9e
	.4byte	.LASF722
	.byte	0x5
	.uleb128 0xaf
	.4byte	.LASF723
	.byte	0x5
	.uleb128 0xb0
	.4byte	.LASF724
	.byte	0x5
	.uleb128 0xb1
	.4byte	.LASF725
	.byte	0x5
	.uleb128 0xb2
	.4byte	.LASF726
	.byte	0x5
	.uleb128 0xb3
	.4byte	.LASF727
	.byte	0x5
	.uleb128 0xb5
	.4byte	.LASF728
	.byte	0x5
	.uleb128 0xb6
	.4byte	.LASF729
	.byte	0x5
	.uleb128 0xb7
	.4byte	.LASF730
	.byte	0x5
	.uleb128 0xef
	.4byte	.LASF731
	.byte	0x5
	.uleb128 0xfc
	.4byte	.LASF732
	.byte	0x5
	.uleb128 0xfd
	.4byte	.LASF733
	.byte	0x5
	.uleb128 0xfe
	.4byte	.LASF734
	.byte	0x5
	.uleb128 0xff
	.4byte	.LASF735
	.byte	0x5
	.uleb128 0x100
	.4byte	.LASF736
	.byte	0x5
	.uleb128 0x101
	.4byte	.LASF737
	.byte	0x5
	.uleb128 0x102
	.4byte	.LASF738
	.byte	0x5
	.uleb128 0x105
	.4byte	.LASF739
	.byte	0x5
	.uleb128 0x10a
	.4byte	.LASF740
	.byte	0x5
	.uleb128 0x163
	.4byte	.LASF741
	.byte	0x5
	.uleb128 0x16c
	.4byte	.LASF742
	.byte	0x5
	.uleb128 0x16d
	.4byte	.LASF743
	.byte	0x5
	.uleb128 0x174
	.4byte	.LASF744
	.byte	0x5
	.uleb128 0x17a
	.4byte	.LASF745
	.byte	0x5
	.uleb128 0x180
	.4byte	.LASF746
	.byte	0x5
	.uleb128 0x181
	.4byte	.LASF747
	.byte	0x5
	.uleb128 0x188
	.4byte	.LASF748
	.byte	0x5
	.uleb128 0x189
	.4byte	.LASF749
	.byte	0x5
	.uleb128 0x190
	.4byte	.LASF750
	.byte	0x5
	.uleb128 0x196
	.4byte	.LASF751
	.byte	0x5
	.uleb128 0x1aa
	.4byte	.LASF752
	.byte	0x5
	.uleb128 0x1cb
	.4byte	.LASF753
	.byte	0x5
	.uleb128 0x1cc
	.4byte	.LASF754
	.byte	0x5
	.uleb128 0x1d3
	.4byte	.LASF755
	.byte	0x5
	.uleb128 0x1d4
	.4byte	.LASF756
	.byte	0x5
	.uleb128 0x1d5
	.4byte	.LASF757
	.byte	0x5
	.uleb128 0x1dc
	.4byte	.LASF758
	.byte	0x5
	.uleb128 0x1dd
	.4byte	.LASF759
	.byte	0x5
	.uleb128 0x1e7
	.4byte	.LASF760
	.byte	0x5
	.uleb128 0x1fd
	.4byte	.LASF761
	.byte	0x5
	.uleb128 0x1ff
	.4byte	.LASF762
	.byte	0x5
	.uleb128 0x201
	.4byte	.LASF763
	.byte	0x5
	.uleb128 0x202
	.4byte	.LASF764
	.byte	0x5
	.uleb128 0x204
	.4byte	.LASF765
	.byte	0x5
	.uleb128 0x210
	.4byte	.LASF766
	.byte	0x5
	.uleb128 0x21e
	.4byte	.LASF767
	.byte	0x5
	.uleb128 0x223
	.4byte	.LASF768
	.byte	0x5
	.uleb128 0x228
	.4byte	.LASF769
	.byte	0x5
	.uleb128 0x22b
	.4byte	.LASF770
	.byte	0x5
	.uleb128 0x22f
	.4byte	.LASF771
	.byte	0x5
	.uleb128 0x231
	.4byte	.LASF772
	.byte	0x5
	.uleb128 0x254
	.4byte	.LASF773
	.byte	0x5
	.uleb128 0x258
	.4byte	.LASF774
	.byte	0x5
	.uleb128 0x25c
	.4byte	.LASF775
	.byte	0x5
	.uleb128 0x260
	.4byte	.LASF776
	.byte	0x5
	.uleb128 0x264
	.4byte	.LASF777
	.byte	0x5
	.uleb128 0x268
	.4byte	.LASF778
	.byte	0x5
	.uleb128 0x26c
	.4byte	.LASF779
	.byte	0x5
	.uleb128 0x270
	.4byte	.LASF780
	.byte	0x5
	.uleb128 0x281
	.4byte	.LASF781
	.byte	0x5
	.uleb128 0x282
	.4byte	.LASF782
	.byte	0x5
	.uleb128 0x294
	.4byte	.LASF783
	.byte	0x5
	.uleb128 0x298
	.4byte	.LASF784
	.byte	0x5
	.uleb128 0x29b
	.4byte	.LASF785
	.byte	0x5
	.uleb128 0x29d
	.4byte	.LASF786
	.byte	0x5
	.uleb128 0x2a1
	.4byte	.LASF787
	.byte	0x5
	.uleb128 0x2a3
	.4byte	.LASF788
	.byte	0x5
	.uleb128 0x2a7
	.4byte	.LASF789
	.byte	0x5
	.uleb128 0x2aa
	.4byte	.LASF790
	.byte	0x5
	.uleb128 0x2ac
	.4byte	.LASF791
	.byte	0x5
	.uleb128 0x2b0
	.4byte	.LASF792
	.byte	0x5
	.uleb128 0x2b2
	.4byte	.LASF793
	.byte	0x5
	.uleb128 0x2b4
	.4byte	.LASF794
	.byte	0x5
	.uleb128 0x2b8
	.4byte	.LASF795
	.byte	0x5
	.uleb128 0x2bb
	.4byte	.LASF796
	.byte	0x5
	.uleb128 0x2bc
	.4byte	.LASF797
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.time.h.14.849270cc7997ccc4e05edd146e568a9f,comdat
.Ldebug_macro17:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xe
	.4byte	.LASF798
	.byte	0x5
	.uleb128 0xf
	.4byte	.LASF799
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.stddef.h.161.19e15733342b50ead2919490b095303e,comdat
.Ldebug_macro18:
	.2byte	0x4
	.byte	0
	.byte	0x6
	.uleb128 0xa1
	.4byte	.LASF459
	.byte	0x6
	.uleb128 0xee
	.4byte	.LASF477
	.byte	0x6
	.uleb128 0x15b
	.4byte	.LASF494
	.byte	0x6
	.uleb128 0x191
	.4byte	.LASF495
	.byte	0x5
	.uleb128 0x196
	.4byte	.LASF496
	.byte	0x6
	.uleb128 0x19c
	.4byte	.LASF497
	.byte	0x5
	.uleb128 0x1a1
	.4byte	.LASF498
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.time.h.2.4581ce0ffb6627cfc02162c94bf846c9,comdat
.Ldebug_macro19:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF800
	.byte	0x5
	.uleb128 0x7
	.4byte	.LASF801
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.time.h.25.0e6a0fdbc9955f5707ed54246ed2e089,comdat
.Ldebug_macro20:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF802
	.byte	0x5
	.uleb128 0x1a
	.4byte	.LASF803
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.types.h.40.e8c16e7ec36ba55f133d0616070e25fc,comdat
.Ldebug_macro21:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x28
	.4byte	.LASF804
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF805
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._stdint.h.10.7a5f60e6741af4a5594a3867d347e1f9,comdat
.Ldebug_macro22:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xa
	.4byte	.LASF806
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF807
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF808
	.byte	0x5
	.uleb128 0x1b
	.4byte	.LASF809
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF810
	.byte	0x5
	.uleb128 0x25
	.4byte	.LASF811
	.byte	0x5
	.uleb128 0x27
	.4byte	.LASF812
	.byte	0x5
	.uleb128 0x2d
	.4byte	.LASF813
	.byte	0x5
	.uleb128 0x31
	.4byte	.LASF814
	.byte	0x5
	.uleb128 0x33
	.4byte	.LASF815
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF816
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF817
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF818
	.byte	0x5
	.uleb128 0x44
	.4byte	.LASF819
	.byte	0x5
	.uleb128 0x49
	.4byte	.LASF820
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._endian.h.31.65a10590763c3dde1ac4a7f66d7d4891,comdat
.Ldebug_macro23:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1f
	.4byte	.LASF822
	.byte	0x5
	.uleb128 0x20
	.4byte	.LASF823
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF824
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF825
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.endian.h.9.49f3a4695c1b61e8a0808de3c4a106cb,comdat
.Ldebug_macro24:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x9
	.4byte	.LASF826
	.byte	0x5
	.uleb128 0xa
	.4byte	.LASF827
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF828
	.byte	0x5
	.uleb128 0x12
	.4byte	.LASF829
	.byte	0x5
	.uleb128 0x13
	.4byte	.LASF830
	.byte	0x5
	.uleb128 0x14
	.4byte	.LASF831
	.byte	0x5
	.uleb128 0x18
	.4byte	.LASF832
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF833
	.byte	0x5
	.uleb128 0x1a
	.4byte	.LASF834
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF835
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF836
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF837
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF838
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4._timeval.h.30.0e8bfd94e85db17dda3286ee81496fe6,comdat
.Ldebug_macro25:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1e
	.4byte	.LASF841
	.byte	0x5
	.uleb128 0x24
	.4byte	.LASF842
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF843
	.byte	0x5
	.uleb128 0x2a
	.4byte	.LASF844
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF845
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF846
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF847
	.byte	0x5
	.uleb128 0x3e
	.4byte	.LASF848
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF849
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF850
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.timespec.h.41.d855182eb0e690443ab8651bcedca6e1,comdat
.Ldebug_macro26:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF853
	.byte	0x5
	.uleb128 0x2e
	.4byte	.LASF854
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.select.h.30.bbece7fa40993a78092dcc5805132560,comdat
.Ldebug_macro27:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1e
	.4byte	.LASF855
	.byte	0x5
	.uleb128 0x22
	.4byte	.LASF856
	.byte	0x5
	.uleb128 0x2a
	.4byte	.LASF857
	.byte	0x5
	.uleb128 0x2e
	.4byte	.LASF858
	.byte	0x5
	.uleb128 0x30
	.4byte	.LASF859
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF860
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF861
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF862
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF863
	.byte	0x5
	.uleb128 0x3e
	.4byte	.LASF864
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.types.h.69.ed3eae3cf73030a737515151ebcab7a1,comdat
.Ldebug_macro28:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF865
	.byte	0x5
	.uleb128 0x46
	.4byte	.LASF866
	.byte	0x5
	.uleb128 0x4a
	.4byte	.LASF867
	.byte	0x5
	.uleb128 0x4f
	.4byte	.LASF868
	.byte	0x5
	.uleb128 0x58
	.4byte	.LASF869
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF870
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF871
	.byte	0x5
	.uleb128 0x64
	.4byte	.LASF872
	.byte	0x5
	.uleb128 0x66
	.4byte	.LASF873
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF874
	.byte	0x5
	.uleb128 0x77
	.4byte	.LASF875
	.byte	0x5
	.uleb128 0x7c
	.4byte	.LASF876
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF877
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF878
	.byte	0x5
	.uleb128 0x8c
	.4byte	.LASF879
	.byte	0x5
	.uleb128 0x92
	.4byte	.LASF880
	.byte	0x5
	.uleb128 0x97
	.4byte	.LASF881
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF882
	.byte	0x5
	.uleb128 0xae
	.4byte	.LASF883
	.byte	0x5
	.uleb128 0xb2
	.4byte	.LASF884
	.byte	0x5
	.uleb128 0xb6
	.4byte	.LASF885
	.byte	0x5
	.uleb128 0xba
	.4byte	.LASF886
	.byte	0x5
	.uleb128 0xbf
	.4byte	.LASF887
	.byte	0x5
	.uleb128 0xc4
	.4byte	.LASF888
	.byte	0x5
	.uleb128 0xc9
	.4byte	.LASF889
	.byte	0x5
	.uleb128 0xce
	.4byte	.LASF890
	.byte	0x5
	.uleb128 0xd3
	.4byte	.LASF891
	.byte	0x5
	.uleb128 0xd8
	.4byte	.LASF892
	.byte	0x5
	.uleb128 0xd9
	.4byte	.LASF893
	.byte	0x5
	.uleb128 0xde
	.4byte	.LASF894
	.byte	0x5
	.uleb128 0xdf
	.4byte	.LASF895
	.byte	0x5
	.uleb128 0xe4
	.4byte	.LASF896
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.time.h.162.d096f2f5887c52e271c4dc33d795dc64,comdat
.Ldebug_macro29:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xa2
	.4byte	.LASF899
	.byte	0x5
	.uleb128 0xf3
	.4byte	.LASF900
	.byte	0x5
	.uleb128 0xf4
	.4byte	.LASF901
	.byte	0x5
	.uleb128 0xf8
	.4byte	.LASF902
	.byte	0x5
	.uleb128 0xfb
	.4byte	.LASF903
	.byte	0x5
	.uleb128 0x101
	.4byte	.LASF904
	.byte	0x5
	.uleb128 0x106
	.4byte	.LASF905
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.stat.h.71.d65ac61ff88c651e198008cfb38bda9c,comdat
.Ldebug_macro30:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x47
	.4byte	.LASF906
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF907
	.byte	0x5
	.uleb128 0x49
	.4byte	.LASF908
	.byte	0x5
	.uleb128 0x4a
	.4byte	.LASF909
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF910
	.byte	0x5
	.uleb128 0x4c
	.4byte	.LASF911
	.byte	0x5
	.uleb128 0x4d
	.4byte	.LASF912
	.byte	0x5
	.uleb128 0x4e
	.4byte	.LASF913
	.byte	0x5
	.uleb128 0x50
	.4byte	.LASF914
	.byte	0x5
	.uleb128 0x52
	.4byte	.LASF915
	.byte	0x5
	.uleb128 0x53
	.4byte	.LASF916
	.byte	0x5
	.uleb128 0x54
	.4byte	.LASF917
	.byte	0x5
	.uleb128 0x56
	.4byte	.LASF918
	.byte	0x5
	.uleb128 0x57
	.4byte	.LASF919
	.byte	0x5
	.uleb128 0x58
	.4byte	.LASF920
	.byte	0x5
	.uleb128 0x59
	.4byte	.LASF921
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF922
	.byte	0x5
	.uleb128 0x5d
	.4byte	.LASF923
	.byte	0x5
	.uleb128 0x5e
	.4byte	.LASF924
	.byte	0x5
	.uleb128 0x5f
	.4byte	.LASF925
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF926
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF927
	.byte	0x5
	.uleb128 0x62
	.4byte	.LASF928
	.byte	0x5
	.uleb128 0x63
	.4byte	.LASF929
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF930
	.byte	0x5
	.uleb128 0x73
	.4byte	.LASF931
	.byte	0x5
	.uleb128 0x74
	.4byte	.LASF932
	.byte	0x5
	.uleb128 0x75
	.4byte	.LASF933
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF934
	.byte	0x5
	.uleb128 0x77
	.4byte	.LASF935
	.byte	0x5
	.uleb128 0x78
	.4byte	.LASF936
	.byte	0x5
	.uleb128 0x79
	.4byte	.LASF937
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF938
	.byte	0x5
	.uleb128 0x7b
	.4byte	.LASF939
	.byte	0x5
	.uleb128 0x7c
	.4byte	.LASF940
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF941
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF942
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF943
	.byte	0x5
	.uleb128 0x82
	.4byte	.LASF944
	.byte	0x5
	.uleb128 0x85
	.4byte	.LASF945
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF946
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF947
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF948
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF949
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF950
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF951
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.time.h.38.20beed93add9f31905d3a626e4660be9,comdat
.Ldebug_macro31:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF952
	.byte	0x5
	.uleb128 0x36
	.4byte	.LASF953
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF954
	.byte	0x5
	.uleb128 0x38
	.4byte	.LASF955
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF956
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF957
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF958
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF959
	.byte	0x5
	.uleb128 0x82
	.4byte	.LASF960
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF961
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF962
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF963
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF964
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF965
	.byte	0x5
	.uleb128 0x8c
	.4byte	.LASF966
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF967
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF968
	.byte	0x5
	.uleb128 0x102
	.4byte	.LASF969
	.byte	0x5
	.uleb128 0x103
	.4byte	.LASF970
	.byte	0x5
	.uleb128 0x104
	.4byte	.LASF971
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.limits.h.2.a76e572559edc4d4305b1cf624158ea8,comdat
.Ldebug_macro32:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF975
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF976
	.byte	0x5
	.uleb128 0xf
	.4byte	.LASF977
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF978
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF979
	.byte	0x5
	.uleb128 0x91
	.4byte	.LASF980
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.limits.h.60.b4bc9eda7e37043243f7148a2c6d0306,comdat
.Ldebug_macro33:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF982
	.byte	0x6
	.uleb128 0x3f
	.4byte	.LASF983
	.byte	0x5
	.uleb128 0x40
	.4byte	.LASF984
	.byte	0x6
	.uleb128 0x48
	.4byte	.LASF985
	.byte	0x5
	.uleb128 0x49
	.4byte	.LASF986
	.byte	0x6
	.uleb128 0x4a
	.4byte	.LASF987
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF988
	.byte	0x6
	.uleb128 0x4e
	.4byte	.LASF989
	.byte	0x5
	.uleb128 0x52
	.4byte	.LASF990
	.byte	0x6
	.uleb128 0x60
	.4byte	.LASF991
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF992
	.byte	0x6
	.uleb128 0x62
	.4byte	.LASF993
	.byte	0x5
	.uleb128 0x63
	.4byte	.LASF994
	.byte	0x6
	.uleb128 0x67
	.4byte	.LASF995
	.byte	0x5
	.uleb128 0x68
	.4byte	.LASF996
	.byte	0x6
	.uleb128 0x69
	.4byte	.LASF997
	.byte	0x5
	.uleb128 0x6a
	.4byte	.LASF998
	.byte	0x6
	.uleb128 0x6d
	.4byte	.LASF999
	.byte	0x5
	.uleb128 0x71
	.4byte	.LASF1000
	.byte	0x6
	.uleb128 0x75
	.4byte	.LASF1001
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF1002
	.byte	0x6
	.uleb128 0x77
	.4byte	.LASF1003
	.byte	0x5
	.uleb128 0x78
	.4byte	.LASF1004
	.byte	0x6
	.uleb128 0x7b
	.4byte	.LASF1005
	.byte	0x5
	.uleb128 0x7c
	.4byte	.LASF1006
	.byte	0x6
	.uleb128 0x80
	.4byte	.LASF1007
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF1008
	.byte	0x6
	.uleb128 0x82
	.4byte	.LASF1009
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF1010
	.byte	0x6
	.uleb128 0x86
	.4byte	.LASF1011
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF1012
	.byte	0x6
	.uleb128 0x8b
	.4byte	.LASF1013
	.byte	0x5
	.uleb128 0x8c
	.4byte	.LASF1014
	.byte	0x6
	.uleb128 0x8d
	.4byte	.LASF1015
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF1016
	.byte	0x6
	.uleb128 0x91
	.4byte	.LASF1017
	.byte	0x5
	.uleb128 0x92
	.4byte	.LASF1018
	.byte	0x6
	.uleb128 0x97
	.4byte	.LASF1019
	.byte	0x5
	.uleb128 0x98
	.4byte	.LASF1020
	.byte	0x6
	.uleb128 0x99
	.4byte	.LASF1021
	.byte	0x5
	.uleb128 0x9a
	.4byte	.LASF1022
	.byte	0x6
	.uleb128 0x9d
	.4byte	.LASF1023
	.byte	0x5
	.uleb128 0x9e
	.4byte	.LASF1024
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.signal.h.4.eb405a82fedf74f85948b2185285e5fe,comdat
.Ldebug_macro34:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x4
	.4byte	.LASF1026
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF1027
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF1028
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF1029
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF1030
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF1031
	.byte	0x5
	.uleb128 0x9b
	.4byte	.LASF1032
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF1033
	.byte	0x5
	.uleb128 0x9d
	.4byte	.LASF1034
	.byte	0x5
	.uleb128 0xbd
	.4byte	.LASF1035
	.byte	0x5
	.uleb128 0xbe
	.4byte	.LASF1036
	.byte	0x5
	.uleb128 0xbf
	.4byte	.LASF1037
	.byte	0x5
	.uleb128 0xc0
	.4byte	.LASF1038
	.byte	0x5
	.uleb128 0xc1
	.4byte	.LASF1039
	.byte	0x5
	.uleb128 0x100
	.4byte	.LASF1040
	.byte	0x5
	.uleb128 0x101
	.4byte	.LASF1041
	.byte	0x5
	.uleb128 0x102
	.4byte	.LASF1042
	.byte	0x5
	.uleb128 0x103
	.4byte	.LASF1043
	.byte	0x5
	.uleb128 0x104
	.4byte	.LASF1044
	.byte	0x5
	.uleb128 0x105
	.4byte	.LASF1045
	.byte	0x5
	.uleb128 0x106
	.4byte	.LASF1046
	.byte	0x5
	.uleb128 0x107
	.4byte	.LASF1047
	.byte	0x5
	.uleb128 0x108
	.4byte	.LASF1048
	.byte	0x5
	.uleb128 0x109
	.4byte	.LASF1049
	.byte	0x5
	.uleb128 0x10a
	.4byte	.LASF1050
	.byte	0x5
	.uleb128 0x10b
	.4byte	.LASF1051
	.byte	0x5
	.uleb128 0x10c
	.4byte	.LASF1052
	.byte	0x5
	.uleb128 0x10d
	.4byte	.LASF1053
	.byte	0x5
	.uleb128 0x10e
	.4byte	.LASF1054
	.byte	0x5
	.uleb128 0x10f
	.4byte	.LASF1055
	.byte	0x5
	.uleb128 0x13a
	.4byte	.LASF1056
	.byte	0x5
	.uleb128 0x13b
	.4byte	.LASF1057
	.byte	0x5
	.uleb128 0x13c
	.4byte	.LASF1058
	.byte	0x5
	.uleb128 0x13d
	.4byte	.LASF1059
	.byte	0x5
	.uleb128 0x13e
	.4byte	.LASF1060
	.byte	0x5
	.uleb128 0x13f
	.4byte	.LASF1061
	.byte	0x5
	.uleb128 0x140
	.4byte	.LASF1062
	.byte	0x5
	.uleb128 0x141
	.4byte	.LASF1063
	.byte	0x5
	.uleb128 0x142
	.4byte	.LASF1064
	.byte	0x5
	.uleb128 0x143
	.4byte	.LASF1065
	.byte	0x5
	.uleb128 0x144
	.4byte	.LASF1066
	.byte	0x5
	.uleb128 0x145
	.4byte	.LASF1067
	.byte	0x5
	.uleb128 0x146
	.4byte	.LASF1068
	.byte	0x5
	.uleb128 0x147
	.4byte	.LASF1069
	.byte	0x5
	.uleb128 0x148
	.4byte	.LASF1070
	.byte	0x5
	.uleb128 0x149
	.4byte	.LASF1071
	.byte	0x5
	.uleb128 0x14a
	.4byte	.LASF1072
	.byte	0x5
	.uleb128 0x14b
	.4byte	.LASF1073
	.byte	0x5
	.uleb128 0x14c
	.4byte	.LASF1074
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.signal.h.18.14c8d0c03fc1e06775633fad7399cfc7,comdat
.Ldebug_macro35:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x12
	.4byte	.LASF1075
	.byte	0x5
	.uleb128 0x13
	.4byte	.LASF1076
	.byte	0x5
	.uleb128 0x14
	.4byte	.LASF1077
	.byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF1043:
	.ascii	"SIGILL 4\000"
.LASF705:
	.ascii	"__GNUCLIKE___SECTION 1\000"
.LASF161:
	.ascii	"__DECIMAL_DIG__ 17\000"
.LASF936:
	.ascii	"S_IWGRP 0000020\000"
.LASF298:
	.ascii	"__UHA_FBIT__ 8\000"
.LASF405:
	.ascii	"__SVID_VISIBLE 1\000"
.LASF188:
	.ascii	"__DEC128_EPSILON__ 1E-33DL\000"
.LASF1082:
	.ascii	"unsigned char\000"
.LASF835:
	.ascii	"__htonl(_x) __bswap32(_x)\000"
.LASF585:
	.ascii	"_REENT_GETDATE_ERR_P(ptr) (&((ptr)->_new._reent._ge"
	.ascii	"tdate_err))\000"
.LASF550:
	.ascii	"_REENT_ASCTIME_SIZE 26\000"
.LASF591:
	.ascii	"_GLOBAL_ATEXIT (_GLOBAL_REENT->_atexit)\000"
.LASF824:
	.ascii	"_PDP_ENDIAN 3412\000"
.LASF190:
	.ascii	"__SFRACT_FBIT__ 7\000"
.LASF612:
	.ascii	"ENOTDIR 20\000"
.LASF1016:
	.ascii	"LLONG_MAX __LONG_LONG_MAX__\000"
.LASF963:
	.ascii	"SBT_1S ((sbintime_t)1 << 32)\000"
.LASF262:
	.ascii	"__LLACCUM_MIN__ (-0X1P31LLK-0X1P31LLK)\000"
.LASF1075:
	.ascii	"SIG_DFL ((_sig_func_ptr)0)\000"
.LASF896:
	.ascii	"_USECONDS_T_DECLARED \000"
.LASF254:
	.ascii	"__LACCUM_EPSILON__ 0x1P-31LK\000"
.LASF80:
	.ascii	"__PTRDIFF_MAX__ 0x7fffffff\000"
.LASF433:
	.ascii	"_LONG_DOUBLE long double\000"
.LASF83:
	.ascii	"__INTMAX_C(c) c ## LL\000"
.LASF814:
	.ascii	"_UINT32_T_DECLARED \000"
.LASF82:
	.ascii	"__INTMAX_MAX__ 0x7fffffffffffffffLL\000"
.LASF652:
	.ascii	"ECONNREFUSED 111\000"
.LASF175:
	.ascii	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF\000"
.LASF279:
	.ascii	"__TQ_IBIT__ 0\000"
.LASF813:
	.ascii	"_INT32_T_DECLARED \000"
.LASF551:
	.ascii	"_REENT_SIGNAL_SIZE 24\000"
.LASF587:
	.ascii	"_Kmax (sizeof (size_t) << 3)\000"
.LASF14:
	.ascii	"__ATOMIC_CONSUME 1\000"
.LASF255:
	.ascii	"__ULACCUM_FBIT__ 32\000"
.LASF76:
	.ascii	"__WCHAR_MAX__ 0xffffffffU\000"
.LASF961:
	.ascii	"bintime_isset(a) ((a)->sec || (a)->frac)\000"
.LASF725:
	.ascii	"__CONCAT(x,y) __CONCAT1(x,y)\000"
.LASF1030:
	.ascii	"SS_ONSTACK 0x1\000"
.LASF1093:
	.ascii	"p_argv\000"
.LASF619:
	.ascii	"EFBIG 27\000"
.LASF670:
	.ascii	"EDQUOT 132\000"
.LASF898:
	.ascii	"_SYS__LOCALE_H \000"
.LASF19:
	.ascii	"__SIZEOF_LONG_LONG__ 8\000"
.LASF146:
	.ascii	"__DBL_MAX_10_EXP__ 308\000"
.LASF775:
	.ascii	"__RCSID_SOURCE(s) struct __hack\000"
.LASF202:
	.ascii	"__FRACT_MIN__ (-0.5R-0.5R)\000"
.LASF404:
	.ascii	"__POSIX_VISIBLE 200809\000"
.LASF955:
	.ascii	"DST_AUST 2\000"
.LASF238:
	.ascii	"__USACCUM_MAX__ 0XFFFFP-8UHK\000"
.LASF172:
	.ascii	"__DEC32_MIN__ 1E-95DF\000"
.LASF275:
	.ascii	"__SQ_IBIT__ 0\000"
.LASF29:
	.ascii	"__ORDER_PDP_ENDIAN__ 3412\000"
.LASF33:
	.ascii	"__SIZE_TYPE__ unsigned int\000"
.LASF178:
	.ascii	"__DEC64_MAX_EXP__ 385\000"
.LASF570:
	.ascii	"_REENT_MP_FREELIST(ptr) ((ptr)->_freelist)\000"
.LASF138:
	.ascii	"__FLT_HAS_DENORM__ 1\000"
.LASF42:
	.ascii	"__INT8_TYPE__ signed char\000"
.LASF338:
	.ascii	"__ARM_ARCH_PROFILE 77\000"
.LASF1054:
	.ascii	"SIGALRM 14\000"
.LASF237:
	.ascii	"__USACCUM_MIN__ 0.0UHK\000"
.LASF427:
	.ascii	"_EXFUN(name,proto) name proto\000"
.LASF157:
	.ascii	"__LDBL_MIN_EXP__ (-1021)\000"
.LASF155:
	.ascii	"__LDBL_MANT_DIG__ 53\000"
.LASF105:
	.ascii	"__UINT8_C(c) c\000"
.LASF43:
	.ascii	"__INT16_TYPE__ short int\000"
.LASF737:
	.ascii	"__aligned(x) __attribute__((__aligned__(x)))\000"
.LASF664:
	.ascii	"EPROTONOSUPPORT 123\000"
.LASF401:
	.ascii	"__ISO_C_VISIBLE 2011\000"
.LASF849:
	.ascii	"timeradd(tvp,uvp,vvp) do { (vvp)->tv_sec = (tvp)->t"
	.ascii	"v_sec + (uvp)->tv_sec; (vvp)->tv_usec = (tvp)->tv_u"
	.ascii	"sec + (uvp)->tv_usec; if ((vvp)->tv_usec >= 1000000"
	.ascii	") { (vvp)->tv_sec++; (vvp)->tv_usec -= 1000000; } }"
	.ascii	" while (0)\000"
.LASF694:
	.ascii	"__unbounded \000"
.LASF660:
	.ascii	"EINPROGRESS 119\000"
.LASF309:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1\000"
.LASF661:
	.ascii	"EALREADY 120\000"
.LASF855:
	.ascii	"_SIGSET_T_DECLARED \000"
.LASF603:
	.ascii	"ECHILD 10\000"
.LASF4:
	.ascii	"__STDC_HOSTED__ 0\000"
.LASF966:
	.ascii	"SBT_1US (SBT_1S / 1000000)\000"
.LASF225:
	.ascii	"__ULLFRACT_FBIT__ 64\000"
.LASF380:
	.ascii	"_LDBL_EQ_DBL 1\000"
.LASF895:
	.ascii	"_TIMER_T_DECLARED \000"
.LASF863:
	.ascii	"FD_ISSET(n,p) ((p)->fds_bits[(n)/NFDBITS] & (1L << "
	.ascii	"((n) % NFDBITS)))\000"
.LASF1000:
	.ascii	"USHRT_MAX (SHRT_MAX * 2 + 1)\000"
.LASF567:
	.ascii	"_REENT_MP_RESULT(ptr) ((ptr)->_result)\000"
.LASF61:
	.ascii	"__INT_FAST64_TYPE__ long long int\000"
.LASF36:
	.ascii	"__WINT_TYPE__ unsigned int\000"
.LASF804:
	.ascii	"__BIT_TYPES_DEFINED__ 1\000"
.LASF574:
	.ascii	"_REENT_STRTOK_LAST(ptr) ((ptr)->_new._reent._strtok"
	.ascii	"_last)\000"
.LASF461:
	.ascii	"__SIZE_T__ \000"
.LASF667:
	.ascii	"EISCONN 127\000"
.LASF756:
	.ascii	"__exported __attribute__((__visibility__(\"default\""
	.ascii	")))\000"
.LASF891:
	.ascii	"_NLINK_T_DECLARED \000"
.LASF637:
	.ascii	"EMULTIHOP 74\000"
.LASF878:
	.ascii	"__daddr_t_defined \000"
.LASF198:
	.ascii	"__USFRACT_MAX__ 0XFFP-8UHR\000"
.LASF903:
	.ascii	"CLOCK_DISALLOWED 0\000"
.LASF628:
	.ascii	"EIDRM 36\000"
.LASF995:
	.ascii	"SHRT_MIN\000"
.LASF494:
	.ascii	"__need_wchar_t\000"
.LASF994:
	.ascii	"CHAR_MAX SCHAR_MAX\000"
.LASF749:
	.ascii	"__result_use_check __attribute__((__warn_unused_res"
	.ascii	"ult__))\000"
.LASF675:
	.ascii	"ECANCELED 140\000"
.LASF1067:
	.ascii	"SIGXFSZ 25\000"
.LASF968:
	.ascii	"SBT_MAX 0x7fffffffffffffffLL\000"
.LASF519:
	.ascii	"__lock_close_recursive(lock) (_CAST_VOID 0)\000"
.LASF613:
	.ascii	"EISDIR 21\000"
.LASF1018:
	.ascii	"ULLONG_MAX (LLONG_MAX * 2ULL + 1ULL)\000"
.LASF13:
	.ascii	"__ATOMIC_ACQ_REL 4\000"
.LASF215:
	.ascii	"__ULFRACT_FBIT__ 32\000"
.LASF978:
	.ascii	"_POSIX2_RE_DUP_MAX 255\000"
.LASF1062:
	.ascii	"SIGTTIN 21\000"
.LASF1057:
	.ascii	"SIGSTOP 17\000"
.LASF476:
	.ascii	"__size_t \000"
.LASF693:
	.ascii	"__bounded \000"
.LASF980:
	.ascii	"PATH_MAX 4096\000"
.LASF996:
	.ascii	"SHRT_MIN (-SHRT_MAX - 1)\000"
.LASF407:
	.ascii	"_POINTER_INT long\000"
.LASF194:
	.ascii	"__SFRACT_EPSILON__ 0x1P-7HR\000"
.LASF724:
	.ascii	"__CONCAT1(x,y) x ## y\000"
.LASF717:
	.ascii	"__CC_SUPPORTS___INLINE 1\000"
.LASF144:
	.ascii	"__DBL_MIN_10_EXP__ (-307)\000"
.LASF620:
	.ascii	"ENOSPC 28\000"
.LASF28:
	.ascii	"__ORDER_BIG_ENDIAN__ 4321\000"
.LASF274:
	.ascii	"__SQ_FBIT__ 31\000"
.LASF811:
	.ascii	"_UINT16_T_DECLARED \000"
.LASF888:
	.ascii	"_KEY_T_DECLARED \000"
.LASF837:
	.ascii	"__ntohl(_x) __bswap32(_x)\000"
.LASF282:
	.ascii	"__UHQ_FBIT__ 16\000"
.LASF900:
	.ascii	"CLOCK_ENABLED 1\000"
.LASF549:
	.ascii	"_REENT_EMERGENCY_SIZE 25\000"
.LASF991:
	.ascii	"CHAR_MIN\000"
.LASF769:
	.ascii	"__weak_reference(sym,alias) __asm__(\".weak \" #ali"
	.ascii	"as); __asm__(\".equ \" #alias \", \" #sym)\000"
.LASF116:
	.ascii	"__UINT_FAST8_MAX__ 0xffffffffU\000"
.LASF1036:
	.ascii	"sigdelset(what,sig) (*(what) &= ~(1<<(sig)), 0)\000"
.LASF174:
	.ascii	"__DEC32_EPSILON__ 1E-6DF\000"
.LASF696:
	.ascii	"__has_extension __has_feature\000"
.LASF495:
	.ascii	"NULL\000"
.LASF556:
	.ascii	"_REENT_CHECK_MP(ptr) \000"
.LASF251:
	.ascii	"__LACCUM_IBIT__ 32\000"
.LASF470:
	.ascii	"_SIZE_T_DEFINED \000"
.LASF291:
	.ascii	"__HA_IBIT__ 8\000"
.LASF367:
	.ascii	"__NEWLIB_H__ 1\000"
.LASF988:
	.ascii	"SCHAR_MAX __SCHAR_MAX__\000"
.LASF862:
	.ascii	"FD_CLR(n,p) ((p)->fds_bits[(n)/NFDBITS] &= ~(1L << "
	.ascii	"((n) % NFDBITS)))\000"
.LASF348:
	.ascii	"__VFP_FP__ 1\000"
.LASF222:
	.ascii	"__LLFRACT_MIN__ (-0.5LLR-0.5LLR)\000"
.LASF120:
	.ascii	"__INTPTR_MAX__ 0x7fffffff\000"
.LASF854:
	.ascii	"TIMESPEC_TO_TIMEVAL(tv,ts) do { (tv)->tv_sec = (ts)"
	.ascii	"->tv_sec; (tv)->tv_usec = (ts)->tv_nsec / 1000; } w"
	.ascii	"hile (0)\000"
.LASF408:
	.ascii	"__RAND_MAX\000"
.LASF322:
	.ascii	"__GCC_ATOMIC_POINTER_LOCK_FREE 2\000"
.LASF117:
	.ascii	"__UINT_FAST16_MAX__ 0xffffffffU\000"
.LASF822:
	.ascii	"_LITTLE_ENDIAN 1234\000"
.LASF66:
	.ascii	"__INTPTR_TYPE__ int\000"
.LASF707:
	.ascii	"__GNUCLIKE_BUILTIN_CONSTANT_P 1\000"
.LASF1013:
	.ascii	"LLONG_MIN\000"
.LASF388:
	.ascii	"__GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_M"
	.ascii	"INOR__ >= ((maj) << 16) + (min))\000"
.LASF207:
	.ascii	"__UFRACT_MIN__ 0.0UR\000"
.LASF552:
	.ascii	"_N_LISTS 30\000"
.LASF819:
	.ascii	"_INTPTR_T_DECLARED \000"
.LASF421:
	.ascii	"_CONST const\000"
.LASF960:
	.ascii	"bintime_clear(a) ((a)->sec = (a)->frac = 0)\000"
.LASF463:
	.ascii	"_SYS_SIZE_T_H \000"
.LASF564:
	.ascii	"_REENT_RAND48_SEED(ptr) ((ptr)->_new._reent._r48._s"
	.ascii	"eed)\000"
.LASF444:
	.ascii	"__error_t_defined 1\000"
.LASF359:
	.ascii	"DEBUG 1\000"
.LASF398:
	.ascii	"__ATFILE_VISIBLE 1\000"
.LASF1098:
	.ascii	"errno\000"
.LASF240:
	.ascii	"__ACCUM_FBIT__ 15\000"
.LASF618:
	.ascii	"ETXTBSY 26\000"
.LASF246:
	.ascii	"__UACCUM_IBIT__ 16\000"
.LASF1085:
	.ascii	"long int\000"
.LASF115:
	.ascii	"__INT_FAST64_MAX__ 0x7fffffffffffffffLL\000"
.LASF149:
	.ascii	"__DBL_MIN__ ((double)2.2250738585072014e-308L)\000"
.LASF851:
	.ascii	"_SYS_TIMESPEC_H_ \000"
.LASF1022:
	.ascii	"LONG_LONG_MAX __LONG_LONG_MAX__\000"
.LASF509:
	.ascii	"___int_least16_t_defined 1\000"
.LASF184:
	.ascii	"__DEC128_MIN_EXP__ (-6142)\000"
.LASF997:
	.ascii	"SHRT_MAX\000"
.LASF58:
	.ascii	"__INT_FAST8_TYPE__ int\000"
.LASF437:
	.ascii	"_NOINLINE __attribute__ ((__noinline__))\000"
.LASF302:
	.ascii	"__UDA_FBIT__ 32\000"
.LASF460:
	.ascii	"__size_t__ \000"
.LASF1050:
	.ascii	"SIGBUS 10\000"
.LASF85:
	.ascii	"__UINTMAX_C(c) c ## ULL\000"
.LASF32:
	.ascii	"__SIZEOF_POINTER__ 4\000"
.LASF50:
	.ascii	"__INT_LEAST8_TYPE__ signed char\000"
.LASF803:
	.ascii	"CLK_TCK CLOCKS_PER_SEC\000"
.LASF312:
	.ascii	"__GCC_ATOMIC_BOOL_LOCK_FREE 2\000"
.LASF1024:
	.ascii	"ULONG_LONG_MAX (LONG_LONG_MAX * 2ULL + 1ULL)\000"
.LASF925:
	.ascii	"S_IFBLK _IFBLK\000"
.LASF594:
	.ascii	"EPERM 1\000"
.LASF829:
	.ascii	"BIG_ENDIAN _BIG_ENDIAN\000"
.LASF296:
	.ascii	"__TA_FBIT__ 63\000"
.LASF349:
	.ascii	"__THUMB_INTERWORK__ 1\000"
.LASF228:
	.ascii	"__ULLFRACT_MAX__ 0XFFFFFFFFFFFFFFFFP-64ULLR\000"
.LASF945:
	.ascii	"S_ISBLK(m) (((m)&_IFMT) == _IFBLK)\000"
.LASF728:
	.ascii	"__const const\000"
.LASF852:
	.ascii	"_SYS__TIMESPEC_H_ \000"
.LASF472:
	.ascii	"_SIZE_T_DECLARED \000"
.LASF40:
	.ascii	"__CHAR32_TYPE__ long unsigned int\000"
.LASF920:
	.ascii	"S_IEXEC 0000100\000"
.LASF395:
	.ascii	"_POSIX_C_SOURCE 200809L\000"
.LASF722:
	.ascii	"__CC_SUPPORTS_DYNAMIC_ARRAY_INIT 1\000"
.LASF118:
	.ascii	"__UINT_FAST32_MAX__ 0xffffffffU\000"
.LASF1076:
	.ascii	"SIG_IGN ((_sig_func_ptr)1)\000"
.LASF131:
	.ascii	"__FLT_MAX_EXP__ 128\000"
.LASF18:
	.ascii	"__SIZEOF_LONG__ 4\000"
.LASF723:
	.ascii	"__P(protos) protos\000"
.LASF941:
	.ascii	"S_IXOTH 0000001\000"
.LASF434:
	.ascii	"_PARAMS(paramlist) paramlist\000"
.LASF764:
	.ascii	"__strfmonlike(fmtarg,firstvararg) __attribute__((__"
	.ascii	"format__ (__strfmon__, fmtarg, firstvararg)))\000"
.LASF413:
	.ascii	"_READ_WRITE_BUFSIZE_TYPE int\000"
.LASF641:
	.ascii	"ENOTEMPTY 90\000"
.LASF22:
	.ascii	"__SIZEOF_DOUBLE__ 8\000"
.LASF532:
	.ascii	"_CLOCK_T_ unsigned long\000"
.LASF631:
	.ascii	"ENOSTR 60\000"
.LASF1033:
	.ascii	"SIG_BLOCK 1\000"
.LASF871:
	.ascii	"__u_int_defined \000"
.LASF674:
	.ascii	"EOVERFLOW 139\000"
.LASF402:
	.ascii	"__LARGEFILE_VISIBLE 0\000"
.LASF180:
	.ascii	"__DEC64_MAX__ 9.999999999999999E384DD\000"
.LASF370:
	.ascii	"__NEWLIB__ 2\000"
.LASF926:
	.ascii	"S_IFREG _IFREG\000"
.LASF669:
	.ascii	"ETOOMANYREFS 129\000"
.LASF918:
	.ascii	"S_IREAD 0000400\000"
.LASF304:
	.ascii	"__UTA_FBIT__ 64\000"
.LASF686:
	.ascii	"__ASMNAME(cname) __XSTRING (__USER_LABEL_PREFIX__) "
	.ascii	"cname\000"
.LASF133:
	.ascii	"__FLT_DECIMAL_DIG__ 9\000"
.LASF622:
	.ascii	"EROFS 30\000"
.LASF998:
	.ascii	"SHRT_MAX __SHRT_MAX__\000"
.LASF100:
	.ascii	"__INT_LEAST32_MAX__ 0x7fffffffL\000"
.LASF1081:
	.ascii	"signed char\000"
.LASF952:
	.ascii	"_SYS_TIME_H_ \000"
.LASF886:
	.ascii	"_GID_T_DECLARED \000"
.LASF790:
	.ascii	"__asserts_exclusive(...) __lock_annotate(assert_exc"
	.ascii	"lusive_lock(__VA_ARGS__))\000"
.LASF1056:
	.ascii	"SIGURG 16\000"
.LASF1040:
	.ascii	"SIGHUP 1\000"
.LASF687:
	.ascii	"__ptr_t void *\000"
.LASF579:
	.ascii	"_REENT_MBRTOWC_STATE(ptr) ((ptr)->_new._reent._mbrt"
	.ascii	"owc_state)\000"
.LASF566:
	.ascii	"_REENT_RAND48_ADD(ptr) ((ptr)->_new._reent._r48._ad"
	.ascii	"d)\000"
.LASF1096:
	.ascii	"raise\000"
.LASF200:
	.ascii	"__FRACT_FBIT__ 15\000"
.LASF264:
	.ascii	"__LLACCUM_EPSILON__ 0x1P-31LLK\000"
.LASF617:
	.ascii	"ENOTTY 25\000"
.LASF315:
	.ascii	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2\000"
.LASF740:
	.ascii	"__alloc_align(x) __attribute__((__alloc_align__(x))"
	.ascii	")\000"
.LASF544:
	.ascii	"_RAND48_SEED_2 (0x1234)\000"
.LASF1102:
	.ascii	"E:\\\\ITI_9_Months\\\\EmbeddedSystems\\\\Tourkey\\\\"
	.ascii	"workspace\\\\RCC\\\\Debug\000"
.LASF647:
	.ascii	"ENOBUFS 105\000"
.LASF568:
	.ascii	"_REENT_MP_RESULT_K(ptr) ((ptr)->_result_k)\000"
.LASF250:
	.ascii	"__LACCUM_FBIT__ 31\000"
.LASF621:
	.ascii	"ESPIPE 29\000"
.LASF1068:
	.ascii	"SIGVTALRM 26\000"
.LASF1104:
	.ascii	"__errno\000"
.LASF128:
	.ascii	"__FLT_DIG__ 6\000"
.LASF971:
	.ascii	"ITIMER_PROF 2\000"
.LASF361:
	.ascii	"TRACE 1\000"
.LASF443:
	.ascii	"__ERRNO_H__ \000"
.LASF691:
	.ascii	"__attribute_format_strfmon__(a,b) \000"
.LASF471:
	.ascii	"_BSD_SIZE_T_DEFINED_ \000"
.LASF64:
	.ascii	"__UINT_FAST32_TYPE__ unsigned int\000"
.LASF473:
	.ascii	"___int_size_t_h \000"
.LASF3:
	.ascii	"__STDC_UTF_32__ 1\000"
.LASF21:
	.ascii	"__SIZEOF_FLOAT__ 4\000"
.LASF231:
	.ascii	"__SACCUM_IBIT__ 8\000"
.LASF714:
	.ascii	"__GNUCLIKE_MATH_BUILTIN_RELOPS \000"
.LASF132:
	.ascii	"__FLT_MAX_10_EXP__ 38\000"
.LASF683:
	.ascii	"__PMT(args) args\000"
.LASF187:
	.ascii	"__DEC128_MAX__ 9.999999999999999999999999999999999E"
	.ascii	"6144DL\000"
.LASF203:
	.ascii	"__FRACT_MAX__ 0X7FFFP-15R\000"
.LASF753:
	.ascii	"__predict_true(exp) __builtin_expect((exp), 1)\000"
.LASF944:
	.ascii	"DEFFILEMODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP "
	.ascii	"| S_IROTH | S_IWOTH)\000"
.LASF763:
	.ascii	"__format_arg(fmtarg) __attribute__((__format_arg__ "
	.ascii	"(fmtarg)))\000"
.LASF114:
	.ascii	"__INT_FAST32_MAX__ 0x7fffffff\000"
.LASF10:
	.ascii	"__ATOMIC_SEQ_CST 5\000"
.LASF412:
	.ascii	"_READ_WRITE_RETURN_TYPE int\000"
.LASF939:
	.ascii	"S_IROTH 0000004\000"
.LASF884:
	.ascii	"_DEV_T_DECLARED \000"
.LASF531:
	.ascii	"__need_wint_t\000"
.LASF772:
	.ascii	"__sym_default(sym,impl,verid) __asm__(\".symver \" "
	.ascii	"#impl \", \" #sym \"@@\" #verid)\000"
.LASF93:
	.ascii	"__UINT16_MAX__ 0xffff\000"
.LASF640:
	.ascii	"ENOSYS 88\000"
.LASF278:
	.ascii	"__TQ_FBIT__ 127\000"
.LASF159:
	.ascii	"__LDBL_MAX_EXP__ 1024\000"
.LASF677:
	.ascii	"EOWNERDEAD 142\000"
.LASF623:
	.ascii	"EMLINK 31\000"
.LASF866:
	.ascii	"quad quad_t\000"
.LASF442:
	.ascii	"_closedir closedir\000"
.LASF422:
	.ascii	"_VOLATILE volatile\000"
.LASF20:
	.ascii	"__SIZEOF_SHORT__ 2\000"
.LASF265:
	.ascii	"__ULLACCUM_FBIT__ 32\000"
.LASF429:
	.ascii	"_EXFNPTR(name,proto) (* name) proto\000"
.LASF638:
	.ascii	"EBADMSG 77\000"
.LASF778:
	.ascii	"__DECONST(type,var) ((type)(__uintptr_t)(const void"
	.ascii	" *)(var))\000"
.LASF387:
	.ascii	"_SYS_FEATURES_H \000"
.LASF745:
	.ascii	"__noinline __attribute__ ((__noinline__))\000"
.LASF23:
	.ascii	"__SIZEOF_LONG_DOUBLE__ 8\000"
.LASF655:
	.ascii	"ENETUNREACH 114\000"
.LASF324:
	.ascii	"__PRAGMA_REDEFINE_EXTNAME 1\000"
.LASF35:
	.ascii	"__WCHAR_TYPE__ unsigned int\000"
.LASF1089:
	.ascii	"char\000"
.LASF301:
	.ascii	"__USA_IBIT__ 16\000"
.LASF795:
	.ascii	"__no_lock_analysis __lock_annotate(no_thread_safety"
	.ascii	"_analysis)\000"
.LASF310:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1\000"
.LASF910:
	.ascii	"_IFREG 0100000\000"
.LASF757:
	.ascii	"__hidden __attribute__((__visibility__(\"hidden\"))"
	.ascii	")\000"
.LASF644:
	.ascii	"EOPNOTSUPP 95\000"
.LASF65:
	.ascii	"__UINT_FAST64_TYPE__ long long unsigned int\000"
.LASF445:
	.ascii	"_SYS_ERRNO_H_ \000"
.LASF530:
	.ascii	"_WINT_T \000"
.LASF965:
	.ascii	"SBT_1MS (SBT_1S / 1000)\000"
.LASF135:
	.ascii	"__FLT_MIN__ 1.1754943508222875e-38F\000"
.LASF798:
	.ascii	"__need_size_t \000"
.LASF290:
	.ascii	"__HA_FBIT__ 7\000"
.LASF800:
	.ascii	"_MACHTIME_H_ \000"
.LASF320:
	.ascii	"__GCC_ATOMIC_LLONG_LOCK_FREE 1\000"
.LASF1065:
	.ascii	"SIGPOLL SIGIO\000"
.LASF522:
	.ascii	"__lock_try_acquire(lock) (_CAST_VOID 0)\000"
.LASF439:
	.ascii	"__SYSLIST_H \000"
.LASF196:
	.ascii	"__USFRACT_IBIT__ 0\000"
.LASF101:
	.ascii	"__INT32_C(c) c ## L\000"
.LASF610:
	.ascii	"EXDEV 18\000"
.LASF1012:
	.ascii	"ULONG_MAX (LONG_MAX * 2UL + 1UL)\000"
.LASF378:
	.ascii	"_HAVE_LONG_DOUBLE 1\000"
.LASF197:
	.ascii	"__USFRACT_MIN__ 0.0UHR\000"
.LASF741:
	.ascii	"__generic(expr,t,yes,no) _Generic(expr, t: yes, def"
	.ascii	"ault: no)\000"
.LASF573:
	.ascii	"_REENT_EMERGENCY(ptr) ((ptr)->_emergency)\000"
.LASF706:
	.ascii	"__GNUCLIKE_CTOR_SECTION_HANDLING 1\000"
.LASF92:
	.ascii	"__UINT8_MAX__ 0xff\000"
.LASF505:
	.ascii	"___int16_t_defined 1\000"
.LASF589:
	.ascii	"_REENT _impure_ptr\000"
.LASF697:
	.ascii	"__has_feature(x) 0\000"
.LASF601:
	.ascii	"ENOEXEC 8\000"
.LASF364:
	.ascii	"USE_HAL_DRIVER 1\000"
.LASF776:
	.ascii	"__SCCSID(s) struct __hack\000"
.LASF152:
	.ascii	"__DBL_HAS_DENORM__ 1\000"
.LASF913:
	.ascii	"_IFIFO 0010000\000"
.LASF933:
	.ascii	"S_IXUSR 0000100\000"
.LASF375:
	.ascii	"_MB_LEN_MAX 1\000"
.LASF294:
	.ascii	"__DA_FBIT__ 31\000"
.LASF98:
	.ascii	"__INT_LEAST16_MAX__ 0x7fff\000"
.LASF423:
	.ascii	"_SIGNED signed\000"
.LASF861:
	.ascii	"FD_SET(n,p) ((p)->fds_bits[(n)/NFDBITS] |= (1L << ("
	.ascii	"(n) % NFDBITS)))\000"
.LASF137:
	.ascii	"__FLT_DENORM_MIN__ 1.4012984643248171e-45F\000"
.LASF645:
	.ascii	"EPFNOSUPPORT 96\000"
.LASF1049:
	.ascii	"SIGKILL 9\000"
.LASF750:
	.ascii	"__returns_twice __attribute__((__returns_twice__))\000"
.LASF269:
	.ascii	"__ULLACCUM_EPSILON__ 0x1P-32ULLK\000"
.LASF793:
	.ascii	"__requires_shared(...) __lock_annotate(shared_locks"
	.ascii	"_required(__VA_ARGS__))\000"
.LASF416:
	.ascii	"_END_STD_C \000"
.LASF946:
	.ascii	"S_ISCHR(m) (((m)&_IFMT) == _IFCHR)\000"
.LASF967:
	.ascii	"SBT_1NS (SBT_1S / 1000000000)\000"
.LASF465:
	.ascii	"_T_SIZE \000"
.LASF69:
	.ascii	"__has_include_next(STR) __has_include_next__(STR)\000"
.LASF805:
	.ascii	"_SYS_TYPES_H \000"
.LASF845:
	.ascii	"_TIMEVAL_DEFINED \000"
.LASF109:
	.ascii	"__UINT32_C(c) c ## UL\000"
.LASF948:
	.ascii	"S_ISFIFO(m) (((m)&_IFMT) == _IFIFO)\000"
.LASF247:
	.ascii	"__UACCUM_MIN__ 0.0UK\000"
.LASF136:
	.ascii	"__FLT_EPSILON__ 1.1920928955078125e-7F\000"
.LASF649:
	.ascii	"EPROTOTYPE 107\000"
.LASF690:
	.ascii	"__attribute_pure__ \000"
.LASF383:
	.ascii	"_WIDE_ORIENT 1\000"
.LASF518:
	.ascii	"__lock_close(lock) (_CAST_VOID 0)\000"
.LASF708:
	.ascii	"__GNUCLIKE_BUILTIN_VARARGS 1\000"
.LASF249:
	.ascii	"__UACCUM_EPSILON__ 0x1P-16UK\000"
.LASF46:
	.ascii	"__UINT8_TYPE__ unsigned char\000"
.LASF562:
	.ascii	"_REENT_SIGNGAM(ptr) ((ptr)->_new._reent._gamma_sign"
	.ascii	"gam)\000"
.LASF119:
	.ascii	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL\000"
.LASF317:
	.ascii	"__GCC_ATOMIC_SHORT_LOCK_FREE 2\000"
.LASF841:
	.ascii	"_SYS__TIMEVAL_H_ \000"
.LASF235:
	.ascii	"__USACCUM_FBIT__ 8\000"
.LASF436:
	.ascii	"_ELIDABLE_INLINE static __inline__\000"
.LASF949:
	.ascii	"S_ISREG(m) (((m)&_IFMT) == _IFREG)\000"
.LASF929:
	.ascii	"S_IFIFO _IFIFO\000"
.LASF879:
	.ascii	"__caddr_t_defined \000"
.LASF500:
	.ascii	"_SYS__TYPES_H \000"
.LASF639:
	.ascii	"EFTYPE 79\000"
.LASF962:
	.ascii	"bintime_cmp(a,b,cmp) (((a)->sec == (b)->sec) ? ((a)"
	.ascii	"->frac cmp (b)->frac) : ((a)->sec cmp (b)->sec))\000"
.LASF912:
	.ascii	"_IFSOCK 0140000\000"
.LASF1007:
	.ascii	"LONG_MIN\000"
.LASF636:
	.ascii	"EPROTO 71\000"
.LASF975:
	.ascii	"_LIBC_LIMITS_H_ 1\000"
.LASF167:
	.ascii	"__LDBL_HAS_INFINITY__ 1\000"
.LASF440:
	.ascii	"_opendir opendir\000"
.LASF8:
	.ascii	"__VERSION__ \"5.4.1 20160919 (release) [ARM/embedde"
	.ascii	"d-5-branch revision 240496]\"\000"
.LASF716:
	.ascii	"__CC_SUPPORTS_INLINE 1\000"
.LASF905:
	.ascii	"TIMER_ABSTIME 4\000"
.LASF353:
	.ascii	"__ARM_ARCH_EXT_IDIV__ 1\000"
.LASF351:
	.ascii	"__ARM_PCS 1\000"
.LASF743:
	.ascii	"__pure __attribute__((__pure__))\000"
.LASF915:
	.ascii	"S_ISUID 0004000\000"
.LASF969:
	.ascii	"ITIMER_REAL 0\000"
.LASF87:
	.ascii	"__SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)\000"
.LASF104:
	.ascii	"__UINT_LEAST8_MAX__ 0xff\000"
.LASF485:
	.ascii	"_BSD_WCHAR_T_ \000"
.LASF875:
	.ascii	"_BLKSIZE_T_DECLARED \000"
.LASF572:
	.ascii	"_REENT_TM(ptr) (&(ptr)->_new._reent._localtime_buf)"
	.ascii	"\000"
.LASF943:
	.ascii	"ALLPERMS (S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S"
	.ascii	"_IRWXG | S_IRWXO)\000"
.LASF658:
	.ascii	"EHOSTDOWN 117\000"
.LASF521:
	.ascii	"__lock_acquire_recursive(lock) (_CAST_VOID 0)\000"
.LASF430:
	.ascii	"_DEFUN(name,arglist,args) name(args)\000"
.LASF1003:
	.ascii	"INT_MAX\000"
.LASF604:
	.ascii	"EAGAIN 11\000"
.LASF831:
	.ascii	"BYTE_ORDER _BYTE_ORDER\000"
.LASF951:
	.ascii	"S_ISSOCK(m) (((m)&_IFMT) == _IFSOCK)\000"
.LASF559:
	.ascii	"_REENT_CHECK_EMERGENCY(ptr) \000"
.LASF125:
	.ascii	"__DEC_EVAL_METHOD__ 2\000"
.LASF1069:
	.ascii	"SIGPROF 27\000"
.LASF659:
	.ascii	"EHOSTUNREACH 118\000"
.LASF911:
	.ascii	"_IFLNK 0120000\000"
.LASF985:
	.ascii	"SCHAR_MIN\000"
.LASF642:
	.ascii	"ENAMETOOLONG 91\000"
.LASF182:
	.ascii	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD\000"
.LASF199:
	.ascii	"__USFRACT_EPSILON__ 0x1P-8UHR\000"
.LASF496:
	.ascii	"NULL ((void *)0)\000"
.LASF883:
	.ascii	"_OFF_T_DECLARED \000"
.LASF510:
	.ascii	"___int_least32_t_defined 1\000"
.LASF263:
	.ascii	"__LLACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LLK\000"
.LASF497:
	.ascii	"__need_NULL\000"
.LASF455:
	.ascii	"_BSD_PTRDIFF_T_ \000"
.LASF307:
	.ascii	"__USER_LABEL_PREFIX__ \000"
.LASF95:
	.ascii	"__UINT64_MAX__ 0xffffffffffffffffULL\000"
.LASF242:
	.ascii	"__ACCUM_MIN__ (-0X1P15K-0X1P15K)\000"
.LASF94:
	.ascii	"__UINT32_MAX__ 0xffffffffUL\000"
.LASF396:
	.ascii	"_ATFILE_SOURCE\000"
.LASF576:
	.ascii	"_REENT_MBTOWC_STATE(ptr) ((ptr)->_new._reent._mbtow"
	.ascii	"c_state)\000"
.LASF1:
	.ascii	"__STDC_VERSION__ 201112L\000"
.LASF575:
	.ascii	"_REENT_MBLEN_STATE(ptr) ((ptr)->_new._reent._mblen_"
	.ascii	"state)\000"
.LASF788:
	.ascii	"__trylocks_shared(...) __lock_annotate(shared_trylo"
	.ascii	"ck_function(__VA_ARGS__))\000"
.LASF96:
	.ascii	"__INT_LEAST8_MAX__ 0x7f\000"
.LASF602:
	.ascii	"EBADF 9\000"
.LASF329:
	.ascii	"__ARM_FEATURE_QBIT 1\000"
.LASF334:
	.ascii	"__ARM_FEATURE_CLZ 1\000"
.LASF11:
	.ascii	"__ATOMIC_ACQUIRE 2\000"
.LASF527:
	.ascii	"unsigned signed\000"
.LASF881:
	.ascii	"_ID_T_DECLARED \000"
.LASF49:
	.ascii	"__UINT64_TYPE__ long long unsigned int\000"
.LASF337:
	.ascii	"__ARM_SIZEOF_WCHAR_T 4\000"
.LASF449:
	.ascii	"_ANSI_STDDEF_H \000"
.LASF68:
	.ascii	"__has_include(STR) __has_include__(STR)\000"
.LASF1032:
	.ascii	"SIG_SETMASK 0\000"
.LASF108:
	.ascii	"__UINT_LEAST32_MAX__ 0xffffffffUL\000"
.LASF833:
	.ascii	"__bswap32(_x) __builtin_bswap32(_x)\000"
.LASF150:
	.ascii	"__DBL_EPSILON__ ((double)2.2204460492503131e-16L)\000"
.LASF212:
	.ascii	"__LFRACT_MIN__ (-0.5LR-0.5LR)\000"
.LASF1088:
	.ascii	"sizetype\000"
.LASF979:
	.ascii	"ARG_MAX 4096\000"
.LASF563:
	.ascii	"_REENT_RAND_NEXT(ptr) ((ptr)->_new._reent._rand_nex"
	.ascii	"t)\000"
.LASF243:
	.ascii	"__ACCUM_MAX__ 0X7FFFFFFFP-15K\000"
.LASF88:
	.ascii	"__INT8_MAX__ 0x7f\000"
.LASF1063:
	.ascii	"SIGTTOU 22\000"
.LASF681:
	.ascii	"_TIME_H_ \000"
.LASF907:
	.ascii	"_IFDIR 0040000\000"
.LASF323:
	.ascii	"__GCC_HAVE_DWARF2_CFI_ASM 1\000"
.LASF504:
	.ascii	"___int8_t_defined 1\000"
.LASF192:
	.ascii	"__SFRACT_MIN__ (-0.5HR-0.5HR)\000"
.LASF1086:
	.ascii	"long unsigned int\000"
.LASF293:
	.ascii	"__SA_IBIT__ 16\000"
.LASF758:
	.ascii	"__offsetof(type,field) offsetof(type, field)\000"
.LASF123:
	.ascii	"__GCC_IEC_559_COMPLEX 0\000"
.LASF5:
	.ascii	"__GNUC__ 5\000"
.LASF747:
	.ascii	"__nonnull_all __attribute__((__nonnull__))\000"
.LASF1045:
	.ascii	"SIGIOT 6\000"
.LASF47:
	.ascii	"__UINT16_TYPE__ short unsigned int\000"
.LASF392:
	.ascii	"_POSIX_SOURCE\000"
.LASF1100:
	.ascii	"GNU C11 5.4.1 20160919 (release) [ARM/embedded-5-br"
	.ascii	"anch revision 240496] -mcpu=cortex-m4 -mthumb -mflo"
	.ascii	"at-abi=soft -g3 -Og -std=gnu11 -fmessage-length=0 -"
	.ascii	"fsigned-char -ffunction-sections -fdata-sections -f"
	.ascii	"freestanding -fno-move-loop-invariants\000"
.LASF347:
	.ascii	"__SOFTFP__ 1\000"
.LASF815:
	.ascii	"__int32_t_defined 1\000"
.LASF171:
	.ascii	"__DEC32_MAX_EXP__ 97\000"
.LASF654:
	.ascii	"ECONNABORTED 113\000"
.LASF464:
	.ascii	"_T_SIZE_ \000"
.LASF418:
	.ascii	"_PTR void *\000"
.LASF689:
	.ascii	"__attribute_malloc__ \000"
.LASF624:
	.ascii	"EPIPE 32\000"
.LASF899:
	.ascii	"tzname _tzname\000"
.LASF62:
	.ascii	"__UINT_FAST8_TYPE__ unsigned int\000"
.LASF261:
	.ascii	"__LLACCUM_IBIT__ 32\000"
.LASF204:
	.ascii	"__FRACT_EPSILON__ 0x1P-15R\000"
.LASF924:
	.ascii	"S_IFCHR _IFCHR\000"
.LASF90:
	.ascii	"__INT32_MAX__ 0x7fffffffL\000"
.LASF535:
	.ascii	"_TIMER_T_ unsigned long\000"
.LASF1053:
	.ascii	"SIGPIPE 13\000"
.LASF930:
	.ascii	"S_IRWXU (S_IRUSR | S_IWUSR | S_IXUSR)\000"
.LASF102:
	.ascii	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL\000"
.LASF341:
	.ascii	"__APCS_32__ 1\000"
.LASF806:
	.ascii	"_SYS__STDINT_H \000"
.LASF799:
	.ascii	"__need_NULL \000"
.LASF1029:
	.ascii	"SIGSTKSZ 8192\000"
.LASF391:
	.ascii	"_DEFAULT_SOURCE 1\000"
.LASF121:
	.ascii	"__UINTPTR_MAX__ 0xffffffffU\000"
.LASF983:
	.ascii	"CHAR_BIT\000"
.LASF498:
	.ascii	"offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEM"
	.ascii	"BER)\000"
.LASF57:
	.ascii	"__UINT_LEAST64_TYPE__ long long unsigned int\000"
.LASF940:
	.ascii	"S_IWOTH 0000002\000"
.LASF195:
	.ascii	"__USFRACT_FBIT__ 8\000"
.LASF164:
	.ascii	"__LDBL_EPSILON__ 2.2204460492503131e-16L\000"
.LASF651:
	.ascii	"ENOPROTOOPT 109\000"
.LASF733:
	.ascii	"__pure2 __attribute__((__const__))\000"
.LASF314:
	.ascii	"__GCC_ATOMIC_CHAR16_T_LOCK_FREE 2\000"
.LASF145:
	.ascii	"__DBL_MAX_EXP__ 1024\000"
.LASF12:
	.ascii	"__ATOMIC_RELEASE 3\000"
.LASF859:
	.ascii	"_howmany(x,y) (((x)+((y)-1))/(y))\000"
.LASF592:
	.ascii	"errno (*__errno())\000"
.LASF127:
	.ascii	"__FLT_MANT_DIG__ 24\000"
.LASF7:
	.ascii	"__GNUC_PATCHLEVEL__ 1\000"
.LASF543:
	.ascii	"_RAND48_SEED_1 (0xabcd)\000"
.LASF287:
	.ascii	"__UDQ_IBIT__ 0\000"
.LASF515:
	.ascii	"__LOCK_INIT_RECURSIVE(class,lock) static int lock ="
	.ascii	" 0;\000"
.LASF15:
	.ascii	"__OPTIMIZE__ 1\000"
.LASF703:
	.ascii	"__GNUCLIKE___TYPEOF 1\000"
.LASF248:
	.ascii	"__UACCUM_MAX__ 0XFFFFFFFFP-16UK\000"
.LASF719:
	.ascii	"__CC_SUPPORTS___FUNC__ 1\000"
.LASF702:
	.ascii	"__GNUCLIKE_MATH_BUILTIN_CONSTANTS \000"
.LASF832:
	.ascii	"__bswap16(_x) __builtin_bswap16(_x)\000"
.LASF609:
	.ascii	"EEXIST 17\000"
.LASF451:
	.ascii	"_T_PTRDIFF_ \000"
.LASF916:
	.ascii	"S_ISGID 0002000\000"
.LASF165:
	.ascii	"__LDBL_DENORM_MIN__ 4.9406564584124654e-324L\000"
.LASF91:
	.ascii	"__INT64_MAX__ 0x7fffffffffffffffLL\000"
.LASF330:
	.ascii	"__ARM_FEATURE_SAT 1\000"
.LASF812:
	.ascii	"__int16_t_defined 1\000"
.LASF226:
	.ascii	"__ULLFRACT_IBIT__ 0\000"
.LASF1095:
	.ascii	"argv\000"
.LASF561:
	.ascii	"_REENT_CHECK_SIGNAL_BUF(ptr) \000"
.LASF986:
	.ascii	"SCHAR_MIN (-SCHAR_MAX - 1)\000"
.LASF643:
	.ascii	"ELOOP 92\000"
.LASF541:
	.ascii	"_REENT_SMALL_CHECK_INIT(ptr) \000"
.LASF666:
	.ascii	"ENETRESET 126\000"
.LASF520:
	.ascii	"__lock_acquire(lock) (_CAST_VOID 0)\000"
.LASF973:
	.ascii	"_GCC_LIMITS_H_ \000"
.LASF459:
	.ascii	"__need_ptrdiff_t\000"
.LASF739:
	.ascii	"__alloc_size(x) __attribute__((__alloc_size__(x)))\000"
.LASF134:
	.ascii	"__FLT_MAX__ 3.4028234663852886e+38F\000"
.LASF605:
	.ascii	"ENOMEM 12\000"
.LASF245:
	.ascii	"__UACCUM_FBIT__ 16\000"
.LASF770:
	.ascii	"__warn_references(sym,msg) __asm__(\".section .gnu."
	.ascii	"warning.\" #sym); __asm__(\".asciz \\\"\" msg \"\\\""
	.ascii	"\"); __asm__(\".previous\")\000"
.LASF209:
	.ascii	"__UFRACT_EPSILON__ 0x1P-16UR\000"
.LASF77:
	.ascii	"__WCHAR_MIN__ 0U\000"
.LASF281:
	.ascii	"__UQQ_IBIT__ 0\000"
.LASF369:
	.ascii	"_NEWLIB_VERSION \"2.4.0\"\000"
.LASF368:
	.ascii	"_NEWLIB_VERSION_H__ 1\000"
.LASF319:
	.ascii	"__GCC_ATOMIC_LONG_LOCK_FREE 2\000"
.LASF257:
	.ascii	"__ULACCUM_MIN__ 0.0ULK\000"
.LASF377:
	.ascii	"_ATEXIT_DYNAMIC_ALLOC 1\000"
.LASF477:
	.ascii	"__need_size_t\000"
.LASF162:
	.ascii	"__LDBL_MAX__ 1.7976931348623157e+308L\000"
.LASF340:
	.ascii	"__ARM_ARCH 7\000"
.LASF44:
	.ascii	"__INT32_TYPE__ long int\000"
.LASF467:
	.ascii	"_SIZE_T_ \000"
.LASF424:
	.ascii	"_DOTS , ...\000"
.LASF600:
	.ascii	"E2BIG 7\000"
.LASF126:
	.ascii	"__FLT_RADIX__ 2\000"
.LASF1079:
	.ascii	"long long int\000"
.LASF565:
	.ascii	"_REENT_RAND48_MULT(ptr) ((ptr)->_new._reent._r48._m"
	.ascii	"ult)\000"
.LASF1037:
	.ascii	"sigemptyset(what) (*(what) = 0, 0)\000"
.LASF653:
	.ascii	"EADDRINUSE 112\000"
.LASF168:
	.ascii	"__LDBL_HAS_QUIET_NAN__ 1\000"
.LASF880:
	.ascii	"_FSBLKCNT_T_DECLARED \000"
.LASF450:
	.ascii	"_PTRDIFF_T \000"
.LASF1071:
	.ascii	"SIGLOST 29\000"
.LASF360:
	.ascii	"USE_FULL_ASSERT 1\000"
.LASF954:
	.ascii	"DST_USA 1\000"
.LASF558:
	.ascii	"_REENT_CHECK_ASCTIME_BUF(ptr) \000"
.LASF1017:
	.ascii	"ULLONG_MAX\000"
.LASF870:
	.ascii	"__u_short_defined \000"
.LASF524:
	.ascii	"__lock_release(lock) (_CAST_VOID 0)\000"
.LASF1021:
	.ascii	"LONG_LONG_MAX\000"
.LASF633:
	.ascii	"ETIME 62\000"
.LASF1028:
	.ascii	"MINSIGSTKSZ 2048\000"
.LASF846:
	.ascii	"timerclear(tvp) ((tvp)->tv_sec = (tvp)->tv_usec = 0"
	.ascii	")\000"
.LASF897:
	.ascii	"__need_inttypes\000"
.LASF877:
	.ascii	"_CLOCK_T_DECLARED \000"
.LASF483:
	.ascii	"__WCHAR_T \000"
.LASF385:
	.ascii	"__SYS_CONFIG_H__ \000"
.LASF1072:
	.ascii	"SIGUSR1 30\000"
.LASF887:
	.ascii	"_PID_T_DECLARED \000"
.LASF711:
	.ascii	"__GNUC_VA_LIST_COMPATIBILITY 1\000"
.LASF506:
	.ascii	"___int32_t_defined 1\000"
.LASF379:
	.ascii	"_HAVE_CC_INHIBIT_LOOP_TO_LIBCALL 1\000"
.LASF648:
	.ascii	"EAFNOSUPPORT 106\000"
.LASF45:
	.ascii	"__INT64_TYPE__ long long int\000"
.LASF210:
	.ascii	"__LFRACT_FBIT__ 31\000"
.LASF25:
	.ascii	"__CHAR_BIT__ 8\000"
.LASF325:
	.ascii	"__SIZEOF_WCHAR_T__ 4\000"
.LASF399:
	.ascii	"__BSD_VISIBLE 1\000"
.LASF676:
	.ascii	"ENOTRECOVERABLE 141\000"
.LASF734:
	.ascii	"__unused __attribute__((__unused__))\000"
.LASF580:
	.ascii	"_REENT_MBSRTOWCS_STATE(ptr) ((ptr)->_new._reent._mb"
	.ascii	"srtowcs_state)\000"
.LASF673:
	.ascii	"EILSEQ 138\000"
.LASF208:
	.ascii	"__UFRACT_MAX__ 0XFFFFP-16UR\000"
.LASF511:
	.ascii	"___int_least64_t_defined 1\000"
.LASF844:
	.ascii	"_TIME_T_DECLARED \000"
.LASF685:
	.ascii	"__THROW \000"
.LASF1047:
	.ascii	"SIGEMT 7\000"
.LASF922:
	.ascii	"S_IFMT _IFMT\000"
.LASF191:
	.ascii	"__SFRACT_IBIT__ 0\000"
.LASF583:
	.ascii	"_REENT_L64A_BUF(ptr) ((ptr)->_new._reent._l64a_buf)"
	.ascii	"\000"
.LASF397:
	.ascii	"_ATFILE_SOURCE 1\000"
.LASF503:
	.ascii	"__EXP(x) __ ##x ##__\000"
.LASF30:
	.ascii	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF129:
	.ascii	"__FLT_MIN_EXP__ (-125)\000"
.LASF417:
	.ascii	"_NOTHROW \000"
.LASF366:
	.ascii	"_ANSIDECL_H_ \000"
.LASF890:
	.ascii	"_MODE_T_DECLARED \000"
.LASF850:
	.ascii	"timersub(tvp,uvp,vvp) do { (vvp)->tv_sec = (tvp)->t"
	.ascii	"v_sec - (uvp)->tv_sec; (vvp)->tv_usec = (tvp)->tv_u"
	.ascii	"sec - (uvp)->tv_usec; if ((vvp)->tv_usec < 0) { (vv"
	.ascii	"p)->tv_sec--; (vvp)->tv_usec += 1000000; } } while "
	.ascii	"(0)\000"
.LASF606:
	.ascii	"EACCES 13\000"
.LASF1064:
	.ascii	"SIGIO 23\000"
.LASF205:
	.ascii	"__UFRACT_FBIT__ 16\000"
.LASF286:
	.ascii	"__UDQ_FBIT__ 64\000"
.LASF715:
	.ascii	"__GNUCLIKE_BUILTIN_MEMCPY 1\000"
.LASF160:
	.ascii	"__LDBL_MAX_10_EXP__ 308\000"
.LASF173:
	.ascii	"__DEC32_MAX__ 9.999999E96DF\000"
.LASF60:
	.ascii	"__INT_FAST32_TYPE__ int\000"
.LASF817:
	.ascii	"_UINT64_T_DECLARED \000"
.LASF882:
	.ascii	"_INO_T_DECLARED \000"
.LASF1078:
	.ascii	"unsigned int\000"
.LASF469:
	.ascii	"_SIZE_T_DEFINED_ \000"
.LASF632:
	.ascii	"ENODATA 61\000"
.LASF885:
	.ascii	"_UID_T_DECLARED \000"
.LASF371:
	.ascii	"__NEWLIB_MINOR__ 4\000"
.LASF731:
	.ascii	"__weak_symbol __attribute__((__weak__))\000"
.LASF927:
	.ascii	"S_IFLNK _IFLNK\000"
.LASF268:
	.ascii	"__ULLACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULLK\000"
.LASF1041:
	.ascii	"SIGINT 2\000"
.LASF236:
	.ascii	"__USACCUM_IBIT__ 8\000"
.LASF744:
	.ascii	"__always_inline __attribute__((__always_inline__))\000"
.LASF350:
	.ascii	"__ARM_ARCH_7EM__ 1\000"
.LASF754:
	.ascii	"__predict_false(exp) __builtin_expect((exp), 0)\000"
.LASF865:
	.ascii	"physadr physadr_t\000"
.LASF266:
	.ascii	"__ULLACCUM_IBIT__ 32\000"
.LASF38:
	.ascii	"__UINTMAX_TYPE__ long long unsigned int\000"
.LASF381:
	.ascii	"_FVWRITE_IN_STREAMIO 1\000"
.LASF492:
	.ascii	"_WCHAR_T_DECLARED \000"
.LASF446:
	.ascii	"_SYS_REENT_H_ \000"
.LASF124:
	.ascii	"__FLT_EVAL_METHOD__ 0\000"
.LASF970:
	.ascii	"ITIMER_VIRTUAL 1\000"
.LASF71:
	.ascii	"__SCHAR_MAX__ 0x7f\000"
.LASF2:
	.ascii	"__STDC_UTF_16__ 1\000"
.LASF547:
	.ascii	"_RAND48_MULT_2 (0x0005)\000"
.LASF426:
	.ascii	"_EXFUN_NOTHROW(name,proto) name proto _NOTHROW\000"
.LASF1014:
	.ascii	"LLONG_MIN (-LLONG_MAX - 1LL)\000"
.LASF1099:
	.ascii	"__dso_handle\000"
.LASF452:
	.ascii	"_T_PTRDIFF \000"
.LASF280:
	.ascii	"__UQQ_FBIT__ 8\000"
.LASF1091:
	.ascii	"pid_t\000"
.LASF177:
	.ascii	"__DEC64_MIN_EXP__ (-382)\000"
.LASF122:
	.ascii	"__GCC_IEC_559 0\000"
.LASF533:
	.ascii	"_TIME_T_ long\000"
.LASF794:
	.ascii	"__requires_unlocked(...) __lock_annotate(locks_excl"
	.ascii	"uded(__VA_ARGS__))\000"
.LASF213:
	.ascii	"__LFRACT_MAX__ 0X7FFFFFFFP-31LR\000"
.LASF327:
	.ascii	"__SIZEOF_PTRDIFF_T__ 4\000"
.LASF458:
	.ascii	"_PTRDIFF_T_DECLARED \000"
.LASF934:
	.ascii	"S_IRWXG (S_IRGRP | S_IWGRP | S_IXGRP)\000"
.LASF508:
	.ascii	"___int_least8_t_defined 1\000"
.LASF354:
	.ascii	"__ARM_FEATURE_IDIV 1\000"
.LASF839:
	.ascii	"_SYS_SELECT_H \000"
.LASF31:
	.ascii	"__FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF491:
	.ascii	"_GCC_WCHAR_T \000"
.LASF1073:
	.ascii	"SIGUSR2 31\000"
.LASF789:
	.ascii	"__unlocks(...) __lock_annotate(unlock_function(__VA"
	.ascii	"_ARGS__))\000"
.LASF410:
	.ascii	"__EXPORT \000"
.LASF54:
	.ascii	"__UINT_LEAST8_TYPE__ unsigned char\000"
.LASF1027:
	.ascii	"SA_NOCLDSTOP 1\000"
.LASF901:
	.ascii	"CLOCK_DISABLED 0\000"
.LASF938:
	.ascii	"S_IRWXO (S_IROTH | S_IWOTH | S_IXOTH)\000"
.LASF853:
	.ascii	"TIMEVAL_TO_TIMESPEC(tv,ts) do { (ts)->tv_sec = (tv)"
	.ascii	"->tv_sec; (ts)->tv_nsec = (tv)->tv_usec * 1000; } w"
	.ascii	"hile (0)\000"
.LASF183:
	.ascii	"__DEC128_MANT_DIG__ 34\000"
.LASF384:
	.ascii	"_UNBUF_STREAM_OPT 1\000"
.LASF411:
	.ascii	"__IMPORT \000"
.LASF538:
	.ascii	"_ATEXIT_SIZE 32\000"
.LASF300:
	.ascii	"__USA_FBIT__ 16\000"
.LASF730:
	.ascii	"__volatile volatile\000"
.LASF516:
	.ascii	"__lock_init(lock) (_CAST_VOID 0)\000"
.LASF386:
	.ascii	"__IEEE_LITTLE_ENDIAN \000"
.LASF158:
	.ascii	"__LDBL_MIN_10_EXP__ (-307)\000"
.LASF140:
	.ascii	"__FLT_HAS_QUIET_NAN__ 1\000"
.LASF950:
	.ascii	"S_ISLNK(m) (((m)&_IFMT) == _IFLNK)\000"
.LASF313:
	.ascii	"__GCC_ATOMIC_CHAR_LOCK_FREE 2\000"
.LASF428:
	.ascii	"_EXPARM(name,proto) (* name) proto\000"
.LASF1048:
	.ascii	"SIGFPE 8\000"
.LASF214:
	.ascii	"__LFRACT_EPSILON__ 0x1P-31LR\000"
.LASF415:
	.ascii	"_BEGIN_STD_C \000"
.LASF742:
	.ascii	"__malloc_like __attribute__((__malloc__))\000"
.LASF1019:
	.ascii	"LONG_LONG_MIN\000"
.LASF336:
	.ascii	"__ARM_SIZEOF_MINIMAL_ENUM 1\000"
.LASF362:
	.ascii	"OS_USE_TRACE_SEMIHOSTING_DEBUG 1\000"
.LASF928:
	.ascii	"S_IFSOCK _IFSOCK\000"
.LASF339:
	.ascii	"__arm__ 1\000"
.LASF894:
	.ascii	"__timer_t_defined \000"
.LASF709:
	.ascii	"__GNUCLIKE_BUILTIN_STDARG 1\000"
.LASF1005:
	.ascii	"UINT_MAX\000"
.LASF409:
	.ascii	"__RAND_MAX 0x7fffffff\000"
.LASF726:
	.ascii	"__STRING(x) #x\000"
.LASF480:
	.ascii	"_WCHAR_T \000"
.LASF773:
	.ascii	"__FBSDID(s) struct __hack\000"
.LASF169:
	.ascii	"__DEC32_MANT_DIG__ 7\000"
.LASF838:
	.ascii	"__ntohs(_x) __bswap16(_x)\000"
.LASF847:
	.ascii	"timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)\000"
.LASF502:
	.ascii	"_MACHINE__DEFAULT_TYPES_H \000"
.LASF26:
	.ascii	"__BIGGEST_ALIGNMENT__ 8\000"
.LASF828:
	.ascii	"LITTLE_ENDIAN _LITTLE_ENDIAN\000"
.LASF457:
	.ascii	"_GCC_PTRDIFF_T \000"
.LASF713:
	.ascii	"__GNUCLIKE_BUILTIN_NEXT_ARG 1\000"
.LASF297:
	.ascii	"__TA_IBIT__ 64\000"
.LASF672:
	.ascii	"ENOTSUP 134\000"
.LASF1092:
	.ascii	"p_argc\000"
.LASF904:
	.ascii	"CLOCK_REALTIME (clockid_t)1\000"
.LASF462:
	.ascii	"_SIZE_T \000"
.LASF488:
	.ascii	"_WCHAR_T_H \000"
.LASF1004:
	.ascii	"INT_MAX __INT_MAX__\000"
.LASF843:
	.ascii	"__time_t_defined \000"
.LASF344:
	.ascii	"__ARM_ARCH_ISA_THUMB 2\000"
.LASF166:
	.ascii	"__LDBL_HAS_DENORM__ 1\000"
.LASF75:
	.ascii	"__LONG_LONG_MAX__ 0x7fffffffffffffffLL\000"
.LASF382:
	.ascii	"_FSEEK_OPTIMIZATION 1\000"
.LASF614:
	.ascii	"EINVAL 22\000"
.LASF1080:
	.ascii	"long double\000"
.LASF781:
	.ascii	"__arg_type_tag(arg_kind,arg_idx,type_tag_idx) \000"
.LASF593:
	.ascii	"__errno_r(ptr) ((ptr)->_errno)\000"
.LASF586:
	.ascii	"_REENT_INIT_PTR(var) { memset((var), 0, sizeof(*(va"
	.ascii	"r))); _REENT_INIT_PTR_ZEROED(var); }\000"
.LASF777:
	.ascii	"__COPYRIGHT(s) struct __hack\000"
.LASF206:
	.ascii	"__UFRACT_IBIT__ 0\000"
.LASF332:
	.ascii	"__ARM_32BIT_STATE 1\000"
.LASF755:
	.ascii	"__sentinel __attribute__((__sentinel__))\000"
.LASF97:
	.ascii	"__INT8_C(c) c\000"
.LASF211:
	.ascii	"__LFRACT_IBIT__ 0\000"
.LASF448:
	.ascii	"_STDDEF_H_ \000"
.LASF143:
	.ascii	"__DBL_MIN_EXP__ (-1021)\000"
.LASF466:
	.ascii	"__SIZE_T \000"
.LASF365:
	.ascii	"HSE_VALUE 25000000\000"
.LASF1090:
	.ascii	"__pid_t\000"
.LASF767:
	.ascii	"__printf0like(fmtarg,firstvararg) \000"
.LASF1066:
	.ascii	"SIGXCPU 24\000"
.LASF626:
	.ascii	"ERANGE 34\000"
.LASF608:
	.ascii	"EBUSY 16\000"
.LASF523:
	.ascii	"__lock_try_acquire_recursive(lock) (_CAST_VOID 0)\000"
.LASF732:
	.ascii	"__dead2 __attribute__((__noreturn__))\000"
.LASF403:
	.ascii	"__MISC_VISIBLE 1\000"
.LASF1026:
	.ascii	"_SYS_SIGNAL_H \000"
.LASF512:
	.ascii	"__EXP\000"
.LASF507:
	.ascii	"___int64_t_defined 1\000"
.LASF662:
	.ascii	"EDESTADDRREQ 121\000"
.LASF947:
	.ascii	"S_ISDIR(m) (((m)&_IFMT) == _IFDIR)\000"
.LASF311:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1\000"
.LASF746:
	.ascii	"__nonnull(x) __attribute__((__nonnull__(x)))\000"
.LASF699:
	.ascii	"__BEGIN_DECLS \000"
.LASF111:
	.ascii	"__UINT64_C(c) c ## ULL\000"
.LASF560:
	.ascii	"_REENT_CHECK_MISC(ptr) \000"
.LASF1044:
	.ascii	"SIGTRAP 5\000"
.LASF419:
	.ascii	"_AND ,\000"
.LASF1010:
	.ascii	"LONG_MAX __LONG_MAX__\000"
.LASF52:
	.ascii	"__INT_LEAST32_TYPE__ long int\000"
.LASF1023:
	.ascii	"ULONG_LONG_MAX\000"
.LASF284:
	.ascii	"__USQ_FBIT__ 32\000"
.LASF110:
	.ascii	"__UINT_LEAST64_MAX__ 0xffffffffffffffffULL\000"
.LASF876:
	.ascii	"__clock_t_defined \000"
.LASF201:
	.ascii	"__FRACT_IBIT__ 0\000"
.LASF1034:
	.ascii	"SIG_UNBLOCK 2\000"
.LASF372:
	.ascii	"__NEWLIB_PATCHLEVEL__ 0\000"
.LASF1025:
	.ascii	"_SIGNAL_H_ \000"
.LASF27:
	.ascii	"__ORDER_LITTLE_ENDIAN__ 1234\000"
.LASF526:
	.ascii	"__size_t\000"
.LASF735:
	.ascii	"__used __attribute__((__used__))\000"
.LASF684:
	.ascii	"__DOTS , ...\000"
.LASF176:
	.ascii	"__DEC64_MANT_DIG__ 16\000"
.LASF1087:
	.ascii	"long long unsigned int\000"
.LASF130:
	.ascii	"__FLT_MIN_10_EXP__ (-37)\000"
.LASF256:
	.ascii	"__ULACCUM_IBIT__ 32\000"
.LASF72:
	.ascii	"__SHRT_MAX__ 0x7fff\000"
.LASF582:
	.ascii	"_REENT_WCSRTOMBS_STATE(ptr) ((ptr)->_new._reent._wc"
	.ascii	"srtombs_state)\000"
.LASF34:
	.ascii	"__PTRDIFF_TYPE__ int\000"
.LASF501:
	.ascii	"_MACHINE__TYPES_H \000"
.LASF276:
	.ascii	"__DQ_FBIT__ 63\000"
.LASF400:
	.ascii	"__GNU_VISIBLE 0\000"
.LASF441:
	.ascii	"_readdir readdir\000"
.LASF453:
	.ascii	"__PTRDIFF_T \000"
.LASF283:
	.ascii	"__UHQ_IBIT__ 0\000"
.LASF1020:
	.ascii	"LONG_LONG_MIN (-LONG_LONG_MAX - 1LL)\000"
.LASF577:
	.ascii	"_REENT_WCTOMB_STATE(ptr) ((ptr)->_new._reent._wctom"
	.ascii	"b_state)\000"
.LASF363:
	.ascii	"STM32F401xC 1\000"
.LASF59:
	.ascii	"__INT_FAST16_TYPE__ int\000"
.LASF514:
	.ascii	"__LOCK_INIT(class,lock) static int lock = 0;\000"
.LASF232:
	.ascii	"__SACCUM_MIN__ (-0X1P7HK-0X1P7HK)\000"
.LASF218:
	.ascii	"__ULFRACT_MAX__ 0XFFFFFFFFP-32ULR\000"
.LASF55:
	.ascii	"__UINT_LEAST16_TYPE__ short unsigned int\000"
.LASF1103:
	.ascii	"__initialize_args\000"
.LASF253:
	.ascii	"__LACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LK\000"
.LASF39:
	.ascii	"__CHAR16_TYPE__ short unsigned int\000"
.LASF578:
	.ascii	"_REENT_MBRLEN_STATE(ptr) ((ptr)->_new._reent._mbrle"
	.ascii	"n_state)\000"
.LASF729:
	.ascii	"__signed signed\000"
.LASF288:
	.ascii	"__UTQ_FBIT__ 128\000"
.LASF571:
	.ascii	"_REENT_ASCTIME_BUF(ptr) ((ptr)->_new._reent._asctim"
	.ascii	"e_buf)\000"
.LASF874:
	.ascii	"_BLKCNT_T_DECLARED \000"
.LASF16:
	.ascii	"__FINITE_MATH_ONLY__ 0\000"
.LASF113:
	.ascii	"__INT_FAST16_MAX__ 0x7fffffff\000"
.LASF953:
	.ascii	"DST_NONE 0\000"
.LASF808:
	.ascii	"_UINT8_T_DECLARED \000"
.LASF569:
	.ascii	"_REENT_MP_P5S(ptr) ((ptr)->_p5s)\000"
.LASF820:
	.ascii	"_UINTPTR_T_DECLARED \000"
.LASF487:
	.ascii	"_WCHAR_T_DEFINED \000"
.LASF258:
	.ascii	"__ULACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULK\000"
.LASF787:
	.ascii	"__trylocks_exclusive(...) __lock_annotate(exclusive"
	.ascii	"_trylock_function(__VA_ARGS__))\000"
.LASF99:
	.ascii	"__INT16_C(c) c\000"
.LASF836:
	.ascii	"__htons(_x) __bswap16(_x)\000"
.LASF1059:
	.ascii	"SIGCONT 19\000"
.LASF217:
	.ascii	"__ULFRACT_MIN__ 0.0ULR\000"
.LASF902:
	.ascii	"CLOCK_ALLOWED 1\000"
.LASF909:
	.ascii	"_IFBLK 0060000\000"
.LASF277:
	.ascii	"__DQ_IBIT__ 0\000"
.LASF581:
	.ascii	"_REENT_WCRTOMB_STATE(ptr) ((ptr)->_new._reent._wcrt"
	.ascii	"omb_state)\000"
.LASF809:
	.ascii	"__int8_t_defined 1\000"
.LASF760:
	.ascii	"__containerof(x,s,m) ({ const volatile __typeof(((s"
	.ascii	" *)0)->m) *__x = (x); __DEQUALIFY(s *, (const volat"
	.ascii	"ile char *)__x - __offsetof(s, m));})\000"
.LASF431:
	.ascii	"_DEFUN_VOID(name) name(_NOARGS)\000"
.LASF468:
	.ascii	"_BSD_SIZE_T_ \000"
.LASF596:
	.ascii	"ESRCH 3\000"
.LASF484:
	.ascii	"_WCHAR_T_ \000"
.LASF816:
	.ascii	"_INT64_T_DECLARED \000"
.LASF1052:
	.ascii	"SIGSYS 12\000"
.LASF70:
	.ascii	"__GXX_ABI_VERSION 1009\000"
.LASF982:
	.ascii	"_LIMITS_H___ \000"
.LASF482:
	.ascii	"_T_WCHAR \000"
.LASF1101:
	.ascii	"../system/src/newlib/_syscalls.c\000"
.LASF650:
	.ascii	"ENOTSOCK 108\000"
.LASF456:
	.ascii	"___int_ptrdiff_t_h \000"
.LASF935:
	.ascii	"S_IRGRP 0000040\000"
.LASF598:
	.ascii	"EIO 5\000"
.LASF534:
	.ascii	"_CLOCKID_T_ unsigned long\000"
.LASF557:
	.ascii	"_REENT_CHECK_TM(ptr) \000"
.LASF671:
	.ascii	"ESTALE 133\000"
.LASF289:
	.ascii	"__UTQ_IBIT__ 0\000"
.LASF292:
	.ascii	"__SA_FBIT__ 15\000"
.LASF490:
	.ascii	"__INT_WCHAR_T_H \000"
.LASF956:
	.ascii	"DST_WET 3\000"
.LASF432:
	.ascii	"_CAST_VOID (void)\000"
.LASF989:
	.ascii	"UCHAR_MAX\000"
.LASF1058:
	.ascii	"SIGTSTP 18\000"
.LASF352:
	.ascii	"__ARM_EABI__ 1\000"
.LASF357:
	.ascii	"__ELF__ 1\000"
.LASF346:
	.ascii	"__THUMBEL__ 1\000"
.LASF328:
	.ascii	"__ARM_FEATURE_DSP 1\000"
.LASF679:
	.ascii	"__ELASTERROR 2000\000"
.LASF271:
	.ascii	"__QQ_IBIT__ 0\000"
.LASF345:
	.ascii	"__ARMEL__ 1\000"
.LASF1011:
	.ascii	"ULONG_MAX\000"
.LASF942:
	.ascii	"ACCESSPERMS (S_IRWXU | S_IRWXG | S_IRWXO)\000"
.LASF1077:
	.ascii	"SIG_ERR ((_sig_func_ptr)-1)\000"
.LASF802:
	.ascii	"CLOCKS_PER_SEC _CLOCKS_PER_SEC_\000"
.LASF260:
	.ascii	"__LLACCUM_FBIT__ 31\000"
.LASF420:
	.ascii	"_NOARGS void\000"
.LASF285:
	.ascii	"__USQ_IBIT__ 0\000"
.LASF6:
	.ascii	"__GNUC_MINOR__ 4\000"
.LASF56:
	.ascii	"__UINT_LEAST32_TYPE__ long unsigned int\000"
.LASF792:
	.ascii	"__requires_exclusive(...) __lock_annotate(exclusive"
	.ascii	"_locks_required(__VA_ARGS__))\000"
.LASF546:
	.ascii	"_RAND48_MULT_1 (0xdeec)\000"
.LASF37:
	.ascii	"__INTMAX_TYPE__ long long int\000"
.LASF318:
	.ascii	"__GCC_ATOMIC_INT_LOCK_FREE 2\000"
.LASF646:
	.ascii	"ECONNRESET 104\000"
.LASF595:
	.ascii	"ENOENT 2\000"
.LASF827:
	.ascii	"_QUAD_LOWWORD 0\000"
.LASF542:
	.ascii	"_RAND48_SEED_0 (0x330e)\000"
.LASF984:
	.ascii	"CHAR_BIT __CHAR_BIT__\000"
.LASF889:
	.ascii	"_SSIZE_T_DECLARED \000"
.LASF499:
	.ascii	"_GCC_MAX_ALIGN_T \000"
.LASF537:
	.ascii	"__Long long\000"
.LASF475:
	.ascii	"_SIZET_ \000"
.LASF239:
	.ascii	"__USACCUM_EPSILON__ 0x1P-8UHK\000"
.LASF154:
	.ascii	"__DBL_HAS_QUIET_NAN__ 1\000"
.LASF695:
	.ascii	"__ptrvalue \000"
.LASF438:
	.ascii	"_NOINLINE_STATIC _NOINLINE static\000"
.LASF223:
	.ascii	"__LLFRACT_MAX__ 0X7FFFFFFFFFFFFFFFP-63LLR\000"
.LASF185:
	.ascii	"__DEC128_MAX_EXP__ 6145\000"
.LASF842:
	.ascii	"_SUSECONDS_T_DECLARED \000"
.LASF1039:
	.ascii	"sigismember(what,sig) (((*(what)) & (1<<(sig))) != "
	.ascii	"0)\000"
.LASF0:
	.ascii	"__STDC__ 1\000"
.LASF233:
	.ascii	"__SACCUM_MAX__ 0X7FFFP-7HK\000"
.LASF590:
	.ascii	"_GLOBAL_REENT _global_impure_ptr\000"
.LASF67:
	.ascii	"__UINTPTR_TYPE__ unsigned int\000"
.LASF306:
	.ascii	"__REGISTER_PREFIX__ \000"
.LASF189:
	.ascii	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000"
	.ascii	"000000001E-6143DL\000"
.LASF142:
	.ascii	"__DBL_DIG__ 15\000"
.LASF219:
	.ascii	"__ULFRACT_EPSILON__ 0x1P-32ULR\000"
.LASF774:
	.ascii	"__RCSID(s) struct __hack\000"
.LASF840:
	.ascii	"_SYS__SIGSET_H_ \000"
.LASF24:
	.ascii	"__SIZEOF_SIZE_T__ 4\000"
.LASF1070:
	.ascii	"SIGWINCH 28\000"
.LASF1094:
	.ascii	"name\000"
.LASF704:
	.ascii	"__GNUCLIKE___OFFSETOF 1\000"
.LASF186:
	.ascii	"__DEC128_MIN__ 1E-6143DL\000"
.LASF103:
	.ascii	"__INT64_C(c) c ## LL\000"
.LASF376:
	.ascii	"HAVE_INITFINI_ARRAY 1\000"
.LASF784:
	.ascii	"__lockable __lock_annotate(lockable)\000"
.LASF414:
	.ascii	"_HAVE_STDC \000"
.LASF864:
	.ascii	"FD_ZERO(p) (__extension__ (void)({ size_t __i; char"
	.ascii	" *__tmp = (char *)p; for (__i = 0; __i < sizeof (*("
	.ascii	"p)); ++__i) *__tmp++ = 0; }))\000"
.LASF700:
	.ascii	"__END_DECLS \000"
.LASF821:
	.ascii	"__MACHINE_ENDIAN_H__ \000"
.LASF163:
	.ascii	"__LDBL_MIN__ 2.2250738585072014e-308L\000"
.LASF241:
	.ascii	"__ACCUM_IBIT__ 16\000"
.LASF860:
	.ascii	"fd_set _types_fd_set\000"
.LASF528:
	.ascii	"unsigned\000"
.LASF834:
	.ascii	"__bswap64(_x) __builtin_bswap64(_x)\000"
.LASF698:
	.ascii	"__has_builtin(x) 0\000"
.LASF1083:
	.ascii	"short int\000"
.LASF447:
	.ascii	"_STDDEF_H \000"
.LASF797:
	.ascii	"__pt_guarded_by(x) __lock_annotate(pt_guarded_by(x)"
	.ascii	")\000"
.LASF796:
	.ascii	"__guarded_by(x) __lock_annotate(guarded_by(x))\000"
.LASF554:
	.ascii	"_REENT_INIT_PTR_ZEROED(var) { (var)->_stdin = &(var"
	.ascii	")->__sf[0]; (var)->_stdout = &(var)->__sf[1]; (var)"
	.ascii	"->_stderr = &(var)->__sf[2]; (var)->_new._reent._ra"
	.ascii	"nd_next = 1; (var)->_new._reent._r48._seed[0] = _RA"
	.ascii	"ND48_SEED_0; (var)->_new._reent._r48._seed[1] = _RA"
	.ascii	"ND48_SEED_1; (var)->_new._reent._r48._seed[2] = _RA"
	.ascii	"ND48_SEED_2; (var)->_new._reent._r48._mult[0] = _RA"
	.ascii	"ND48_MULT_0; (var)->_new._reent._r48._mult[1] = _RA"
	.ascii	"ND48_MULT_1; (var)->_new._reent._r48._mult[2] = _RA"
	.ascii	"ND48_MULT_2; (var)->_new._reent._r48._add = _RAND48"
	.ascii	"_ADD; }\000"
.LASF107:
	.ascii	"__UINT16_C(c) c\000"
.LASF957:
	.ascii	"DST_MET 4\000"
.LASF540:
	.ascii	"_REENT_INIT_ATEXIT _NULL, _ATEXIT_INIT,\000"
.LASF718:
	.ascii	"__CC_SUPPORTS___INLINE__ 1\000"
.LASF303:
	.ascii	"__UDA_IBIT__ 32\000"
.LASF761:
	.ascii	"__printflike(fmtarg,firstvararg) __attribute__((__f"
	.ascii	"ormat__ (__printf__, fmtarg, firstvararg)))\000"
.LASF139:
	.ascii	"__FLT_HAS_INFINITY__ 1\000"
.LASF748:
	.ascii	"__fastcall __attribute__((__fastcall__))\000"
.LASF857:
	.ascii	"FD_SETSIZE 64\000"
.LASF656:
	.ascii	"ENETDOWN 115\000"
.LASF783:
	.ascii	"__lock_annotate(x) \000"
.LASF9:
	.ascii	"__ATOMIC_RELAXED 0\000"
.LASF435:
	.ascii	"_ATTRIBUTE(attrs) __attribute__ (attrs)\000"
.LASF992:
	.ascii	"CHAR_MIN SCHAR_MIN\000"
.LASF588:
	.ascii	"__ATTRIBUTE_IMPURE_PTR__ \000"
.LASF153:
	.ascii	"__DBL_HAS_INFINITY__ 1\000"
.LASF766:
	.ascii	"__gnu_inline __attribute__((__gnu_inline__, __artif"
	.ascii	"icial__))\000"
.LASF86:
	.ascii	"__SIG_ATOMIC_MAX__ 0x7fffffff\000"
.LASF545:
	.ascii	"_RAND48_MULT_0 (0xe66d)\000"
.LASF615:
	.ascii	"ENFILE 23\000"
.LASF597:
	.ascii	"EINTR 4\000"
.LASF759:
	.ascii	"__rangeof(type,start,end) (__offsetof(type, end) - "
	.ascii	"__offsetof(type, start))\000"
.LASF959:
	.ascii	"DST_CAN 6\000"
.LASF1002:
	.ascii	"INT_MIN (-INT_MAX - 1)\000"
.LASF358:
	.ascii	"__USES_INITFINI__ 1\000"
.LASF914:
	.ascii	"S_BLKSIZE 1024\000"
.LASF179:
	.ascii	"__DEC64_MIN__ 1E-383DD\000"
.LASF635:
	.ascii	"ENOLINK 67\000"
.LASF147:
	.ascii	"__DBL_DECIMAL_DIG__ 17\000"
.LASF454:
	.ascii	"_PTRDIFF_T_ \000"
.LASF536:
	.ascii	"_NULL 0\000"
.LASF692:
	.ascii	"__flexarr [0]\000"
.LASF525:
	.ascii	"__lock_release_recursive(lock) (_CAST_VOID 0)\000"
.LASF818:
	.ascii	"__int64_t_defined 1\000"
.LASF89:
	.ascii	"__INT16_MAX__ 0x7fff\000"
.LASF374:
	.ascii	"_WANT_REGISTER_FINI 1\000"
.LASF599:
	.ascii	"ENXIO 6\000"
.LASF779:
	.ascii	"__DEVOLATILE(type,var) ((type)(__uintptr_t)(volatil"
	.ascii	"e void *)(var))\000"
.LASF479:
	.ascii	"__WCHAR_T__ \000"
.LASF335:
	.ascii	"__ARM_FEATURE_SIMD32 1\000"
.LASF406:
	.ascii	"__XSI_VISIBLE 0\000"
.LASF270:
	.ascii	"__QQ_FBIT__ 7\000"
.LASF321:
	.ascii	"__GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1\000"
.LASF917:
	.ascii	"S_ISVTX 0001000\000"
.LASF868:
	.ascii	"_IN_PORT_T_DECLARED \000"
.LASF937:
	.ascii	"S_IXGRP 0000010\000"
.LASF1074:
	.ascii	"NSIG 32\000"
.LASF389:
	.ascii	"__GNUC_PREREQ__(ma,mi) __GNUC_PREREQ(ma, mi)\000"
.LASF305:
	.ascii	"__UTA_IBIT__ 64\000"
.LASF41:
	.ascii	"__SIG_ATOMIC_TYPE__ int\000"
.LASF768:
	.ascii	"__strong_reference(sym,aliassym) extern __typeof (s"
	.ascii	"ym) aliassym __attribute__ ((__alias__ (#sym)))\000"
.LASF229:
	.ascii	"__ULLFRACT_EPSILON__ 0x1P-64ULLR\000"
.LASF751:
	.ascii	"__unreachable() __builtin_unreachable()\000"
.LASF826:
	.ascii	"_QUAD_HIGHWORD 1\000"
.LASF326:
	.ascii	"__SIZEOF_WINT_T__ 4\000"
.LASF1097:
	.ascii	"kill\000"
.LASF634:
	.ascii	"ENOSR 63\000"
.LASF331:
	.ascii	"__ARM_FEATURE_UNALIGNED 1\000"
.LASF356:
	.ascii	"__GXX_TYPEINFO_EQUALITY_INLINE 0\000"
.LASF786:
	.ascii	"__locks_shared(...) __lock_annotate(shared_lock_fun"
	.ascii	"ction(__VA_ARGS__))\000"
.LASF976:
	.ascii	"MB_LEN_MAX _MB_LEN_MAX\000"
.LASF425:
	.ascii	"_VOID void\000"
.LASF701:
	.ascii	"__GNUCLIKE_ASM 3\000"
.LASF252:
	.ascii	"__LACCUM_MIN__ (-0X1P31LK-0X1P31LK)\000"
.LASF112:
	.ascii	"__INT_FAST8_MAX__ 0x7fffffff\000"
.LASF762:
	.ascii	"__scanflike(fmtarg,firstvararg) __attribute__((__fo"
	.ascii	"rmat__ (__scanf__, fmtarg, firstvararg)))\000"
.LASF170:
	.ascii	"__DEC32_MIN_EXP__ (-94)\000"
.LASF267:
	.ascii	"__ULLACCUM_MIN__ 0.0ULLK\000"
.LASF807:
	.ascii	"_INT8_T_DECLARED \000"
.LASF489:
	.ascii	"___int_wchar_t_h \000"
.LASF316:
	.ascii	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2\000"
.LASF710:
	.ascii	"__GNUCLIKE_BUILTIN_VAALIST 1\000"
.LASF771:
	.ascii	"__sym_compat(sym,impl,verid) __asm__(\".symver \" #"
	.ascii	"impl \", \" #sym \"@\" #verid)\000"
.LASF1015:
	.ascii	"LLONG_MAX\000"
.LASF1001:
	.ascii	"INT_MIN\000"
.LASF355:
	.ascii	"__ARM_ASM_SYNTAX_UNIFIED__ 1\000"
.LASF932:
	.ascii	"S_IWUSR 0000200\000"
.LASF785:
	.ascii	"__locks_exclusive(...) __lock_annotate(exclusive_lo"
	.ascii	"ck_function(__VA_ARGS__))\000"
.LASF1042:
	.ascii	"SIGQUIT 3\000"
.LASF48:
	.ascii	"__UINT32_TYPE__ long unsigned int\000"
.LASF801:
	.ascii	"_CLOCKS_PER_SEC_ 100\000"
.LASF343:
	.ascii	"__thumb2__ 1\000"
.LASF858:
	.ascii	"NFDBITS (sizeof (fd_mask) * 8)\000"
.LASF390:
	.ascii	"_DEFAULT_SOURCE\000"
.LASF977:
	.ascii	"NL_ARGMAX 32\000"
.LASF474:
	.ascii	"_GCC_SIZE_T \000"
.LASF720:
	.ascii	"__CC_SUPPORTS_WARNING 1\000"
.LASF151:
	.ascii	"__DBL_DENORM_MIN__ ((double)4.9406564584124654e-324"
	.ascii	"L)\000"
.LASF227:
	.ascii	"__ULLFRACT_MIN__ 0.0ULLR\000"
.LASF481:
	.ascii	"_T_WCHAR_ \000"
.LASF873:
	.ascii	"_BSDTYPES_DEFINED \000"
.LASF555:
	.ascii	"_REENT_CHECK_RAND48(ptr) \000"
.LASF553:
	.ascii	"_REENT_INIT(var) { 0, &(var).__sf[0], &(var).__sf[1"
	.ascii	"], &(var).__sf[2], 0, \"\", 0, _NULL, 0, _NULL, _NU"
	.ascii	"LL, 0, _NULL, _NULL, 0, _NULL, { { 0, _NULL, \"\", "
	.ascii	"{0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 1, { {_RAND48_SEED_"
	.ascii	"0, _RAND48_SEED_1, _RAND48_SEED_2}, {_RAND48_MULT_0"
	.ascii	", _RAND48_MULT_1, _RAND48_MULT_2}, _RAND48_ADD }, {"
	.ascii	"0, {0}}, {0, {0}}, {0, {0}}, \"\", \"\", 0, {0, {0}"
	.ascii	"}, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}} } }, _REE"
	.ascii	"NT_INIT_ATEXIT _NULL, {_NULL, 0, _NULL} }\000"
.LASF17:
	.ascii	"__SIZEOF_INT__ 4\000"
.LASF493:
	.ascii	"_BSD_WCHAR_T_\000"
.LASF221:
	.ascii	"__LLFRACT_IBIT__ 0\000"
.LASF721:
	.ascii	"__CC_SUPPORTS_VARADIC_XXX 1\000"
.LASF752:
	.ascii	"__restrict restrict\000"
.LASF616:
	.ascii	"EMFILE 24\000"
.LASF923:
	.ascii	"S_IFDIR _IFDIR\000"
.LASF234:
	.ascii	"__SACCUM_EPSILON__ 0x1P-7HK\000"
.LASF607:
	.ascii	"EFAULT 14\000"
.LASF1046:
	.ascii	"SIGABRT 6\000"
.LASF629:
	.ascii	"EDEADLK 45\000"
.LASF974:
	.ascii	"_GCC_NEXT_LIMITS_H \000"
.LASF393:
	.ascii	"_POSIX_SOURCE 1\000"
.LASF63:
	.ascii	"__UINT_FAST16_TYPE__ unsigned int\000"
.LASF299:
	.ascii	"__UHA_IBIT__ 8\000"
.LASF308:
	.ascii	"__GNUC_STDC_INLINE__ 1\000"
.LASF529:
	.ascii	"__need_wint_t \000"
.LASF244:
	.ascii	"__ACCUM_EPSILON__ 0x1P-15K\000"
.LASF259:
	.ascii	"__ULACCUM_EPSILON__ 0x1P-32ULK\000"
.LASF156:
	.ascii	"__LDBL_DIG__ 15\000"
.LASF981:
	.ascii	"_GCC_NEXT_LIMITS_H\000"
.LASF79:
	.ascii	"__WINT_MIN__ 0U\000"
.LASF908:
	.ascii	"_IFCHR 0020000\000"
.LASF181:
	.ascii	"__DEC64_EPSILON__ 1E-15DD\000"
.LASF106:
	.ascii	"__UINT_LEAST16_MAX__ 0xffff\000"
.LASF78:
	.ascii	"__WINT_MAX__ 0xffffffffU\000"
.LASF738:
	.ascii	"__section(x) __attribute__((__section__(x)))\000"
.LASF906:
	.ascii	"_IFMT 0170000\000"
.LASF688:
	.ascii	"__long_double_t long double\000"
.LASF51:
	.ascii	"__INT_LEAST16_TYPE__ short int\000"
.LASF810:
	.ascii	"_INT16_T_DECLARED \000"
.LASF148:
	.ascii	"__DBL_MAX__ ((double)1.7976931348623157e+308L)\000"
.LASF1084:
	.ascii	"short unsigned int\000"
.LASF220:
	.ascii	"__LLFRACT_FBIT__ 63\000"
.LASF478:
	.ascii	"__wchar_t__ \000"
.LASF342:
	.ascii	"__thumb__ 1\000"
.LASF823:
	.ascii	"_BIG_ENDIAN 4321\000"
.LASF678:
	.ascii	"EWOULDBLOCK EAGAIN\000"
.LASF1006:
	.ascii	"UINT_MAX (INT_MAX * 2U + 1U)\000"
.LASF517:
	.ascii	"__lock_init_recursive(lock) (_CAST_VOID 0)\000"
.LASF627:
	.ascii	"ENOMSG 35\000"
.LASF712:
	.ascii	"__compiler_membar() __asm __volatile(\" \" : : : \""
	.ascii	"memory\")\000"
.LASF1055:
	.ascii	"SIGTERM 15\000"
.LASF272:
	.ascii	"__HQ_FBIT__ 15\000"
.LASF611:
	.ascii	"ENODEV 19\000"
.LASF782:
	.ascii	"__datatype_type_tag(kind,type) \000"
.LASF584:
	.ascii	"_REENT_SIGNAL_BUF(ptr) ((ptr)->_new._reent._signal_"
	.ascii	"buf)\000"
.LASF919:
	.ascii	"S_IWRITE 0000200\000"
.LASF81:
	.ascii	"__SIZE_MAX__ 0xffffffffU\000"
.LASF1035:
	.ascii	"sigaddset(what,sig) (*(what) |= (1<<(sig)), 0)\000"
.LASF867:
	.ascii	"_IN_ADDR_T_DECLARED \000"
.LASF630:
	.ascii	"ENOLCK 46\000"
.LASF1060:
	.ascii	"SIGCHLD 20\000"
.LASF1061:
	.ascii	"SIGCLD 20\000"
.LASF74:
	.ascii	"__LONG_MAX__ 0x7fffffffL\000"
.LASF682:
	.ascii	"_SYS_CDEFS_H_ \000"
.LASF848:
	.ascii	"timercmp(tvp,uvp,cmp) (((tvp)->tv_sec == (uvp)->tv_"
	.ascii	"sec) ? ((tvp)->tv_usec cmp (uvp)->tv_usec) : ((tvp)"
	.ascii	"->tv_sec cmp (uvp)->tv_sec))\000"
.LASF668:
	.ascii	"ENOTCONN 128\000"
.LASF548:
	.ascii	"_RAND48_ADD (0x000b)\000"
.LASF972:
	.ascii	"_SYS_TIMES_H \000"
.LASF333:
	.ascii	"__ARM_FEATURE_LDREX 7\000"
.LASF1009:
	.ascii	"LONG_MAX\000"
.LASF830:
	.ascii	"PDP_ENDIAN _PDP_ENDIAN\000"
.LASF224:
	.ascii	"__LLFRACT_EPSILON__ 0x1P-63LLR\000"
.LASF958:
	.ascii	"DST_EET 5\000"
.LASF193:
	.ascii	"__SFRACT_MAX__ 0X7FP-7HR\000"
.LASF856:
	.ascii	"_SYS_TYPES_FD_SET \000"
.LASF999:
	.ascii	"USHRT_MAX\000"
.LASF625:
	.ascii	"EDOM 33\000"
.LASF665:
	.ascii	"EADDRNOTAVAIL 125\000"
.LASF663:
	.ascii	"EMSGSIZE 122\000"
.LASF990:
	.ascii	"UCHAR_MAX (SCHAR_MAX * 2 + 1)\000"
.LASF987:
	.ascii	"SCHAR_MAX\000"
.LASF1008:
	.ascii	"LONG_MIN (-LONG_MAX - 1L)\000"
.LASF295:
	.ascii	"__DA_IBIT__ 32\000"
.LASF993:
	.ascii	"CHAR_MAX\000"
.LASF765:
	.ascii	"__strftimelike(fmtarg,firstvararg) __attribute__((_"
	.ascii	"_format__ (__strftime__, fmtarg, firstvararg)))\000"
.LASF539:
	.ascii	"_ATEXIT_INIT {_NULL, 0, {_NULL}, {{_NULL}, {_NULL},"
	.ascii	" 0, 0}}\000"
.LASF780:
	.ascii	"__DEQUALIFY(type,var) ((type)(__uintptr_t)(const vo"
	.ascii	"latile void *)(var))\000"
.LASF869:
	.ascii	"__u_char_defined \000"
.LASF727:
	.ascii	"__XSTRING(x) __STRING(x)\000"
.LASF921:
	.ascii	"S_ENFMT 0002000\000"
.LASF273:
	.ascii	"__HQ_IBIT__ 0\000"
.LASF736:
	.ascii	"__packed __attribute__((__packed__))\000"
.LASF486:
	.ascii	"_WCHAR_T_DEFINED_ \000"
.LASF657:
	.ascii	"ETIMEDOUT 116\000"
.LASF373:
	.ascii	"_WANT_IO_LONG_LONG 1\000"
.LASF931:
	.ascii	"S_IRUSR 0000400\000"
.LASF791:
	.ascii	"__asserts_shared(...) __lock_annotate(assert_shared"
	.ascii	"_lock(__VA_ARGS__))\000"
.LASF513:
	.ascii	"__SYS_LOCK_H__ \000"
.LASF1038:
	.ascii	"sigfillset(what) (*(what) = ~(0), 0)\000"
.LASF964:
	.ascii	"SBT_1M (SBT_1S * 60)\000"
.LASF1051:
	.ascii	"SIGSEGV 11\000"
.LASF825:
	.ascii	"_BYTE_ORDER _LITTLE_ENDIAN\000"
.LASF892:
	.ascii	"__clockid_t_defined \000"
.LASF394:
	.ascii	"_POSIX_C_SOURCE\000"
.LASF84:
	.ascii	"__UINTMAX_MAX__ 0xffffffffffffffffULL\000"
.LASF141:
	.ascii	"__DBL_MANT_DIG__ 53\000"
.LASF216:
	.ascii	"__ULFRACT_IBIT__ 0\000"
.LASF1031:
	.ascii	"SS_DISABLE 0x2\000"
.LASF680:
	.ascii	"_SYS_STAT_H \000"
.LASF872:
	.ascii	"__u_long_defined \000"
.LASF73:
	.ascii	"__INT_MAX__ 0x7fffffff\000"
.LASF53:
	.ascii	"__INT_LEAST64_TYPE__ long long int\000"
.LASF893:
	.ascii	"_CLOCKID_T_DECLARED \000"
.LASF230:
	.ascii	"__SACCUM_FBIT__ 7\000"
	.ident	"GCC: (GNU Tools for ARM Embedded Processors) 5.4.1 20160919 (release) [ARM/embedded-5-branch revision 240496]"
